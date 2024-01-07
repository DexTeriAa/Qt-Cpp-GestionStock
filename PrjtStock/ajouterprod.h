#ifndef AJOUTERPROD_H
#define AJOUTERPROD_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>


namespace Ui {
class AjouterProd;
}

class AjouterProd : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase database;
       void ConnectClose()
       {
           database.close();
           database.removeDatabase(QSqlDatabase::defaultConnection);
       }
       bool ConnectOpen()
       {
           database = QSqlDatabase::addDatabase("QSQLITE");
           database.setDatabaseName("C:/Users/AIT KADDOUR/Desktop/database1/DBQt.db");
           if(!database.open())
           {
               qDebug()<<("Connexion errone");
               return false;
           }
           else
           {
               qDebug()<<("connection etablis");
               return true;
           }

       }

public:
    explicit AjouterProd(QWidget *parent = nullptr);
    ~AjouterProd();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AjouterProd *ui;
};

#endif // AJOUTERPROD_H
