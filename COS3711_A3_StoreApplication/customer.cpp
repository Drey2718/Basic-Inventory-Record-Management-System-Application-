#include "customer.h"

Customer::Customer(QObject *parent) : QObject(parent)
{

}

void Customer::setName(QString n)
{
    name = n;
}

QString Customer::getName() const
{
    return name;
}
