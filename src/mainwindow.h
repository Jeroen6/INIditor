/* INIditor (Automatic graphical editor for ini file)
 * Copyright (C) 2014  Jeroen Lodder
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QFileInfo>

#include "inisection.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void init(QString filename);

protected:
    Ui::MainWindow *ui;
    QFile file;
    QString lastOpenFile;
    QString lastOpenDir;
    QFileInfo lastOpenFileInfo;
    QStringList fileData;

    QList<iniSection*> sections;

    void openFileDialog();
    void loadFile();
    void parseData();

};

#endif // MAINWINDOW_H
