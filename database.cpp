#include "database.h"
#include "ui_database.h"
#include "insertcomputer.h"
#include "insert.h"
#include "addconnection.h"
#include "scienceservice.h"

#include "scientist.h"


database::database(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::database)
{
    ui->setupUi(this);

    ui->Search_edit->setPlaceholderText("Search");

}

void database::fillPersonTable(){
    ui->tableWidget->clearContents();
    QStringList personheader;
    personheader << "ID" << "Name" << "Gender" << "Year born" << "Year died";
    ui->tableWidget->setColumnCount(5);

    ui->tableWidget->setHorizontalHeaderLabels(personheader);
    ui->tableWidget->setColumnHidden(0, true);
    list<Scientist> currentScientists = scienceService.getAllScientists();
   int counter = 0;
    for(std::list<Scientist>::iterator iter = currentScientists.begin(); iter != currentScientists.end(); iter ++) {
           ui->tableWidget->insertRow(counter);
           ui->tableWidget->setItem(counter, 0, new QTableWidgetItem(QString::number(iter->getId())));
           ui->tableWidget->setItem(counter, 1, new QTableWidgetItem(QString::fromStdString(iter->getName())));
           ui->tableWidget->setItem(counter, 2, new QTableWidgetItem(QString::fromStdString(iter->getGender())));
           ui->tableWidget->setItem(counter, 3, new QTableWidgetItem(QString::fromStdString(iter->getDateOfBirth())));
           ui->tableWidget->setItem(counter, 4, new QTableWidgetItem(QString::fromStdString(iter->getDateOfDeath())));
           counter++;
        }
    ui->tableWidget->setRowCount(counter);
}

void database::fillComputerTable(){
    ui->tableWidget->clearContents();
    QStringList computerheader;
    QStringList horzHeaders = computerheader;
    computerheader << "ID" << "Name" << "Year built" << "Type" << "Was it built?";
    ui->tableWidget->setColumnCount(5);

    ui->tableWidget->setColumnHidden(0, true);
    ui->tableWidget->setHorizontalHeaderLabels(computerheader);
    list<Computer> currentComputer = scienceService.getAllComputers();
       int counter2 = 0;
    for(std::list<Computer>::iterator iter = currentComputer.begin(); iter != currentComputer.end(); iter ++) {
           ui->tableWidget->insertRow(counter2);
           ui->tableWidget->setItem(counter2, 0, new QTableWidgetItem(QString::number(iter->getId())));
           ui->tableWidget->setItem(counter2, 1, new QTableWidgetItem(QString::fromStdString(iter->getName())));
           ui->tableWidget->setItem(counter2, 2, new QTableWidgetItem(QString::fromStdString(iter->getYearBuilt())));
           ui->tableWidget->setItem(counter2, 3, new QTableWidgetItem(QString::number(iter->getType())));
           ui->tableWidget->setItem(counter2, 4, new QTableWidgetItem(QString::number(iter->getWasBuilt())));
           counter2++;
    }
        ui->tableWidget->setRowCount(counter2);
}

database::~database()
{
    delete ui;
}

int database::start()
{

}

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

void database::on_pushButton_persons_clicked()
{
    ui->tableWidget->clearContents();

    fillPersonTable();
}

void database::on_pushButton_computers_clicked()
{
    ui->tableWidget->clearContents();
    fillComputerTable();
}

void database::on_pushButton_clicked()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);


}
