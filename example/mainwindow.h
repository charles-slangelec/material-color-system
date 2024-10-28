#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "materialcolorscheme.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    void initUi();
    void initSignalSlot();

    void makeColorScheme();
    void updateColorScheme(const MaterialColorsSystem::SchemeColors &schemeColors);


    Ui::MainWindow *ui;
};

#endif  // MAINWINDOW_H
