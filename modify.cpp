#include "modif.h"
#include "ui_modif.h"
#include <QMessageBox>

Modif::Modif(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Modif)
{
    ui->setupUi(this);
    appdb = QSqlDatabase::addDatabase("QSQLITE");
    appdb.setDatabaseName("C:/Users/Dell/Desktop/database/appdb.db");
    loadData();
    if (!appdb.open()) {
        qDebug() << "Failed to connect to factdb: " << appdb.lastError().text();
    }
}
