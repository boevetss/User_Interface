#include "employ.h"
#include "ui_employ.h"
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

Employ::Employ(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Employ)
{
    ui -> setupUi(this);
    deviceEmploy = std::unique_ptr<DialogForEmploy>(new DialogForEmploy(this));
    deviceEmploy -> setWindowTitle("Добавление заявки");
    connect(deviceEmploy.get(), &DialogAddDevice::accepted, this, &Employ::setTableDat);

    // Создаём модель данных для отображения таблицы из CSV файла
    csvModel = new QStandardItemModel(this);
    csvModel->setColumnCount(3);
    csvModel->setHorizontalHeaderLabels(QStringList() << "ФИО" << "Должность" << "Название По" << "Назначение ПО" << "Количество" << "Местоположение" << "Состояние заявки");
    ui -> tableView -> setModel(csvModel);
    // Разрешаем выделение только одного элемента
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    // Разрешаем выделение построчно
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // растягиваем таблицу
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

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
}

//slot
void Employ::setTableDat()
{
    setTableData(-1, deviceEmploy->GetInputData());
}

Employ::~Employ()
{
    delete ui;
}

void Employ::on_pushButton_clicked()
{
    deviceEmploy -> exec();
}

void Employ::setTableData(int rowIndex, QVector<QString> inputData)
{
    QAbstractItemModel* tableViewModel = ui -> tableView -> model();

    size_t curRowIndex;
    if(rowIndex == -1)
    {
        curRowIndex = tableViewModel->rowCount();
        tableViewModel -> insertRow(curRowIndex);
    }
    else
        curRowIndex = rowIndex;

    for (size_t i = 0; i < inputData.size(); ++i)
        tableViewModel -> setData(tableViewModel -> index(curRowIndex, i), inputData[i]);
}

