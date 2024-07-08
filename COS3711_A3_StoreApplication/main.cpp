#include <QCoreApplication>
#include <QApplication>
#include "customerform.h"
#include "checkdataform.h"
#include "shopmainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ShopMainWindow myShop;
    myShop.show();

    return a.exec();
}
