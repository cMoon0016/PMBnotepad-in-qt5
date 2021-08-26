#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cController.h"
#include "cView.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow* getUI();
    //void setController(cController*);
    void setView(cView*);

private slots:
    void on_actionColor_triggered();

    void on_actionBackground_Color_triggered();

    void on_actionAlign_Right_triggered();

    void on_actionAlign_Center_triggered();

    void on_actionAlign_Left_triggered();

    void on_actionBold_triggered();

    void on_actionUnderline_triggered();

    void on_actionItalics_triggered();

    void on_actionReset_Font_triggered();

    void on_actionSize_triggered();

    void on_actionZoom_triggered();

    void on_actionZoom_2_triggered();

    void on_actionZoom_3_triggered();

    void on_actionDefine_triggered();

    void on_actionDefine_2_triggered();

    void on_actionDefine_3_triggered();

    void on_actionDefine_4_triggered();

    void on_actionDefine_5_triggered();

    void on_actionUse_triggered();

    void on_actionUse_2_triggered();

    void on_actionUse_3_triggered();

    void on_actionUse_4_triggered();

    void on_actionUse_5_triggered();

    void on_actionFont_triggered();

    void on_actionPixelSize_triggered();

    void on_actionPixelSize_2_triggered();

    void on_actionPointSize_triggered();

    void on_actionPointSize_2_triggered();

    void on_actionExit_triggered();

    void on_actionClear_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_as_triggered();

    void on_actionPrint_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

private:
    Ui::MainWindow *ui;
    //cController* mController;
    cView* mView;
};
#endif // MAINWINDOW_H
