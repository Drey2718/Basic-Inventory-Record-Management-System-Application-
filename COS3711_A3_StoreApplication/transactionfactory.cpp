#include "transactionfactory.h"
#include "book.h"
#include "magazine.h"

TransactionFactory::TransactionFactory()
{

}

Transaction *TransactionFactory::createTransaction(QString itemName, QString type, QDateTime dateTime, int quantity)
{
    if (type.toLower() == "book") {
        return new Transaction(itemName, "B", dateTime, quantity);
    } else if (type.toLower() == "magazine") {
        return new Transaction(itemName, "M", dateTime, quantity);
    } else {
        return new Transaction(itemName, type, dateTime, quantity);
    }
}
