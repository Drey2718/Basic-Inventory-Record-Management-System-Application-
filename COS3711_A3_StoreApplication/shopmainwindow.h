#ifndef SHOPMAINWINDOW_H
#define SHOPMAINWINDOW_H

#include <QApplication>
#include <QtCore>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QTextEdit>
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>
#include <QLabel>
#include <QRadioButton>
#include <QLineEdit>
#include <QSpinBox>
#include "customerform.h"
#include "shoptreemodelview.h"
#include <QTreeView>
#include <QTableView>
#include <QListView>
#include <shoptransactionserializer.h>

class QLabel;


class ShopMainWindow : public QMainWindow
{


    Q_OBJECT

    public:
      explicit ShopMainWindow(QWidget *parent = nullptr);

        //Destructor
        ~ShopMainWindow();

        //textEdit
        QTextEdit *textEdit;

    private:
        void setupMainGUI();
        //Layout
        QGridLayout *mainLayout;

        //QMenus
        QMenu *fileMenu;
        QMenu *addMenu;
        QMenu *restoreMenu;
        QMenu *xmlMenu;

        //QActions
        //for fileMenu:
        QAction *viewCustomerAction;
        QAction *viewAllTransactions;
        //for addMenu
        QAction *addPurchaseAction;
        //for restoreMenu
        QAction *restoreAction;
        //for xmlMenu
        QAction *broadcastXmlAction;
        QAction *displayXmlAction;

        //Model & View
        ShopTreeModelView *mainTreeModel;
        QTreeView *mainTreeView;

        //QTableView
        QTableView *mainTableView;

        //QListView
        QListView *mainListView;

        //Serializer
        ShopTransactionSerializer* serialize;

        //Thread
        QThread* thread;


    private slots:

        void onViewCustomerActionTriggered();
        void onViewAllTransactionsTriggered();

        void onAddPurchaseActionActionTriggered();

        void onBroadcastXMLActionTriggered();
        void onDisplayXMLActionTriggered();

        void onRestoreActionTriggered();




 };





#endif // SHOPMAINWINDOW_H
