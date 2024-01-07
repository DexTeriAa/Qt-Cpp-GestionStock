#include "affichage.h"
#include "ui_affichage.h"

Affichage::Affichage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Affichage)
{
    ui->setupUi(this);
    AjouterProd conn;
    if (conn.ConnectOpen())
       qDebug() << "Connectee";
    else
        qDebug() << "Non connecte";

}


Affichage::~Affichage()
{
    delete ui;
}

void Affichage::on_pushButton_2_clicked()
{
    AjouterProd conn;
    QSqlQueryModel* model = new QSqlQueryModel();

    conn.ConnectOpen();

    QSqlQuery* Query = new QSqlQuery(conn.database);
    Query->prepare("SELECT IdProduit, Nom, Prix, Qte FROM ProduitTable");
    if (Query->exec()){
        ui->label_2->setText("Done");
    }
    else {
        ui->label_2->setText("Probleme");
    }
    model->setQuery(*Query);
    ui->tableView->setModel(model);

    conn.ConnectClose();
}


void Affichage::on_pushButton_3_clicked()
{
    AjouterProd conn;
    QString Id = ui->label_2->text();
    QSqlQueryModel* model = new QSqlQueryModel();

    conn.ConnectOpen();

    QSqlQuery* Query = new QSqlQuery(conn.database);
    Query->prepare("SELECT IdProduit, Nom, Prix, Qte FROM ProduitTable WHERE IdProduit = '"+Id+"'");
    if (Query->exec()){
        ui->label_2->setText("Done");
    }
    else {
        ui->label_2->setText("Probleme");
    }
    model->setQuery(*Query);
    ui->tableView->setModel(model);

    conn.ConnectClose();
}


void Affichage::on_pushButton_4_clicked()
{
    close();
}

