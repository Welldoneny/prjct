#pragma once
#include <QString>
#include <QDateTime>

class SimpleNote
{
public:
    SimpleNote();
    SimpleNote(QString n);
    void SetContent(QString t);
    SimpleNote(const SimpleNote &other);
    SimpleNote &operator=(const SimpleNote &other);
    QString GetName();
    QString GetContent();
    void SetDeadLine(QDate t);
    void SetName(QString t);

protected:
     QString name;
     QDateTime createTime;
     QDate deadLineTime;
     QString content;
};

