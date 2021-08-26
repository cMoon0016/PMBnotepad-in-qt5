#ifndef CMCOLORRGB_H
#define CMCOLORRGB_H


class cMcolorRGB
{
public:
    cMcolorRGB(int r = 255, int g = 255, int b = 255, int a = 255);
    cMcolorRGB(cMcolorRGB &aColor);


    ///      set
    void set(int r, int g, int b, int a = 255);
    void setRed(int r);
    void setGreen(int g);
    void setBlue(int b);
    void setAlpha(int a);

    ///      get
    int getRed();
    int getGreen();
    int getBlue();
    int getAlpha();

    ///    operators
    cMcolorRGB& operator=(cMcolorRGB aColor);

private:
    int mRed;
    int mGreen;
    int mBlue;
    int mAlpha;

};

#endif // CMCOLORRGB_H
