#include "magazine.h"

Magazine::Magazine(QObject *parent) : QObject(parent)
{

}

Magazine::Magazine(QString n):magazineName(n)
{

}

void Magazine::setMagazineName(QString n)
{
    magazineName = n;
}

QString Magazine::getMagazineName() const
{
    return magazineName;
}
