#include "inifile.h"

IniFile::IniFile(QString filename, QObject *parent) : QObject(parent)
{
    file.setFileName(filename);
    file.open(QIODevice::ReadOnly);
    parselog.setFileName(filename + QString(".parselog"));
    parselog.open(QIODevice::WriteOnly | QIODevice::Truncate);
    log.setDevice(&parselog);
}

IniFile::~IniFile()
{

}

void IniFile::parse()
{
    QTextStream f(&file);
    int ln = 0;
    IniKey *k;
    IniSection *s = new IniSection(ln, f);

#error Comments are not added to key/section this way. Find a better way.

    while(!f.atEnd()){
        QString line = f.readLine();
        ln++;
        switch(findLineType(line)){
        case blank:
            continue;
        case comment:
            comments.append(line);
            break;
        case key:
            k = new IniKey(ln, f);
            s.append(k);
            QDEBUG << "created key";
            break;
        case section:
            s = new IniSection(ln, f);
            QDEBUG << "created section";
            break;
        default:
        case invalid:
            log << "line :" << ln << ": invalid\r\n";
            break;
        }
    }
}

IniFile::LineType IniFile::findLineType(QString &line){
    // regexp for sections, starting with [ with x chars ending with ] followed by x chars
    QRegularExpression msection("^[\[].*\].*");
    // regexp for comments, starting with # or ;
    QRegularExpression mcomment("^[;#]");
    // regexp for keys, starting with alphanumerical characters
    QRegularExpression mkey("^[A-Za-z0-9_]");
    // regexp for blank line
    QRegularExpression mblank("^\s*$");
    // Result
    QRegularExpressionMatch res;
    // Test
    res = mblank.match(line);
    if(res.hasMatch()){
        return IniFile::blank;
    }
    res = mcomment.match(line);
    if(res.hasMatch()){
        return IniFile::comment;
    }
    res = mkey.match(line);
    if(res.hasMatch()){
        return IniFile::key;
    }
    res = mblank.match(line);
    if(res.hasMatch()){
        return IniFile::section;
    }
    return invalid;
}
