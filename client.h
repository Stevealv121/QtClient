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

/**
 * @brief Cliente el cual prueba la distancia mas corta
 * entre dos vertices, solucion dada por el servidor
 *
 */
class Client : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructor
     *
     * @param parent
     */
    explicit Client(QWidget *parent = 0);
    /**
     * @brief Destructor
     *
     */
    ~Client();

    QStringList graph; /**< Lista que contiene el grafo solucionado */
    /**
     * @brief Establece el grafo solucionado
     *
     * @param list solucion del grafo
     */
    void setGraph(QStringList list);

private slots:
    /**
     * @brief Calcula la distancia mas corta entre pares
     *
     */
    void on_pushButton_clicked();
    /**
     * @brief Se conecta al server
     *
     */
    void connectToServer();
    /**
     * @brief Conectado!
     *
     */
    void connected();
    /**
     * @brief Desconectado!
     *
     */
    void disconnected();
    /**
     * @brief Bytes escribidos
     *
     * @param bytes numero de bytes
     */
    void bytesWritten(qint64 bytes);
    /**
     * @brief Listo para leer del servidor
     *
     */
    void readyRead();

private:
    Ui::Client *ui; /**< gui */
    QTcpSocket *tcpSocket = nullptr; /**< Socket */
    QDataStream in; /**< Contenido entrante */
    QGraphicsScene *scene; /**< scene */
    QGraphicsEllipseItem *ellipse; /**< Vertice */
    QGraphicsLineItem *edge; /**< Arista */
    QGraphicsPolygonItem *arrow; /**< Flecha */
    QGraphicsTextItem *text; /**< Nodo A */
    QGraphicsTextItem *text1; /**< Nodo B */
    QGraphicsTextItem *text2; /**< Nodo C */
    QGraphicsTextItem *text3; /**< Nodo D */
    QGraphicsTextItem *text4; /**< Nodo E */
    QGraphicsTextItem *text5; /**< Peso 8 */
    QGraphicsTextItem *text6; /**< Peso 3 */
    QGraphicsTextItem *text7; /**< Peso 5 */
    QGraphicsTextItem *text8; /**< Peso 5 */
    QGraphicsTextItem *text9; /**< Peso 12 */

    /**
     * @brief Dibuja el grafo en pantalla
     *
     */
    void drawGraph();

};

#endif // CLIENT_H
