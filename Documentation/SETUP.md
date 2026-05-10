# 🛠️ 开发环境配置指南

## 环境要求

### 系统要求
- **操作系统:** Windows 10/11、macOS 12+、Linux (Ubuntu 20.04+)
- **内存:** 最少 8GB（推荐 16GB+）
- **硬盘:** 150GB+ 可用空间
- **GPU:** NVIDIA 推荐（RTX 系列），AMD 可选

### 软件要求
- **Unreal Engine 5.0** 或更高版本
- **Visual Studio 2022**（Windows）或 **Xcode 14+**（Mac）
- **Git** 2.30+
- **Python 3.9+**（可选，用于构建脚本）

## 安装步骤

### 1. 安装 Unreal Engine 5

#### Windows
```bash
# 下载 UE5 安装程序
# 访问: https://www.unrealengine.com/download

# 运行安装程序并选择安装位置
# 确保勾选以下组件：n# - Editor
# - Engine Source
# - Development Tools
```

#### macOS
```bash
# 通过 Epic Games Launcher 安装
# 1. 下载 Epic Games Launcher
# 2. 登录 Epic Games 账户
# 3. 选择 Unreal Engine > Library > Install
```

### 2. 配置 Visual Studio（Windows）

```bash
# 安装必要的工作负载
# - Desktop development with C++
# - Game development with C++
# - Windows 10/11 SDK

# 配置 UE5 使用 Visual Studio
# 1. 打开 UE5 编辑器
# 2. Edit > Editor Preferences > Source Code
# 3. 选择 Visual Studio 的路径
```

### 3. 克隆项目

```bash
# 使用 HTTPS（推荐新手）
git clone https://github.com/15317515359-coder/HangHang-Game.git
cd HangHang-Game

# 或使用 SSH（需配置 SSH 密钥）
git clone git@github.com:15317515359-coder/HangHang-Game.git
cd HangHang-Game
```

### 4. 生成项目文件

#### Windows
```bash
# 运行批处理文件生成 Visual Studio 项目
"C:\Program Files (x86)\Epic Games\UE_5.X\Engine\Build\BatchFiles\GenerateProjectFiles.bat"

# 或在项目目录右键 -> Generate Visual Studio project files
```

#### macOS
```bash
# 使用 Xcode
open HangHangGame.uproject

# UE5 会自动生成 Xcode 项目
```

### 5. 编译项目

#### 方法 1: 使用 UE5 编辑器
```bash
# 1. 双击 HangHangGame.uproject
# 2. 选择 "Generate Visual Studio project files"
# 3. 打开 .sln 文件
# 4. 在 Visual Studio 中编译
```

#### 方法 2: 使用命令行
```bash
# Windows
"C:\Program Files (x86)\Epic Games\UE_5.X\Engine\Build\BatchFiles\Build.bat" HangHangGame Win64 Development

# macOS
/Users/Shared/Epic\ Games/UE_5.X/Engine/Build/BatchFiles/Mac/Build.sh HangHangGame Mac Development

# Linux
/home/user/EpicGames/UE_5.X/Engine/Build/BatchFiles/Linux/Build.sh HangHangGame Linux Development
```

### 6. 首次启动

```bash
# 打开编辑器
# 双击 HangHangGame.uproject

# 或使用命令行
"C:\Program Files (x86)\Epic Games\UE_5.X\Engine\Binaries\Win64\UnrealEditor.exe" "path/to/HangHangGame.uproject"
```

## 常见问题

### Q1: "Plugin 'X' could not be found"

**解决方案:**
```bash
# 删除临时文件
rm -rf Binaries Intermediate Saved .vs

# 重新生成项目文件
# 右键 .uproject -> Generate Visual Studio project files
# 右键 .sln -> Rebuild Solution
```

### Q2: 编译失败 "Module 'X' could not be found"

**解决方案:**
```bash
# 检查 .uproject 文件中的模块依赖
# 确保所有必要的插件已安装

# 编辑 HangHangGame.uproject:
{
  "Modules": [
    {
      "Name": "HangHangGame",
      "Type": "Runtime",
      "LoadingPhase": "Default",
      "PlatformAllowList": [ "Win64", "Mac", "Linux" ]
    }
  ]
}
```

### Q3: "Unable to find module 'UE4Editor-Core'"

**解决方案:**
```bash
# 检查 UE5 安装是否完整
# 重新安装 Engine Source

# 使用 Epic Games Launcher 修复安装
```

### Q4: Git LFS 错误

**解决方案:**
```bash
# 安装 Git LFS
brew install git-lfs  # macOS
choco install git-lfs  # Windows
wget https://github.com/git-lfs/git-lfs/releases/download/v3.4.0/git-lfs-linux-amd64-v3.4.0.tar.gz  # Linux

# 初始化 LFS
git lfs install
git lfs pull
```

## 开发工具配置

### Visual Studio 扩展（推荐）

```bash
# 安装以下扩展以改进开发体验：
# - Unreal Automation Tool
# - UE4 Coding Standard
# - IntelliCode
```

### 代码编辑器配置

#### 使用 Visual Studio Code（可选）
```bash
# 1. 安装 C++ 扩展
# 2. 安装 Unreal Engine 扩展
# 3. 配置 IntelliSense

# .vscode/c_cpp_properties.json
{
  "configurations": [
    {
      "name": "UE5",
      "includePath": [
        "${workspaceFolder}/Source",
        "${workspaceFolder}/Intermediate/Includes"
      ]
    }
  ]
}
```

## Git 配置

```bash
# 配置 Git LFS 用于大文件
git lfs install

# 追踪大文件类型
git lfs track "*.uasset"
git lfs track "*.umap"
git lfs track "*.exe"
git lfs track "*.dll"

# 添加 .gitattributes
git add .gitattributes
```

## 运行和调试

### 编辑器中调试

```bash
# 1. 在 Visual Studio 中设置断点
# 2. Debug > Attach to Process
# 3. 选择 UE5 编辑器进程
# 4. 在编辑器中执行操作触发断点
```

### 命令行参数

```bash
# 启动特定地图
UnrealEditor.exe HangHangGame -map=/Game/Maps/Farm_01

# 启用详细日志
UnrealEditor.exe HangHangGame -LogCmds="LogTemp Warning"

# 无头模式（服务器）
UnrealEditor.exe HangHangGame -server -log
```

## 性能分析

### 使用 Profiler

```bash
# 在编辑器中启用 Profiler
# Window > Developer Tools > Profiler

# 记录性能数据
# Profiler > Record

# 分析 CPU、GPU、内存使用
```

## 下一步

- 阅读 [游戏玩法指南](./GAMEPLAY.md)
- 阅读 [架构设计文档](./ARCHITECTURE.md)
- 查看 [代码示例](../Source/)
- 参与 [贡献流程](../CONTRIBUTING.md)

---

需要更多帮助？查看 [常见问题](./FAQ.md) 或在 Issues 中提问！
