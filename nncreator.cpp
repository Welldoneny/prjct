#include "nncreator.h"
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QDebug>
NNCreator::NNCreator(QListWidget *lw, QList<SimpleNote*> *nts, QWidget *parent ): QWidget(parent)
{
    //создание внешнего вида окна в котором создаётся заметка
    listwidget = lw;
    noteList = nts;
    QPushButton *create = new QPushButton("Create", this);

    QLabel *name = new QLabel("Name",this);
    QLabel *date = new QLabel("Срок",this);
    nameed = new QLineEdit(this);
   // dateed = new QLineEdit(this);
    calendar = new QCalendarWidget(this);


    QGridLayout *grid = new QGridLayout();

      grid->addWidget(name, 0, 0);
      grid->addWidget(nameed, 0, 1);
      grid->addWidget(date, 1, 0);
      grid->addWidget(calendar, 1, 1);
      grid->addWidget(create, 2, 1);

    setLayout(grid);
    connect(create, &QPushButton::clicked, this, &NNCreator::CreateNote);
    connect(calendar, &QCalendarWidget::clicked, this, &NNCreator::SetDate);
    note = new SimpleNote();
}
void NNCreator:: CreateNote()
{
    QString name = nameed->text();
    //SimpleNote *note = new SimpleNote(name);
    //SetDate(this, note);
    //если заметке дали имя, то мы его устанавливаем, если не указано, то по умолчанию останется дата создания
    if(name !="")
    {
        note->SetName(name);
    }
    noteList->append(note);
    // уведомляем список заметок, что есть изменение
    Notify(listwidget, note);
    NNCreator::setEnabled(false);
    NNCreator::setVisible(false);
}
void NNCreator:: Notify(QListWidget *lw, SimpleNote *n)
{
        QString item = n->GetName();
        lw->addItem(item);
}
void NNCreator:: SetDate(const QDate &date)
{
    note->SetDeadLine(date);
}
