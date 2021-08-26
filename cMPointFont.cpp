#include "cMPointFont.h"

cMPointFont::cMPointFont(bool aB, bool aU, bool aI, int aPointSize)
    : cMfont(aB, aU, aI), mPointSize(aPointSize) {}

void cMPointFont::setSize(int aPointSize) {
    mPointSize = aPointSize;
}

int cMPointFont::getSize() {
    return mPointSize;
}

void cMPointFont::operator+(int a) {
    mPointSize += a;
}

void cMPointFont::operator-(int a) {
    mPointSize -= a;
}
