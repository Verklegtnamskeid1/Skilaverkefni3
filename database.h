#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>
#include "insertcomputer.h"
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

<<<<<<< HEAD
=======

>>>>>>> 46bdd310f64b1a3cb2da3c4555c9e6901b211a82
    void on_treeWidget_activated(const QModelIndex &index);

    void on_Search_edit_textChanged(const QString &arg1);
    void displayCurrentPersons();

<<<<<<< HEAD
    void on_listWidget_activated(const QModelIndex &index);

    void on_listWidget_2_activated(const QModelIndex &index);

=======
>>>>>>> 46bdd310f64b1a3cb2da3c4555c9e6901b211a82
private:
    Ui::database *ui;
    Insertcomputer *insertcomp;
};

#endif // DATABASE_H
