#include "cMStyle.h"


cMStyle::cMStyle()
{
    cMcolorRGB white;
    cMcolorRGB black(0,0,0,255);
    setTextColor(black);
    setTextBackgroundColor(white);

    cMalignment align;
    align.setAlign(0); //left
    setAlignment(align);

    mFontDetails = new cMPixelFont(false, false, false, 16);
    mFontDetails = new cMPointFont(false, false, false, 12);
    //setBold(false);
    //setUnderline(false);
    //setItalics(false);
    IsFontPixel = true;
}

cMStyle::~cMStyle() {
    delete mFontDetails;
    delete mFontDetailsPoint;
}

void cMStyle::define(cMcolorRGB aTextColor, cMcolorRGB aBTextColor, cMalignment aAlign, bool aB, bool aU, bool aI, int aPixel, int aPoint) {
    setTextColor(aTextColor);
    setTextBackgroundColor(aBTextColor);
    setAlignment(aAlign);
    setBold(aB);
    setUnderline(aU);
    setItalics(aI);
    setPixelSize(aPixel);
    setPointSize(aPoint);
}

/////get

cMcolorRGB cMStyle::getTextColor() {
    return mTextColor;
}

cMcolorRGB cMStyle::getTextBackgroundColor() {
    return mTextBackgroundColor;
}

cMalignment cMStyle::getAlignment() {
    return mAlignment;
}

cMfont* cMStyle::getFontDetails() {
    return mFontDetails;
}

//////set

void cMStyle::setTextColor(cMcolorRGB aColor) {
    mTextColor = aColor;
}

void cMStyle::setTextBackgroundColor(cMcolorRGB aColor) {
    mTextBackgroundColor = aColor;
}

void cMStyle::setAlignment(cMalignment aAlign) {
    mAlignment = aAlign;
}

void cMStyle::setBold(bool aBold) {
    mFontDetails->setBold(aBold);
    //mFontDetailsPoint->setBold(aBold);
}

void cMStyle::setUnderline(bool aUnderline) {
    mFontDetails->setUnderline(aUnderline);
    //mFontDetailsPoint->setUnderline(aUnderline);
}

void cMStyle::setItalics(bool aItalics) {
    mFontDetails->setItalics(aItalics);
    //mFontDetailsPoint->setItalics(aItalics);
}

void cMStyle::setPixelSize(int aPixelSize) {
    mFontDetails->setSize(aPixelSize);
}

void cMStyle::setPointSize(int aPointSize) {
    mFontDetails->setSize(aPointSize);
}

void cMStyle::changePixelAndPoint() {
    cMfont* bufor;
    bufor = mFontDetailsPoint;
    mFontDetailsPoint = mFontDetails;
    mFontDetails = bufor;
    delete bufor;
}
