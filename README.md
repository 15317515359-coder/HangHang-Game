# 🎮 HangHang-Game

欢迎来到 **航航的游戏** 项目！这是一个基于 Unreal Engine 5 开发的休闲农场模拟游戏。

## 📋 项目概述

**HangHang-Game** 是一款集策略、模拟和休闲元素于一身的游戏，玩家可以：n- 🌾 种植和收获各种作物
- 🏠 建设和装饰自己的农场
- 💰 通过交易获取利润
- 👥 与 NPC 互动和交友
- 🎯 完成各类任务和挑战

## 🛠️ 技术栈

- **引擎:** Unreal Engine 5 (UE5)
- **语言:** C++, Blueprint
- **平台:** Windows, Mac, Linux
- **版本控制:** Git

## 📁 项目结构

```
HangHang-Game/
├── Content/                  # 游戏资源文件
│   ├── Characters/          # 角色模型和动画
│   ├── Environments/        # 环境和地形
│   ├── Items/              # 物品和道具
│   └── UI/                 # 用户界面资源
├── Source/                  # C++ 源代码
│   ├── HangHangGame/       # 游戏模块
│   ├── Player/             # 玩家相关代码
│   ├── Farm/               # 农场系统
│   ├── NPCs/               # NPC 系统
│   └── UI/                 # UI 系统
├── Binaries/               # 编译输出
├── Intermediate/           # 中间文件
├── Saved/                  # 保存文件
├── HangHangGame.uproject   # 项目文件
└── Documentation/          # 项目文档
    ├── GAMEPLAY.md         # 游戏玩法说明
    ├── ARCHITECTURE.md     # 架构设计文档
    └── SETUP.md           # 开发环境配置
```

## 🚀 快速开始

### 环境要求
- Unreal Engine 5.0 或更高版本
- Visual Studio 2022（Windows）或 Xcode（Mac）
- 至少 150GB 可用磁盘空间
- 8GB 以上 RAM（推荐 16GB+）

### 安装步骤

1. **克隆仓库**
   ```bash
   git clone https://github.com/15317515359-coder/HangHang-Game.git
   cd HangHang-Game
   ```

2. **生成 Visual Studio 项目文件**
   ```bash
   # Windows
   \\Engine\\Build\\BatchFiles\\GenerateProjectFiles.bat
   ```

3. **编译项目**
   ```bash
   # 使用 UE5 编辑器打开 HangHangGame.uproject
   # 或使用命令行编译
   ```

4. **启动游戏**
   - 在 UE5 编辑器中按 **Play** 按钮
   - 或构建发行版本

## 📖 核心系统

### 1. 🌾 农场系统
- 动态作物种植和生长
- 季节系统影响作物类型
- 土壤肥力管理
- 自动灌溉和施肥

### 2. 💼 经济系统
- 市场价格动态变化
- NPC 贸易系统
- 投资和收益计算
- 玩家资产管理

### 3. 👥 社交系统
- NPC 日程和例程
- 好感度系统
- 对话和任务系统
- 特殊事件触发

### 4. 🏗️ 建筑系统
- 自由建筑和装饰
- 建筑功能性（存储、制作、繁殖）
- 升级系统
- 美化度评分

## 🎮 游戏特色

✨ **沉浸式农场体验** - 真实的农业模拟流程
🎨 **自由创意建设** - 无限的装饰和布局可能性
🤝 **丰富的社交互动** - 与多个个性化 NPC 建立关系
📊 **深度经营策略** - 平衡收入和投资的经营乐趣
🌍 **多样化内容** - 四季变化、节日活动、隐藏任务

## 📚 文档

- [游戏玩法指南](./Documentation/GAMEPLAY.md)
- [架构设计文档](./Documentation/ARCHITECTURE.md)
- [开发环境设置](./Documentation/SETUP.md)
- [API 参考](./Documentation/API_REFERENCE.md)
- [美术资源指南](./Documentation/ART_GUIDELINES.md)

## 🤝 贡献指南

欢迎贡献代码、报告 Bug 或提出功能建议！

### 贡献流程
1. Fork 本仓库
2. 创建功能分支 (`git checkout -b feature/AmazingFeature`)
3. 提交更改 (`git commit -m 'Add some AmazingFeature'`)
4. 推送到分支 (`git push origin feature/AmazingFeature`)
5. 提交 Pull Request

### 代码规范
- 遵循 Unreal Engine 编码标准
- 使用有意义的变量和函数名
- 添加必要的注释和文档
- 确保代码通过编译和基本测试

## 🐛 Bug 反馈

发现 Bug？请在 [Issues](https://github.com/15317515359-coder/HangHang-Game/issues) 页面创建新的 issue，包含：
- Bug 描述
- 复现步骤
- 预期行为 vs 实际行为
- 系统信息（OS、UE5 版本等）

## 📋 开发路线图

### Phase 1: 核心系统（当前）
- ✅ 农场基础系统
- ✅ 作物种植机制
- ✅ 基础 NPC 系统
- 🔄 经济交易系统

### Phase 2: 扩展内容（计划中）
- 🔜 节日和特殊事件
- 🔜 高级建筑和工具
- 🔜 多人游戏功能
- 🔜 更多 NPC 和故事线

### Phase 3: 优化和发布（计划中）
- 🔜 性能优化
- 🔜 UI/UX 改进
- 🔜 本地化（多语言）
- 🔜 正式发布

## 📞 联系方式

- **GitHub Issues:** 用于 Bug 报告和功能请求
- **讨论区:** 用于一般讨论和建议
- **Email:** 联系项目维护者

## 📜 许可证

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

**🎮 开始你的农场冒险吧！** 🌾✨

如有任何问题，欢迎在 Issues 或 Discussions 中提出！
