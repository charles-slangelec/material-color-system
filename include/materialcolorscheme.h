#ifndef MATERIAL_COLOR_SYSTEM_H_
#define MATERIAL_COLOR_SYSTEM_H_

#include "cpp/dynamiccolor/dynamic_scheme.h"
#include "cpp/dynamiccolor/variant.h"
#include "cpp/utils/utils.h"

class MaterialColorsSystem
{
public:
    // material_color_utilities::Variant {
    //     kMonochrome,   // 单色方案,使用单一色调的变化
    //     kNeutral,      // 中性方案,提供中性的色彩选择
    //     kTonalSpot,    // 色调点缀方案,强调主色调的变化
    //     kVibrant,      // 鲜艳方案,提供鲜艳生动的色彩
    //     kExpressive,   // 表现力方案,提供更丰富多彩的色彩选择
    //     kFidelity,     // 保真方案,尽可能保持原始颜色的特性
    //     kContent,      // 内容方案,适用于内容丰富的界面
    //     kRainbow,      // 彩虹方案,提供彩虹般的多彩效果
    //     kFruitSalad,   // 水果沙拉方案,提供多样化的色彩组合
    // };
    using Variant = material_color_utilities::Variant;

    /** @note
     *  Here are helpful-to-know words you'll see in the names of color roles:
     *  Surface – A role used for backgrounds and large, low-emphasis areas of the screen.
     *  Primary, Secondary, Tertiary – Accent color roles used to emphasize or de-emphasize foreground elements.
     *  Container – Roles used as a fill color for foreground elements like buttons. They should not be used for text or icons.
     *  On – Roles starting with this term indicate a color for text or icons on top of its paired parent color. For example, on primary is used for text and icons against the primary fill color.
     *  Variant – Roles ending with this term offer a lower emphasis alternative to its non-variant pair. For example, outline variant is a less emphasized version of the outline color.
     *  
     * 表面 – 用于背景和屏幕上较大、低强调区域的角色。
     * 主色、次色、第三色 – 用于强调或弱化前景元素的强调色角色。
     * 容器 – 用作按钮等前景元素的填充颜色的角色。它们不应用于文本或图标。
     * 上层 – 以此术语开头的角色表示文本或图标的颜色使用的是其反色。例如，反色表示文本和图标的颜色与主色相反。
     * 变体 – 以此术语结尾的角色提供与其非变体对相比强调程度较低的替代方案。例如，轮廓变体是轮廓颜色强调程度较低的版本。
    **/
    // 定义SchemeColors结构体，用于存储 Material Design 3的颜色方案
    struct SchemeColors
    {
        material_color_utilities::Argb sourceColor;                    // 源颜色
        material_color_utilities::Argb primaryPaletteKeyColor;         // 主要调色板关键色
        material_color_utilities::Argb secondaryPaletteKeyColor;       // 次要调色板关键色
        material_color_utilities::Argb tertiaryPaletteKeyColor;        // 第三调色板关键色
        material_color_utilities::Argb neutralPaletteKeyColor;         // 中性调色板关键色
        material_color_utilities::Argb neutralVariantPaletteKeyColor;  // 中性变体调色板关键色
        material_color_utilities::Argb background;                     // 背景色
        material_color_utilities::Argb onBackground;                   // 背景上的前景色
        material_color_utilities::Argb surface;                        // 表面色
        material_color_utilities::Argb surfaceDim;                     // 暗表面色
        material_color_utilities::Argb surfaceBright;                  // 亮表面色
        material_color_utilities::Argb surfaceContainerLowest;         // 最低容器表面色
        material_color_utilities::Argb surfaceContainerLow;            // 低容器表面色
        material_color_utilities::Argb surfaceContainer;               // 容器表面色
        material_color_utilities::Argb surfaceContainerHigh;           // 高容器表面色
        material_color_utilities::Argb surfaceContainerHighest;        // 最高容器表面色
        material_color_utilities::Argb onSurface;                      // 表面上的前景色
        material_color_utilities::Argb surfaceVariant;                 // 表面变体色
        material_color_utilities::Argb onSurfaceVariant;               // 表面变体上的前景色
        material_color_utilities::Argb inverseSurface;                 // 反向表面色
        material_color_utilities::Argb inverseOnSurface;               // 反向表面上的前景色
        material_color_utilities::Argb outline;                        // 轮廓色
        material_color_utilities::Argb outlineVariant;                 // 轮廓变体色
        material_color_utilities::Argb shadow;                         // 阴影色
        material_color_utilities::Argb scrim;                          // 遮罩色
        material_color_utilities::Argb surfaceTint;                    // 表面色调
        material_color_utilities::Argb primary;                        // 主要色
        material_color_utilities::Argb onPrimary;                      // 主要色上的前景色
        material_color_utilities::Argb primaryContainer;               // 主要容器色
        material_color_utilities::Argb onPrimaryContainer;             // 主要容器上的前景色
        material_color_utilities::Argb inversePrimary;                 // 反向主要色
        material_color_utilities::Argb secondary;                      // 次要色
        material_color_utilities::Argb onSecondary;                    // 次要色上的前景色
        material_color_utilities::Argb secondaryContainer;             // 次要容器色
        material_color_utilities::Argb onSecondaryContainer;           // 次要容器上的前景色
        material_color_utilities::Argb tertiary;                       // 第三色
        material_color_utilities::Argb onTertiary;                     // 第三色上的前景色
        material_color_utilities::Argb tertiaryContainer;              // 第三容器色
        material_color_utilities::Argb onTertiaryContainer;            // 第三容器上的前景色
        material_color_utilities::Argb error;                          // 错误色
        material_color_utilities::Argb onError;                        // 错误色上的前景色
        material_color_utilities::Argb errorContainer;                 // 错误容器色
        material_color_utilities::Argb onErrorContainer;               // 错误容器上的前景色
        material_color_utilities::Argb primaryFixed;                   // 固定主要色
        material_color_utilities::Argb primaryFixedDim;                // 暗固定主要色
        material_color_utilities::Argb onPrimaryFixed;                 // 固定主要色上的前景色
        material_color_utilities::Argb onPrimaryFixedVariant;    // 固定主要色变体上的前景色
        material_color_utilities::Argb secondaryFixed;           // 固定次要色
        material_color_utilities::Argb secondaryFixedDim;        // 暗固定次要色
        material_color_utilities::Argb onSecondaryFixed;         // 固定次要色上的前景色
        material_color_utilities::Argb onSecondaryFixedVariant;  // 固定次要色变体上的前景色
        material_color_utilities::Argb tertiaryFixed;            // 固定第三色
        material_color_utilities::Argb tertiaryFixedDim;         // 暗固定第三色
        material_color_utilities::Argb onTertiaryFixed;          // 固定第三色上的前景色
        material_color_utilities::Argb onTertiaryFixedVariant;   // 固定第三色变体上的前景色

        // 打印所有颜色值的函数
        void printColors() const
        {
            printf("\n=== Material Design 3 颜色方案 ===\n\n");

            // 源颜色和调色板关键色
            printf("源颜色和调色板关键色:\n");
            printf("  源颜色: 0x%08X\n", sourceColor);
            printf("  主要调色板关键色: 0x%08X\n", primaryPaletteKeyColor);
            printf("  次要调色板关键色: 0x%08X\n", secondaryPaletteKeyColor);
            printf("  第三调色板关键色: 0x%08X\n", tertiaryPaletteKeyColor);
            printf("  中性调色板关键色: 0x%08X\n", neutralPaletteKeyColor);
            printf("  中性变体调色板关键色: 0x%08X\n\n", neutralVariantPaletteKeyColor);

            // 背景和表面相关颜色
            printf("背景和表面相关颜色:\n");
            printf("  背景色: 0x%08X\t\t背景上的前景色: 0x%08X\n", background, onBackground);
            printf("  表面色: 0x%08X\t\t表面上的前景色: 0x%08X\n", surface, onSurface);
            printf("  暗表面色: 0x%08X\t\t亮表面色: 0x%08X\n", surfaceDim, surfaceBright);
            printf("  最低容器表面色: 0x%08X\t最高容器表面色: 0x%08X\n", surfaceContainerLowest,
                   surfaceContainerHighest);
            printf("  低容器表面色: 0x%08X\t高容器表面色: 0x%08X\n", surfaceContainerLow,
                   surfaceContainerHigh);
            printf("  容器表面色: 0x%08X\n\n", surfaceContainer);

            // 主要色相关
            printf("主要色相关:\n");
            printf("  主要色: 0x%08X\t\t主要色上的前景色: 0x%08X\n", primary, onPrimary);
            printf("  主要容器色: 0x%08X\t主要容器上的前景色: 0x%08X\n", primaryContainer,
                   onPrimaryContainer);
            printf("  反向主要色: 0x%08X\n", inversePrimary);
            printf("  固定主要色: 0x%08X\t暗固定主要色: 0x%08X\n", primaryFixed, primaryFixedDim);
            printf("  固定主要色上的前景色: 0x%08X\n", onPrimaryFixed);
            printf("  固定主要色变体上的前景色: 0x%08X\n\n", onPrimaryFixedVariant);

            // 次要色相关
            printf("次要色相关:\n");
            printf("  次要色: 0x%08X\t\t次要色上的前景色: 0x%08X\n", secondary, onSecondary);
            printf("  次要容器色: 0x%08X\t次要容器上的前景色: 0x%08X\n", secondaryContainer,
                   onSecondaryContainer);
            printf("  固定次要色: 0x%08X\t暗固定次要色: 0x%08X\n", secondaryFixed, secondaryFixedDim);
            printf("  固定次要色上的前景色: 0x%08X\n", onSecondaryFixed);
            printf("  固定次要色变体上的前景色: 0x%08X\n\n", onSecondaryFixedVariant);

            // 第三色相关
            printf("第三色相关:\n");
            printf("  第三色: 0x%08X\t\t第三色上的前景色: 0x%08X\n", tertiary, onTertiary);
            printf("  第三容器色: 0x%08X\t第三容器上的前景色: 0x%08X\n", tertiaryContainer,
                   onTertiaryContainer);
            printf("  固定第三色: 0x%08X\t暗固定第三色: 0x%08X\n", tertiaryFixed, tertiaryFixedDim);
            printf("  固定第三色上的前景色: 0x%08X\n", onTertiaryFixed);
            printf("  固定第三色变体上的前景色: 0x%08X\n\n", onTertiaryFixedVariant);

            // 错误色相关
            printf("错误色相关:\n");
            printf("  错误色: 0x%08X\t\t错误色上的前景色: 0x%08X\n", error, onError);
            printf("  错误容器色: 0x%08X\t错误容器上的前景色: 0x%08X\n\n", errorContainer,
                   onErrorContainer);

            // 其他颜色
            printf("其他颜色:\n");
            printf("  表面变体色: 0x%08X\t表面变体上的前景色: 0x%08X\n", surfaceVariant,
                   onSurfaceVariant);
            printf("  反向表面色: 0x%08X\t反向表面上的前景色: 0x%08X\n", inverseSurface,
                   inverseOnSurface);
            printf("  轮廓色: 0x%08X\t\t轮廓变体色: 0x%08X\n", outline, outlineVariant);
            printf("  阴影色: 0x%08X\t\t遮罩色: 0x%08X\n", shadow, scrim);
            printf("  表面色调: 0x%08X\n", surfaceTint);
            printf("\n=== 颜色方案打印完成 ===\n\n");
            fflush(stdout);
        }
    };

    template <Variant V>
    static SchemeColors getSchemeColor(material_color_utilities::Argb argb, bool isDark,
                                       double contrast);

private:
    MaterialColorsSystem()  = delete;
    ~MaterialColorsSystem() = delete;

    template <Variant V>
    static std::unique_ptr<material_color_utilities::DynamicScheme> getScheme(
        material_color_utilities::Argb argb, bool isDark, double contrast);
};

#endif  // MATERIAL_COLOR_SYSTEM_H_
