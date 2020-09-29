#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDataStream>
#include <QDebug>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsTextItem>

namespace Ui {
class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();

    QStringList graph;
    void setGraph(QStringList list);

private slots:
    void on_pushButton_clicked();
    void connectToServer();
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();

private:
    Ui::Client *ui;
    QTcpSocket *tcpSocket = nullptr;
    QDataStream in;
    QGraphicsScene *scene;
    QGraphicsEllipseItem *ellipse;
    QGraphicsLineItem *edge;
    QGraphicsPolygonItem *arrow;
    QGraphicsTextItem *text;
    QGraphicsTextItem *text1;
    QGraphicsTextItem *text2;
    QGraphicsTextItem *text3;
    QGraphicsTextItem *text4;
    QGraphicsTextItem *text5;
    QGraphicsTextItem *text6;
    QGraphicsTextItem *text7;
    QGraphicsTextItem *text8;
    QGraphicsTextItem *text9;

    void drawGraph();

};

#endif // CLIENT_H
