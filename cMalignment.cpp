#include "cMalignment.h"

//MANUAL
//mAlign=0 -> left
//mAlign=1 -> center
//mAlign=2 -> right

//////////////////////////////////////////////////////
///        constructors
///

cMalignment::cMalignment()
{
    mAlign = 0;
}

//////////////////////////////////////////////////////
///           set
///


void cMalignment::setAlign(int aAlign) {
    mAlign = aAlign;
}

//////////////////////////////////////////////////////
///           get
///

int cMalignment::getAlign() {
    return mAlign;
}

//////////////////////////////////////////////////////
///        operators
///

void cMalignment::operator=(const int aAlign) {
    mAlign = aAlign;
}

///////////////////////////////////////////////////
///         END
