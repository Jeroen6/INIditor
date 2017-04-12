/* INIditor (Automatic graphical editor for ini file)
 * Copyright (C) 2014  Jeroen Lodder
 */
#include <qDebug>

#include "inisection.h"
#include "inikey.h"

iniSection::iniSection(QWidget *p, int i) :
    QMainWindow(p), parent(p), index(i)
{
    keycount = 0;

}

void iniSection::addKey(int i)
{
    iniKey *k = new iniKey(parent, i);
    keys.append(k);
    keycount++;
}

int iniSection::getKeycount() const
{
    return keycount;
}

void iniSection::removeKey(int i)
{
    if(i < 0){
        delete keys.last();
        keys.removeLast();
        keycount--;
    }else{
        if(i < keycount){
            delete keys.at(i);
            keys.removeAt(i);
            keycount--;
        }else{
            qDebug() << "iniSection::removeKey-> Cannot remove a non-existing key";
        }
    }
}
