#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent * ){
    paint = new QPainter(this);

//    if(flag){


//        for(int i = 0;i<noOfSend;i++)
//            drawRec((i*60)+30,30+30,50,50,Qt::white,getMeTheColor(0,bufferS[i%8].type,noError),QString::number(bufferS[i%8].seq));

//        for(int i = 0;i<noOfRec;i++){

//            drawRec((i*60)+30+60,30+50+100+30,50,50,Qt::white,getMeTheColor(1,sent,bufferR[i%8].type),QString::number(bufferR[i%8].seq));
//           }
//        for(int i=0;i<noOfRec;i++){
//            pen.setColor(Qt::black);
//            paint->setPen(pen);
//            QLine li((i*60)+60,30+55+30,(i*60)+30+60+30,30+45+100+30);
//            paint->drawLine(li);

//        }
//        for(int i=1;i<noOfRec;i++){
//            if(bufferR[(i-1)%8].type==noError){
//                pen.setStyle(Qt::DashLine);
//                pen.setColor(Qt::black);
//                paint->setPen(pen);
//                QLine liAck(((i-1)*60)+30+60+30,30+45+100+30,(i*60)+60+60,30+55+30);
//                paint->drawLine(liAck);
//            }
//        }
//    }
}
void MainWindow::drawRec(int x, int y,int width,int hight,QColor color,QColor outterColor,QString seq){
    pen.setWidth(5);
    pen.setStyle(Qt::SolidLine);
    pen.setColor(outterColor);
    paint->setPen(pen);
    QRect rect(x,y,width,hight);
    paint->fillRect(rect,color);
    paint->drawRect(rect);
    paint->drawText(rect,Qt::AlignCenter,seq);

    //paint->drawText(rect,Qt::AlignCenter,QString::number(seq));
}

