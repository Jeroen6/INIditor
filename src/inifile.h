/* INIditor (Automatic graphical editor for ini file)
 * Copyright (C) 2014  Jeroen Lodder
 */
#ifndef INIFILE_H
#define INIFILE_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QChar>
#include <QRegularExpression>
#include "inisection.h"
#include "inikey.h"

class IniFile : public QObject
{
    Q_OBJECT
public:
    explicit IniFile(QString filename, QObject *parent = 0);
    ~IniFile();

    enum LineType { blank, comment, key, section, invalid };
signals:

public slots:

private:
    QFile file;
    QFile parselog;
    QTextStream log;
    QList<IniSection *> sections;
    QStringList comments;

    void parse();

    LineType findLineType(QString &line);
};

#endif // INIFILE_H
