#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>
#include "insertcomputer.h"
#include <QObject>
#include "scientistrepository.h"
#include "scientist.h"
#include "scienceservice.h"
namespace Ui {
class database;
}

class database : public QMainWindow
{
    Q_OBJECT

public:
    explicit database(QWidget *parent = 0);
    int start();
    ~database();

private slots:
    void on_Search_edit_cursorPositionChanged(int arg1, int arg2);

    void on_actionAdd_new_computer_triggered();

    void on_actionAdd_a_new_computer_triggered();

    void on_actionAdd_a_new_person_2_triggered();

    void on_actionAdd_a_new_connection_triggered();

    void on_tableWidget_activated(const QModelIndex &index);

    void on_listWidget_clicked(const QModelIndex &index);

    void on_actionAdd_a_person_triggered();

    void on_actionAdd_a_computer_triggered();

    void on_treeWidget_activated(const QModelIndex &index);

private:
    Ui::database *ui;
    Insertcomputer *insertcomp;
    ScientistRepository scientistRepository;
    ScienceService scienceService;

};

#endif // DATABASE_H
