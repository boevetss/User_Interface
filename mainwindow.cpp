#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include <stdio.h>
#include <QComboBox>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd("D:/study/4 cource/8 sem/vkr/voenmeh.bmp");
    QSize bkgn(800,600);
    bkgnd = bkgnd.scaled(bkgn, Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

}

MainWindow::~MainWindow()
{
    delete ui;
}

QVector<QString> MainWindow::input()
{
    QVector<QString> vec;
    vec.push_back(ui -> textEdit -> toPlainText());
    vec.push_back(ui -> lineEdit ->text());
    vec.push_back(ui -> comboBox ->currentText());
    return vec;
}


void MainWindow::on_pushButton_clicked()
{
    QVector<QString> pr = input();
    if (pr[2] == "Сотрудник УИТ" /*&& pr[1] == "users" && pr[0] !=""*/)
    {
        hide();
        QMessageBox::information(this, "Help!", "Вы успешно авторизовались!");
        users = new Users(this);
        users->show();
    }
    else if (pr[2] == "Руководство университета" /*&& pr[1] == "admin" && pr[0] !=""*/)
    {
        hide();
        QMessageBox::information(this, "Help!", "Вы успешно авторизовались!");
        admin = new Admin(this);
        admin->show();
    }
    else if (pr[2] == "Учебная часть"/* && pr[1] == "employ" && pr[0] !=""*/)
    {
        hide();
        QMessageBox::information(this, "Help!", "Вы успешно авторизовались!");
        employ = new Employ(this);
        employ->show();
        }
    else
        QMessageBox::information(this, "Help!", "Авторизация не выполнена! Проверьте введеные данные!");
}
