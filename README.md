# Material Color System

这是一个基于 Material Design 3 的颜色系统实现，可以根据一个主题色生成完整的 Material Design 3 配色方案。

## 项目结构

material-color/
├── include/                          # 头文件目录
│   ├── materialcolorscheme.h         # 颜色系统主要接口
│   ├── materialcolorscheme.cpp       # 颜色系统实现
│   ├── materialcolorscheme.pri       # Qt 项目配置文件
│   └── third_party/                  # 第三方库
│       └── material-color-utilities/  # Material Color Utilities 库
│           ├── blend/                # 颜色混合相关
│           ├── cam/                  # CAM16 颜色模型相关
│           ├── contrast/             # 对比度计算相关
│           ├── dislike/              # 不受欢迎颜色处理
│           ├── dynamiccolor/         # 动态颜色系统
│           ├── palettes/             # 调色板
│           ├── scheme/               # 颜色方案
│           ├── temperature/          # 颜色温度
│           └── utils/                # 工具函数
└── example/                          # 示例程序
    ├── main.cpp                      # 程序入口
    ├── mainwindow.cpp                # 主窗口实现
    ├── mainwindow.h                  # 主窗口头文件
    └── mainwindow.ui                 # Qt UI 文件

## 功能特性

1. 支持多种颜色方案：
   - Monochrome (单色方案)
   - Neutral (中性方案)
   - TonalSpot (色彩点缀方案)
   - Vibrant (鲜艳方案)
   - Expressive (表现力方案)
   - Fidelity (保真方案)
   - Content (内容方案)
   - Rainbow (彩虹方案)
   - FruitSalad (水果沙拉方案)

2. 支持深色/浅色模式切换

3. 支持四种对比度级别：
   - low (-1.0)
   - normal (0.0)
   - medium (0.5)
   - high (1.0)

4. 提供完整的 Material Design 3 颜色系统：
   - Primary Colors
   - Secondary Colors
   - Tertiary Colors
   - Error Colors
   - Surface Colors
   - Background Colors
   - Outline Colors
   - Fixed Colors

## 技术要求

- C++17 或更高版本
- Qt 6.0 或更高版本
- CMake 3.16 或更高版本

## 使用方法

1. 在你的项目中包含必要的文件：
```qmake
include(path/to/materialcolorscheme.pri)
```
2. 使用颜色系统：
```cpp
// 创建一个颜色方案
MaterialColorsSystem::SchemeColors colors = MaterialColorsSystem::getSchemeColor<MaterialColorsSystem::Variant::kVibrant>(
sourceColor, // 源颜色 (ARGB 格式)
isDark, // 是否深色模式
contrast // 对比度级别
);
// 使用生成的颜色
Argb primary = colors.primary;
Argb onPrimary = colors.onPrimary;
// ... 其他颜色
```

## 示例程序

项目包含一个完整的示例程序，展示了如何使用颜色系统生成和预览不同的颜色方案。示例程序提供了直观的界面，可以：

1. 输入源颜色（十六进制格式）
2. 选择深色/浅色模式
3. 调整对比度级别
4. 选择不同的颜色方案
5. 实时预览生成的颜色方案

## 许可证

本项目基于 Apache License 2.0 开源协议。

## 贡献

欢迎提交 Issues 和 Pull Requests 来改进这个项目。

## 致谢

本项目基于 Google 的 Material Color Utilities 库实现，感谢 Material Design 团队的工作。