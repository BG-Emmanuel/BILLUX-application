#include "facturation.h"
#include "ui_facturation.h"

Facturation::Facturation(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Facturation)
{
    ui->setupUi(this);

    factdb =  QSqlDatabase::addDatabase("QSQLITE");
    factdb.setDatabaseName("C:/Users/Dell/Desktop/database/itemdb.db");

}

Facturation::~Facturation()
{
    delete ui;
}
/*void Facturation::setLineEdit(const QString &text) {
    ui->lineEdit_1->setText(text);
}*/
void Facturation::setLineEditText(const QString &text)
{
    ui->lineEdit_1->setText(text);
}
void Facturation::on_pushButton_clicked()
{
    if (!factdb.open()) {
        qDebug() << "Failed to connect to the database:" << factdb.lastError();
    }
    QSqlQuery query;
    QString columnName = "totalPrice";  // Replace with your actual column name
    QString tableName = "factdt";    // Replace with your actual table name

    // Construct the SQL query
    QString queryString = QString("SELECT SUM(%1) FROM %2").arg(columnName).arg(tableName);

    if (query.exec(queryString)) {
        if (query.next()) {
            double sum = query.value(5).toDouble();  // Get the sum from the result
            ui->label->setText(QString::number(sum));  // Set the sum to the label
        }
    } else {
        // Handle SQL error
        qDebug() << "Query failed:" << query.lastError();
        ui->label->setText("Error");
    }
}

