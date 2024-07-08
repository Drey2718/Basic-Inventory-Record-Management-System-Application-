#ifndef CUSTOMERFORM_H
#define CUSTOMERFORM_H

#include <QMainWindow>
#include <QtCore>
#include <QtWidgets>
#include "customer.h"
#include "book.h"
#include "magazine.h"
#include "transaction.h"
#include "checkdataform.h"
#include "itemlistmemento.h"


class CustomerForm : public QMainWindow
{
    Q_OBJECT
public:
    explicit CustomerForm(QWidget *parent = nullptr);

public:
    //GETTERS:
    QList<QObject*> getItemList() const;
    QList<Transaction*> getTransactionList() const;
    QList<Customer*> getCustomerList() const;

    Transaction* getTransactionFromTransactionList(QString itemName, QString customerName) const;

    CheckDataForm* getCheckDataForm() const;

    //Originator - methods:

    void setItemListMemento(ItemListMemento *m);
    ItemListMemento* createItemListMemento();
    void setCurrentState(QStringList  st);
    QStringList getCurrentState();


    //Caretaker - methods:
    void backUp();
    void restore();


private:
    QLabel *enterDataLabel;
    QLabel *itemTypeLabel;
    QLabel *itemNameLabel;
    QComboBox *itemTypeComboBox;
    QLineEdit *itemNameLineEdit;

    QPushButton *addItemButton;

    QList<Customer*> customerList;
    //itemList - is the state to be saved (Originator)
    QList<QObject*> itemList;
    QList<Transaction*> transactionList;

    CheckDataForm* m_CheckDataForm;

    QString customerNameFromComboBoxSelection;

    void setUpUI();

    ItemListMemento *m_state;

    QStringList stateValues;

public slots:
    void onAddItemClicked();
    void updateItemSelection(int index);
    void updateTypeDisplayLabael(int index);

};

#endif // CUSTOMERFORM_H
