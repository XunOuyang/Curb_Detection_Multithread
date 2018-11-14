#include "simpleqt.h"
#include <QApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("ON Semiconductor");
    QCoreApplication::setOrganizationDomain("onsemi.com");
    QCoreApplication::setApplicationName("SimpleQt");
    SimpleQt w;
    w.show();
    QTimer::singleShot(10, &w, SLOT(onFirstStartup()));
    return a.exec();
}
