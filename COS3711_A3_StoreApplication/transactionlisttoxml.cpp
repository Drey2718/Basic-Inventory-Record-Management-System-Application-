#include "transactionlisttoxml.h"
#include "customerform.h"

TransactionListToXML::TransactionListToXML()
{


}

void TransactionListToXML::writeToXMLfromLists(QList<Transaction *> listTransactions, QList<Customer *> listCustomers)
{
    QDomDocument doc;

    QDomElement modelData = doc.createElement("ModelData");
    doc.appendChild(modelData);

    foreach(Customer* k, listCustomers) {
        QDomElement customer = doc.createElement("customer ");
        customer.setAttribute("name", k->getName());
        modelData.appendChild(customer);

        foreach(Transaction* t, listTransactions) {
            if (k->getName() == t->getCustomer()->getName()) {
                QDomElement transaction = doc.createElement("transaction");
                QString dateTime = t->getDateTime().toString("yyyy-MM-dd") + "T" + t->getDateTime().toString("hh:mm:ss.z");
                transaction.setAttribute("date",  dateTime);
                customer.appendChild(transaction);

                QDomElement lineItem = doc.createElement("lineitem");
                lineItem.setAttribute("name", t->getItemName());
                lineItem.setAttribute("type", t->getType());
                lineItem.setAttribute("quantity", t->getQuantity());
                transaction.appendChild(lineItem);
            }
        }
    }

    xmlText = doc.toString();
}



QString TransactionListToXML::getXMLText() const
{
    return xmlText;
}
