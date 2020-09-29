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

namespace Ui {
class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();

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
};

#endif // CLIENT_H
