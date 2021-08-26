#ifndef CMFONT_H
#define CMFONT_H


class cMfont
{
public:
    cMfont();
    cMfont(bool,bool,bool);
    virtual ~cMfont();

    ///set
    virtual void setBold(bool aBold);
    virtual void setUnderline(bool aUnderline);
    virtual void setItalics(bool aItalics);
    virtual void setSize(int) = 0;
    //void setPixelSize(int aPixelSize);
    //void setPointSize(int aPointSize);
    virtual void operator+(int) = 0;
    virtual void operator-(int) = 0;

    ///get
    virtual bool getBold();
    virtual bool getUnderline();
    virtual bool getItalics();
    virtual int getSize() = 0;
    //int getPixelSize();
    //int getPointSize();

protected:
    bool mBold;
    bool mUnderline;
    bool mItalics;
    //int mPixelSize;
    //int mPointSize;
};

#endif // CMFONT_H
