#ifndef MODIF_H
#define MODIF_H

#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>

#include<additem.h>

namespace Ui {
class Modif;
}

class Modif : public QDialog
{
    Q_OBJECT

public:
    explicit Modif(QWidget *parent = nullptr);
    ~Modif();

private slots:
    void on_listView_indexesMoved(const QModelIndexList &indexes);

    void on_listView_activated(const QModelIndex &index);

    void on_listView_2_activated(const QModelIndex &index);

private:
    Ui::Modif *ui;
    QSqlDatabase appdb;
    void loadData();
};

#endif // MODIF_H

