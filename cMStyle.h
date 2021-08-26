#ifndef CMSTYLE_H
#define CMSTYLE_H

#include "cMcolorRGB.h"
#include "cMalignment.h"
#include "cMfont.h"
#include "cMPixelFont.h"
#include "cMPointFont.h"

class cMStyle
{
public:
    cMStyle();
    ~cMStyle();
    void define(cMcolorRGB, cMcolorRGB, cMalignment, bool, bool, bool, int, int);

    //set
    void setTextColor(cMcolorRGB aColor);
    void setTextBackgroundColor(cMcolorRGB aColor);
    void setAlignment(cMalignment aAlign);
    void setBold(bool aBold);
    void setUnderline(bool aUnderline);
    void setItalics(bool aItalics);
    void setPixelSize(int aPixelSize);
    void setPointSize(int aPointSize);
    void changePixelAndPoint();

    //get
    cMcolorRGB getTextColor();
    cMcolorRGB getTextBackgroundColor();
    cMalignment getAlignment();
    cMfont* getFontDetails();

private:
    cMcolorRGB mTextColor;
    cMcolorRGB mTextBackgroundColor;
    cMalignment mAlignment;
    cMfont* mFontDetails;
    cMfont* mFontDetailsPoint;
    bool IsFontPixel;
};

#endif // CMSTYLE_H
