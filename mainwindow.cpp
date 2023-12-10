#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "nncreator.h"
#include <QList>
//конструктор главного окна
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // создание списка указателей на заметку
    _noteList = new QList<SimpleNote*>;
    // в будущем здесь будем сразу при включении приложения заполнять виджет заметками из БД
//    for (int i = 0; i < _noteList->size(); i++)
//    {
//        SimpleNote *tmp = _noteList->at(i);
//        QString item = tmp->GetName();
//        ui->ListOfNotes->addItem(item);
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

// обработка кнопки создания заметки
void MainWindow::on_CreateBtn_clicked()
{
    // класс создатель заметок
    NNCreator *nvc;
    nvc = new NNCreator(ui->ListOfNotes, _noteList); // первый аргумент это указатель на виджет хранящий заметки
    // второй аргумент это список с заметками
    nvc->show();
}

void MainWindow::on_ListOfNotes_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    // перебираем наши заметки и если её имя совпадает с выбранной, то выводим её содержимое
   QString name = current->text();
   for (int i = 0; i < _noteList->size(); i++)
   {
       SimpleNote *tmp = (SimpleNote*)(_noteList->at(i));
       if(name == tmp->GetName())
       {
           //промежуточная переменная, показывает заметку с которой мы работаем
           chosenNote = tmp;
           ui->NoteEditor->setText(tmp->GetContent());
       }
   }
}
// при изменении текста в заметке, она сохраняется
void MainWindow::on_NoteEditor_textChanged()
{
    QString text = ui->NoteEditor->toPlainText();
    chosenNote->SetContent(text);
}
