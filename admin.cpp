#include "admin.h"
#include "ui_admin.h"
#include "dialogforemploy.h"
#include <stdlib.h>
#include <stdio.h>
#include <QComboBox>
#include <QMessageBox>
#include <QDebug>
#include <QAction>
#include <QMenu>
#include <QFile>
#include <QTextStream>

Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);

    // Создаём модель данных для отображения таблицы из CSV файла
    csvModel = new QStandardItemModel(this);
    csvModel->setColumnCount(3);
    csvModel->setHorizontalHeaderLabels(QStringList() << "ФИО" << "Должность" << "Название ПО" << "Назначение ПО" << "Количество" << "Местоположение" << "Состояние заявки");
    ui -> tableView_1 -> setModel(csvModel);
    // Разрешаем выделение только одного элемента
    ui -> tableView_1 ->setSelectionMode(QAbstractItemView::SingleSelection);
    // Разрешаем выделение построчно
    ui -> tableView_1 ->setSelectionBehavior(QAbstractItemView::SelectRows);
    // растягиваем таблицу
    ui -> tableView_1 ->horizontalHeader()->setStretchLastSection(true);

    // Открываем файл из ресурсов. Вместо данного файла
    // необходимо указывать путь к вашему требуемому файлу
    QFile file("D:/study/4 cource/8 sem/vkr/system/request.csv");
    if ( !file.open(QFile::ReadOnly | QFile::Text) )
    {
        qDebug() << "File not exists";
    }
    else
    {
        // Создаём поток для извлечения данных из файла
        QTextStream in(&file);
        // Считываем данные до конца файла
        while (!in.atEnd())
        {
            // ... построчно
            QString line = in.readLine();
            // Добавляем в модель по строке с элементами
            QList <QStandardItem *> standardItemsList;
            // учитываем, что строка разделяется точкой с запятой на колонки
            for (QString item : line.split(";"))
            {
                standardItemsList.append(new QStandardItem(item));
            }
            csvModel->insertRow(csvModel->rowCount(), standardItemsList);
         }
         file.close();
    }
    csvModel = new QStandardItemModel(this);
    csvModel->setColumnCount(3);
    csvModel->setHorizontalHeaderLabels(QStringList() << "Название" << "Пользователь" << "Дата");
    ui -> tableView_2 -> setModel(csvModel);
    ui->tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_2->horizontalHeader()->setStretchLastSection(true);

    QFile file2("D:/study/4 cource/8 sem/vkr/system/plan.csv");
    if ( !file2.open(QFile::ReadOnly | QFile::Text) )
    {
        qDebug() << "File not exists";
    }
    else
    {
        QTextStream in(&file2);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QList <QStandardItem *> standardItemsList;
            for (QString item : line.split(";"))
            {
                standardItemsList.append(new QStandardItem(item));
            }
            csvModel->insertRow(csvModel->rowCount(), standardItemsList);
         }
         file2.close();
    }
    csvModel = new QStandardItemModel(this);
    csvModel->setColumnCount(3);
    csvModel->setHorizontalHeaderLabels(QStringList() << "Название ПО" << "Количество" << "Статус");
    ui -> tableView -> setModel(csvModel);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    QFile file3("D:/study/4 cource/8 sem/vkr/system/planinfo.csv");
    if ( !file3.open(QFile::ReadOnly | QFile::Text) )
    {
        qDebug() << "File not exists";
    }
    else
    {
        QTextStream in(&file3);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QList <QStandardItem *> standardItemsList;
            for (QString item : line.split(";"))
            {
                standardItemsList.append(new QStandardItem(item));
            }
            csvModel->insertRow(csvModel->rowCount(), standardItemsList);
         }
         file2.close();
    }
    csvModel = new QStandardItemModel(this);
    csvModel->setColumnCount(3);
    csvModel->setHorizontalHeaderLabels(QStringList() << "Название" << "Пользователь" << "Дата");
    ui -> tableView_3 -> setModel(csvModel);
    ui->tableView_3->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_3->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_3->horizontalHeader()->setStretchLastSection(true);

    QFile file4("D:/study/4 cource/8 sem/vkr/system/otchet.csv");
    if ( !file4.open(QFile::ReadOnly | QFile::Text) )
    {
        qDebug() << "File not exists";
    }
    else
    {
        QTextStream in(&file4);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QList <QStandardItem *> standardItemsList;
            for (QString item : line.split(";"))
            {
                standardItemsList.append(new QStandardItem(item));
            }
            csvModel->insertRow(csvModel->rowCount(), standardItemsList);
         }
         file2.close();
    }
    csvModel = new QStandardItemModel(this);
    csvModel->setColumnCount(3);
    csvModel->setHorizontalHeaderLabels(QStringList() << "Название ПО" << "Количество" << "Статус");
    ui -> tableView_4 -> setModel(csvModel);
    ui->tableView_4->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_4->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_4->horizontalHeader()->setStretchLastSection(true);

    QFile file5("D:/study/4 cource/8 sem/vkr/system/otchetinfo.csv");
    if ( !file5.open(QFile::ReadOnly | QFile::Text) )
    {
        qDebug() << "File not exists";
    }
    else
    {
        QTextStream in(&file5);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QList <QStandardItem *> standardItemsList;
            for (QString item : line.split(";"))
            {
                standardItemsList.append(new QStandardItem(item));
            }
            csvModel->insertRow(csvModel->rowCount(), standardItemsList);
         }
         file2.close();
    }
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_pushButton_clicked()
{

}
