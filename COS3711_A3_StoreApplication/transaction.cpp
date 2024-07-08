#include "transaction.h"

Transaction::Transaction(QObject *parent) : QObject(parent)
{

}

Transaction::Transaction(QString iN, QString ty, QDateTime dt, int q):
    itemName(iN),
    type(ty),
    dateTime(dt),
    quantity(q)
{

}

void Transaction::setItemName(QString iN)
{
    itemName = iN;
}

void Transaction::setType(QString ty)
{
    type = ty;
}

void Transaction::setDateTime(QDateTime dt)
{
    dateTime = dt;
}

void Transaction::setQuantity(int q)
{
    quantity = q;
}

void Transaction::setCustomer(Customer *c)
{
    customer = c;
}


QString Transaction::getItemName() const
{
    return itemName;
}

QString Transaction::getType() const
{
    return type;
}

QDateTime Transaction::getDateTime() const
{
    return dateTime;
}

int Transaction::getQuantity() const
{
    return quantity;
}

Customer *Transaction::getCustomer() const
{
    return customer;
}


QString Transaction::toString() const
{
    QString tranactionString;
    tranactionString = QString("Transaction: ") + QString(" Item name: ") +
            getItemName() + QString(", Type: ") + getType() + QString(", Date: ") + dateTime.toString("yyyy.MM.dd") + QString(" ") + dateTime.toString("hh:mm")
            + QString(", Quantity: ") + QString::number(quantity);

    return tranactionString;
}


