# Material Color Utilities C++ 库

这个文件夹包含了 `Material Color Utilities` 的 `C++` 实现,用于处理颜色、生成配色方案等功能。

## HCT颜色空间
HCT颜色空间是`Material Design 3`中引入的一个新的颜色空间,它基于`CAM16`色貌模型和`L`亮度。HCT代表**色相**(`Hue`)、**色度**(`Chroma`)和**色调**(`Tone`)。根据[Material Color Utilities仓库](https://github.com/material-foundation/material-color-utilities.git)中的描述,`HCT`颜色空间具有以下特点:

1. 基于CAM16 x L*:结合了CAM16色貌模型的优点和L*亮度的简单性。
2. 考虑了观看条件:HCT可以根据不同的观看环境调整颜色的感知。
3. 更好的感知均匀性:相比RGB,HCT在人眼感知上更加均匀。

HCT的三个分量含义如下:
- Hue(色相): 0-360度,表示颜色的基本属性。
- Chroma(色度): 表示颜色的纯度或饱和度。
- Tone(色调): 0-100,类似于亮度,但更符合人眼感知。

## RGB到HCT的转换
具体算法比较复杂,但基本步骤如下:
1. `RGB`到`XYZ`:首先将`RGB`值转换为`XYZ`色彩空间。
2. `XYZ`到`CAM16`:使用`CAM16`模型将`XYZ`转换为`CAM16`参数。
3. `CAM16`到`HCT`:基于`CAM16`参数计算`HCT`值。

具体实现可以参考Material Color Utilities仓库中的代码,例如在[hct目录](https://github.com/material-foundation/material-color-utilities/tree/main/typescript/hct)下有相关的实现。

## `HCT`颜色空间的优势
1. 更好的感知均匀性,有利于创建和谐的配色方案。
2. 考虑了观看条件,可以在不同环境下保持一致的视觉效果。
3. 便于进行颜色插值、调和和渐变等操作。

在`Material Design 3`中,`HCT`被广泛用于动态颜色系统,可以根据用户的壁纸等输入自动生成美观且无障碍的配色方案。

总之,`HCT`颜色空间是`Material Design 3`中的一个重要创新,为设计师和开发者提供了更强大、更灵活的颜色处理工具。

## 文件结构及功能

### 1. `blend` 文件夹:
- `blend.cc/blend.h`: 实现颜色混合算法,包括调和混合和HCT色调混合。
- `blend_test.cc`: 对`blend.cc`中的混合函数进行单元测试,确保其正确性。

### 2. `cam` 文件夹:
- `cam.cc/cam.h`: 实现CAM16颜色外观模型,提供颜色空间转换和计算功能。
- `cam_test.cc`: 测试CAM16模型的各项功能。
- `hct.cc/hct.h`: 定义HCT(色调、色度、色调)颜色空间,提供相关转换方法。
- `hct_test.cc`: 测试HCT颜色空间的功能。
- `hct_solver.cc/hct_solver.h`: 提供HCT颜色空间的求解器,用于在不同颜色空间间转换。
- `hct_solver_test.cc`: 测试HCT求解器的准确性。
- `viewing_conditions.cc/viewing_conditions.h`: 定义和处理颜色观看条件,影响颜色感知。

### 3. `contrast` 文件夹:
- `contrast.cc/contrast.h`: 提供计算和处理颜色对比度的功能,包括对比度比率计算等。
- `contrast_test.cc`: 测试对比度相关函数的正确性。

### 4. `dislike` 文件夹:
- `dislike.cc/dislike.h`: 实现检测和修复不受欢迎颜色的算法,基于色彩心理学研究。
- `dislike_test.cc`: 测试不受欢迎颜色检测和修复功能。

### 5. `dynamiccolor` 文件夹:
- `contrast_curve.h`: 定义随对比度级别变化的曲线,用于动态调整颜色。
- `dynamic_color.cc/dynamic_color.h`: 实现动态颜色系统,根据环境动态调整颜色。
- `dynamic_scheme.cc/dynamic_scheme.h`: 定义动态配色方案,提供一套完整的动态颜色系统。

### 6. `palettes` 文件夹:
- `tones.h`: 定义色调调色板,提供一系列预定义的色调。

### 7. `quantize` 文件夹:
- `quantizer_celebi.cc/quantizer_celebi.h`: 实现Celebi颜色量化算法。
- `quantizer_map.cc/quantizer_map.h`: 实现基于映射的颜色量化。
- `quantizer_wsmeans.cc/quantizer_wsmeans.h`: 实现加权平方均值颜色量化。
- `quantizer_wu.cc/quantizer_wu.h`: 实现Wu颜色量化算法。
    
### 8. `scheme` 文件夹:
- `scheme_content.cc/scheme_content.h`: 实现了 **内容** 颜色方案,适用于内容丰富的界面。
- `scheme_expressive.cc/scheme_expressive.h`: 实现了 **表现力** 颜色方案,提供更丰富多彩的色彩选择。
- `scheme_fidelity.cc/scheme_fidelity.h`: 实现了 **保真** 颜色方案,尽可能保持原始颜色的特性。
- `scheme_fruit_salad.cc/scheme_fruit_salad.h`: 实现了 **水果沙拉** 颜色方案,提供多样化的色彩组合。
- `scheme_monochrome.cc/scheme_monochrome.h`: 实现了 **单色** 颜色方案,使用单一色调的变化。
- `scheme_neutral.cc/scheme_neutral.h`: 实现了 **中性** 颜色方案,提供中性的色彩选择。
- `scheme_rainbow.cc/scheme_rainbow.h`: 实现了 **彩虹** 颜色方案,提供彩虹般的多彩效果。
- `scheme_tonal_spot.cc/scheme_tonal_spot.h`: 实现了 **色调点缀** 颜色方案,强调主色调的变化。
- `scheme_vibrant.cc/scheme_vibrant.h`: 实现了 **鲜艳** 颜色方案,提供鲜艳生动的色彩。
- `scheme_monochrome_test.cc` 文件是对 `Monochrome` 方案的单元测试,验证了该方案在不同情况下的正确性。
* 每个方案文件都包含一个继承自 `DynamicScheme` 的结构体,实现了特定的颜色生成逻辑。这些方案通过调整色相、色度和色调来创建不同风格的配色方案。
所有这些方案类都遵循相似的模式: **它们接受一个源颜色(Hct 对象)、一个表示是否为暗色主题的布尔值,以及一个可选的对比度级别。**

### 9. `score` 文件夹:
- `score.cc/score.h`: 实现颜色评分系统,用于评估颜色的适用性和美观度。

### 10. `temperature` 文件夹:
- `temperature.cc/temperature.h`: 处理颜色温度相关功能,如冷暖色调转换。

### 11. `utils` 文件夹:
- `utils.h`: 提供各种实用函数和常量,如颜色格式转换、数学运算等。

## 依赖关系
```UML
[Utils]
  ^
  |
  v
[Cam16] <-- [HctSolver] --> [Hct]
  ^                           ^
  |                           |
  v                           v
[ViewingConditions]    [DynamicColor]
                             ^
                             |
                             v
                      [DynamicScheme] <-- [Scheme]
                             ^
                             |
                             v
                      [ContrastCurve]

[Blend] --> [Hct]

[Contrast] --> [Utils]

[Dislike] --> [Hct]

[Quantizer]
  ^
  |
  +-- [QuantizerCelebi]
  |
  +-- [QuantizerMap]
  |
  +-- [QuantizerWsmeans]
  |
  +-- [QuantizerWu]

[Score] --> [Hct]

[Temperature] --> [Hct]

[TonalPalette] --> [Hct]
```
说明：
- 箭头（-->）表示依赖关系或使用关系
- 双向箭头（<-->）表示相互依赖
- 继承关系用（^）表示
这个简化的图示展示了主要类之间的关系：
1. `Utils` 类被多个其他类使用。
2. `Cam16`、`HctSolver` 和 `Hct` 类之间有密切的关系，它们共同实现了颜色空间转换。
3. `ViewingConditions` 类被 `Cam16` 使用。
4. `DynamicColor` 和 `DynamicScheme` 类实现了动态颜色系统，它们依赖于 `Hct` 和 `ContrastCurve`。
5. `Scheme` 类是各种颜色方案的基类。
6. `Blend`、`Contrast`、`Dislike` 等类都依赖于基本的颜色类如 `Hct` 或 `Utils`。
7. `Quantizer` 是一个抽象类，有多个具体实现。
8. `Score` 和 `Temperature` 类使用 `Hct` 进行颜色评分和温度相关操作。
9. `TonalPalette` 类使用 `Hct` 来创建色调调色板。
这个结构展示了库的模块化设计，每个类都有明确的职责，同时通过合理的依赖关系实现了复杂的颜色处理功能。

## 使用说明

这个库提供了丰富的颜色处理功能,包括:
1. 颜色空间转换 (如 RGB、CAM16、HCT 等)
2. 颜色混合和调和
3. 对比度计算和调整
4. 动态颜色系统生成
5. 配色方案创建

要使用这个库,请包含相应的头文件,并链接编译后的库文件。

## 注意事项

- 确保使用 `C++17` 或更高版本编译
- 这个库并不是自包含的,它依赖于 `Abseil` 库，这是一个由 Google 开发的 `C++` 库集合，提供了许多有用的工具和扩展。
- 部分功能可能依赖于其他文件,使用时请检查依赖关系

## 许可证
`Abseil (abseil-cpp)` 和`Material Color Utilities`都使用 `Apache License 2.0` 许可证。这是一个非常宽松的开源许可证，允许用户自由地使用、修改和分发代码，同时也可以将其用于商业目的。