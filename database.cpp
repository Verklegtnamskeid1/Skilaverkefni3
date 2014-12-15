#include "database.h"
#include "ui_database.h"
#include "insertcomputer.h"
#include "insert.h"
#include "addconnection.h"
#include "scienceservice.h"



database::database(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::database)
{
    ui->setupUi(this);
    ui->Search_edit->setPlaceholderText("Search");

    //  setCentralWidget(ui->tableWidget);  //setur þannig að tablewidget tekur mest alt plássið
<<<<<<< HEAD
 //  setCentralWidget(ui->tableWidget);  //setur þannig að tablewidget tekur mest alt plássið
=======


  //  setCentralWidget(ui->tableWidget);  //setur þannig að tablewidget tekur mest alt plássið
>>>>>>> fdaf210c9d5b4c82d3b0c5e0ff8fefa98f38c8ac

}

database::~database()
{
    delete ui;
}


//database::start()
//
//int database::start()
//{
<<<<<<< HEAD
=======

int database::start()
{
>>>>>>> fdaf210c9d5b4c82d3b0c5e0ff8fefa98f38c8ac

    // scienceservice.open();

  //  scienceservice.open();

//}

//void database::createToolBars()
  //  {
  /*  //    fileToolBar = addToolBar(tr("File"));
        fileToolBar->addAction(newAct);
}*/
<<<<<<< HEAD
=======

>>>>>>> fdaf210c9d5b4c82d3b0c5e0ff8fefa98f38c8ac
/*void database::displayCurrentPersons()

/*
void database::displayCurrentPersons()
<<<<<<< HEAD
=======

>>>>>>> fdaf210c9d5b4c82d3b0c5e0ff8fefa98f38c8ac
{
   std::string search = ui->Search_edit->text().toStdString();
   std::list<Scientist> s = ScienceService.searchScientist(search);
    ui->display_all->setRowCount(s.size());
    ui->display_all->setColumnCount(4);

        for (unsigned int i = 0; i < currentPersons.size(); i++) {
        ui->display_all->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(currentPersons[i].getName())));
       ui->display_all->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(currentPersons[i].getBirthyear())));
       ui->display_all->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(currentPersons[i].getDeathyear())));
        ui->display_all->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(currentPersons[i].getGender())));
    }
}
*/

<<<<<<< HEAD




=======
>>>>>>> fdaf210c9d5b4c82d3b0c5e0ff8fefa98f38c8ac
void database::on_tableWidget_activated(const QModelIndex &index)
{


 }





void database::on_listWidget_activated(const QModelIndex &index)
{

}

void database::on_listWidget_2_activated(const QModelIndex &index)
{
<<<<<<< HEAD
   }
void database::on_listWidget_clicked(const QModelIndex &index)
{
=======
    addconnection addcon;
    addcon.setModal(true);
    addcon.exec();
}
>>>>>>> fdaf210c9d5b4c82d3b0c5e0ff8fefa98f38c8ac

void database::on_listWidget_clicked(const QModelIndex &index)
{
     insert ins;
    ins.setModal(true);
    ins.exec();
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
