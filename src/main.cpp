// --- QT includes -------------------------------------------------------------
#include <QApplication>
#include <QStyle>
//#include <QCleanlooksStyle>
#include <QMainWindow>

//---MyClass includes-----------------------------------------------------------
#include "mainwindow.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // QApplication::setStyle(new QCleanlooksStyle);
    a.connect( &a, SIGNAL( lastWindowClosed() ), &a, SLOT( quit() ) );
    MainWindow w;
    w.show();
    return a.exec();
}
