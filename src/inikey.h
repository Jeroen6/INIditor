/* INIditor (Automatic graphical editor for ini file)
 * Copyright (C) 2014  Jeroen Lodder
 */
#ifndef INIKEY_H
#define INIKEY_H

#include <QMainWindow>

class iniKey : public QMainWindow
{
    Q_OBJECT
public:
    explicit iniKey(QWidget *parent = 0, int i=-1);

signals:

public slots:

private:
    int index;  /// Line number of file this key resides
};

#endif // INIKEY_H
