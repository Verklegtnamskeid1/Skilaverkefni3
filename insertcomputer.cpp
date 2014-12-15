#include "insertcomputer.h"
#include "ui_insertcomputer.h"

Insertcomputer::Insertcomputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Insertcomputer)
{
    ui->setupUi(this);
    ui->lineEdit_namecomputer->setPlaceholderText("For example skynet");
    ui->lineEdit_type->setPlaceholderText("Terminator is a type");
    ui->lineEdit_wasitbuilt->setPlaceholderText("Yes or no question");
    ui->lineEdit_yearbuilt->setPlaceholderText("Btw skynet has not been built");
}

Insertcomputer::~Insertcomputer()
{
    delete ui;
}

void Insertcomputer::on_submit_computer_clicked()
{

}

void Insertcomputer::on_lineEdit_namecomputer_cursorPositionChanged(int arg1, int arg2)
{

}
