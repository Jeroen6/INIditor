/* INIditor (Automatic graphical editor for ini file)
 * Copyright (C) 2014  Jeroen Lodder
 */
#ifndef INISECTION_H
#define INISECTION_H

#include <QMainWindow>
#include "inikey.h"

class iniSection : public QMainWindow
{
    Q_OBJECT
public:
    explicit iniSection(QWidget *parent = 0, int i=-1);

    void addKey(int i);
    void removeKey(int i = -1);

    int getKeycount() const;

signals:

public slots:

private:
    QWidget *parent;
    int index; /// Line number of file this section resides
    QList<iniKey *> keys;   /// List of keys
    int keycount;

};

#endif // INISECTION_H
