#include "users.h"
#include "ui_users.h"
#include <QAction>
#include <QMessageBox>
#include <QMenu>
#include <QFile>
#include <QTextStream>
#include <QDebug>

Users::Users(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Users)
{
    ui -> setupUi(this);
    deviceDialog = std::unique_ptr<DialogAddDevice>(new DialogAddDevice(this));
    deviceDialog -> setWindowTitle("Добавить Устройство");
    connect(deviceDialog.get(), &DialogAddDevice::accepted, this, &Users::setTableDat);

    ui->tableView -> setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(slotEditRecord()));
    connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotCustomMenuRequested(QPoint)));

    // Создаём модель данных для отображения таблицы из CSV файла
    csvModel = new QStandardItemModel(this);
    csvModel->setColumnCount(11);
    csvModel->setHorizontalHeaderLabels(QStringList() << "ПО" << "Лицензия" << "Срок" << "Статус" << "ТС" << "Название"  << "№" << "Место" << "Описание" << "№" <<"Сегмент сети");
    ui -> tableView -> setModel(csvModel);
    // Разрешаем выделение только одного элемента
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    // Разрешаем выделение построчно
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // растягиваем таблицу
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    // Открываем файл из ресурсов. Вместо данного файла
    // необходимо указывать путь к вашему требуемому файлу
    QFile file("D:/study/4 cource/8 sem/vkr/system/basa.csv");
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
    csvModel->setColumnCount(10);
    csvModel->setHorizontalHeaderLabels(QStringList() << "Название ТС" << "№" << "Лицензия" << "Срок" << "Статус"  << "Место" << "Описание" << "№" <<"Местоположение" << "Сегмент");
    ui -> tableView_2 -> setModel(csvModel);
    ui->tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_2->horizontalHeader()->setStretchLastSection(true);

    QFile file2("D:/study/4 cource/8 sem/vkr/system/info.csv");
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
    csvModel->setColumnCount(8);
    csvModel->setHorizontalHeaderLabels(QStringList() << "ФИО" << "Должность" << "ПО" << "Назначение" << "Количество" << "Местоположение" << "Статус заявки");
    ui -> tableView_3 -> setModel(csvModel);
    ui->tableView_3->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_3->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_3->horizontalHeader()->setStretchLastSection(true);
    QFile file3("D:/study/4 cource/8 sem/vkr/system/request.csv");
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
         file3.close();
    }
}

Users::~Users()
{
    delete ui;
    delete csvModel;
}

void Users::on_pushButton_2_clicked()
{
    deviceDialog -> exec();
}

void Users::slotCustomMenuRequested(QPoint pos)
{
    /* Создаем объект контекстного меню */
    QMenu * menu = new QMenu(this);
    /* Создаём действия для контекстного меню */
    QAction * editDevice = new QAction(("Редактировать"), this);
    QAction * deleteDevice = new QAction(("Удалить"), this);
    /* Подключаем СЛОТы обработчики для действий контекстного меню */
    connect(editDevice, SIGNAL(triggered()), this, SLOT(slotEditRecord()));     // Обработчик вызова диалога редактирования
    connect(deleteDevice, SIGNAL(triggered()), this, SLOT(slotRemoveRecord())); // Обработчик удаления записи
    /* Устанавливаем действия в меню */
    menu->addAction(editDevice);
    menu->addAction(deleteDevice);
    /* Вызываем контекстное меню */
    menu->popup(ui->tableView->viewport()->mapToGlobal(pos));
}

void Users::slotEditRecord()
{
    /* Также создаем диалог и подключаем его сигнал завершения работы к слоту обновления вида модели представления данных, но передаём
         в качестве параметров строку записи */

    std::unique_ptr<DialogAddDevice> addDeviceDialog(new DialogAddDevice(this));
    connect(addDeviceDialog.get(), &DialogAddDevice::inputChanged, this, &Users::slotUpdateModel);

    addDeviceDialog->setWindowTitle("Редактировать Устройство");
    addDeviceDialog->exec();
}

void Users::slotUpdateModel(QVector<QString> inputData)
{
    setTableData(ui->tableView->selectionModel()->currentIndex().row(), inputData);
}

void Users::slotRemoveRecord()
{
    int row = ui->tableView->selectionModel()->currentIndex().row();
    if(row >= 0)
    {
        if (QMessageBox::warning(this,"Удаление записи","Вы уверены, что хотите удалить эту запись?",
                                    QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
        {
            return;
        }
        else
        {
            if(!csvModel->removeRow(row))
            {
                QMessageBox::warning(this, "Уведомление","Не удалось удалить запись\n");
            }
            ui->tableView->setCurrentIndex(csvModel->index(-1, -1));
        }
   }
}

//slot
void Users::setTableDat()
{
    setTableData(-1, deviceDialog->GetInputData());
}

void Users::setTableData(int rowIndex, QVector<QString> inputData)
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

