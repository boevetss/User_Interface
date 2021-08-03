#ifndef EMPLOY_H
#define EMPLOY_H
#include "dialogforemploy.h"

#include <QDialog>
#include <iostream>
#include <vector>
#include <memory>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <functional>
#include "dialogadddevice.h"
#include <QStandardItemModel>

namespace Ui {
class Employ;
}

class Employ : public QDialog
{
    Q_OBJECT

public:
    explicit Employ(QWidget *parent = nullptr);
    ~Employ();



private slots:
    void on_pushButton_clicked();
    void setTableDat();

private:
    void setTableData(int rowIndex, QVector<QString> inputData);
    Ui::Employ *ui;
    std::unique_ptr<DialogForEmploy> deviceEmploy;
    QStandardItemModel *csvModel;
};

#endif // EMPLOY_H
