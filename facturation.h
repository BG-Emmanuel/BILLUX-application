#ifndef FACTURATION_H
#define FACTURATION_H

#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>
#include <QPushButton>
#include<item.h>

namespace Ui {
class Facturation;
}

class Facturation : public QDialog
{
    Q_OBJECT

public:
    explicit Facturation(QWidget *parent = nullptr);
    ~Facturation();
    void setLineEditText(const QString &text);


private slots:
    void on_pushButton_clicked();


private:
    Ui::Facturation *ui;
    QSqlDatabase factdb;
};

#endif // FACTURATION_H
