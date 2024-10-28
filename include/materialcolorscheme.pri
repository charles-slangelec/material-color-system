CONFIG += c++17

INCLUDEPATH += $$PWD \
               $$PWD/third_party \
               $$PWD/third_party/material-color-utilities

SOURCES += \
    $$PWD/materialcolorscheme.cpp \
    $$PWD/third_party/material-color-utilities/cpp/blend/blend.cc \
    $$PWD/third_party/material-color-utilities/cpp/cam/cam.cc \
    $$PWD/third_party/material-color-utilities/cpp/cam/hct.cc \
    $$PWD/third_party/material-color-utilities/cpp/cam/hct_solver.cc \
    $$PWD/third_party/material-color-utilities/cpp/cam/viewing_conditions.cc \
    $$PWD/third_party/material-color-utilities/cpp/contrast/contrast.cc \
    $$PWD/third_party/material-color-utilities/cpp/dislike/dislike.cc \
    $$PWD/third_party/material-color-utilities/cpp/dynamiccolor/dynamic_color.cc \
    $$PWD/third_party/material-color-utilities/cpp/dynamiccolor/dynamic_scheme.cc \
    $$PWD/third_party/material-color-utilities/cpp/dynamiccolor/material_dynamic_colors.cc \
    $$PWD/third_party/material-color-utilities/cpp/palettes/tones.cc \
    $$PWD/third_party/material-color-utilities/cpp/scheme/scheme_content.cc \
    $$PWD/third_party/material-color-utilities/cpp/scheme/scheme_expressive.cc \
    $$PWD/third_party/material-color-utilities/cpp/scheme/scheme_fidelity.cc \
    $$PWD/third_party/material-color-utilities/cpp/scheme/scheme_fruit_salad.cc \
    $$PWD/third_party/material-color-utilities/cpp/scheme/scheme_monochrome.cc \
    $$PWD/third_party/material-color-utilities/cpp/scheme/scheme_neutral.cc \
    $$PWD/third_party/material-color-utilities/cpp/scheme/scheme_rainbow.cc \
    $$PWD/third_party/material-color-utilities/cpp/scheme/scheme_tonal_spot.cc \
    $$PWD/third_party/material-color-utilities/cpp/scheme/scheme_vibrant.cc \
    $$PWD/third_party/material-color-utilities/cpp/temperature/temperature_cache.cc \
    $$PWD/third_party/material-color-utilities/cpp/quantize/lab.cc \
    $$PWD/third_party/material-color-utilities/cpp/utils/utils.cc

HEADERS += \
    $$PWD/materialcolorscheme.h \
    $$PWD/third_party/material-color-utilities/cpp/blend/blend.h \
    $$PWD/third_party/material-color-utilities/cpp/cam/cam.h \
    $$PWD/third_party/material-color-utilities/cpp/cam/hct.h \
    $$PWD/third_party/material-color-utilities/cpp/cam/hct_solver.h \
    $$PWD/third_party/material-color-utilities/cpp/cam/viewing_conditions.h \
    $$PWD/third_party/material-color-utilities/cpp/contrast/contrast.h \
    $$PWD/third_party/material-color-utilities/cpp/dislike/dislike.h \
    $$PWD/third_party/material-color-utilities/cpp/dynamiccolor/contrast_curve.h \
    $$PWD/third_party/material-color-utilities/cpp/dynamiccolor/dynamic_color.h \
    $$PWD/third_party/material-color-utilities/cpp/dynamiccolor/dynamic_scheme.h \
    $$PWD/third_party/material-color-utilities/cpp/dynamiccolor/material_dynamic_colors.h \
    $$PWD/third_party/material-color-utilities/cpp/dynamiccolor/variant.h \
    $$PWD/third_party/material-color-utilities/cpp/palettes/core.h \
    $$PWD/third_party/material-color-utilities/cpp/palettes/tones.h \
    $$PWD/third_party/material-color-utilities/cpp/scheme/scheme_content.h \
    $$PWD/third_party/material-color-utilities/cpp/scheme/scheme_expressive.h \
    $$PWD/third_party/material-color-utilities/cpp/scheme/scheme_fidelity.h \
    $$PWD/third_party/material-color-utilities/cpp/scheme/scheme_fruit_salad.h \
    $$PWD/third_party/material-color-utilities/cpp/scheme/scheme_monochrome.h \
    $$PWD/third_party/material-color-utilities/cpp/scheme/scheme_neutral.h \
    $$PWD/third_party/material-color-utilities/cpp/scheme/scheme_rainbow.h \
    $$PWD/third_party/material-color-utilities/cpp/scheme/scheme_tonal_spot.h \
    $$PWD/third_party/material-color-utilities/cpp/scheme/scheme_vibrant.h \
    $$PWD/third_party/material-color-utilities/cpp/temperature/temperature_cache.h \
    $$PWD/third_party/material-color-utilities/cpp/quantize/lab.h \
    $$PWD/third_party/material-color-utilities/cpp/utils/utils.h
