/* INIditor (Automatic graphical editor for ini file)
 * Copyright (C) 2014  Jeroen Lodder
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>

#include "inisection.h"

/**
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    // Cleanup!
    while(sections.count())
        while(sections.last()->getKeycount())
            sections.last()->removeKey();
    delete ui;
}

/**
 * @brief MainWindow::init
 * @details initiliaze the MainWindow after the MainWindow is created.
 *          This way all GUI elements have been loaded safely.
 * @param filename
 */
void MainWindow::init(QString filename)
{
    if(filename == ""){
        openFileDialog();
    }else{
        lastOpenFile = filename;
    }

    loadFile();
    parseData();
    exit(0);
}

/**
 * @brief MainWindow::openFileDialog
 * @details This function pops-up an file-Open dialog
 */
void MainWindow::openFileDialog(){

    QFileDialog dialog(this, "Load INI file", lastOpenDir, "Settings (*.ini)");
    dialog.setFileMode(QFileDialog::ExistingFile);
    if(dialog.exec()){
        lastOpenFile = dialog.selectedFiles().first();
        lastOpenDir = lastOpenFile;
        lastOpenDir.chop(lastOpenDir.count() - lastOpenFile.lastIndexOf('/'));
    }
}

/**
 * @brief MainWindow::loadFile
 * @details This function load the ini file to a QStringList
 */
void MainWindow::loadFile(){
    lastOpenFileInfo.setFile(lastOpenFile);
    if(!lastOpenFileInfo.exists()){
        QMessageBox::critical(this,tr("Error"),
                              tr("Could not retrieve file details.\n"),
                              QMessageBox::Ok);
        return;
    }else{
        file.setFileName(lastOpenFile);
        file.open(QIODevice::ReadOnly);
        fileData.clear();
        while(!file.atEnd()){
            QString l = file.readLine();
            l.remove('\n');
            l.remove('\r');
            fileData.append(l);
        }
        file.close();
    }
}

/**
 * @brief MainWindow::parseData
 * @details Regular expression are used to filter the 3 main line categories
 *          and create the corresponding object with the line number.
 *          The 4 categories
 *          - section headers [text]
 *          - instructions ;<
 *          - keys
 *          - normal comment lines ; or # (these are ignored)
 *
 */
void MainWindow::parseData(){
    QRegularExpression msection("^[\[].*\].*"); // regexp for sections, starting with [ with x chars ending with ] followed by x chars
    QRegularExpression mcomment("^[;#]");       // regexp for comments, starting with # or ;
    QRegularExpression msyntax("^;<");          // regexp for instruction, starting with ;<
    QRegularExpression mkey("^[A-Za-z0-9_]");   // regexp for keys, starting with alphanumerical characters

    for(int i=0; i<fileData.count(); i++)
    {
        // Check for section
        QRegularExpressionMatch res = msection.match(fileData.at(i));
        if(res.hasMatch()){
            qDebug() << "S: " << fileData.at(i);
            iniSection *s = new iniSection(this, i);
            sections.append(s);
            continue;
        }

        // Check for instructions
        QRegularExpressionMatch syntax = msyntax.match(fileData.at(i));
        if( syntax.hasMatch() ){
            qDebug() << "I: " << fileData.at(i);
            continue;
        }

        // Check for key
        QRegularExpressionMatch key = mkey.match(fileData.at(i));
        if( key.hasMatch() ){
            qDebug() << "K: " << fileData.at(i);
            sections.last()->addKey(i);
            continue;
        }
    }
}
