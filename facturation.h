#ifndef FACTURATION_H
#define FACTURATION_H

#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Facturation;
}
QT_END_NAMESPACE

class Facturation : public QMainWindow
{
    Q_OBJECT

public:
    Facturation(QWidget *parent = nullptr);
    ~Facturation();
    void loadData();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Facturation *ui;
    QSqlDatabase appdb;
};
#endif // FACTURATION_H
