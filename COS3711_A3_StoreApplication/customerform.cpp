#include "customerform.h"
#include "transactionfactory.h"
#include <QInputDialog>

CustomerForm::CustomerForm(QWidget *parent) : QMainWindow(parent),
    enterDataLabel{new QLabel(this)},
    itemNameLabel{new QLabel(this)},
    itemTypeLabel{new QLabel(this)},
    itemTypeComboBox{new QComboBox(this)},
    itemNameLineEdit{new QLineEdit(this)},
    addItemButton{new QPushButton(this)},
    m_CheckDataForm{new CheckDataForm(this)}
{
    setUpUI();
}

//GETTERS:

QList<QObject *> CustomerForm::getItemList() const
{
    return itemList;
}

QList<Transaction *> CustomerForm::getTransactionList() const
{
    return transactionList;
}

QList<Customer *> CustomerForm::getCustomerList() const
{
    return customerList;
}

Transaction *CustomerForm::getTransactionFromTransactionList(QString itemName, QString customerName) const
{
    foreach(Transaction* t, transactionList) {
        if (itemName == t->getItemName() && customerName == t->getCustomer()->getName()) {
            return t;
        }
    }
}

CheckDataForm *CustomerForm::getCheckDataForm() const
{
    return m_CheckDataForm;
}

//ORIGINATOR - METHODS
void CustomerForm::setItemListMemento(ItemListMemento *m)
{
    qDebug() << "SetItemListMemento called" << endl;

    if (itemList.isEmpty()) {
        QMessageBox messageBox;
        messageBox.setIcon(QMessageBox::Warning);
        messageBox.setWindowTitle("Restore Failed - No items");
        messageBox.setText("No items have been added (purchased), please select Add Purchase to add an item.");
        messageBox.exec();

    } else {

        QStringList state = m->getState();
        stateValues.clear();
        for (int j = 0; j < state.count(); j++) {
            stateValues.append(state.at(j));
        }
     }
}

ItemListMemento *CustomerForm::createItemListMemento()
{
   QStringList state;

   foreach(QObject* w, itemList){
       if (w->property("bookName").isValid()) {
           state.append(w->property("bookName").toString());
       } else {
            state.append(w->property("magazineName").toString());
       }
   }

   ItemListMemento *l_memento = new ItemListMemento;
   l_memento->setState(state);

   return l_memento;
}

void CustomerForm::setCurrentState(QStringList st)
{
    stateValues = st;
}


QStringList CustomerForm::getCurrentState()
{
    return stateValues;
}


void CustomerForm::backUp()
{
    m_state = this->createItemListMemento();
}

void CustomerForm::restore()
{
    qDebug() << "RESTOR CALLED" << endl;
    this->setItemListMemento(m_state);
}


void CustomerForm::setUpUI()
{
    setWindowTitle("Shop");
    setFixedSize(380, 230);

    //Labels
    enterDataLabel->setGeometry(100, 30, 300, 20);
    enterDataLabel->setText("Complete the required data");

    itemTypeLabel->setGeometry(50, 40, 80, 100);
    itemTypeLabel->setText("Item type");

    itemNameLabel->setGeometry(50, 90, 100, 100);
    itemNameLabel->setText("Name of item");

    itemTypeComboBox->setGeometry(170, 80, 150, 30);
    itemTypeComboBox->addItem("Book");
    itemTypeComboBox->addItem("Magazine");

    itemNameLineEdit->setGeometry(170, 125, 150, 30);
    itemNameLineEdit->setText("");

    addItemButton->setGeometry(120, 180, 150, 30);
    addItemButton->setText("Add Item");

    //Adding widgets to the layout
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(enterDataLabel);
    layout->addWidget(itemTypeLabel);
    layout->addWidget(itemNameLabel);
    layout->addWidget(itemTypeComboBox);
    layout->addWidget(itemNameLineEdit);
    layout->addWidget(addItemButton);

    //Connecting signals and slots
    connect(addItemButton, &QPushButton::clicked, this, &CustomerForm::onAddItemClicked);
    connect(m_CheckDataForm->getSelectCustomerComboBox(), QOverload<int>::of(&QComboBox::activated),
            this, &CustomerForm::updateItemSelection);
    connect(m_CheckDataForm->getSelectItemComboBox(), QOverload<int>::of(&QComboBox::activated),
            this, &CustomerForm::updateTypeDisplayLabael);


}

void CustomerForm::updateItemSelection(int index)
{
   m_CheckDataForm->getSelectItemComboBox()->clear();

    customerNameFromComboBoxSelection = m_CheckDataForm->getSelectCustomerComboBox()->itemText(index);

       foreach(Transaction* t, transactionList) {
           if (m_CheckDataForm->getSelectItemComboBox()->findText(t->getItemName()) == -1) {
                 if (customerNameFromComboBoxSelection == t->getCustomer()->getName()) {
                        m_CheckDataForm->getSelectItemComboBox()->addItem(t->getItemName());

                  }
           }
       }

}

void CustomerForm::updateTypeDisplayLabael(int index)
{

      QString itemNameFromSelection = m_CheckDataForm->getSelectItemComboBox()->itemText(index);

      qDebug() << "customer list COUNT:" << customerList.count();
      Transaction* transactionFromSelection = getTransactionFromTransactionList(itemNameFromSelection, customerNameFromComboBoxSelection);
      m_CheckDataForm->getItemTypeDisplay()->setText(transactionFromSelection->getType());
      m_CheckDataForm->getQuantitySpinBox()->setValue(transactionFromSelection->getQuantity());

}


//SLOTS:
void CustomerForm::onAddItemClicked()
{
    QDateTime dt = dt.currentDateTime();
    TransactionFactory tf;
    int customerQuantity;

    QString customerName = QInputDialog::getText(nullptr, "Customer Name", "Please Enter Your Name:");

    for (int i = 0; i < customerList.count(); i++) {
        if (customerName == customerList.at(i)->getName()) {
            customerList.removeAt(i);
        }
    }

    Customer *customer = new Customer();
    customer->setName(customerName);

    customerList.append(customer);


    if (itemTypeComboBox->currentText() == "Book") {
        Book *book = new Book();
        book->setName(itemNameLineEdit->text());
        //Adding the item (Book) to the item list:
        itemList.append(book);
        customerQuantity = QInputDialog::getInt(nullptr, "Quantity of Books", "Please enter the Quantity (Amount of Books):", 0, 1);


        Transaction *bookTransaction = tf.createTransaction(book->getName(), "book", dt, customerQuantity);
        bookTransaction->setCustomer(customer);
        transactionList.append(bookTransaction);



    } else if (itemTypeComboBox->currentText() == "Magazine") {
        Magazine *magazine = new Magazine();
        magazine->setMagazineName(itemNameLineEdit->text());
        //Adding the item (Magazine) to the item list:
        itemList.append(magazine);
        customerQuantity = QInputDialog::getInt(nullptr, "Quantity of Magazines", "Please enter the Quantity (Amount of Magazines):", 0, 1);


        Transaction *magazineTransaction = tf.createTransaction(magazine->getMagazineName(), "magazine", dt, customerQuantity);
        magazineTransaction->setCustomer(customer);
        transactionList.append(magazineTransaction);

    }

    if (m_CheckDataForm->getSelectCustomerComboBox()->findText(customerName) == -1)
     {
          m_CheckDataForm->getSelectCustomerComboBox()->addItem(customer->getName());
     }

     //saving (back up) the item list:
     this->backUp();

     itemNameLineEdit->clear();
}


