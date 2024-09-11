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
