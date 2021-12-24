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
    ~MainWindow();
signals:
public slots:void click_fn();
private:
    Ui::MainWindow *ui;
    QPushButton * b ;
    QVBoxLayout * l ;
    QPainter * paint;
    QLabel * label;
    QPen pen;
};
#endif // MAINWINDOW_H
