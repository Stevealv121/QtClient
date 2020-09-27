#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client),
    tcpSocket(new QTcpSocket(this))
{
    ui->setupUi(this);

    connect(tcpSocket, SIGNAL(connected()), this, SLOT(connected()));
    connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(tcpSocket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));

    qDebug() << "Connecting...";
    connectToServer();
    if(!tcpSocket->waitForConnected(1000)){

        qDebug() << "Error: " << tcpSocket->errorString();
    }
}

Client::~Client()
{
    delete ui;
}

void Client::connectToServer()
{
    //tcpSocket->abort();
    tcpSocket->connectToHost("127.0.0.1",1234);
}

void Client::on_pushButton_clicked()
{
    connectToServer();
    //ui->label->setText("connected to server");

}

void Client::connected()
{
    qDebug() << "Connected!";

    tcpSocket->write("Hello Server\r\n");
}

void Client::disconnected()
{
    qDebug() << "Disconnected!";
}

void Client::bytesWritten(qint64 bytes)
{
    qDebug() << "We wrote : "<< bytes;
}

void Client::readyRead()
{
    qDebug() << "Reading...";
    QString buffer = tcpSocket->readAll();
    qDebug() << buffer;
    ui->label->setText(buffer);
}
