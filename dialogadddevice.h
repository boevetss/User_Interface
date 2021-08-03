#ifndef DIALOGADDDEVICE_H
#define DIALOGADDDEVICE_H

#include <QDialog>
#include <QtSql/QSqlTableModel>
#include <QDataWidgetMapper>

namespace Ui {
class DialogAddDevice;
}

class DialogAddDevice : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddDevice(int row = -1, QWidget *parent = 0);
    explicit DialogAddDevice(QWidget *parent = 0);
    ~DialogAddDevice();

    QVector<QString> GetInputData()
    {
        return input();
    }

signals:
    void inputChanged(QVector<QString>);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    QVector<QString> input();

private:
    Ui::DialogAddDevice         *ui;
    QSqlTableModel              *model;
    QDataWidgetMapper           *mapper;
};

#endif // DIALOGADDDEVICE_H
