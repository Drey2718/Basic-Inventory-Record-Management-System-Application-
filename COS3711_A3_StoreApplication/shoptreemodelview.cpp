#include "shoptreemodelview.h"

ShopTreeModelView::ShopTreeModelView():model{new QStandardItemModel},
    t_CustomerForm{new CustomerForm}
{

}

void ShopTreeModelView::updateModel()
{


    model->setColumnCount(3);

    model->setHeaderData(0, Qt::Horizontal, "Transaction");
    model->setHeaderData(1, Qt::Horizontal, "Type");
    model->setHeaderData(2, Qt::Horizontal, "Quantity");

    QStandardItem *transactionRoot = new QStandardItem("Transaction");
    transactionRoot->setEditable(false);


    foreach(Customer* k, t_CustomerForm->getCustomerList()) {
        QStandardItem *customerRoot = new QStandardItem();
        customerRoot->setText(k->getName());
        transactionRoot->appendRow(customerRoot);
        customerRoot->setEditable(false);


        foreach(Transaction* t, t_CustomerForm->getTransactionList()) {

            if (k->getName() == t->getCustomer()->getName()) {

                QStandardItem *transactionDateRoot = new QStandardItem();
                transactionDateRoot->setText(t->getDateTime().toString("yyyy/MM/dd") + QString(" ") + t->getDateTime().toString("hh:mm"));
                transactionDateRoot->setEditable(false);


                    QStandardItem *item = new QStandardItem();
                    item->setText(t->getItemName());

                    customerRoot->appendRow(transactionDateRoot);

                    QList<QStandardItem*> row;

                    row.append(item);

                    QStandardItem *columnType = new QStandardItem();
                    columnType->setText(t->getType());
                    row.append(columnType);

                    QStandardItem *columnQuantity = new QStandardItem();
                    columnQuantity->setText(QString::number(t->getQuantity()));
                    row.append(columnQuantity);

                    transactionDateRoot->appendRow(row);

            }

         }

    }

        model->appendRow(transactionRoot);

}

QStandardItemModel *ShopTreeModelView::getModel() const
{
    return model;
}

CustomerForm *ShopTreeModelView::getCustomerForm() const
{
    return t_CustomerForm;
}


