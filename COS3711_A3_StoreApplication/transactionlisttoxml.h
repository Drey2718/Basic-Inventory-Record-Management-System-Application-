#ifndef TRANSACTIONLISTTOXML_H
#define TRANSACTIONLISTTOXML_H

#include <QtXml>
#include "transaction.h"
#include "customer.h"

class TransactionListToXML
{
public:
    TransactionListToXML();
    void writeToXMLfromLists(QList<Transaction*> listTransactions, QList<Customer*> listCustomers);

    QString getXMLText() const;

private:
    QString xmlText;
};

#endif // TRANSACTIONLISTTOXML_H
