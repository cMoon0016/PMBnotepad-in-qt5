#include "cMfont.h"

/////////////----CONSTRUCTORS----/////////////////

cMfont::cMfont() {}

cMfont::cMfont(bool aB, bool aU, bool aI)
    : mBold(aB), mUnderline(aU), mItalics(aI) {}

cMfont::~cMfont() {}

/////////////----SET----/////////////////

void cMfont::setBold(bool aBold) {
    mBold = aBold;
}

void cMfont::setUnderline(bool aUnderline) {
    mUnderline = aUnderline;
}

void cMfont::setItalics(bool aItalics) {
    mItalics = aItalics;
}

//void cMfont::setPixelSize(int aPixelSize) {
//    mPixelSize = aPixelSize;
//}

//void cMfont::setPointSize(int aPointSize) {
//    mPointSize = aPointSize;
//}

/////////////----GET----/////////////////

bool cMfont::getBold() {
    return mBold;
}

bool cMfont::getUnderline() {
    return mUnderline;
}

bool cMfont::getItalics() {
    return mItalics;
}

//int cMfont::getPixelSize() {
//    return mPixelSize;
//}

//int cMfont::getPointSize() {
//    return mPointSize;
//}

/////////////----END----/////////////////
