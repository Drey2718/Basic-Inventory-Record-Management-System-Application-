#include "shopmainwindow.h"
#include <QInputDialog>
#include <transactionlisttoxml.h>


ShopMainWindow::ShopMainWindow(QWidget *parent): QMainWindow(parent),
    mainLayout{new QGridLayout(this)},
    textEdit{new QTextEdit(this)},
    fileMenu{new QMenu(this)},
    addMenu{new QMenu(this)},
    restoreMenu{new QMenu(this)},
    xmlMenu{new QMenu(this)},
    viewCustomerAction{new QAction(this)},
    viewAllTransactions{new QAction(this)},
    addPurchaseAction{new QAction(this)},
    restoreAction{new QAction(this)},
    broadcastXmlAction{new QAction(this)},
    displayXmlAction{new QAction(this)},
    mainTreeModel{new ShopTreeModelView},
    mainTreeView{new QTreeView(this)},
    mainTableView{new QTableView(this)},
    mainListView{new QListView(this)},
    thread{nullptr},
    serialize{nullptr}


{
    setupMainGUI();

}

ShopMainWindow::~ShopMainWindow()
{
    if ((thread != nullptr) && (thread->isRunning())) {
        thread->quit();
        thread->deleteLater();
        serialize->deleteLater();
    }

    delete mainTreeModel;

    this->destroy(true);


}

void ShopMainWindow::setupMainGUI()
{

        setWindowTitle("Shop");
        resize(600, 400);

        //QMenu
        fileMenu = menuBar()->addMenu("File");
        addMenu = menuBar()->addMenu("Add");
        restoreMenu = menuBar()->addMenu("Restore");
        xmlMenu = menuBar()->addMenu("XML");

        //Adding menu items
        viewCustomerAction->setText("View Customer Data");
        fileMenu->addAction(viewCustomerAction);
        viewAllTransactions->setText("View All Transactions");
        fileMenu->addAction(viewAllTransactions);
        fileMenu->addSeparator();

        addPurchaseAction->setText("Add Purchase");
        addMenu->addAction(addPurchaseAction);

        restoreAction->setText("Restore items");
        restoreMenu->addAction(restoreAction);

        broadcastXmlAction->setText("Broadcast XML");
        xmlMenu->addAction(broadcastXmlAction);
        displayXmlAction->setText("Display XML");
        xmlMenu->addAction(displayXmlAction);


        connect(viewCustomerAction, &QAction::triggered, this, &ShopMainWindow::onViewCustomerActionTriggered);
        connect(viewAllTransactions, &QAction::triggered, this, &ShopMainWindow::onViewAllTransactionsTriggered);

        connect(addPurchaseAction, &QAction::triggered, this, &ShopMainWindow::onAddPurchaseActionActionTriggered);

        connect(restoreAction, &QAction::triggered, this, &ShopMainWindow::onRestoreActionTriggered);

        connect(broadcastXmlAction, &QAction::triggered, this, &ShopMainWindow::onBroadcastXMLActionTriggered);
        connect(displayXmlAction, &QAction::triggered, this, &ShopMainWindow::onDisplayXMLActionTriggered);



        mainTreeView->setGeometry(0, 0, 0, 0);
        textEdit->setGeometry(0, 0, 600, 370);

        mainLayout->addWidget(textEdit);
        mainLayout->addWidget(mainTreeView);
        textEdit->setText("Hello");


}

void ShopMainWindow::onViewCustomerActionTriggered()
{
    mainTreeModel->getCustomerForm()->getCheckDataForm()->show();
    QMessageBox messageBox;
    messageBox.setIcon(QMessageBox::Information);
    messageBox.setWindowTitle("Info");
    messageBox.setText("Please select each item or Customer again in the ComboBox to get data (e.g. reselect customer & item to display correct data - type & quantity");
    messageBox.exec();
}

void ShopMainWindow::onViewAllTransactionsTriggered()
{
     if (mainTreeModel->getCustomerForm()->getTransactionList().isEmpty()) {
         QMessageBox messageBox;
         messageBox.setIcon(QMessageBox::Information);
         messageBox.setWindowTitle("Info");
         messageBox.setText("Please select 'Add purchase' to create transactions in the 'Add Menu'");
         messageBox.exec();
     }

     mainTreeView->setGeometry(0, 0, 600, 370);
     textEdit->setGeometry(0, 0, 0, 0);
     mainTreeModel->getModel()->clear();
     mainTreeModel->updateModel();
     mainTreeView->setModel(mainTreeModel->getModel());
     mainTreeView->expandAll();
     mainTreeView->resizeColumnToContents(0);


     /*
     mainTableView->setGeometry(0, 0, 600, 370);
     textEdit->setGeometry(0, 0, 0, 0);
     mainTreeModel->getModel()->clear();
     mainTreeModel->updateModel();
     mainTableView->setModel(mainTreeModel->getModel());
     mainTableView->resizeColumnsToContents();
     */

     /*
     mainListView->setGeometry(0, 0, 600, 370);
     textEdit->setGeometry(0, 0, 0, 0);
     mainTreeModel->getModel()->clear();
     mainTreeModel->updateModel();
     mainListView->setModel(mainTreeModel->getModel());
     */





}

void ShopMainWindow::onAddPurchaseActionActionTriggered()
{
    mainTreeModel->getCustomerForm()->show();

}



void ShopMainWindow::onBroadcastXMLActionTriggered()
{
    mainTreeView->setGeometry(0, 0, 0, 0);
    textEdit->setGeometry(0, 0, 600, 370);
    textEdit->setText("Broadcasting XML...");

    serialize = new ShopTransactionSerializer();
    serialize->setSerializerTransactionList(mainTreeModel->getCustomerForm()->getTransactionList());
    serialize->setSerializerCustomerList(mainTreeModel->getCustomerForm()->getCustomerList());

    thread = new QThread();

    serialize->moveToThread(thread);

    connect(thread, SIGNAL(started()), serialize, SLOT(generateSerialization()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), serialize, SLOT(deleteLater()));

    thread->start();


}


void ShopMainWindow::onDisplayXMLActionTriggered()
{
    mainTreeView->setGeometry(0, 0, 0, 0);
    textEdit->setGeometry(0, 0, 600, 370);

    TransactionListToXML t_toXML;

    t_toXML.writeToXMLfromLists(mainTreeModel->getCustomerForm()->getTransactionList(),
                                mainTreeModel->getCustomerForm()->getCustomerList());
    textEdit->setText(t_toXML.getXMLText());

}

void ShopMainWindow::onRestoreActionTriggered()
{
    textEdit->clear();
    qDebug() << "Restore Triggered" << endl;
    mainTreeView->setGeometry(0, 0, 0, 0);
    textEdit->setGeometry(0, 0, 600, 370);
    textEdit->setText("Restoring Item List...");

    mainTreeModel->getCustomerForm()->restore();


    QStringList itemsList;
    itemsList = mainTreeModel->getCustomerForm()->getCurrentState();
    textEdit->setText("Item list:");

    foreach(QString item, itemsList){
        textEdit->append(item);
    }

    itemsList.clear();
}








