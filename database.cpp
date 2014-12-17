#include "database.h"
#include "ui_database.h"
#include "insertcomputer.h"
#include "insert.h"
#include "addconnection.h"
#include "scienceservice.h"

#include "scientist.h"

void database::resizeEvent(QResizeEvent* event)
{

    ui->tableWidget->move((ui->treeView->x() + ui->treeView->width()) + 20 ,
                          ui->Search_edit->y() + 40);



   // qDebug() << this->width();
    ui->tableWidget->resize(this->width(), this->width());
    ui->tableWidget->resize((this->width() - (ui->tableWidget->x() + 30)),
                            (this->height() - (ui->tableWidget->y())));
    ui->Search_edit->move(( ui->tableWidget->x() + ui->tableWidget->width()) -
                            ui->Search_edit->width(), ui->Search_edit->y());

    ui->treeView->move(ui->treeView->x(), ui->tableWidget->y() + 20);

    for (int c = 0; c < ui->tableWidget->horizontalHeader()->count(); ++c)
    {
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(
            c, QHeaderView::Stretch);
    }
    ui->frame->resize(this->width(), ui->frame->height());
    ui->frame->move(-20, 0);

    ui->frame_persons->move(ui->tableWidget->x(),ui->tableWidget->y());
    ui->frame_persons->resize(ui->tableWidget->width(), ui->tableWidget->height());

    ui->frame_computers->move(ui->tableWidget->x(),ui->tableWidget->y());
    ui->frame_computers->resize(ui->tableWidget->width(), ui->tableWidget->height());

    ui->connectText->move(0, this->height() - (ui->connectText->height() + 20));

}


database::database(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::database)
{
    ui->setupUi(this);

    // ui->treeView->setModel(treemodel);
    ui->treeView->header()->hide();
    ui->treeView->setSelectionBehavior(QTreeView::SelectRows);
    ui->treeView->setAnimated(true);
    ui->treeView->setRootIsDecorated(false);

    ui->Search_edit->setPlaceholderText("Search");

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->verticalHeader()->hide();
    ui->tableWidget->hideColumn(0);
    ui->tableWidget->setShowGrid(false);


    ui->tableWidget->setSelectionMode( QAbstractItemView::SingleSelection );


    ui->frame->hide();
    ui->frame_persons->hide();
    ui->frame_computers->hide();

    connect(ui->tableWidget->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(_clickHeader(int)));


    fillPersonTable();
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

/*void database::on_actionAdd_a_person_triggered()
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
*/
void database::personstable()
{
    cleartable();
    fillPersonTable();

}

void database::computerstable()
{

    cleartable();
    fillComputerTable();

}

void database::cleartable()
{

    ui->tableWidget->clearContents();
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);


}

void database::_clickHeader(int col){
    if (asc)
    {
            ui->tableWidget->sortByColumn(col, Qt::AscendingOrder);
            asc = false;
    }
    else
    {
        ui->tableWidget->sortByColumn(col,Qt::DescendingOrder);
        asc = true;

    }
    qDebug() << " Sort";
}


/*void database::on_Search_edit_computer_textChanged(const QString &arg1)
{

}*/
