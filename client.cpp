#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client),
    tcpSocket(new QTcpSocket(this))
{
    ui->setupUi(this);
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
    ui->label->setText("connected to server");

}
