#include "window.h"
#include <QScrollArea>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    QWidget* wrapper = new QWidget();
    Window * window = new Window();
    QLabel * label = new QLabel("  ");

     QVBoxLayout* layout = new QVBoxLayout(window);
       layout->addWidget(label);
     window->setParent(wrapper);
    //window.show();
    QWidget* scrollAreaContent = new QWidget;
    scrollAreaContent->setLayout( layout );

    QScrollArea* scrollArea = new QScrollArea;
//    QScrollBar* scrollBar = scrollArea->horizontalScrollBar();
    scrollArea->setWidgetResizable(false);
    scrollArea->setHorizontalScrollBarPolicy( Qt::ScrollBarAsNeeded );
    scrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAsNeeded );
    scrollArea->setWidgetResizable( true );
    scrollArea->setWidget( window);
   // scrollArea->setBaseSize( QSize(600,400));

    scrollArea->show();

    return a.exec();
}
