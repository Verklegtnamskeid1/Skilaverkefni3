#include "insert.h"
#include "ui_insert.h"

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
