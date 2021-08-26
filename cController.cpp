#include "cController.h"
#include "mainwindow.h"
#include <QFontDialog>

////////////////////////////////////////////////////

cController::cController(/*MainWindow* aView,*/ cModel* aModel)
{
    //mView = aView;
    mModel = aModel;
}

cController::~cController() {
    delete mModel;
}

/*
Ui::MainWindow* cController::getUI(){
   return(mView->getUI());
}*/

////////////////////////////////////////////////////
///        model -> view
///

QColor cController::getTextColor() {
    QColor bufor;

    bufor.setRed(mModel->getTextColor().getRed());
    bufor.setGreen(mModel->getTextColor().getGreen());
    bufor.setBlue(mModel->getTextColor().getBlue());
    bufor.setAlpha(mModel->getTextColor().getAlpha());

    return bufor;
}

QColor cController::getTextBackgroundColor() {
    QColor bufor;

    bufor.setRed(mModel->getTextBackgroundColor().getRed());
    bufor.setGreen(mModel->getTextBackgroundColor().getGreen());
    bufor.setBlue(mModel->getTextBackgroundColor().getBlue());
    bufor.setAlpha(mModel->getTextBackgroundColor().getAlpha());

    return bufor;
}

Qt::Alignment cController::getAlignment() {
    if(mModel->getAlignment().getAlign() == 0)
        return Qt::AlignLeft;
    else if(mModel->getAlignment().getAlign() == 1)
        return Qt::AlignCenter;
    else
        return Qt::AlignRight;

    /// don't care about other value then {0,1,2}
    /// because model set 0 (left) if argument
    /// don't belong to domain {0,1,2}
}

bool cController::getBold() {
    return mModel->getFontDetails()->getBold();
}

bool cController::getUnderline() {
    return mModel->getFontDetails()->getUnderline();
}

bool cController::getItalics() {
    return mModel->getFontDetails()->getItalics();
}

//int cController::getPixelSize() {
//    return mModel->getFontDetails().getPixelSize();
//}

//int cController::getPointSize() {
//   return mModel->getFontDetails().getPointSize();
//}

QString cController::getText() {
    QString bufor;
    bufor.fromStdString(mModel->getText());
    return bufor;
}

//style

QFont cController::getStyleFont(int aStyleIndex) {
    return mStyleFont[aStyleIndex];
}

QColor cController::getStyleTextColor(int aStyleIndex) {
    QColor bufor;

    bufor.setRed(mModel->getStyleTextColor(aStyleIndex).getRed());
    bufor.setGreen(mModel->getStyleTextColor(aStyleIndex).getGreen());
    bufor.setBlue(mModel->getStyleTextColor(aStyleIndex).getBlue());
    bufor.setAlpha(mModel->getStyleTextColor(aStyleIndex).getAlpha());

    return bufor;
}

QColor cController::getStyleBackgroundColor(int aStyleIndex) {
    QColor bufor;

    bufor.setRed(mModel->getStyleBackgroundColor(aStyleIndex).getRed());
    bufor.setGreen(mModel->getStyleBackgroundColor(aStyleIndex).getGreen());
    bufor.setBlue(mModel->getStyleBackgroundColor(aStyleIndex).getBlue());
    bufor.setAlpha(mModel->getStyleBackgroundColor(aStyleIndex).getAlpha());

    return bufor;
}

Qt::Alignment cController::getStyleAlignment(int aStyleIndex) {
    Qt::Alignment bufor;

    if(mModel->getStyleAlignment(aStyleIndex).getAlign() == 0)
        bufor = Qt::AlignLeft;
    else if(mModel->getStyleAlignment(aStyleIndex).getAlign() == 1)
        bufor = Qt::AlignCenter;
    else
        bufor = Qt::AlignRight;

    return bufor;
}

int cController::getPixelSize() {
   return mModel->getPixelSize();
}

int cController::getPointSize() {
    return mModel->getPointSize();
}

////////////////////////////////////////////////////
///        view -> model
///

void cController::setTextColor(QColor aColor) {
    cMcolorRGB bufor;

    bufor.setRed(aColor.red());
    bufor.setGreen(aColor.green());
    bufor.setBlue(aColor.blue());
    bufor.setAlpha(aColor.alpha());

    mModel->setTextColor(bufor);
}

void cController::setTextBackgroundColor(QColor aColor) {
    cMcolorRGB bufor;

    bufor.setRed(aColor.red());
    bufor.setGreen(aColor.green());
    bufor.setBlue(aColor.blue());
    bufor.setAlpha(aColor.alpha());

    mModel->setTextBackgroundColor(bufor);
}

void cController::setAlignment(Qt::Alignment aAlign) {
    cMalignment align;

    if(aAlign == Qt::AlignLeft)
        align.setAlign(0);
    else if(aAlign == Qt::AlignCenter)
        align.setAlign(1);
    else if(aAlign == Qt::AlignRight)
        align.setAlign(2);

    mModel->setAlignment(align);
}

void cController::setBold(bool aBold) {
    mModel->setBold(aBold);
}

void cController::setUnderline(bool aUnderline) {
    mModel->setUnderline(aUnderline);
}

void cController::setItalics(bool aItalics) {
    mModel->setItalics(aItalics);
}

void cController::setPixelSize(int aPixelSize) {
    mModel->setPixelSize(aPixelSize);
}

void cController::setPointSize(int aPointSize) {
    mModel->setPointSize(aPointSize);
}

void cController::resetFont() {
    mModel->resetFont();
}

void cController::setText(QString aText) {
    std::string bufor;
    bufor = aText.toStdString();
    mModel->setText(bufor);
}

void cController::pixelSizeIncrease() {
    mModel->pixelSizeIncrease();
}

void cController::pixelSizeReduce() {
    mModel->pixelSizeReduce();
}

void cController::pointSizeIncrease() {
    mModel->pointSizeIncrease();
}

void cController::pointSizeReduce() {
    mModel->pointSizeReduce();
}

void cController::StyleDefine(QFont aFont, QColor aTextColor, QColor aBackgroundColor, Qt::Alignment aAlign, int aStyleIndex) {
    mStyleFont[aStyleIndex] = aFont;
    cMcolorRGB textColor(aTextColor.red(), aTextColor.green(), aTextColor.blue(), aTextColor.alpha());
    cMcolorRGB backgroundColor(aBackgroundColor.red(), aBackgroundColor.green(), aBackgroundColor.blue(), aBackgroundColor.alpha());
    cMalignment align;
    if(aAlign == Qt::AlignLeft)
        align.setAlign(0);
    else if(aAlign == Qt::AlignCenter)
        align.setAlign(1);
    else
        align.setAlign(2);

    mModel->StyleDefine(aStyleIndex, textColor, backgroundColor, align, aFont.bold(), aFont.underline(), aFont.italic(), aFont.pixelSize(), aFont.pointSize());
}



