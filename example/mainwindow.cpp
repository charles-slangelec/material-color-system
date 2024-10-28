#include "mainwindow.h"

#include <QApplication>
#include <QClipboard>
#include <QPushButton>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initUi();
    initSignalSlot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject* watched, QEvent* event)
{
    if (watched == ui->schemeListWidget)
    {
        if (event->type() == QEvent::Resize)
        {
            QSize itemSize(ui->schemeListWidget->width(),
                           (ui->schemeListWidget->height() - 20) / ui->schemeListWidget->count());
            for (int i = 0, ie = ui->schemeListWidget->count(); i < ie; ++i)
            {
                ui->schemeListWidget->item(i)->setSizeHint(itemSize);
            }
        }
    }
    else if (watched->inherits("QLabel"))
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            if (!qobject_cast<QLabel*>(watched)->toolTip().isEmpty())
            {
                QApplication::clipboard()->setText(qobject_cast<QLabel*>(watched)->toolTip());
            }
        }
    }

    return QMainWindow::eventFilter(watched, event);
}

void MainWindow::initUi()
{
    ui->schemeListWidget->installEventFilter(this);

    // 添加全局样式表,设置QLabel的字体
    this->setStyleSheet("QLabel { font-family: \"Consolas\";}");
    ui->backgroundWidget->setStyleSheet(
        "QLabel { font-size: 16px; padding-left: 10px; ; padding-top: 3px;}");


    ui->backgroundWidget->setAutoFillBackground(true);

    // 设置所有颜色相关的QLabel为自动填充背景
    QList<QLabel*> colorLabels = {ui->neutralPalette,
                                  ui->neutralVariantPalette,
                                  ui->primaryPalette,
                                  ui->primary,
                                  ui->onPrimary,
                                  ui->primaryContainer,
                                  ui->onPrimaryContainer,
                                  ui->secondaryPalette,
                                  ui->secondary,
                                  ui->onSecondary,
                                  ui->secondaryContainer,
                                  ui->onSecondaryContainer,
                                  ui->tertiaryPalette,
                                  ui->tertiary,
                                  ui->onTertiary,
                                  ui->tertiaryContainer,
                                  ui->onTertiaryContainer,
                                  ui->error,
                                  ui->onError,
                                  ui->errorContainer,
                                  ui->onErrorContainer,
                                  ui->surface,
                                  ui->onSurface,
                                  ui->surfaceVariant,
                                  ui->onSurfaceVariant,
                                  ui->background,
                                  ui->onBackground,
                                  ui->outline,
                                  ui->outlineVariant,
                                  ui->shadow,
                                  ui->scrim,
                                  ui->inverseSurface,
                                  ui->inverseOnSurface,
                                  ui->inversePrimary,
                                  ui->surfaceContainerLowest,
                                  ui->surfaceContainerLow,
                                  ui->surfaceContainer,
                                  ui->surfaceContainerHigh,
                                  ui->surfaceContainerHighest,
                                  ui->surfaceDim,
                                  ui->surfaceBright,
                                  ui->primaryFixed,
                                  ui->primaryFixedDim,
                                  ui->onPrimaryFixed,
                                  ui->onPrimaryFixedVariant,
                                  ui->secondaryFixed,
                                  ui->secondaryFixedDim,
                                  ui->onSecondaryFixed,
                                  ui->onSecondaryFixedVariant,
                                  ui->tertiaryFixed,
                                  ui->tertiaryFixedDim,
                                  ui->onTertiaryFixed,
                                  ui->onTertiaryFixedVariant};

    // 为所有颜色标签设置自动填充背景和点击事件
    for (auto label : colorLabels)
    {
        label->setWordWrap(true);
        label->setAutoFillBackground(true);
        label->setAlignment(Qt::AlignLeft | Qt::AlignTop);

        // 设置鼠标追踪和光标样式
        label->setMouseTracking(true);
        label->setCursor(Qt::PointingHandCursor);
        label->installEventFilter(this);
    }
}

void MainWindow::initSignalSlot()
{
    connect(ui->sourceColorLineEdit, &QLineEdit::editingFinished, this,
            [this]()
            {
                auto palette = ui->sourceColorLineEdit->palette();
                palette.setColor(QPalette::Active, QPalette::Base,
                                 QColor(ui->sourceColorLineEdit->text()));
                ui->sourceColorLineEdit->setPalette(palette);
            });


    // 连接源颜色输入框的回车键事件
    connect(ui->sourceColorLineEdit, &QLineEdit::returnPressed, this, &MainWindow::makeColorScheme);

    // 连接对比度单选按钮组的点击事件
    connect(ui->lowCheckBox, &QRadioButton::toggled, this, &MainWindow::makeColorScheme);
    connect(ui->normalCheckBox, &QRadioButton::toggled, this, &MainWindow::makeColorScheme);
    connect(ui->mediumCheckBox, &QRadioButton::toggled, this, &MainWindow::makeColorScheme);
    connect(ui->highCheckBox, &QRadioButton::toggled, this, &MainWindow::makeColorScheme);

    // 连接深浅模式单选按钮组的点击事件
    connect(ui->darkCheckBox, &QRadioButton::toggled, this, &MainWindow::makeColorScheme);
    connect(ui->lightCheckBox, &QRadioButton::toggled, this, &MainWindow::makeColorScheme);

    // 连接色彩方案列表的点击事件
    connect(ui->schemeListWidget, &QListWidget::currentRowChanged, this, &MainWindow::makeColorScheme);
}

void MainWindow::makeColorScheme()
{
    MaterialColorsSystem::SchemeColors schemeColors;

    // 获取源颜色ARGB值
    auto argb = QColor(ui->sourceColorLineEdit->text()).rgba();

    // 获取是否为暗色主题
    auto isDark = ui->darkCheckBox->isChecked();

    // 获取对比度设置
    /** @note 这里的()是立即调用lambda表达式的意思
     * 如果去掉()的话,contrast就变成了一个lambda函数对象,而不是函数返回的double值
     * 所以这里需要保留(),以获取实际的对比度数值
    **/
    auto contrast = [this]() -> double
    {
        if (ui->lowCheckBox->isChecked()) return -1.0;
        if (ui->normalCheckBox->isChecked()) return 0.0;
        if (ui->mediumCheckBox->isChecked()) return 0.5;
        if (ui->highCheckBox->isChecked()) return 1.0;
        return 0.0;  // 默认值
    }();

    // 获取当前选中的变体类型
    // 创建一个函数指针数组,避免使用大量的switch-case语句
    using SchemeColorFunc = MaterialColorsSystem::SchemeColors (*)(uint32_t, bool, double);
    static const SchemeColorFunc schemeColorFuncs[] = {
        MaterialColorsSystem::getSchemeColor<MaterialColorsSystem::Variant::kMonochrome>,
        MaterialColorsSystem::getSchemeColor<MaterialColorsSystem::Variant::kNeutral>,
        MaterialColorsSystem::getSchemeColor<MaterialColorsSystem::Variant::kTonalSpot>,
        MaterialColorsSystem::getSchemeColor<MaterialColorsSystem::Variant::kVibrant>,
        MaterialColorsSystem::getSchemeColor<MaterialColorsSystem::Variant::kExpressive>,
        MaterialColorsSystem::getSchemeColor<MaterialColorsSystem::Variant::kFidelity>,
        MaterialColorsSystem::getSchemeColor<MaterialColorsSystem::Variant::kContent>,
        MaterialColorsSystem::getSchemeColor<MaterialColorsSystem::Variant::kRainbow>,
        MaterialColorsSystem::getSchemeColor<MaterialColorsSystem::Variant::kFruitSalad>};

    QElapsedTimer timer;
    timer.start();
    // 检查variant是否在有效范围内并获取颜色方案
    const size_t index = ui->schemeListWidget->currentRow();
    if (index < sizeof(schemeColorFuncs) / sizeof(schemeColorFuncs[0]))
    {
        // 调用对应的函数并保存返回值
        schemeColors = schemeColorFuncs[index](argb, isDark, contrast);
    }
    else
    {
        // 默认使用 kNeutral
        schemeColors = MaterialColorsSystem::getSchemeColor<MaterialColorsSystem::Variant::kNeutral>(
            argb, isDark, contrast);
    }
    qDebug() << "getSchemeColor execution time:" << timer.nsecsElapsed() / 1000.0 << "ms";

    updateColorScheme(schemeColors);

    schemeColors.printColors();
}

void MainWindow::updateColorScheme(const MaterialColorsSystem::SchemeColors& schemeColors)
{
    // 创建一个辅助函数来减少重复代码
    auto updatePalette = [](QWidget* widget, uint32_t foreground, uint32_t background)
    {
        auto palette = widget->palette();
        palette.setColor(QPalette::Active, QPalette::WindowText, QColor::fromRgba(foreground));
        palette.setColor(QPalette::Active, QPalette::Window, QColor::fromRgba(background));
        palette.setColor(QPalette::Inactive, QPalette::WindowText, QColor::fromRgba(foreground));
        palette.setColor(QPalette::Inactive, QPalette::Window, QColor::fromRgba(background));
        widget->setPalette(palette);

        widget->setToolTip(QColor::fromRgba(background).name());
    };

    // 背景
    updatePalette(ui->backgroundWidget, schemeColors.onBackground, schemeColors.background);

    // 调色板关键色
    updatePalette(ui->primaryPalette, schemeColors.onPrimary, schemeColors.primaryPaletteKeyColor);
    updatePalette(ui->secondaryPalette, schemeColors.onSecondary,
                  schemeColors.secondaryPaletteKeyColor);
    updatePalette(ui->tertiaryPalette, schemeColors.onTertiary, schemeColors.tertiaryPaletteKeyColor);
    updatePalette(ui->neutralPalette, schemeColors.onTertiary, schemeColors.neutralPaletteKeyColor);
    updatePalette(ui->neutralVariantPalette, schemeColors.onTertiary,
                  schemeColors.neutralVariantPaletteKeyColor);

    // 背景和表面相关颜色
    updatePalette(ui->background, schemeColors.onBackground, schemeColors.background);
    updatePalette(ui->onBackground, schemeColors.background, schemeColors.onBackground);

    updatePalette(ui->surface, schemeColors.onSurface, schemeColors.surface);
    updatePalette(ui->surfaceDim, schemeColors.onSurface, schemeColors.surfaceDim);
    updatePalette(ui->surfaceBright, schemeColors.onSurface, schemeColors.surfaceBright);
    updatePalette(ui->surfaceContainerLowest, schemeColors.onSurface,
                  schemeColors.surfaceContainerLowest);
    updatePalette(ui->surfaceContainerLow, schemeColors.onSurface, schemeColors.surfaceContainerLow);
    updatePalette(ui->surfaceContainer, schemeColors.onSurface, schemeColors.surfaceContainer);
    updatePalette(ui->surfaceContainerHigh, schemeColors.onSurface, schemeColors.surfaceContainerHigh);
    updatePalette(ui->surfaceContainerHighest, schemeColors.onSurface,
                  schemeColors.surfaceContainerHighest);
    updatePalette(ui->surfaceTint, schemeColors.onSurface, schemeColors.surfaceTint);
    updatePalette(ui->onSurface, schemeColors.surface, schemeColors.onSurface);
    updatePalette(ui->surfaceVariant, schemeColors.onSurfaceVariant, schemeColors.surfaceVariant);
    updatePalette(ui->onSurfaceVariant, schemeColors.surfaceVariant, schemeColors.onSurfaceVariant);
    updatePalette(ui->inverseSurface, schemeColors.inverseOnSurface, schemeColors.inverseSurface);
    updatePalette(ui->inverseOnSurface, schemeColors.inverseSurface, schemeColors.inverseOnSurface);

    // 轮廓、阴影和遮罩相关颜色
    updatePalette(ui->outline, schemeColors.onPrimary, schemeColors.outline);
    updatePalette(ui->outlineVariant, schemeColors.onPrimary, schemeColors.outlineVariant);
    updatePalette(ui->shadow, schemeColors.onPrimary, schemeColors.shadow);
    updatePalette(ui->scrim, schemeColors.onPrimary, schemeColors.scrim);

    // 主要色相关颜色
    updatePalette(ui->primary, schemeColors.onPrimary, schemeColors.primary);
    updatePalette(ui->onPrimary, schemeColors.primary, schemeColors.onPrimary);
    updatePalette(ui->primaryContainer, schemeColors.onPrimaryContainer, schemeColors.primaryContainer);
    updatePalette(ui->onPrimaryContainer, schemeColors.primaryContainer,
                  schemeColors.onPrimaryContainer);
    updatePalette(ui->inversePrimary, schemeColors.inversePrimary, schemeColors.inverseSurface);

    // 次要色相关颜色
    updatePalette(ui->secondary, schemeColors.onSecondary, schemeColors.secondary);
    updatePalette(ui->onSecondary, schemeColors.secondary, schemeColors.onSecondary);
    updatePalette(ui->secondaryContainer, schemeColors.onSecondaryContainer,
                  schemeColors.secondaryContainer);
    updatePalette(ui->onSecondaryContainer, schemeColors.secondaryContainer,
                  schemeColors.onSecondaryContainer);

    // 第三色相关颜色
    updatePalette(ui->tertiary, schemeColors.onTertiary, schemeColors.tertiary);
    updatePalette(ui->onTertiary, schemeColors.tertiary, schemeColors.onTertiary);
    updatePalette(ui->tertiaryContainer, schemeColors.onTertiaryContainer,
                  schemeColors.tertiaryContainer);
    updatePalette(ui->onTertiaryContainer, schemeColors.tertiaryContainer,
                  schemeColors.onTertiaryContainer);

    // 错误色相关颜色
    updatePalette(ui->error, schemeColors.onError, schemeColors.error);
    updatePalette(ui->onError, schemeColors.error, schemeColors.onError);
    updatePalette(ui->errorContainer, schemeColors.onErrorContainer, schemeColors.errorContainer);
    updatePalette(ui->onErrorContainer, schemeColors.errorContainer, schemeColors.onErrorContainer);

    // 固定主要色相关颜色
    updatePalette(ui->primaryFixed, schemeColors.onPrimaryFixed, schemeColors.primaryFixed);
    updatePalette(ui->primaryFixedDim, schemeColors.onPrimaryFixed, schemeColors.primaryFixedDim);
    updatePalette(ui->onPrimaryFixed, schemeColors.primaryFixed, schemeColors.onPrimaryFixed);
    updatePalette(ui->onPrimaryFixedVariant, schemeColors.primaryFixed,
                  schemeColors.onPrimaryFixedVariant);

    // 固定次要色相关颜色
    updatePalette(ui->secondaryFixed, schemeColors.onSecondaryFixed, schemeColors.secondaryFixed);
    updatePalette(ui->secondaryFixedDim, schemeColors.onSecondaryFixed, schemeColors.secondaryFixedDim);
    updatePalette(ui->onSecondaryFixed, schemeColors.secondaryFixed, schemeColors.onSecondaryFixed);
    updatePalette(ui->onSecondaryFixedVariant, schemeColors.secondaryFixed,
                  schemeColors.onSecondaryFixedVariant);

    // 固定第三色相关颜色
    updatePalette(ui->tertiaryFixed, schemeColors.onTertiaryFixed, schemeColors.tertiaryFixed);
    updatePalette(ui->tertiaryFixedDim, schemeColors.onTertiaryFixed, schemeColors.tertiaryFixedDim);
    updatePalette(ui->onTertiaryFixed, schemeColors.tertiaryFixed, schemeColors.onTertiaryFixed);
    updatePalette(ui->onTertiaryFixedVariant, schemeColors.tertiaryFixed,
                  schemeColors.onTertiaryFixedVariant);
}
