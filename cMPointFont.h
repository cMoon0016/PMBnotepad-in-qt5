#ifndef CMPOINTFONT_H
#define CMPOINTFONT_H

#include "cMfont.h"
#include "cMPixelFont.h"

class cMPointFont : public cMfont
{
public:
   cMPointFont(bool, bool, bool, int);

   int getSize();
   void setSize(int aPointSize);
   virtual void operator+(int);
   virtual void operator-(int);

private:
   int mPointSize;
};

#endif // CMPOINTFONT_H
