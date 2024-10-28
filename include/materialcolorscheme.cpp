#include "materialcolorscheme.h"

#include <functional>
#include <memory>
#include <unordered_map>

#include "material-color-utilities/cpp/cam/hct.h"
#include "material-color-utilities/cpp/scheme/scheme_content.h"
#include "material-color-utilities/cpp/scheme/scheme_expressive.h"
#include "material-color-utilities/cpp/scheme/scheme_fidelity.h"
#include "material-color-utilities/cpp/scheme/scheme_fruit_salad.h"
#include "material-color-utilities/cpp/scheme/scheme_monochrome.h"
#include "material-color-utilities/cpp/scheme/scheme_neutral.h"
#include "material-color-utilities/cpp/scheme/scheme_rainbow.h"
#include "material-color-utilities/cpp/scheme/scheme_tonal_spot.h"
#include "material-color-utilities/cpp/scheme/scheme_vibrant.h"

using namespace material_color_utilities;

template <MaterialColorsSystem::Variant V>
std::unique_ptr<material_color_utilities::DynamicScheme> MaterialColorsSystem::getScheme(
    material_color_utilities::Argb argb, bool isDark, double contrast)
{
    // 使用映射表来简化switch语句
    static const std::unordered_map<
        MaterialColorsSystem::Variant,
        std::function<std::unique_ptr<DynamicScheme>(const Hct&, bool, double)>>
        schemeMap = {
            {MaterialColorsSystem::Variant::kMonochrome,
             [](const auto& color, bool dark, double cont)
 {
 return std::make_unique<SchemeMonochrome>(color, dark, cont);
 }                                            },
            {   MaterialColorsSystem::Variant::kNeutral,
             [](const auto& color, bool dark, double cont)
 {
 return std::make_unique<SchemeNeutral>(color, dark, cont);
 }                                            },
            { MaterialColorsSystem::Variant::kTonalSpot,
             [](const auto& color, bool dark, double cont)
 {
 return std::make_unique<SchemeTonalSpot>(color, dark, cont);
 }                                            },
            {   MaterialColorsSystem::Variant::kVibrant,
             [](const auto& color, bool dark, double cont)
 {
 return std::make_unique<SchemeVibrant>(color, dark, cont);
 }                                            },
            {MaterialColorsSystem::Variant::kExpressive,
             [](const auto& color, bool dark, double cont)
 {
 return std::make_unique<SchemeExpressive>(color, dark, cont);
 }                                            },
            {  MaterialColorsSystem::Variant::kFidelity,
             [](const auto& color, bool dark, double cont)
 {
 return std::make_unique<SchemeFidelity>(color, dark, cont);
 }                                            },
            {   MaterialColorsSystem::Variant::kContent,
             [](const auto& color, bool dark, double cont)
 {
 return std::make_unique<SchemeContent>(color, dark, cont);
 }                                            },
            {   MaterialColorsSystem::Variant::kRainbow,
             [](const auto& color, bool dark, double cont)
 {
 return std::make_unique<SchemeRainbow>(color, dark, cont);
 }                                            },
            {MaterialColorsSystem::Variant::kFruitSalad, [](const auto& color, bool dark, double cont)
 {
 return std::make_unique<SchemeFruitSalad>(color, dark, cont);
 }}
    };

    // 创建一个HCT颜色对象作为源颜色
    Hct sourceColor(argb);

    // 查找对应的方案创建函数，如果没有找到则使用默认的Vibrant方案
    auto it = schemeMap.find(V);
    return (it != schemeMap.end()) ? it->second(sourceColor, isDark, contrast)
                                   : std::make_unique<SchemeVibrant>(sourceColor, isDark, contrast);
}

template <MaterialColorsSystem::Variant V>
MaterialColorsSystem::SchemeColors MaterialColorsSystem::getSchemeColor(
    material_color_utilities::Argb argb, bool isDark, double contrast)
{
    // 获取scheme对象
    auto scheme = getScheme<V>(argb, isDark, contrast);

    // 创建SchemeColors对象
    SchemeColors colors;

    // 设置源颜色
    colors.sourceColor = argb;

    // 定义内联函数来简化重复代码
    auto setColor = [&](Argb& field, auto (DynamicScheme::*getter)() const)
    {
        field = (scheme.get()->*getter)();
    };

    // 设置调色板关键色
    setColor(colors.primaryPaletteKeyColor, &DynamicScheme::GetPrimaryPaletteKeyColor);
    setColor(colors.secondaryPaletteKeyColor, &DynamicScheme::GetSecondaryPaletteKeyColor);
    setColor(colors.tertiaryPaletteKeyColor, &DynamicScheme::GetTertiaryPaletteKeyColor);
    setColor(colors.neutralPaletteKeyColor, &DynamicScheme::GetNeutralPaletteKeyColor);
    setColor(colors.neutralVariantPaletteKeyColor, &DynamicScheme::GetNeutralVariantPaletteKeyColor);

    // 设置背景和表面相关颜色
    setColor(colors.background, &DynamicScheme::GetBackground);
    setColor(colors.onBackground, &DynamicScheme::GetOnBackground);
    setColor(colors.surface, &DynamicScheme::GetSurface);
    setColor(colors.surfaceDim, &DynamicScheme::GetSurfaceDim);
    setColor(colors.surfaceBright, &DynamicScheme::GetSurfaceBright);
    setColor(colors.surfaceContainerLowest, &DynamicScheme::GetSurfaceContainerLowest);
    setColor(colors.surfaceContainerLow, &DynamicScheme::GetSurfaceContainerLow);
    setColor(colors.surfaceContainer, &DynamicScheme::GetSurfaceContainer);
    setColor(colors.surfaceContainerHigh, &DynamicScheme::GetSurfaceContainerHigh);
    setColor(colors.surfaceContainerHighest, &DynamicScheme::GetSurfaceContainerHighest);
    setColor(colors.onSurface, &DynamicScheme::GetOnSurface);
    setColor(colors.surfaceVariant, &DynamicScheme::GetSurfaceVariant);
    setColor(colors.onSurfaceVariant, &DynamicScheme::GetOnSurfaceVariant);
    setColor(colors.inverseSurface, &DynamicScheme::GetInverseSurface);
    setColor(colors.inverseOnSurface, &DynamicScheme::GetInverseOnSurface);

    // 设置轮廓、阴影和遮罩颜色
    setColor(colors.outline, &DynamicScheme::GetOutline);
    setColor(colors.outlineVariant, &DynamicScheme::GetOutlineVariant);
    setColor(colors.shadow, &DynamicScheme::GetShadow);
    setColor(colors.scrim, &DynamicScheme::GetScrim);
    setColor(colors.surfaceTint, &DynamicScheme::GetSurfaceTint);

    // 设置主要、次要和第三色相关颜色
    setColor(colors.primary, &DynamicScheme::GetPrimary);
    setColor(colors.onPrimary, &DynamicScheme::GetOnPrimary);
    setColor(colors.primaryContainer, &DynamicScheme::GetPrimaryContainer);
    setColor(colors.onPrimaryContainer, &DynamicScheme::GetOnPrimaryContainer);
    setColor(colors.inversePrimary, &DynamicScheme::GetInversePrimary);
    setColor(colors.secondary, &DynamicScheme::GetSecondary);
    setColor(colors.onSecondary, &DynamicScheme::GetOnSecondary);
    setColor(colors.secondaryContainer, &DynamicScheme::GetSecondaryContainer);
    setColor(colors.onSecondaryContainer, &DynamicScheme::GetOnSecondaryContainer);
    setColor(colors.tertiary, &DynamicScheme::GetTertiary);
    setColor(colors.onTertiary, &DynamicScheme::GetOnTertiary);
    setColor(colors.tertiaryContainer, &DynamicScheme::GetTertiaryContainer);
    setColor(colors.onTertiaryContainer, &DynamicScheme::GetOnTertiaryContainer);

    // 设置错误相关颜色
    setColor(colors.error, &DynamicScheme::GetError);
    setColor(colors.onError, &DynamicScheme::GetOnError);
    setColor(colors.errorContainer, &DynamicScheme::GetErrorContainer);
    setColor(colors.onErrorContainer, &DynamicScheme::GetOnErrorContainer);

    // 设置固定颜色
    setColor(colors.primaryFixed, &DynamicScheme::GetPrimaryFixed);
    setColor(colors.primaryFixedDim, &DynamicScheme::GetPrimaryFixedDim);
    setColor(colors.onPrimaryFixed, &DynamicScheme::GetOnPrimaryFixed);
    setColor(colors.onPrimaryFixedVariant, &DynamicScheme::GetOnPrimaryFixedVariant);
    setColor(colors.secondaryFixed, &DynamicScheme::GetSecondaryFixed);
    setColor(colors.secondaryFixedDim, &DynamicScheme::GetSecondaryFixedDim);
    setColor(colors.onSecondaryFixed, &DynamicScheme::GetOnSecondaryFixed);
    setColor(colors.onSecondaryFixedVariant, &DynamicScheme::GetOnSecondaryFixedVariant);
    setColor(colors.tertiaryFixed, &DynamicScheme::GetTertiaryFixed);
    setColor(colors.tertiaryFixedDim, &DynamicScheme::GetTertiaryFixedDim);
    setColor(colors.onTertiaryFixed, &DynamicScheme::GetOnTertiaryFixed);
    setColor(colors.onTertiaryFixedVariant, &DynamicScheme::GetOnTertiaryFixedVariant);

    return colors;
}


// 显式实例化
template MaterialColorsSystem::SchemeColors MaterialColorsSystem::getSchemeColor<
    MaterialColorsSystem::Variant::kMonochrome>(material_color_utilities::Argb, bool, double);
template MaterialColorsSystem::SchemeColors MaterialColorsSystem::getSchemeColor<
    MaterialColorsSystem::Variant::kNeutral>(material_color_utilities::Argb, bool, double);
template MaterialColorsSystem::SchemeColors MaterialColorsSystem::getSchemeColor<
    MaterialColorsSystem::Variant::kTonalSpot>(material_color_utilities::Argb, bool, double);
template MaterialColorsSystem::SchemeColors MaterialColorsSystem::getSchemeColor<
    MaterialColorsSystem::Variant::kVibrant>(material_color_utilities::Argb, bool, double);
template MaterialColorsSystem::SchemeColors MaterialColorsSystem::getSchemeColor<
    MaterialColorsSystem::Variant::kExpressive>(material_color_utilities::Argb, bool, double);
template MaterialColorsSystem::SchemeColors MaterialColorsSystem::getSchemeColor<
    MaterialColorsSystem::Variant::kFidelity>(material_color_utilities::Argb, bool, double);
template MaterialColorsSystem::SchemeColors MaterialColorsSystem::getSchemeColor<
    MaterialColorsSystem::Variant::kContent>(material_color_utilities::Argb, bool, double);
template MaterialColorsSystem::SchemeColors MaterialColorsSystem::getSchemeColor<
    MaterialColorsSystem::Variant::kRainbow>(material_color_utilities::Argb, bool, double);
template MaterialColorsSystem::SchemeColors MaterialColorsSystem::getSchemeColor<
    MaterialColorsSystem::Variant::kFruitSalad>(material_color_utilities::Argb, bool, double);
