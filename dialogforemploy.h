#ifndef DIALOGFOREMPLOY_H
#define DIALOGFOREMPLOY_H
#include <QDialog>
#include <QtSql/QSqlTableModel>
#include <QDataWidgetMapper>

namespace Ui {
class DialogForEmploy;
}

class DialogForEmploy : public QDialog
{
    Q_OBJECT

public:
    explicit DialogForEmploy(QWidget *parent = 0);
    ~DialogForEmploy();

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
    Ui::DialogForEmploy *ui;
};

#endif // DIALOGFOREMPLOY_H
