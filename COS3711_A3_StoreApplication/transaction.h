#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QObject>
#include <QtCore>
#include "book.h"
#include "magazine.h"
#include "customer.h"

class Transaction : public QObject
{
    Q_OBJECT
public:
    explicit Transaction(QObject *parent = nullptr);

    //Custom Constructor
    Transaction(QString iN, QString ty, QDateTime dt, int q);

    //SETTERS
    void setItemName(QString iN);
    void setType(QString ty);
    void setDateTime(QDateTime dt);
    void setQuantity(int q);
    void setCustomer(Customer* c);

    //GETTERS
    QString getItemName() const;
    QString getType() const;
    QDateTime getDateTime() const;
    int getQuantity() const;
    Customer* getCustomer() const;

    //toString()
    QString toString() const;

private:
    //data members
    QString itemName;
    QString type;
    QDateTime dateTime;
    int quantity;

    Customer* customer;

};

#endif // TRANSACTION_H
