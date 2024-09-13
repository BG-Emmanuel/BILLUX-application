#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>

#include<modif.h>

namespace Ui {
class Additem;
}

class Additem : public QDialog
{
    Q_OBJECT

public:
    explicit Additem(QWidget *parent = nullptr);
    ~Additem();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Additem *ui;
    QSqlDatabase appdb;
};

#endif // ADDITEM_H
