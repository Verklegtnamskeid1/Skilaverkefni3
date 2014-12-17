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
public slots:
  virtual void resizeEvent(QResizeEvent *event);


private slots:



    void on_tableWidget_activated(const QModelIndex &index);




    void personstable();

    void computerstable();

    void cleartable();

    void _clickHeader(int col);




    //

private:

    bool asc = true;

    Ui::database *ui;
    Insertcomputer *insertcomp;
    ScientistRepository scientistRepository;
    ScienceService scienceService;

    list<Scientist> currentScientists;

    void fillPersonTable();
    void fillComputerTable();
};

#endif // DATABASE_H
