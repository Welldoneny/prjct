#pragma once
#include "simplenote.h"
#include<QLineEdit>
#include <QWidget>
#include <QTextEdit>
#include <QListWidget>
#include <QCalendarWidget>
class NNCreator : public QWidget
{

    Q_OBJECT
public:
    NNCreator(QListWidget *lw, QList<SimpleNote*> *nts, QWidget *parent = 0);
    void Notify(QListWidget *lw, SimpleNote *n);

private slots:
    void CreateNote();
    void SetDate(const QDate &date);

private:
    QCalendarWidget *calendar;
    QLineEdit *nameed;
    QLineEdit *dateed;
    QTextEdit *txt;
    QListWidget *listwidget;
    QList<SimpleNote*> *noteList;
    SimpleNote *note;
};

