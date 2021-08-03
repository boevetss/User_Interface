#ifndef USERS_H
#define USERS_H

#include <iostream>
#include <vector>
#include <memory>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <functional>
#include <QDialog>
#include "dialogadddevice.h"
#include <QStandardItemModel>

namespace Ui {
class Users;
}

class Users : public QDialog
{
    Q_OBJECT

public:
    explicit Users(QWidget *parent = nullptr);
    ~Users();

    Ui::Users* GetUI()
    {
        return ui;
    }

private slots:
    void on_pushButton_2_clicked();
    void setTableDat();
    void slotCustomMenuRequested(QPoint pos);
    void slotEditRecord();
    void slotRemoveRecord();
    void slotUpdateModel(QVector<QString> inputData);

private:
    void setTableData(int rowIndex, QVector<QString> inputData);
    Ui::Users *ui;
    std::unique_ptr<DialogAddDevice> deviceDialog;
    QStandardItemModel *csvModel;
};

#endif // USERS_H
