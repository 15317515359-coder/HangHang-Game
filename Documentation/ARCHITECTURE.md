# 🏗️ 架构设计文档

## 系统架构概述

```
┌─────────────────────────────────────────────────────────┐
│                    HangHang-Game                          │
│                  Unreal Engine 5                          │
└─────────────────────────────────────────────────────────┘
           ↓
┌─────────────────────────────────────────────────────────┐
│                   Core Systems                           │
├─────────────────────────────────────────────────────────┤
│  Player System  │ Farm System  │ NPC System │ UI System  │
└─────────────────────────────────────────────────────────┘
           ↓
┌─────────────────────────────────────────────────────────┐
│              Gameplay Mechanics                          │
├─────────────────────────────────────────────────────────┤
│  Economy │ Trading │ Crafting │ Relationship │ Weather  │
└─────────────────────────────────────────────────────────┘
           ↓
┌─────────────────────────────────────────────────────────┐
│           Data & Persistence Layer                       │
├─────────────────────────────────────────────────────────┤
│  Save System │ Database │ Config Files │ Analytics      │
└─────────────────────────────────────────────────────────┘
```

## 模块设计

### 1. Player System（玩家系统）

**职责:**
- 管理玩家角色和状态
- 处理输入和交互
- 管理背包和资源
- 追踪玩家进度

**关键类:**

```cpp
class APlayerCharacter : public ACharacter
{
public:
    // 基础属性
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Health = 100.0f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Stamina = 100.0f;
    
    // 资源
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Gold = 0;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Prestige = 0;
    
    // 背包系统
    UPROPERTY(BlueprintReadOnly)
    class AInventorySystem* Inventory;
    
    // 接口
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
    
    UFUNCTION(BlueprintCallable)
    void AddGold(int32 Amount);
    
    UFUNCTION(BlueprintCallable)
    void RemoveGold(int32 Amount);
    
    UFUNCTION(BlueprintCallable)
    void GainPrestige(int32 Amount);
};
```

**相关类:**
- `AInventorySystem` - 背包管理
- `UPlayerStats` - 玩家统计数据
- `UPlayerSaveGame` - 游戏保存

### 2. Farm System（农场系统）

**职责:**
- 管理农田和作物
- 处理作物生长机制
- 管理土壤肥力
- 处理收获和销售

**关键类:**

```cpp
class AFarmTile : public AActor
{
public:
    // 作物信息
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    class ACrop* CurrentCrop;
    
    // 土壤属性
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SoilFertility = 60.0f; // 0-100
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SoilMoisture = 50.0f; // 0-100
    
    // 方法
    UFUNCTION(BlueprintCallable)
    void PlantCrop(class ACrop* CropType);
    
    UFUNCTION(BlueprintCallable)
    void Water();
    
    UFUNCTION(BlueprintCallable)
    void Fertilize();
    
    UFUNCTION(BlueprintCallable)
    class ACrop* Harvest();
    
    virtual void Tick(float DeltaTime) override;
    
private:
    void UpdateCropGrowth(float DeltaTime);
    void UpdateSoilConditions(float DeltaTime);
};

class ACrop : public AActor
{
public:
    // 作物类型
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CropName;
    
    // 生长阶段（0-100%）
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float GrowthProgress = 0.0f;
    
    // 生长参数
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float GrowthDaysRequired = 5.0f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float WaterRequirementPerDay = 2.0f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 YieldAmount = 10;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SellPrice = 50;
    
    // 方法
    UFUNCTION(BlueprintCallable)
    bool IsRipe() const;
    
    UFUNCTION(BlueprintCallable)
    void UpdateGrowth(float DeltaTime);
};
```

**生长计算:**
```
生长速度 = 基础速度 × 土壤肥力系数 × 天气系数 × 水分系数

基础速度 = 1.0 / 生长天数
土壤肥力系数 = (肥力等级 + 30) / 100
天气系数：
  - 晴天: 1.0
  - 多云: 0.8
  - 雨天: 1.2
  - 暴雨: 0.5
water系数 = MIN(1.0, 当前水分 / 需要水分)
```

### 3. NPC System（NPC 系统）

**职责:**
- 管理 NPC 角色和行为
- 处理日程和例程
- 管理好感度
- 处理对话和任务

**关键类:**

```cpp
class ANPC : public ACharacter
{
public:
    // NPC 信息
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NPCName;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Description;
    
    // 好感度系统
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Affection = 0.0f; // 0-100
    
    // 日程
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<struct FDailySchedule> DailySchedule;
    
    // 方法
    UFUNCTION(BlueprintCallable)
    void Interact(class APlayerCharacter* Player);
    
    UFUNCTION(BlueprintCallable)
    void ReceiveGift(class UItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void AffectAffection(float Delta);
    
    UFUNCTION(BlueprintCallable)
    void StartQuest();
    
    UFUNCTION(BlueprintCallable)
    void CompleteQuest();
    
    virtual void Tick(float DeltaTime) override;
    
private:
    void ExecuteSchedule();
    void UpdateAffection();
};

struct FDailySchedule
{
    FTime StartTime;
    FTime EndTime;
    FVector Location;
    FString Activity;
};
```

**好感度系统:**
```
好感度等级划分：
[0, 20): 陌生人  (Stranger)
[20, 40): 熟人   (Acquaintance)
[40, 60): 朋友   (Friend)
[60, 80): 好友   (Close Friend)
[80, 100]: 知心  (Best Friend)

好感度增加来源：
- 赠送喜欢的物品: +5
- 完成 NPC 任务: +10
- 每日对话: +1
- 参加节日活动: +15
- 在他们生日送礼: +20
```

### 4. Economy System（经济系统）

**职责:**
- 管理市场价格
- 处理交易
- 管理库存
- 计算利润

**关键类:**

```cpp
class UEconomyManager : public UGameInstanceSubsystem
{
public:
    // 市场数据
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FString, struct FMarketItem> MarketPrices;
    
    // 方法
    UFUNCTION(BlueprintCallable)
    float GetDynamicPrice(const FString& ItemID);
    
    UFUNCTION(BlueprintCallable)
    void SellItem(const FString& ItemID, int32 Amount);
    
    UFUNCTION(BlueprintCallable)
    void BuyItem(const FString& ItemID, int32 Amount);
    
    UFUNCTION(BlueprintCallable)
    void UpdateMarketPrices();
    
private:
    void CalculatePriceFluctuation();
};

struct FMarketItem
{
    FString ItemID;
    FString ItemName;
    float BasePrice;
    float CurrentPrice;
    int32 AvailableQuantity;
    float DemandLevel; // 需求水平
};
```

**价格计算:**
```
动态价格 = 基础价格 × 需求系数 × 供应系数

需求系数 = 0.8 + (需求水平 × 0.4)
供应系数 = 1.0 / (1.0 + 库存 / 平衡库存)

价格范围：基础价格 × 0.6 ~ 基础价格 × 1.6
```

### 5. UI System（UI 系统）

**职责:**
- 管理游戏界面
- 处理菜单和对话
- 显示信息和通知
- 处理用户输入

**关键类:**

```cpp
class UMainHUD : public AHUD
{
public:
    virtual void BeginPlay() override;
    virtual void DrawHUD() override;
    
    UFUNCTION(BlueprintCallable)
    void ShowInventory();
    
    UFUNCTION(BlueprintCallable)
    void HideInventory();
    
    UFUNCTION(BlueprintCallable)
    void ShowDialogue(const FString& NPCName, const FString& DialogueText);
    
    UFUNCTION(BlueprintCallable)
    void ShowNotification(const FString& Message);
    
private:
    class UInventoryWidget* InventoryWidget;
    class UDialogueWidget* DialogueWidget;
    class UNotificationWidget* NotificationWidget;
};
```

## 数据流

### 游戏循环

```
初始化
  ↓
加载游戏数据
  ↓
主游戏循环
  ├─ 更新玩家输入
  ├─ 更新游戏逻辑
  │   ├─ 更新天气系统
  │   ├─ 更新作物生长
  │   ├─ 更新 NPC 行为
  │   ├─ 更新市场价格
  │   └─ 更新任务进度
  ├─ 更新 UI
  └─ 渲染场景
  ↓
保存游戏（定期）
  ↓
游戏结束时保存
```

### 作物生长流程

```
播种
  ↓
记录种植时间和参数
  ↓
每帧更新
  ├─ 计算生长进度
  ├─ 检查水分
  ├─ 检查肥力
  ├─ 检查天气
  └─ 更新视觉表现
  ↓
检查是否成熟
  ├─ 是 → 允许收获
  └─ 否 → 继续生长
  ↓
收获
  ├─ 添加到背包
  ├─ 更新统计
  └─ 清空农田
```

## 保存系统

**保存内容:**
```cpp
struct FSaveGameData
{
    // 玩家数据
    FVector PlayerLocation;
    float PlayerHealth;
    int32 Gold;
    int32 Prestige;
    
    // 农场数据
    TArray<struct FFarmTileData> FarmTiles;
    
    // NPC 数据
    TMap<FString, struct FNPCData> NPCData;
    
    // 游戏时间
    int32 CurrentDay;
    int32 CurrentSeason;
    float TimeOfDay;
    
    // 任务数据
    TArray<struct FQuestData> Quests;
};
```

**保存频率:**
- 自动保存：每 5 分钟
- 手动保存：玩家请求时
- 退出游戏时：强制保存

## 性能优化

### 优化策略

1. **对象池:**
   - 复用子弹和效果
   - 减少内存分配

2. **LOD 系统:**
   - 距离远的物体使用低多边形模型
   - 减少渲染压力

3. **异步加载:**
   - 后台加载区域
   - 不中断游戏流程

4. **数据缓存:**
   - 缓存经常访问的数据
   - 避免重复计算

### 性能指标

- 目标帧率：60 FPS
- 目标内存：4GB
- 加载时间：<30 秒

---

**架构设计遵循 SOLID 原则，确保可维护性和扩展性。** ✨
