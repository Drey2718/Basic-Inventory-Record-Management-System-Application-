#include "udpreceivermainwindow.h"

UDPReceiverMainWindow::UDPReceiverMainWindow(QWidget *parent) : QMainWindow(parent),
    textEdit{new QTextEdit(this)},
    socket{new QUdpSocket(this)},
    fileMenu{new QMenu(this)},
    startListenAction{new QAction(this)}
{
    setUpMainGUI();
}

void UDPReceiverMainWindow::setUpMainGUI()
{
    setWindowTitle("UDP Receiver");
    resize(500, 500);

    fileMenu = menuBar()->addMenu("File");

    //Adding menu items
    startListenAction->setText("Listen");
    fileMenu->addAction(startListenAction);

    QGridLayout* mainLayout = new QGridLayout(this);
    textEdit->setGeometry(0, 0, 500, 480);
    mainLayout->addWidget(textEdit);
    textEdit->setText("Please select listen from File menu to begin listening");

    textEdit->setReadOnly(true);


    //Connecting signals and slots
    connect(startListenAction, &QAction::triggered, this, &UDPReceiverMainWindow::beginListening);
}


void UDPReceiverMainWindow::beginListening()
{
    textEdit->setText("listening...");
    socket = new QUdpSocket(this);


    if (!socket->bind(QHostAddress::Any, 12345)) {
        qDebug() << "Cannot bind to port 12345";
        textEdit->setText("Cannot bind to port 12345");
    }

    textEdit->setText("listening on port 12345...");

    connect(socket, SIGNAL(readyRead()), this, SLOT(processIncomingDatagrams()));


}

void UDPReceiverMainWindow::processIncomingDatagrams()
{

   bool condition = true;

    while (condition == true) {

        QByteArray message;
        message.resize(socket->pendingDatagramSize());
        socket->waitForReadyRead();

        socket->readDatagram(message.data(), message.size());

        QString dataReceived(message);

        textEdit->clear();
        textEdit->append(message);

        qDebug() << "Received Data: " << dataReceived;

        if (dataReceived.contains("<ModelData>")) {
            condition = false;
            qDebug() << "STOP" << endl;
            socket->close();
        }
    }
}

