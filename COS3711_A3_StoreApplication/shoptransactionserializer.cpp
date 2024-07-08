#include "shoptransactionserializer.h"

ShopTransactionSerializer::ShopTransactionSerializer(QObject *parent) : QObject(parent)
{

}

void ShopTransactionSerializer::setSerializerTransactionList(QList<Transaction *> s)
{
    s_listTransactions = s;
}

void ShopTransactionSerializer::setSerializerCustomerList(QList<Customer *> k)
{
    s_listCustomers = k;
}

QList<Transaction *> ShopTransactionSerializer::getSerializerTransactionList() const
{
    return s_listTransactions;
}

QList<Customer *> ShopTransactionSerializer::getSerializerCustomerList() const
{
    return s_listCustomers;
}

//doWork()
void ShopTransactionSerializer::generateSerialization()
{

    TransactionListToXML transToXML;
    transToXML.writeToXMLfromLists(s_listTransactions, s_listCustomers);

    QString xmlContent = transToXML.getXMLText();;

    bool condition = true;
    while (condition) {

        QUdpSocket socketUdp;

        QHostAddress senderAddress(QHostAddress::LocalHost);
        quint16 senderPort = 12345;

        QByteArray dataToSend =  xmlContent.toUtf8();

        socketUdp.writeDatagram(dataToSend, senderAddress, senderPort);

        qDebug() << "XML Data sent" << endl;

    }

    //emit finished();

}
