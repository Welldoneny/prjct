#include "mainwindow.h"
#include <QApplication>
#include <QList>
#include <QList>
#include "simplenote.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // установка стандартного стиля
    a.setStyle("fusion");
    // главное окно
    MainWindow w;
    w.show();
    return a.exec();
}
