#include "cView.h"
#include "mainwindow.h"
#include <iostream>
#include <QColorDialog>
#include <QFontDialog>
#include "qdebug.h"
#include "QFile"
#include "QFileDialog"
#include "QMessageBox"
#include "QPrintDialog"
#include "QPrinter"

//////////////////////////////////////////////////

cView::cView(MainWindow* aMainWindow, cController* aController)
{
    mMainWindow = aMainWindow;
    mController = aController;
}

cView::~cView() {
    delete mMainWindow;
    delete mController;
}

void cView::setController(cController* controller) {
    mController = controller;
}

Ui::MainWindow* cView::getUI(){

   return(mMainWindow->getUI());
}

//////////////////------UPDATE------////////////////////////////////

void cView::update() {
    ///color
    getUI()->textEdit->setTextColor(mController->getTextColor());
    getUI()->textEdit->setTextBackgroundColor(mController->getTextBackgroundColor());

    ///alignment
    getUI()->textEdit->setAlignment(mController->getAlignment());

    getUI()->actionAlign_Left->setIcon(QIcon(":new/imgs/icon::alignLeft.png"));
    getUI()->actionAlign_Center->setIcon(QIcon(":new/imgs/icon::alignCenter.png"));
    getUI()->actionAlign_Right->setIcon(QIcon(":new/imgs/icon::alignRight.png"));

    if(mController->getAlignment()==Qt::AlignLeft)
        getUI()->actionAlign_Left->setIcon(QIcon(":new/imgs/[c]icon::alignLeft.png"));
    else if(mController->getAlignment()==Qt::AlignCenter)
        getUI()->actionAlign_Center->setIcon(QIcon(":new/imgs/[c]icon::alignCenter.png"));
    else if(mController->getAlignment()==Qt::AlignRight)
        getUI()->actionAlign_Right->setIcon(QIcon(":new/imgs/[c]icon::alignRight.png"));

    //font
    QFont font = getUI()->textEdit->currentFont();

    font.setBold(mController->getBold());
    if(mController->getBold()==true)
        getUI()->actionBold->setIcon(QIcon(":new/imgs/[c]icon::bold.png"));
    else
        getUI()->actionBold->setIcon(QIcon(":new/imgs/icon::bold.png"));

    font.setUnderline(mController->getUnderline());
    if(mController->getUnderline()==true)
        getUI()->actionUnderline->setIcon(QIcon(":new/imgs/[c]icon::underline.png"));
    else
        getUI()->actionUnderline->setIcon(QIcon(":new/imgs/icon::underline.png"));

    font.setItalic(mController->getItalics());
    if(mController->getItalics()==true)
        getUI()->actionItalics->setIcon(QIcon(":new/imgs/[c]icon::italics.png"));
    else
        getUI()->actionItalics->setIcon(QIcon(":new/imgs/icon::italics.png"));

    getUI()->textEdit->setCurrentFont(font);

    //style
    DisableStyleIcon();
}

void cView::updateFontSize() { //0 -> pixel; 1 -> point
    QFont font = getUI()->textEdit->currentFont();
    //if(pixelOrPoint == 0)
      //  font.setPixelSize(mController->getPixelSize());
    //else
      //  font.setPointSize(mController->getPointSize());
    font.setPixelSize(mController->getPixelSize());
    getUI()->textEdit->setCurrentFont(font);
}

///////////-----RESET_FONT-----///////////////////

void cView::resetFont() {
    QFont font;
    getUI()->textEdit->setCurrentFont(font);
    mController->resetFont();
    this->update();
    this->updateFontSize();
}

///////////-----ZOOM-----///////////////////

void cView::zoomIN() {
    getUI()->textEdit->zoomIn();
}

void cView::zoomOUT() {
    getUI()->textEdit->zoomOut();
}

//////////////////--------SET---------//////////////////////

void cView::setTextColor() {
    QColor color = QColorDialog::getColor(Qt::white);

    mController->setTextColor(color);

    this->update();
}

void cView::setTextBackgroundColor() {
    QColor color = QColorDialog::getColor(Qt::white);

    mController->setTextBackgroundColor(color);

    this->update();
}

void cView::setAlignment(Qt::Alignment aAlign) {
    mController->setAlignment(aAlign);
    this->update();
}

void cView::changeBold() {
    mController->setBold( mController->getBold() ? false : true );
    this->update();
}

void cView::changeUnderline() {
    mController->setUnderline( mController->getUnderline() ? false : true );
    this->update();
}

void cView::changeItalics() {
    mController->setItalics( mController->getItalics() ? false : true );
    this->update();
}

void cView::StyleDefine(int aStyleIndex) {
    QFont font = getUI()->textEdit->currentFont();
    QColor textColor = getUI()->textEdit->textColor();
    QColor backgroundColor = getUI()->textEdit->textBackgroundColor();
    Qt::Alignment align = getUI()->textEdit->alignment();

    mController->StyleDefine(font, textColor, backgroundColor, align, aStyleIndex);
}

void cView::StyleUse(int aStyleIndex) {
    getUI()->textEdit->setCurrentFont(mController->getStyleFont(aStyleIndex));
    getUI()->textEdit->setTextColor(mController->getStyleTextColor(aStyleIndex));
    getUI()->textEdit->setTextBackgroundColor(mController->getStyleBackgroundColor(aStyleIndex));
    getUI()->textEdit->setAlignment(mController->getStyleAlignment(aStyleIndex));
    this->update();
}

void cView::DisableStyleIcon() {
    getUI()->actionUse->setIcon(QIcon(":new/imgs/icon::style1.png"));
    getUI()->actionUse_2->setIcon(QIcon(":new/imgs/icon::style2.png"));
    getUI()->actionUse_3->setIcon(QIcon(":new/imgs/icon::style3.png"));
    getUI()->actionUse_4->setIcon(QIcon(":new/imgs/icon::style4.png"));
    getUI()->actionUse_5->setIcon(QIcon(":new/imgs/icon::style5.png"));
}

void cView::chooseFont() {
    QFont font = QFontDialog::getFont(0);
    mController->setBold(font.bold());
    mController->setUnderline(font.underline());
    mController->setItalics(font.italic());
//    mController->setPixelSize(font.pixelSize());
//    mController->setPointSize(font.pointSize());
    mController->setPointSize(font.pointSize());
    getUI()->textEdit->setCurrentFont(font);
    this->update();
}

void cView::pixelSizeIncrease() {
    mController->pixelSizeIncrease();
    this->updateFontSize();
}

void cView::pixelSizeReduce() {
    mController->pixelSizeReduce();
    this->updateFontSize();
}

void cView::pointSizeIncrease() {
    mController->pointSizeIncrease();
    this->updateFontSize();
}

void cView::pointSizeReduce() {
    mController->pointSizeReduce();
    this->updateFontSize();
}

void cView::clearNotepad() {
    getUI()->textEdit->clear();
}

void cView::openFile() {
    QString filename = QFileDialog::getOpenFileName(nullptr, "Open the file"); //open dialog box
    QFile file(filename); //object for reading and writing dialogs


    if(!file.open(QIODevice::ReadOnly | QFile::Text)) //open file: if not -> something went wrong and file cannot be open
    {
        QMessageBox::warning(nullptr, "Warning", "Cannot open file: " + file.errorString());
        return;
    }

    QTextStream in(&file); //creating inerface for reading file
    QString text = in.readAll(); //inicjalize text with file
    getUI()->textEdit->setText(text); //inicjalize textEdit with text

    file.close(); //close file
}

void cView::saveAS() {
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Save as"); //open dialog for saving
    QFile file(fileName); //creating object for reading and writing dialogs

    if(!file.open(QIODevice::WriteOnly | QFile::Text)) //for problems with file
    {
        return;
    }

    QTextStream out(&file); //creating interface for writing file
    QString text = getUI()->textEdit->toPlainText(); //inicjalize variable text with content of textEdit
    out << text; //put text to file

    file.close(); //close file
}

void cView::print() {
    QPrinter printer; //creating variable printer
    printer.setPrinterName("Printer Name"); //setting printer name

    QPrintDialog pDialog(&printer, nullptr); //dialog for choosing printer

    if(pDialog.exec() == QDialog::Rejected) //if printer not oppend correctly
    {
        return;
    }

    getUI()->textEdit->print(&printer); //print
}

void cView::copy() {
    getUI()->textEdit->copy();
}

void cView::paste() {
    getUI()->textEdit->paste();
}

void cView::cut() {
    getUI()->textEdit->cut();
}

void cView::undo() {
    getUI()->textEdit->undo();
}

void cView::redo() {
    getUI()->textEdit->redo();
}
//////////////////////////////////////////////////
///           END

