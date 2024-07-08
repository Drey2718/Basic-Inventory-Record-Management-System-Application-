#ifndef SHOPTRANSACTIONSERIALIZER_H
#define SHOPTRANSACTIONSERIALIZER_H

#include <QObject>
#include <QtCore>
#include "transaction.h"
#include "customer.h"
#include "transactionlisttoxml.h"
#include <QUdpSocket>

//This is the Worker Class to run as a Thread (using QThread)
class ShopTransactionSerializer : public QObject
{
    Q_OBJECT
public:
    explicit ShopTransactionSerializer(QObject *parent = nullptr);

    //setters
    void setSerializerTransactionList(QList<Transaction*> s);
    void setSerializerCustomerList(QList<Customer*> k);

    //getters
    QList<Transaction*> getSerializerTransactionList() const;
    QList<Customer*> getSerializerCustomerList() const;


public slots:
    //doWork():
    void generateSerialization();


signals:
    void xmlText(QString);
    void finished();

private:
    QList<Transaction*> s_listTransactions;
    QList<Customer*> s_listCustomers;

};

#endif // SHOPTRANSACTIONSERIALIZER_H
