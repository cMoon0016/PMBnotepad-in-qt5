#include "cModel.h"
#include "qdebug.h"

//////////////////////////////////////////////////////
///        constructors
///

cModel::cModel() {
    mCurrentFileName = "";
    mTextColor.set(0,0,0,255); ///set black
    mTextBackgroundColor.set(255,255,255,255); ///set white
    mAlignment = 0; //set left
    mFontDetails = new cMPixelFont(false,false,false,16);
    mFontDetailsPoint = new cMPointFont(false,false,false,12);
    mIsFontPixel = true;
}

cModel::~cModel() {
    delete mFontDetails;
    delete mFontDetailsPoint;
}

/////////////////////////////////////////////////////
///        set
///

void cModel::setCurrentFileName(std::string aName) {
    mCurrentFileName = aName;
}

void cModel::setTextColor(cMcolorRGB aColor) {
    mTextColor = aColor;
}

void cModel::setTextBackgroundColor(cMcolorRGB aColor) {
    mTextBackgroundColor = aColor;
}

void cModel::setAlignment(cMalignment aAlign) {
    mAlignment = aAlign;
}

void cModel::setBold(bool aBold) {
    mFontDetails->setBold(aBold);
}

void cModel::setUnderline(bool aUnderline) {
    mFontDetails->setUnderline(aUnderline);
}

void cModel::setItalics(bool aItalics) {
    mFontDetails->setItalics(aItalics);
}

void cModel::setPixelSize(int aPixelSize) {
    if(mIsFontPixel == true)
        mFontDetails->setSize(aPixelSize);
    else
        mFontDetailsPoint->setSize(aPixelSize);
}

void cModel::setPointSize(int aPointSize) {
    if(mIsFontPixel == false)
        mFontDetails->setSize(aPointSize);
    else
        mFontDetailsPoint->setSize(aPointSize);
}

void cModel::setText(std::string aText) {
    mText = aText;
}

void cModel::StyleDefine(int aStyleIndex, cMcolorRGB aTColor, cMcolorRGB aBTColor, cMalignment aAlign, bool aB, bool aU, bool aI, int aPixel, int aPoint) {
    mStyle[aStyleIndex].define(aTColor, aBTColor, aAlign, aB, aU, aI, aPixel, aPoint);
}

void cModel::changePixelAndPoint() {
    cMfont* bufor;
    bufor = mFontDetailsPoint;
    mFontDetailsPoint = mFontDetails;
    mFontDetails = bufor;
    mIsFontPixel = mIsFontPixel ? false : true;
}

void cModel::pixelSizeIncrease() {
    mFontDetails->setSize(mFontDetails->getSize()+1);
    if(mIsFontPixel == false)
        changePixelAndPoint();
}

void cModel::pixelSizeReduce() {
    mFontDetails->setSize(mFontDetails->getSize()-1);
    if(mIsFontPixel == false)
        changePixelAndPoint();
}

void cModel::pointSizeIncrease() {
    mFontDetailsPoint->setSize(mFontDetailsPoint->getSize()+1);
    if(mIsFontPixel == true)
        changePixelAndPoint();
}

void cModel::pointSizeReduce() {
    mFontDetailsPoint->setSize(mFontDetailsPoint->getSize()-1);
    if(mIsFontPixel == true)
        changePixelAndPoint();
}

/////////////////////////////////////////////////////
///        get
///

std::string cModel::getCurrentFileName() {
    return mCurrentFileName;
}

cMcolorRGB cModel::getTextColor() {
    return mTextColor;
}

cMcolorRGB cModel::getTextBackgroundColor() {
    return mTextBackgroundColor;
}

cMalignment cModel::getAlignment() {
    return mAlignment;

}

cMfont* cModel::getFontDetails() {
    return mFontDetails;
}

std::string cModel::getText() {
    return mText;
}

cMcolorRGB cModel::getStyleTextColor(int aStyleIndex) {
    cMcolorRGB color;
    color.setRed(mStyle[aStyleIndex].getTextColor().getRed());
    color.setGreen(mStyle[aStyleIndex].getTextColor().getGreen());
    color.setBlue(mStyle[aStyleIndex].getTextColor().getBlue());
    color.setAlpha(mStyle[aStyleIndex].getTextColor().getAlpha());
    mTextColor = color;
    return color;
}

cMcolorRGB cModel::getStyleBackgroundColor(int aStyleIndex) {
    cMcolorRGB color;
    color.setRed(mStyle[aStyleIndex].getTextBackgroundColor().getRed());
    color.setGreen(mStyle[aStyleIndex].getTextBackgroundColor().getGreen());
    color.setBlue(mStyle[aStyleIndex].getTextBackgroundColor().getBlue());
    color.setAlpha(mStyle[aStyleIndex].getTextBackgroundColor().getAlpha());
    mTextBackgroundColor = color;
    return color;
}

cMalignment cModel::getStyleAlignment(int aStyleIndex) {
    cMalignment align;
    align = mStyle[aStyleIndex].getAlignment().getAlign();
    mAlignment = align;
    return align;
}

bool cModel::getStyleBold(int aStyleIndex) {
    bool bold;
    bold = mStyle[aStyleIndex].getFontDetails()->getBold();
    mFontDetails->setBold(bold);
    return bold;
}

bool cModel::getStyleUnderline(int aStyleIndex) {
    bool underline;
    underline = mStyle[aStyleIndex].getFontDetails()->getUnderline();
    mFontDetails->setUnderline(underline);
    return underline;
}

bool cModel::getStyleItalics(int aStyleIndex) {
    bool italics;
    italics = mStyle[aStyleIndex].getFontDetails()->getItalics();
    mFontDetails->setItalics(italics);
    return italics;
}

int cModel::getPixelSize() {
    if(mIsFontPixel == true)
        return mFontDetails->getSize();
    else
        return mFontDetailsPoint->getSize();
}

int cModel::getPointSize() {
    if(mIsFontPixel == false)
        return mFontDetails->getSize();
    else
        return mFontDetailsPoint->getSize();
}
/////////////---resetFont---//////////////

void cModel::resetFont() {
    mFontDetails->setBold(false);
    mFontDetails->setUnderline(false);
    mFontDetails->setItalics(false);
    if(mIsFontPixel == true) { //to know if pixel or point font object is in cMfont pointer
        mFontDetails->setSize(16);
        mFontDetailsPoint->setSize(12);
    }
    else {
        mFontDetails->setSize(12);
        mFontDetailsPoint->setSize(16);
    }

    cMcolorRGB white(255,255,255,255);
    cMcolorRGB black(0,0,0,255);
    mTextColor = black;
    mTextBackgroundColor = white;

    mAlignment.setAlign(0); //left
}

///////////////////////////////////////////////////
///         END
