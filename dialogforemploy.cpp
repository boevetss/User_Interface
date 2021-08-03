#include "dialogforemploy.h"
#include "ui_dialogforemploy.h"

DialogForEmploy::DialogForEmploy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogForEmploy)
{
    ui->setupUi(this);
}

QVector<QString> DialogForEmploy::input()
{
    QVector<QString> vec;
    vec.push_back(ui -> lineEdit -> text());
    vec.push_back(ui -> lineEdit_2 -> text());
    vec.push_back(ui -> lineEdit_3 -> text());
    vec.push_back(ui -> lineEdit_4 -> text());
    vec.push_back(ui -> spinBox -> text());
    vec.push_back(ui -> lineEdit_6 -> text());
    return vec;
}

DialogForEmploy::~DialogForEmploy()
{
    delete ui;
}

void DialogForEmploy::on_pushButton_clicked()
{
    emit inputChanged(input());
    this->accept();
}

void DialogForEmploy::on_pushButton_2_clicked()
{
    this->reject();
}
