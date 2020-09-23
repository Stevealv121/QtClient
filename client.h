#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QTcpSocket>

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

private:
    Ui::Client *ui;
    QTcpSocket *tcpSocket = nullptr;
    QDataStream in;
};

#endif // CLIENT_H
