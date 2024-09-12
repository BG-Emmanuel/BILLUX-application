#include "newowner.h"
#include "ui_newowner.h"

#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QRegExp>

Newowner::Newowner(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Newowner)
{
    ui->setupUi(this);
    appdb = QSqlDatabase::addDatabase("QSQLITE");
    appdb.setDatabaseName("C:/Users/dell/Desktop/Databases/appdb.db");
    if (!appdb.open()) {
        qDebug() << "Failed to connect to appdb: " << appdb.lastError().text();
    } else {
        loadData();
    }
}

Newowner::~Newowner()
{
    delete ui;
}

void Newowner::loadData(){
    ui->lineEdit->setText("Mice");
}

void Newowner::on_pushButton_clicked()
{
    QString name, lastName, enterpriseName, emailAddress, phone, password, confirmPassword;
    name = ui->lineEdit->text();
    lastName = ui->lineEdit_2->text();
    enterpriseName = ui->lineEdit_3->text();
    emailAddress = ui->lineEdit_4->text();
    phone = ui->lineEdit_5->text();
    password = ui->lineEdit_6->text();
    confirmPassword = ui->lineEdit_7->text();

    // Vérification des mots de passe
    if (password != confirmPassword) {
        QMessageBox::warning(this, tr("Erreur"), tr("Les mots de passe ne correspondent pas."));
        return;
    }

    // Vérification du numéro de téléphone (entiers uniquement)
    QRegExp phoneRegex("\\d+");
    if (!phoneRegex.exactMatch(phone)) {
        QMessageBox::warning(this, tr("Erreur"), tr("Le numéro de téléphone doit contenir uniquement des chiffres."));
        return;
    }

    // Vérification de l'adresse email
    QRegExp emailRegex("[\\w\\.]+@[\\w\\.]+\\.[a-z]{2,3}");
    if (!emailRegex.exactMatch(emailAddress)) {
        QMessageBox::warning(this, tr("Erreur"), tr("L'adresse email n'est pas valide."));
        return;
    }

    if (!appdb.isOpen()) {
        qDebug() << "Database connection failed!";
        return;
    }

    QSqlQuery qry;
    qry.prepare("INSERT INTO newdt(name, lastName, enterpriseName, emailAddress, phone, password, confirmPassword) "
                "VALUES (:name, :lastName, :enterpriseName, :emailAddress, :phone, :password, :confirmPassword)");
    qry.bindValue(":name", name);
    qry.bindValue(":lastName", lastName);
    qry.bindValue(":enterpriseName", enterpriseName);
    qry.bindValue(":emailAddress", emailAddress);
    qry.bindValue(":phone", phone);
    qry.bindValue(":password", password);
    qry.bindValue(":confirmPassword", confirmPassword);

    if (qry.exec()) {
        QMessageBox::information(this, tr("SAVED"), tr("DATA SAVED"));
    } else {
        QMessageBox::critical(this, tr("Error"), qry.lastError().text());
    }
}

void Newowner::on_pushButton_2_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    this->hide();
}
