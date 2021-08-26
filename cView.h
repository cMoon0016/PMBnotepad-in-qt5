#ifndef CVIEW_H
#define CVIEW_H

#include <QMainWindow>
#include <QObject>
#include "cController.h"

class MainWindow;

class cView
{
public:
    cView(MainWindow* aWin, cController* aController);
    ~cView();
    Ui::MainWindow* getUI();
    void setController(cController* controller);

    void update();
    void updateFontSize();
    void resetFont();
    void zoomIN();
    void zoomOUT();
    void StyleUse(int aStyleIndex);
    void clearNotepad();
    void openFile();
    void saveAS();
    void print();
    void copy();
    void paste();
    void cut();
    void undo();
    void redo();


    ///      set
    void setTextColor();
    void setTextBackgroundColor();
    void setAlignment(Qt::Alignment aAlign);
    void changeBold();
    void changeUnderline();
    void changeItalics();
    void StyleDefine(int aStyleIndex);
    void DisableStyleIcon();
    void chooseFont();
    void pixelSizeIncrease();
    void pixelSizeReduce();
    void pointSizeIncrease();
    void pointSizeReduce();

private:
    MainWindow* mMainWindow;
    cController*  mController;

};

#endif // CVIEW_H
