#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QWidget"
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

QT_BEGIN_NAMESPACE
class QPushButton;
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent * );
    void drawRec(int x, int y,int width,int hight,QColor color,QColor outterColor,QString seq);
    void drawEllipse(int x, int y,int width,int hight,QColor color,QColor outterColor,QString seq);
    ~MainWindow();
signals:
public slots:void click_fn();
public slots:void parseScannerOutput(string code);
private:
    Ui::MainWindow *ui;
    QPushButton * b ;
    QVBoxLayout * l ;
    QPainter * paint;
    QLabel * label;
    QPen pen;
    QTextEdit *textEdit;
};
#endif // MAINWINDOW_H
