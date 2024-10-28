/*
 * Copyright 2023 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef CPP_DYNAMICCOLOR_VARIANT_H_
#define CPP_DYNAMICCOLOR_VARIANT_H_

namespace material_color_utilities {

// Variant 枚举类定义了不同的配色方案变体
enum class Variant {
  kMonochrome,   // 单色方案,使用单一色调的变化
  kNeutral,      // 中性方案,提供中性的色彩选择
  kTonalSpot,    // 色调点缀方案,强调主色调的变化
  kVibrant,      // 鲜艳方案,提供鲜艳生动的色彩
  kExpressive,   // 表现力方案,提供更丰富多彩的色彩选择
  kFidelity,     // 保真方案,尽可能保持原始颜色的特性
  kContent,      // 内容方案,适用于内容丰富的界面
  kRainbow,      // 彩虹方案,提供彩虹般的多彩效果
  kFruitSalad,   // 水果沙拉方案,提供多样化的色彩组合
};

}  // namespace material_color_utilities

#endif  // CPP_DYNAMICCOLOR_VARIANT_H_
