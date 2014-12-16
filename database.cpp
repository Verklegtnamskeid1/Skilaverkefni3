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

    ui->Search_edit->setPlaceholderText("Search for a person...");
    ui->Search_edit_computer->setPlaceholderText("Search for a computer...");

}

void database::fillPersonTable(){
    ui->tableWidget->clearContents();
    QStringList personheader;
    personheader << "ID" << "Name" << "Gender" << "Year born" << "Year dead";
    ui->tableWidget->setColumnCount(5);

    ui->tableWidget->setHorizontalHeaderLabels(personheader);
    ui->tableWidget->setColumnHidden(0, true);
    currentScientists = scienceService.getAllScientists();
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
    ui->Search_edit->show();
    ui->Search_edit_computer->hide();
    ui->Search_edit_computer->clear();
    ui->tableWidget->clearContents();
    fillPersonTable();

}

void database::on_pushButton_computers_clicked()
{
    ui->Search_edit_computer->show();
    ui->Search_edit->hide();
    ui->Search_edit->clear();
    ui->tableWidget->clearContents();
    fillComputerTable();

}

void database::on_pushButton_clicked()
{
    ui->Search_edit->hide();
    ui->Search_edit_computer->hide();

    ui->tableWidget->clearContents();
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);


}

void database::on_Search_edit_textChanged(const QString &arg1)
{
    ui->tableWidget->clear();
    int add = 0;
    for(std::list<Scientist>::iterator iter = currentScientists.begin(); iter != currentScientists.end(); iter ++) {
        Scientist tempScientist = (*iter);
        std::string searchStr = ui->Search_edit->text().toStdString();

        if(currentScientists[i] == searchStr) {
            ui->tableWidget->setItem(....);
            currentDisplayedScientists.push_back(currentScientists[i]);
        }

        qDebug() << add;
        ++add;
    }
}

void database::on_Search_edit_computer_textChanged(const QString &arg1)
{

}
