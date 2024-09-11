#ifndef NEWOWNER_H
#define NEWOWNER_H

#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class Newowner;
}

class Newowner : public QDialog
{
    Q_OBJECT

public:
    explicit Newowner(QWidget *parent = nullptr);
    ~Newowner();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Newowner *ui;
    QSqlDatabase appdb;
    void loadData();
};

#endif // NEWOWNER_H
