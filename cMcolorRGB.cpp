#include "cMcolorRGB.h"

//////////////////////////////////////////////////////
///        constructors
///

cMcolorRGB::cMcolorRGB(int r, int g, int b, int a) { /// default all = 255
    set(r,g,b,a);
}

cMcolorRGB::cMcolorRGB(cMcolorRGB &aColor) {
    mRed = aColor.getRed();
    mGreen = aColor.getGreen();
    mBlue = aColor.getBlue();
    mAlpha = aColor.getAlpha();
}

/////////////////////////////////////////////////////
///        set
///

void cMcolorRGB::set(int r, int g, int b, int a) { /// default a = 255
    mRed = r;
    mGreen = g;
    mBlue = b;
    mAlpha = a;
}

void cMcolorRGB::setRed(int r) {
    mRed = r;
}

void cMcolorRGB::setGreen(int g) {
    mGreen = g;
}

void cMcolorRGB::setBlue(int b) {
    mBlue = b;
}

void cMcolorRGB::setAlpha(int a) {
    mAlpha = a;
}

////////////////////////////////////////////////////
///        get
///

int cMcolorRGB::getRed() {
    return mRed;
}

int cMcolorRGB::getGreen() {
    return mGreen;
}

int cMcolorRGB::getBlue() {
    return mBlue;
}

int cMcolorRGB::getAlpha() {
    return mAlpha;
}

////////////////////////////////////////////////////
///      operators
///

cMcolorRGB& cMcolorRGB::operator=(cMcolorRGB aColor) {
    mRed = aColor.getRed();
    mGreen = aColor.getGreen();
    mBlue = aColor.getBlue();
    mAlpha = aColor.getAlpha();

    return *this;
}
///////////////////////////////////////////////////
///         END
