# 贡献指南

感谢你对 HangHang-Game 的兴趣！我们欢迎所有形式的贡献。

## 代码贡献流程

### 1. Fork 仓库

点击 GitHub 页面右上角的 "Fork" 按钮，创建你的仓库副本。

### 2. Clone 你的 Fork

```bash
git clone https://github.com/YOUR-USERNAME/HangHang-Game.git
cd HangHang-Game
git remote add upstream https://github.com/15317515359-coder/HangHang-Game.git
```

### 3. 创建功能分支

```bash
git checkout -b feature/your-feature-name
# 或
git checkout -b fix/your-bugfix-name
```

### 4. 提交更改

遵循以下提交消息格式：

```
<type>(<scope>): <subject>

<body>

<footer>
```

**类型:**
- `feat`: 新功能
- `fix`: 修复 bug
- `docs`: 文档更新
- `style`: 代码风格（不改变功能）
- `refactor`: 重构代码
- `test`: 添加或修改测试
- `chore`: 构建或依赖更新

**示例:**
```
feat(farm): add crop growth system

Implement dynamic crop growth based on soil fertility,
water level, and weather conditions.

Closes #123
```

### 5. Push 到你的 Fork

```bash
git push origin feature/your-feature-name
```

### 6. 创建 Pull Request

访问你的 Fork，点击 "New Pull Request"，并填写以下信息：

- **标题:** 清晰简洁地描述你的更改
- **描述:** 详细说明
  - 为什么做这个更改
  - 做了什么
  - 测试情况
  - 相关的 Issue

### 7. 代码审查

- 等待项目维护者审查
- 根据反馈进行修改
- 重新 Push 更新
- PR 被接受并合并

## 代码规范

### C++ 代码风格

```cpp
// 遵循 Unreal Engine 编码标准

// 类和结构体
class AMyActor : public AActor
{
public:
    // 公共属性
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyCategory")
    float MyProperty;
    
    // 公共方法
    UFUNCTION(BlueprintCallable, Category = "MyCategory")
    void MyMethod();
    
private:
    // 私有属性
    UPROPERTY()
    float PrivateProperty;
    
    // 私有方法
    void PrivateMethod();
};

// 命名约定
// - 类名前缀: A (Actor), U (Object), F (Struct), S (Slate)
// - 常量: k 前缀 (kMaxHealth)
// - 布尔值: b 前缀 (bIsAlive)
// - 方法: 大驼峰 (MyMethod)
// - 变量: 大驼峰 (MyVariable)
```

### 注释规范

```cpp
// 简短说明（一行）
int32 Health;

// 较长的说明
// 跨越多行时使用多个 // 注释
// 而不是 /* */ 块注释

/** 
 * Unreal Engine 标准文档注释
 * @param Damage 造成的伤害值
 * @return 是否成功
 */
bool TakeDamage(float Damage);
```

## 测试要求

在提交 PR 前，请确保：

- ✅ 代码在编辑器中编译通过
- ✅ 没有编译警告
- ✅ 功能按预期工作
- ✅ 没有引入新的 Bug
- ✅ 相关的单元测试通过

## 文档更新

如果你的更改影响用户，请更新相关文档：

- `README.md` - 项目概述
- `Documentation/GAMEPLAY.md` - 游戏玩法
- `Documentation/ARCHITECTURE.md` - 架构设计
- `Documentation/SETUP.md` - 开发环境

## 问题报告

发现 Bug？请创建 Issue 并包含：

1. **描述:** 清楚地描述问题
2. **复现步骤:** 详细的重现步骤
3. **预期行为:** 应该发生什么
4. **实际行为:** 实际发生了什么
5. **系统信息:**
   - OS: Windows/Mac/Linux
   - UE5 版本
   - GPU/CPU 信息
6. **截图/视频:** 如果适用

## 功能请求

建议新功能？创建 Issue 并包含：

1. **标题:** 简洁的功能名称
2. **描述:** 详细的功能说明
3. **用例:** 为什么需要这个功能
4. **实现建议:** 如果有想法的话

## 许可证

通过提交代码，你同意你的贡献在 MIT 许可证下发布。

## 行为准则

我们致力于为所有人创建一个包容和受欢迎的社区。请阅读并遵守我们的行为准则。

---

感谢你的贡献！❤️
