#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("PMB NotePad");
    setWindowIcon(QIcon(":/new/imgs/icon::notepad.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mView;
}

Ui::MainWindow* MainWindow::getUI(){
    std::cout << ui <<std::endl;
    return(ui);
}

//void MainWindow::setController(cController* aController){
//    mController = aController;
//}

void MainWindow::setView(cView* aView){
    mView = aView;
}

////////////////////////////////////////////////////////
///           ACTIONS


///colors
void MainWindow::on_actionColor_triggered()
{
    mView->setTextColor();
}

void MainWindow::on_actionBackground_Color_triggered()
{
    mView->setTextBackgroundColor();
}


///alignment
void MainWindow::on_actionAlign_Right_triggered()
{
    mView->setAlignment(Qt::AlignRight);
}


void MainWindow::on_actionAlign_Center_triggered()
{
    mView->setAlignment(Qt::AlignCenter);
}

void MainWindow::on_actionAlign_Left_triggered()
{
    mView->setAlignment(Qt::AlignLeft);
}

void MainWindow::on_actionBold_triggered()
{
    mView->changeBold();
}

void MainWindow::on_actionUnderline_triggered()
{
    mView->changeUnderline();
}

void MainWindow::on_actionItalics_triggered()
{
    mView->changeItalics();
}

void MainWindow::on_actionReset_Font_triggered()
{
    mView->resetFont();
}

void MainWindow::on_actionZoom_2_triggered()
{

}

void MainWindow::on_actionZoom_3_triggered()
{

}

void MainWindow::on_actionDefine_triggered()
{
    mView->StyleDefine(0); //STYLE1
    ui->actionDefine->setIcon(QIcon(":new/imgs/[c]icon::defineStyle.png"));
}

void MainWindow::on_actionDefine_2_triggered()
{
    mView->StyleDefine(1); //STYLE2
    ui->actionDefine_2->setIcon(QIcon(":new/imgs/[c]icon::defineStyle.png"));
}

void MainWindow::on_actionDefine_3_triggered()
{
    mView->StyleDefine(2); //STYLE3
    ui->actionDefine_3->setIcon(QIcon(":new/imgs/[c]icon::defineStyle.png"));
}

void MainWindow::on_actionDefine_4_triggered()
{
    mView->StyleDefine(3); //STYLE4
    ui->actionDefine_4->setIcon(QIcon(":new/imgs/[c]icon::defineStyle.png"));
}

void MainWindow::on_actionDefine_5_triggered()
{
    mView->StyleDefine(4); //STYLE5
    ui->actionDefine_5->setIcon(QIcon(":new/imgs/[c]icon::defineStyle.png"));
}

void MainWindow::on_actionUse_triggered()
{
    mView->DisableStyleIcon();
    mView->StyleUse(0); //USE STYLE1
    ui->actionUse->setIcon(QIcon(":new/imgs/[c]icon::style1.png"));
}

void MainWindow::on_actionUse_2_triggered()
{
    mView->DisableStyleIcon();
    mView->StyleUse(1); //USE STYLE2
    ui->actionUse_2->setIcon(QIcon(":new/imgs/[c]icon::style2.png"));
}

void MainWindow::on_actionUse_3_triggered()
{
    mView->DisableStyleIcon();
    mView->StyleUse(2); //USE STYLE3
    ui->actionUse_3->setIcon(QIcon(":new/imgs/[c]icon::style3.png"));
}

void MainWindow::on_actionUse_4_triggered()
{
    mView->DisableStyleIcon();
    mView->StyleUse(3); //USE STYLE4
    ui->actionUse_4->setIcon(QIcon(":new/imgs/[c]icon::style4.png"));
}

void MainWindow::on_actionUse_5_triggered()
{
    mView->DisableStyleIcon();
    mView->StyleUse(4); //USE STYLE5
    ui->actionUse_5->setIcon(QIcon(":new/imgs/[c]icon::style5.png"));
}

void MainWindow::on_actionFont_triggered()
{
    mView->chooseFont();
}

void MainWindow::on_actionPixelSize_triggered()
{
    mView->pixelSizeIncrease();
}

void MainWindow::on_actionPixelSize_2_triggered()
{
    mView->pixelSizeReduce();
}

void MainWindow::on_actionPointSize_triggered()
{
    mView->pointSizeIncrease();
}

void MainWindow::on_actionPointSize_2_triggered()
{
    mView->pointSizeReduce();
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionClear_triggered()
{
    mView->clearNotepad();
}

void MainWindow::on_actionOpen_triggered()
{
    mView->openFile();
}

void MainWindow::on_actionSave_as_triggered()
{
    mView->saveAS();
}

void MainWindow::on_actionPrint_triggered()
{
    mView->print();
}

void MainWindow::on_actionCopy_triggered()
{
    mView->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    mView->paste();
}

void MainWindow::on_actionCut_triggered()
{
    mView->cut();
}

void MainWindow::on_actionUndo_triggered()
{
    mView->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    mView->redo();
}

void MainWindow::on_actionZoom_triggered()
{
    mView->zoomIN();
}
