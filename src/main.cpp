#include <QApplication>
#include "MainWindow.h"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    // Create a new MainWindow
    MainWindow w;
    // show it
    w.show();
    // hand control over to Qt framework
    return a.exec();
}
