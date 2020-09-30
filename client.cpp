#include "client.h"
#include "ui_client.h"

/**
 * @brief Constructor
 * Encargado de inicializar la gui y el nuevo socket.
 * Establece el dispositivo stream al socket creado,
 * luego elegimos la version Qt_4_0 para que se puedo conectar
 * con el servidor.
 * Para la GUI se le agregan todos los items necesarios:
 * scene, grapchisView, comboBoxs,labels y el push button.
 * Ademas se dibuja la representacion del grafo.
 * Luego se implementa las signals connected(),disconnected(),
 * readyRead() y bytesWritten() para el buen funcionamiento
 * de la conexion cliente-servidor.
 * Por ultimo se avanza a conectar con el servidor llamando
 * a la funcion connectToServer().
 *
 * @param parent
 */
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

    //comboBox
    ui->comboBox->addItem("A");
    ui->comboBox->addItem("B");
    ui->comboBox->addItem("C");
    ui->comboBox->addItem("D");
    ui->comboBox->addItem("E");
    ui->comboBox_2->addItem("A");
    ui->comboBox_2->addItem("B");
    ui->comboBox_2->addItem("C");
    ui->comboBox_2->addItem("D");
    ui->comboBox_2->addItem("E");

    drawGraph();

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

/**
 * @brief Destructor del Cliente, cierra el cliente
 *
 */
Client::~Client()
{
    delete ui;
}

/**
 * @brief Se conecta al servidor mediante
 * socket->connectToHost() y le pide la direccion
 * de IP y el numero de puerto ubicado.
 *
 */
void Client::connectToServer()
{

    tcpSocket->connectToHost("127.0.0.1",1234);
}

/**
 * @brief Calcula la distancia mas corta entre los vertices seleccionados
 *
 */
void Client::on_pushButton_clicked()
{
   //A Cases
   if(ui->comboBox->currentText() == "A" && ui->comboBox_2->currentText() == "A")
   {
       ui->label_5->setText(graph[0]);
   }
   if(ui->comboBox->currentText() == "A" && ui->comboBox_2->currentText() == "B")
   {
       ui->label_5->setText(graph[1]);
   }
   if(ui->comboBox->currentText() == "A" && ui->comboBox_2->currentText() == "C")
   {
       ui->label_5->setText(graph[2]);
   }
   if(ui->comboBox->currentText() == "A" && ui->comboBox_2->currentText() == "D")
   {
       ui->label_5->setText(graph[3]);
   }
   if(ui->comboBox->currentText() == "A" && ui->comboBox_2->currentText() == "E")
   {
       ui->label_5->setText(graph[4]);
   }
   //B Cases
   if(ui->comboBox->currentText() == "B" && ui->comboBox_2->currentText() == "A")
   {
       ui->label_5->setText(graph[5]);
   }
   if(ui->comboBox->currentText() == "B" && ui->comboBox_2->currentText() == "B")
   {
       ui->label_5->setText(graph[6]);
   }
   if(ui->comboBox->currentText() == "B" && ui->comboBox_2->currentText() == "C")
   {
       ui->label_5->setText(graph[7]);
   }
   if(ui->comboBox->currentText() == "B" && ui->comboBox_2->currentText() == "D")
   {
       ui->label_5->setText(graph[8]);
   }
   if(ui->comboBox->currentText() == "B" && ui->comboBox_2->currentText() == "E")
   {
       ui->label_5->setText(graph[9]);
   }
   //C Cases
   if(ui->comboBox->currentText() == "C" && ui->comboBox_2->currentText() == "A")
   {
       ui->label_5->setText(graph[10]);
   }
   if(ui->comboBox->currentText() == "C" && ui->comboBox_2->currentText() == "B")
   {
       ui->label_5->setText(graph[11]);
   }
   if(ui->comboBox->currentText() == "C" && ui->comboBox_2->currentText() == "C")
   {
       ui->label_5->setText(graph[12]);
   }
   if(ui->comboBox->currentText() == "C" && ui->comboBox_2->currentText() == "D")
   {
       ui->label_5->setText(graph[13]);
   }
   if(ui->comboBox->currentText() == "C" && ui->comboBox_2->currentText() == "E")
   {
       ui->label_5->setText(graph[14]);
   }
   //D Cases
   if(ui->comboBox->currentText() == "D" && ui->comboBox_2->currentText() == "A")
   {
       ui->label_5->setText(graph[15]);
   }
   if(ui->comboBox->currentText() == "D" && ui->comboBox_2->currentText() == "B")
   {
       ui->label_5->setText(graph[16]);
   }
   if(ui->comboBox->currentText() == "D" && ui->comboBox_2->currentText() == "C")
   {
       ui->label_5->setText(graph[17]);
   }
   if(ui->comboBox->currentText() == "D" && ui->comboBox_2->currentText() == "D")
   {
       ui->label_5->setText(graph[18]);
   }
   if(ui->comboBox->currentText() == "D" && ui->comboBox_2->currentText() == "E")
   {
       ui->label_5->setText(graph[19]);
   }
   //E Cases
   if(ui->comboBox->currentText() == "E" && ui->comboBox_2->currentText() == "A")
   {
       ui->label_5->setText(graph[20]);
   }
   if(ui->comboBox->currentText() == "E" && ui->comboBox_2->currentText() == "B")
   {
       ui->label_5->setText(graph[21]);
   }
   if(ui->comboBox->currentText() == "E" && ui->comboBox_2->currentText() == "C")
   {
       ui->label_5->setText(graph[22]);
   }
   if(ui->comboBox->currentText() == "E" && ui->comboBox_2->currentText() == "D")
   {
       ui->label_5->setText(graph[23]);
   }
   if(ui->comboBox->currentText() == "E" && ui->comboBox_2->currentText() == "E")
   {
       ui->label_5->setText(graph[24]);
   }


}

/**
 * @brief El cliente se conecta satisfactoriamente al servidor y le escribe para asi
 * obtener la solucion del algoritmo Floyd-Warshall
 *
 */
void Client::connected()
{
    qDebug() << "Connected!";

    tcpSocket->write("Hello Server\r\n");
}

/**
 * @brief Cliente se desconecta del servidor
 *
 */
void Client::disconnected()
{
    qDebug() << "Disconnected!";
}

/**
 * @brief Numero de bytes escritos al servidor
 *
 * @param bytes numero de bytes
 */
void Client::bytesWritten(qint64 bytes)
{
    qDebug() << "We wrote : "<< bytes;
}

/**
 * @brief Utilizamos QDataStream para la lectura del socket
 * Empezamos llamando startTransaction() lo que hace es resetear
 * el estado del stream para indicar que nueva data ha sido
 * recibida en el socket. Luego procedemos utilizar el operador
 * ">>" de QDataStream para leer test. Por ultimo establecemos
 * el grafo llamando a setGraph y le pasamos test al constructor.
 *
 */
void Client::readyRead()
{
    qDebug() << "Reading...";

    in.startTransaction();
    QStringList test;

    in >> test;
    setGraph(test);

}

/**
 * @brief Dibuja el grafo representado
 * Los vertices y aristas con sus respectivos
 * pesos y texto son agregados a la scene.
 *
 */
void Client::drawGraph(){

    QBrush blackBrush(Qt::black);
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

    text = scene->addText("A");
    text->setPos(-94,-75);
    text->setScale(2);
    text1 = scene->addText("B");
    text1->setPos(-94,75);
    text1->setScale(2);
    text2 = scene->addText("C");
    text2->setPos(6,0);
    text2->setScale(2);
    text3 = scene->addText("D");
    text3->setPos(106,75);
    text3->setScale(2);
    text4 = scene->addText("E");
    text4->setPos(106,-75);
    text4->setScale(2);
    text5 = scene->addText("8");
    text5->setPos(-120,-5);
    text5->setScale(2);
    text6 = scene->addText("3");
    text6->setPos(-30,55);
    text6->setScale(2);
    text7 = scene->addText("5");
    text7->setPos(37,55);
    text7->setScale(2);
    text8 = scene->addText("5");
    text8->setPos(130,0);
    text8->setScale(2);
    text9 = scene->addText("12");
    text9->setPos(1,-105);
    text9->setScale(2);
}

/**
 * @brief Establece el grafo que contiene la solucion del
 * algoritmo Floyd-Warshall
 *
 * @param list
 */
void Client::setGraph(QStringList list)
{
    graph = list;
}
