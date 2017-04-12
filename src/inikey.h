/* INIditor (Automatic graphical editor for ini file)
 * Copyright (C) 2014  Jeroen Lodder
 */
#ifndef INIKEY_H
#define INIKEY_H

#include <QMainWindow>
#include <QTextStream>

class IniKey : public QObject
{
    Q_OBJECT
public:
    explicit IniKey(int lineNumber, QTextStream &f, QWidget *parent = 0);

signals:

public slots:

private:
    int ln;  /// Line number of file this key resides
};

#endif // INIKEY_H
