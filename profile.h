#ifndef PROFILE_H
#define PROFILE_H

#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>


namespace Ui {
class Profile;
}

class Profile : public QDialog
{
    Q_OBJECT

public:
    explicit Profile(QWidget *parent = nullptr);
    ~Profile();
    void loadData();
    void setText(const QString &text);


private slots:

    void on_pushButton_2_clicked();

private:
    Ui::Profile *ui;
    QString receivedText;
    QSqlDatabase appdb;
    QString dataText;
};

#endif // PROFILE_H
