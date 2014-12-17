#include "insert.h"
#include "ui_insert.h"
#include <QMessageBox>

insert::insert(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::insert)
{
    ui->setupUi(this);
    ui->lineEdit_nameperson->setPlaceholderText("For example billibob");
    ui->lineEdit_genderperson->setPlaceholderText("Male or female");
    ui->lineEdit_yearbornperson->setPlaceholderText("Add BC if your jesus");
    ui->lineEdit_yeardeathperson->setPlaceholderText("3000 if your terminator");
    //ui->search2->setPlaceholderText("Search");
}

insert::~insert()
{
    delete ui;
}

void insert::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{

}
/*
 * Okkur datt í hug að hafa þetta svona með insert gluggann til að byrja með í staðinn fyrir að hafa listann
 * að hafa insert gluggann sem poppar upp eins einfaldan og hægt er. Svo er ýtt bara á submit og eftir það
 * opnast aðalvalmyndin aftur  með listanum og öllum valmyndum.*/

void insert::on_lineEdit_nameperson_cursorPositionChanged(int arg1, int arg2)
{

}


/*void insert::on_pushButton_insert_clicked()
{

//void insert::on_pushButton_insert_clicked()
//{
/*

void insert::on_pushButton_insert_clicked()
{
if (addpersonIsValid())
{
}
/*

{
    clearinsertErrors();
    std::string name = ui->lineEdit_nameperson->text().toStdstring();
    std::string gender = ui->lineEdit_genderperson->text().toStdString();
    std::string yearborn = ui->lineEdit_yearbornperson->text().toStdString();
    std::string yearofdeath = ui->lineEdit_yeardeathperson->text();
    (Person(name,gender,yearborn,yearofdeath)
}
}

*/


/*

bool insert::addpersonIsValid()
{

    ui->label_error_name->setText("");
    ui->label_error_gender->setText("");
    ui->label_error_yearborn->setText("");
    ui->label_error_yearofdeath->setText("");
    bool isValid= true;
    if (ui->lineEdit_nameperson->text().isEmpty())
    {
        ui->label_error_name->setText("Name cannot be empty");
        isValid = false;
    }
    if (ui->lineEdit_genderperson->text().isEmpty())
    {
        ui->label_error_gender->setText("Gender cannot be empty");
            isValid = false;
    }
    if (ui->lineEdit_yearbornperson->text().isEmpty())
    {
    ui->label_error_yearborn("Year born cannot be empty");
            isValid = false;
}


    return isValid;
}
*/
