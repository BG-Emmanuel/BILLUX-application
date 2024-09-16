#include "login.h"
#include "ui_login.h"
#include <QIcon>
#include <QMessageBox>
#include <QRegularExpression>

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    appdb = QSqlDatabase::addDatabase("QSQLITE");
    appdb.setDatabaseName("C:/Users/EUROPEONLINE/Desktop/BILLUX_/database/appdb.db");
    loadStyle();
    if (!appdb.open()) {
        qDebug() << "Failed to connect to factdb: " << appdb.lastError().text();
    }
}

Login::~Login()
{
    delete ui;
}

void Login::loadStyle(){
    if(!appdb.open()){
        qDebug()<<"Connection Failed";

        return;
    }


    ui->label_4->setStyleSheet("QLabel { color: rgb(88, 88, 92); }");

    ui->groupBox->setStyleSheet(
        "QGroupBox {"           // General border around the group box
        //"border: 2px solid lightblue;"
        "background-color: rgb(66, 158, 245);"
        //"background-image: url(C:/Users/EUROPEONLINE/Desktop/BILLUX_/image/9385289.png);"
        "}"
        );
    ui->groupBox_2->setStyleSheet(
        "QGroupBox {"           // General border around the group box
        //"border: 2px solid lightblue;"
        "background-color: rgb(230, 231, 232);"
        //"background-image: url(C:/Users/EUROPEONLINE/Desktop/BILLUX_/image/blue-and-grey-glossy-corporate-abstract-background-vector.jpg);"
        "}"
        );
    ui->groupBox_3->setStyleSheet(
        "QGroupBox {"
        "background-image: url(C:/Users/EUROPEONLINE/Desktop/BILLUX_/image/welcome7.jpg);"
        "background-position: center;"
        "background-repeat: no-repeat;"
        "border-bottom-left-radius: 13px;"      // Rounding the top-left corner
        "border-top-left-radius: 13px;"
        "background-size: 30px 30px;"
        "}"
        );
    ui->groupBox_4->setStyleSheet(
        "QGroupBox {"           // General border around the group box
        //"border: 2px solid lightblue;"
        "background-color: rgb(242, 244, 245);"
        "border-bottom-right-radius: 13px;"      // Rounding the top-left corner
        "border-top-right-radius: 13px;"
        //"background-image: url(C:/Users/EUROPEONLINE/Desktop/BILLUX_/image/9385289.png);"
        "}"
        );
    ui->groupBox_5->setStyleSheet(
        "QGroupBox {"           // General border around the group box
        //"border: 2px solid lightblue;"
        "background-color: rgb(66, 158, 245);"
        "    border-radius: 70px;"
        //"background-image: url(C:/Users/EUROPEONLINE/Desktop/BILLUX_/image/9385289.png);"
        "}"
        );
    ui->groupBox_6->setStyleSheet(
        "QGroupBox {"           // General border around the group box
        //"border: 2px solid lightblue;"
        "background-color: rgb(66, 158, 245);"
        "    border-radius: 30px;"
        //"background-image: url(C:/Users/EUROPEONLINE/Desktop/BILLUX_/image/9385289.png);"
        "}"
        );
    ui->groupBox_7->setStyleSheet(
        "QGroupBox {"           // General border around the group box
        //"border: 2px solid lightblue;"
        "background-color: rgb(66, 158, 245);"
        "    border-radius: 30px;"
        //"background-image: url(C:/Users/EUROPEONLINE/Desktop/BILLUX_/image/9385289.png);"
        "}"
        );


    ui->pushButton->setStyleSheet(
        "QPushButton {"
        "    background-color: rgb(66, 158, 245);"
        //"    border: 1px solid white;"
        "    border-radius: 5px;"
        "    color: white;"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->pushButton_2->setStyleSheet(
        "QPushButton {"
        "    background-color: rgb(242, 244, 245);"
        //"    border: 1px solid white;"
        "    border-radius: 5px;"
        "    color: rgb(66, 158, 245);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->lineEdit->setStyleSheet(
        "QLineEdit {"
        //"    background-color: rgb(242, 244, 245);"
        //"    border: 1px solid white;"
        "    border-radius: 5px;"
        "    color: rgb(141, 142, 143);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->lineEdit_2->setStyleSheet(
        "QLineEdit {"
        //"    background-color: rgb(242, 244, 245);"
        //"    border: 1px solid white;"
        "    border-radius: 5px;"
        "    color: rgb(141, 142, 143);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );


}


void Login::on_pushButton_clicked()
{

    //testing the datatype of input entered
    QString input4 = ui->lineEdit->text();
    // Check if the input is empty
    if (input4.isEmpty()) {
        QMessageBox::warning(nullptr, "Invalid Input", "The input field cannot be empty.");
        return;
    }
    // Define a regular expression that allows only letters (upper and lowercase)
    QRegularExpression regex2("^[A-Za-z ]+$");
    QRegularExpressionMatch match2 = regex2.match(input4);
    // Check if the input matches the regex
    if (!match2.hasMatch()) {
        QMessageBox::warning(nullptr, "Invalid Input", "Please enter alphabetic characters only.");
        ui->lineEdit->clear();
        return;
    }

    QString input = ui->lineEdit_2->text();
    // Check if the input is empty
    if (input.isEmpty()) {
        QMessageBox::warning(nullptr, "Invalid Input", "The input field cannot be empty.");
        return;
    }
    // Define a regular expression that allows only letters (upper and lowercase)
    QRegularExpression regex("^[A-Za-z0-9 ,.\\-_]+$");
    QRegularExpressionMatch match = regex.match(input);
    // Check if the input matches the regex
    if (!match.hasMatch()) {
        QMessageBox::warning(nullptr, "Invalid Input", "Please enter alphabetic characters only.");
        ui->lineEdit_2->clear();
        return;
    }



    QString username,password;
    username = ui->lineEdit->text();
    password = ui->lineEdit_2->text();

    if(!appdb.isOpen()){
        qDebug()<<"Connections Failed";
        return;
    }
    QSqlQuery qry;
    if(qry.exec("select * from newdt where name='"+username+"' and password='"+password+"'")){

        int count = 0;
        while(qry.next()){
            count++;
        }
        if(count==1){
            ui->label->setText("Correct");
            this->hide();
            //QString setString = ui->lineEdit->text();

            // Heap-allocated Profile object with a QString passed to its constructor
            Facturation f;
            QString setString = ui->lineEdit->text();
            f.setText(setString);  // Set the text
            f.loadData();          // Load data using the text
            //profile.setModal(true);
            //profile.exec();

            f.setModal(true);
            f.exec();

            /*QString setString = ui->lineEdit->text();

            // Create the second window and pass the text
            Profile *p = new Profile(setString, this);

            // Call the load function in the SecondWindow to use the passed text
            p->loadData();

            Facturation f;
            f.setModal(true);
            f.exec();*/


        }
        if(count>1)
            ui->label->setText("Duplicate");
        if(count<1)
            ui->label->setText("Not Correct");

    }

}

void Login::on_pushButton_2_clicked()
{   this->hide();
    Newowner n;
    n.setModal(true);
    n.exec();
}

