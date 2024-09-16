#include "profile.h"
#include "ui_profile.h"
#include <QObject>


Profile::Profile(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Profile)
{
    ui->setupUi(this);
    // Connect the button click signal to the appropriate slot
    connect(ui->pushButton, &QPushButton::clicked, this, &Profile::on_pushButton_2_clicked);
    appdb = QSqlDatabase::addDatabase("QSQLITE");
    appdb.setDatabaseName("C:/Users/EUROPEONLINE/Desktop/database/appdb.db");

    if (!appdb.open()) {
        qDebug() << "Failed to connect to appdb: " << appdb.lastError().text();
        return;
    }
}


Profile::~Profile()
{
    delete ui;
}

void Profile::on_pushButton_2_clicked()
{
    // For example, retrieve data from line edits and print them
    QString name = ui->lineEdit->text();
    QString lastName = ui->lineEdit_2->text();
    QString phone = ui->lineEdit_3->text();
    QString email = ui->lineEdit_4->text();
    QString business = ui->lineEdit_5->text();

    // You can implement more actions here, such as validating or saving the data
    qDebug() << "Name:" << name;
    qDebug() << "Last name:" << lastName;
    qDebug() << "Phone:" << phone;
    qDebug() << "Email:" << email;
    qDebug() << "Business:" << business;
}
