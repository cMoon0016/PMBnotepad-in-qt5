#include "cMPixelFont.h"

cMPixelFont::cMPixelFont(bool aB, bool aU, bool aI, int aPixelSize)
    : cMfont(aB, aU, aI), mPixelSize(aPixelSize) {}

void cMPixelFont::setSize(int aPixelSize) {
    mPixelSize = aPixelSize;
}

int cMPixelFont::getSize() {
    return mPixelSize;
}

void cMPixelFont::operator+(int a) {
    mPixelSize += a;
}

void cMPixelFont::operator-(int a) {
    mPixelSize -= a;
}
