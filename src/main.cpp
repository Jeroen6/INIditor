/* INIditor (Automatic graphical editor for ini file)
 * Copyright (C) 2014  Jeroen Lodder
 */
#include "mainwindow.h"
#include <QApplication>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QString filename;
    if(argc > 1){
        filename = argv[1];
    }else{
        filename = "";
    }

    w.show();
    w.init(filename);

    return a.exec();
}
