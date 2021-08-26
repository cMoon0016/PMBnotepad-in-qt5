#ifndef FONTSIZEDIALOG_H
#define FONTSIZEDIALOG_H

#include <QMainWindow>
#include <QObject>

class FontSizeDialog
{
    Q_OBJECT

public:
    FontSizeDialog(QWidget *parent = nullptr);
    ~FontSizeDialog();
    Ui::FontSizeDialog* getUI();
    void setController(cController*);
    void setView(cView*);

public:
    FontSizeDialog();
};

#endif // FONTSIZEDIALOG_H
