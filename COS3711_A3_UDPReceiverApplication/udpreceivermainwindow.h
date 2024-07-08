#ifndef UDPRECEIVERMAINWINDOW_H
#define UDPRECEIVERMAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtWidgets>
#include <QUdpSocket>

class QLineEdit;
class QTextEdit;
class QUdpSocket;

class UDPReceiverMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit UDPReceiverMainWindow(QWidget *parent = nullptr);

signals:

public slots:
    void beginListening();
    void processIncomingDatagrams();

private:
    void setUpMainGUI();
    QTextEdit *textEdit;
    QUdpSocket *socket;

    //QMenus
    QMenu *fileMenu;

    //QActions
    QAction *startListenAction;

};

#endif // UDPRECEIVERMAINWINDOW_H
