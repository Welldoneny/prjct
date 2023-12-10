#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "simplenote.h"
#include <QList>
#include <QListWidgetItem>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_CreateBtn_clicked();

    void on_ListOfNotes_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_NoteEditor_textChanged();

private:
    Ui::MainWindow *ui;
    QList<SimpleNote*> *_noteList;
    SimpleNote *chosenNote;
};
#endif // MAINWINDOW_H
