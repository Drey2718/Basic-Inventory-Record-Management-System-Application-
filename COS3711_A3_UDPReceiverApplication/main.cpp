#include <QCoreApplication>
#include <QApplication>
#include "udpreceivermainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    UDPReceiverMainWindow udpR;
    udpR.show();

    return a.exec();
}
