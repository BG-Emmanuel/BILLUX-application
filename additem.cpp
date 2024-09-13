#include "additem.h"
#include "ui_additem.h"
#include <QMessageBox>

Additem::Additem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Additem)
{
    ui->setupUi(this);
    appdb = QSqlDatabase::addDatabase("QSQLITE");
    appdb.setDatabaseName("C:/Users/Dell/Desktop/database/appdb.db");
    if (!appdb.open()) {
        qDebug() << "Failed to connect to factdb: " << appdb.lastError().text();
    }
}
