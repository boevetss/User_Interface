#ifndef ADMIN_H
#define ADMIN_H
#include "dialogforemploy.h"
#include <QDialog>
#include <iostream>
#include <vector>
#include <memory>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <functional>
#include <QStandardItemModel>

namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();


private slots:
    void on_pushButton_clicked();



private:
    Ui::Admin *ui;
    QStandardItemModel *csvModel;
};

#endif // ADMIN_H
