/* INIditor (Automatic graphical editor for ini file)
 * Copyright (C) 2014  Jeroen Lodder
 */
#include <qDebug>

#include "inisection.h"
#include "inikey.h"

/**
 * @brief IniSection
 * @param lineNumber    to edit later
 * @param f             QTextStream to continue parsing
 * @param parent
 */
IniSection::IniSection(int lineNumber, QTextStream &f, QWidget *parent) :
    QObject(parent)
{
    keycount = 0;

}

void IniSection::append(IniKey *k)
{

}

void IniSection::addKey(int i)
{
    //IniKey *k = new IniKey(parent, i);
    //keys.append(k);
    //keycount++;
}

int IniSection::getKeycount() const
{
    return keycount;
}

void IniSection::removeKey(int i)
{
    //if(i < 0){
    //    delete keys.last();
    //    keys.removeLast();
    //    keycount--;
    //}else{
    //    if(i < keycount){
    //        delete keys.at(i);
    //        keys.removeAt(i);
    //        keycount--;
    //    }else{
    //        qDebug() << "iniSection::removeKey-> Cannot remove a non-existing key";
    //    }
    //}
}
