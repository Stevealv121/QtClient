#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client),
    tcpSocket(new QTcpSocket(this))
{
    ui->setupUi(this);
    in.setDevice(tcpSocket);
    in.setVersion(QDataStream::Qt_4_0);
    //graphics scene
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

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
    //connectToServer();
    //ui->label->setText("connected to server");

    QBrush blackBrush(Qt::black);
    QBrush blueBrush(Qt::blue);
    QBrush whiteBrush(Qt::white);
    QPen blackPen(Qt::black);
    blackPen.setWidth(4);

    ellipse = scene->addEllipse(0,0,50,50,blackPen,whiteBrush);
    ellipse = scene->addEllipse(-100,75,50,50,blackPen,whiteBrush);
    ellipse = scene->addEllipse(-100,-75,50,50,blackPen,whiteBrush);
    ellipse = scene->addEllipse(100,75,50,50,blackPen,whiteBrush);
    ellipse = scene->addEllipse(100,-75,50,50,blackPen,whiteBrush);

    edge = scene->addLine(-75,-25,-75,75,blackPen);
    edge = scene->addLine(125,-25,125,75,blackPen);
    edge = scene->addLine(-50,-50,100,-50,blackPen);
    edge = scene->addLine(-50,100,0,25,blackPen);
    edge = scene->addLine(50,25,100,100,blackPen);

    QPolygonF a1;
    a1 << QPointF(-75,75)<<QPointF(-85,75-20)<<QPointF(-65,75-20);
    QPolygonF a2;
    a2 << QPointF(0,30)<<QPointF(-20,30)<<QPointF(-5,55);
    QPolygonF a3;
    a3 << QPointF(100,100)<<QPointF(75,90)<<QPointF(95,75);
    QPolygonF a4;
    a4 << QPointF(125,-25)<<QPointF(115,-5)<<QPointF(135,-5);
    QPolygonF a5;
    a5 << QPointF(100,-50)<<QPointF(80,-60)<<QPointF(80,-40);

    arrow = scene->addPolygon(a1,blackPen,blackBrush);
    arrow = scene->addPolygon(a2,blackPen,blackBrush);
    arrow = scene->addPolygon(a3,blackPen,blackBrush);
    arrow = scene->addPolygon(a4,blackPen,blackBrush);
    arrow = scene->addPolygon(a5,blackPen,blackBrush);

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

    in.startTransaction();
    QString message;
    QStringList test;

    in >> test;
    QString buffer = tcpSocket->readAll();
    qDebug() << buffer;
    qDebug() <<test[4];
    //ui->label->setText(buffer)
}
