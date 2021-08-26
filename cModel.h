#ifndef CMODEL_H
#define CMODEL_H

#include <string>
#include "cMStyle.h"
#include "cMcolorRGB.h"
#include "cMalignment.h"
#include "cMfont.h"
#include "cMPixelFont.h"
#include "cMPointFont.h"

class cModel
{
public:
    cModel();
    ~cModel();

    ///         set
    void setCurrentFileName(std::string aName);
    void setTextColor(cMcolorRGB aColor);
    void setTextBackgroundColor(cMcolorRGB aColor);
    void setAlignment(cMalignment aAlign);
    void setBold(bool aBold);
    void setUnderline(bool aUnderline);
    void setItalics(bool aItalics);
    void setPixelSize(int aPixelSize);
    void setPointSize(int aPointSize);
    void setText(std::string aText);
    void StyleDefine(int aStyleIndex, cMcolorRGB, cMcolorRGB, cMalignment, bool, bool, bool, int, int);
    void changePixelAndPoint();
    void pixelSizeIncrease();
    void pixelSizeReduce();
    void pointSizeIncrease();
    void pointSizeReduce();

    ///         get
    std::string getCurrentFileName();
    cMcolorRGB getTextColor();
    cMcolorRGB getTextBackgroundColor();
    cMalignment getAlignment();
    cMfont* getFontDetails();
    std::string getText();
    int getPixelSize();
    int getPointSize();

    cMcolorRGB getStyleTextColor(int aStyleIndex);
    cMcolorRGB getStyleBackgroundColor(int aStyleIndex);
    cMalignment getStyleAlignment(int aStyleIndex);
    bool getStyleBold(int aStyleIndex);
    bool getStyleUnderline(int aStyleIndex);
    bool getStyleItalics(int aStyleIndex);

    ///      resetFont
    void resetFont();

private:
    std::string mCurrentFileName;
    cMcolorRGB mTextColor;
    cMcolorRGB mTextBackgroundColor;
    cMalignment mAlignment;
    cMfont* mFontDetails;
    cMfont* mFontDetailsPoint;
    std::string mText;
    cMStyle mStyle[5];
    bool mIsFontPixel;
};

#endif // CMODEL_H
