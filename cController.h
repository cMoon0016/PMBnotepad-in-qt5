#ifndef CCONTROLLER_H
#define CCONTROLLER_H

#include <QMainWindow>
#include <QObject>
#include "cModel.h"
#include "ui_mainwindow.h"

class MainWindow;

class cController
{
private:
    //MainWindow* mView;
    cModel*  mModel;
    //QFont mCurrentFont;
    QFont mStyleFont[5];

public:
    cController(/*MainWindow* aView,*/ cModel* aModel);
    ~cController();
    //Ui::MainWindow* getUI();

    ///     model -> view

    //color
    QColor getTextColor();
    QColor getTextBackgroundColor();
    //alignment
    Qt::Alignment getAlignment();
    //font
    bool getBold();
    bool getUnderline();
    bool getItalics();
    int getPixelSize();
    int getPointSize();

    //style
    QFont getStyleFont(int aStyleIndex);
    QColor  getStyleTextColor(int aStyleIndex);
    QColor getStyleBackgroundColor(int aStyleIndex);
    Qt::Alignment getStyleAlignment(int aStyleIndex);

    //text
    QString getText();

    ///     view -> model

    //color
    void setTextColor(QColor aColor);
    void setTextBackgroundColor(QColor aColor);
    //alignment
    void setAlignment(Qt::Alignment aAlign);
    //font
    void setBold(bool aBold);
    void setUnderline(bool aUnderline);
    void setItalics(bool aItalics);
    void setPixelSize(int aPixelSize);
    void setPointSize(int aPointSize);
    void setFont();
    void pixelSizeIncrease();
    void pixelSizeReduce();
    void pointSizeIncrease();
    void pointSizeReduce();

    //text
    void setText(QString aText);
    //style
    void StyleDefine(QFont aFont, QColor aTextColor, QColor aBackgroundColor, Qt::Alignment, int aStyleIndex);

    //reset font
    void resetFont();
};

#endif // CCONTROLLER_H
