#ifndef CMALIGNMENT_H
#define CMALIGNMENT_H

//MANUAL
//mAlign=0 -> left
//mAlign=1 -> center
//mAlign=2 -> right

class cMalignment
{
public:
    cMalignment();

    void setAlign(int aAlign);

    int getAlign();

    void operator=(const int aAlign);

private:
    int mAlign;
};

#endif // CMALIGNMENT_H
