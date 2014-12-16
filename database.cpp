#include "database.h"
#include "ui_database.h"
#include "insertcomputer.h"
#include "insert.h"
#include "addconnection.h"
#include "scienceservice.h"
<<<<<<< HEAD
=======
#include "scientist.h"

>>>>>>> d46c2b6c865c0c8adccc5f02e84b15a2544f95cc

database::database(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::database)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(4);
    list<Scientist> currentScientists = scienceService.getAllScientists();
       int counter = 0;
    for(std::list<Scientist>::iterator iter = currentScientists.begin(); iter != currentScientists.end(); iter ++) {
           ui->tableWidget->insertRow(counter);
           ui->tableWidget->setItem(counter, 0, new QTableWidgetItem(QString::fromStdString(iter->getName())));
           ui->tableWidget->setItem(counter, 1, new QTableWidgetItem(QString::fromStdString(iter->getGender())));
           ui->tableWidget->setItem(counter, 2, new QTableWidgetItem(QString::fromStdString(iter->getDateOfBirth())));
           ui->tableWidget->setItem(counter, 3, new QTableWidgetItem(QString::fromStdString(iter->getDateOfDeath())));
           counter++;
        }



    ui->tableWidget->setColumnCount(4);
    list<Computer> currentComputer = scienceService.getAllComputers();
       int counter2 = 0;
    for(std::list<Computer>::iterator iter = currentComputer.begin(); iter != currentComputer.end(); iter ++) {
           ui->tableWidget->insertRow(counter);
           ui->tableWidget->setItem(counter2, 0, new QTableWidgetItem(QString::fromStdString(iter->getName())));
           ui->tableWidget->setItem(counter2, 1, new QTableWidgetItem(QString::fromStdString(iter->getYearBuilt())));
           ui->tableWidget->setItem(counter2, 2, new QTableWidgetItem(QString::number(iter->getType())));
           ui->tableWidget->setItem(counter2, 3, new QTableWidgetItem(QString::number(iter->getWasBuilt())));
           counter2++;
        }

    ui->Search_edit->setPlaceholderText("Search");

    //setCentralWidget(ui->tableWidget);  //setur þannig að tablewidget tekur mest alt plássið

    //setCentralWidget(ui->tableWidget);  //setur þannig að tablewidget tekur mest alt plássið

    //setCentralWidget(ui->tableWidget);  //setur þannig að tablewidget tekur mest alt plássið

    //  setCentralWidget(ui->tableWidget);  //setur þannig að tablewidget tekur mest alt plássið

    //  setCentralWidget(ui->tableWidget);  //setur þannig að tablewidget tekur mest alt plássið

    //  setCentralWidget(ui->tableWidget);  //setur þannig að tablewidget tekur mest alt plássið


}

database::~database()
{
    delete ui;
}

//database::start()
//
//int database::start()
//{

int database::start()
{

    //scienceservice.open();

    //scienceservice.open();

}

//void database::createToolBars()
    //{
  /*  //    fileToolBar = addToolBar(tr("File"));
        fileToolBar->addAction(newAct);
}*/


/*
void database::displayCurrentPersons()
{
   std::string search = ui->Search_edit->text().toStdString();
   std::list<Scientist> s = ScienceService.searchScientist(search);
    ui->display_all->setRowCount(s.size());
    ui->display_all->setColumnCount(4);


    }
}
*/

void database::on_tableWidget_activated(const QModelIndex &index)
{

}

void database::on_actionAdd_a_person_triggered()
{
    insert ins;
   ins.setModal(true);
   ins.exec();
}

void database::on_actionAdd_a_computer_triggered()
{
    insertcomp = new Insertcomputer(this);
    insertcomp->show();
}
