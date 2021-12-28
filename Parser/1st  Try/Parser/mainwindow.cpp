#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    flag = false;

    b=new QPushButton("Run",this);
    b->setGeometry(width()/8,height()-25,60,20);

    textEdit= new QTextEdit(this);
    textEdit -> setGeometry(10,10,width()/4,height()-40);
    textEdit->setTextBackgroundColor(Qt::yellow);
    posN={(width()/4) +20, 15};

//    label = new QLabel(this);
//    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
//    label ->setGeometry((width()/4)+20,35,50,20);
//    label->setAlignment(Qt::AlignCenter);

//    connect(textEdit,SIGNAL(textChanged()),this,SLOT(parseScannerOutput((textEdit->toPlainText()).toUtf8().constData())));
    connect(b,SIGNAL(clicked()),this,SLOT(click_fn()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::click_fn(){

    parseScannerOutput((textEdit->toPlainText().toUtf8().constData()));
    token =tokenQueue.front();
    syntexTreeRoot = program_proc();
//    string x = tokenQueue.front().val;
//    label->setText(QString::fromStdString(tokenQueue.front().val));
//    tokenQueue.pop();
    flag = true;
    update();
}
void MainWindow::drawNode(Node * node,Position posD){
        switch (node->getType()){
        case stmt:
            drawRec(posD.x, posD.y,60,50,Qt::white,Qt::black,QString::fromStdString(node->getTockenRecord().val));
        break;
        case expr:
            drawEllipse(posD.x, posD.y,60,50,Qt::white,Qt::black,QString::fromStdString(node->getTockenRecord().val));
          break;
        }
}
void MainWindow::drawTree(Node * node){
    drawNode(node,{posN.x,posN.y});
    int numOfChildren = node->getNumChildren();
    posN.y+=70;
    for(int i=0;i<numOfChildren;i++){
        drawTree(node->getChild());
        posN.x+=70;
    }
    posN.y-=70;
    if(node->getMyBro()!=NULL){
        posN.x+=70;
        drawTree(node->getMyBro());
    }
}
void MainWindow::paintEvent(QPaintEvent * ){
    paint = new QPainter(this);
    paint->setClipping(false);//
    this->setFixedSize(100000,10000);

    if(flag){
           drawTree(syntexTreeRoot);

//        for(int i = 0;i<20;i++)
//            drawRec((i*110)+30,30+30,100,50,Qt::white,Qt::blue,QString::number(i));

//        for(int i = 0;i<20;i++)
//            drawEllipse((i*110)+30+60,30+50+100+30,100,50,Qt::white,Qt::black,QString::number(i));
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
    }
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
void MainWindow::drawEllipse(int x, int y,int width,int hight,QColor color,QColor outterColor,QString seq){
    pen.setWidth(5);
    pen.setStyle(Qt::SolidLine);
    pen.setColor(outterColor);
    paint->setPen(pen);
    QRect rect(x,y,width,hight);
    paint->fillRect(rect,color);
    paint->drawEllipse(rect);
    paint->drawText(rect,Qt::AlignCenter,seq);

    //paint->drawText(rect,Qt::AlignCenter,QString::number(seq));
}



void  MainWindow::parseScannerOutput(string code) {
    queue<TockenRecord> res;
    for (int i = 0; i < code.length(); i++) {
        TockenRecord temp;
        string tempType = "";
        while (code[i] != ',' && i < code.length()) {
            temp.val += (code[i]);
            i++;
        }
        if (i < code.length()) i++;

        while (code[i] != '\n' && i < code.length()) {
            tempType += (code[i]);
            i++;
        }

        if (tempType == "IF") temp.tt = IF;
        else if (tempType == "THEN") temp.tt = THEN;
        else if (tempType == "ELSE") temp.tt = ELSE;
        else if (tempType == "END") temp.tt = END;
        else if (tempType == "REPEAT") temp.tt = REPEAT;
        else if (tempType == "UNTIL") temp.tt = UNTIL;
        else if (tempType == "READ") temp.tt = READ;
        else if (tempType == "WRITE") temp.tt = WRITE;
        else if (tempType == "PLUS") temp.tt = PLUS;
        else if (tempType == "MINUS") temp.tt = MINUS;
        else if (tempType == "MULT") temp.tt = MUL;
        else if (tempType == "DIV") temp.tt = DIVIDE;
        else if (tempType == "EQUAL") temp.tt = EQUAL;
        else if (tempType == "LESSTHAN") temp.tt = LESSTHAN;
        else if (tempType == "GREATERTHAN") temp.tt = GREATERTHAN;
        else if (tempType == "OPENBRACKET") temp.tt = LEFTBRACKET;
        else if (tempType == "CLOSEDBRACKET") temp.tt = RIGHTBRACKET;
        else if (tempType == "SEMICOLON") temp.tt = SEMICOLON;
        else if (tempType == "ASSIGN") temp.tt = ASSIGN;
        else if (tempType == "NUMBER") temp.tt = NUMBER;
        else if (tempType == "IDENTIFIER") temp.tt = IDENTIFIER;
        else if (tempType == "SPACE") temp.tt = SPACE;

        res.push(temp);
    }

    tokenQueue = res;
}
