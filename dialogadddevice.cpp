#include "dialogadddevice.h"
#include "ui_dialogadddevice.h"

DialogAddDevice::DialogAddDevice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddDevice)
{
    ui->setupUi(this);
}

DialogAddDevice::DialogAddDevice(int row, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddDevice)
{
    if(row == -1)
    {
        model->insertRow(model->rowCount(QModelIndex()));
        mapper->toLast();
    }
    else
    {
        mapper->setCurrentModelIndex(model->index(row,0));
    }
}

DialogAddDevice::~DialogAddDevice()
{
    delete ui;
}

QVector<QString> DialogAddDevice::input()
{
    QVector<QString> vec;
    vec.push_back(ui -> textEdit -> toPlainText());
    vec.push_back(ui -> textEdit_2 -> toPlainText());
    vec.push_back(ui -> textEdit_3 -> toPlainText());
    return vec;
}

void DialogAddDevice::on_pushButton_clicked()
{
    emit inputChanged(input());
    this->accept();
}

void DialogAddDevice::on_pushButton_2_clicked()
{
    this->reject();
}
