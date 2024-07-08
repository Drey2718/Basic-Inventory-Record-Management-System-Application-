#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

#include <QtCore>
#include "transaction.h"
class Transaction;

class TransactionFactory
{
public:
    TransactionFactory();

    Transaction* createTransaction(QString itemName, QString type, QDateTime dateTime, int quantity);
};

#endif // TRANSACTIONFACTORY_H
