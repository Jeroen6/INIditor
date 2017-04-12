/* INIditor (Automatic graphical editor for ini file)
 * Copyright (C) 2014  Jeroen Lodder
 */
#ifndef INISECTION_H
#define INISECTION_H

#include <QMainWindow>
#include "inikey.h"

class IniSection : public QObject
{
    Q_OBJECT
public:
    explicit IniSection(int lineNumber, QTextStream &f, QWidget *parent = 0);

    void append(IniKey *k);

    void addKey(int i);
    void removeKey(int i = -1);

    int getKeycount() const;

signals:

public slots:

private:
    QWidget *parent;
    int index; /// Line number of file this section resides
    QList<IniKey *> keys;   /// List of keys
    int keycount;

};

#endif // INISECTION_H
