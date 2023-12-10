#include "simplenote.h"
#include <QDebug>
SimpleNote::SimpleNote()
{
    QDate dt = QDate::currentDate();
    QString n = dt.toString();
    QTime tm = QTime::currentTime();
    QString nn = tm.toString();
    //qDebug() << n;
    name = n + " " + nn;
    createTime = QDateTime::currentDateTime();
}

SimpleNote::SimpleNote(QString n)
{
    QDateTime *dt = new QDateTime;
    createTime = dt->currentDateTime();
    name = n;
}

SimpleNote::SimpleNote(const SimpleNote &other)
{
    this->name = other.name;
    this->createTime = other.createTime;
    this->deadLineTime = other.deadLineTime;
    this->content = other.content;
}

void SimpleNote::SetContent(QString t)
{
    content = t;
}
QString SimpleNote::GetName()
{
    return this->name;
}
QString SimpleNote::GetContent()
{
    return this->content;
}
void SimpleNote::SetDeadLine(QDate t)
{
    this->deadLineTime = t;
}
void SimpleNote:: SetName(QString t)
{
    name = t;
}
