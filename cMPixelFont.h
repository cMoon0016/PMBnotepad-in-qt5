#ifndef CMPIXELFONT_H
#define CMPIXELFONT_H

#include "cMfont.h"
#include "cMPointFont.h"

class cMPixelFont : public cMfont
{
public:
    cMPixelFont(bool, bool, bool, int);

    int getSize();
    void setSize(int aPixelSize);
    virtual void operator+(int);
    virtual void operator-(int);

private:
    int mPixelSize;
};

#endif // CMPIXELFONT_H
