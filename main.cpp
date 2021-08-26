#include "mainwindow.h"
#include "cModel.h"
#include "cController.h"
#include "cView.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    cModel model;
    cController controller(&model);
    cView view(&w, &controller);
    w.setView(&view);
    w.show();
    view.update();
    return a.exec();
}
