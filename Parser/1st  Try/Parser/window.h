#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include "QPushButton"
#include "QApplication"
#include "QScrollArea"
#include "QVBoxLayout"
#include "QLabel"
#include "qpainter.h"
#include "QTextEdit"
#include "string"
#include "queue"
#include "node.h"
#include "iostream"
#include "proceduresA.h"
#include "proc.h"

using namespace std;

typedef struct {
    int x;
    int y;
}Count;

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent * );
    void drawRec(int x, int y,int width,int hight,QColor color,QColor outterColor,QString seq);
    void drawEllipse(int x, int y,int width,int hight,QColor color,QColor outterColor,QString seq);
    void drawNode(Node * node,Position posD);
    void drawTree(Node * node);
    void drawLine(int stX, int stY,int enX,int enY,QColor color);
    int counterTree(Node * node);
signals:
public slots:void click_fn();
public slots:void parseScannerOutput(string code);
private:
    QPushButton * b ;
    QVBoxLayout * l ;
    QPainter * paint;
    QLabel * label;
    QPen pen;
    bool flag;
    QTextEdit *textEdit;
    Node * syntexTreeRoot;
    Position start;
    Count counter;

};

#endif // WINDOW_H
