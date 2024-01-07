#include "ajouterprod.h"
#include "ui_ajouterprod.h"

AjouterProd::AjouterProd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjouterProd)
{
    ui->setupUi(this);
}

AjouterProd::~AjouterProd()
{
    delete ui;
}

void AjouterProd::on_pushButton_clicked()
{
    QString IdProd = ui->lineEdit->text();
    QString NomProd = ui->lineEdit_2->text();
    QString Prix = ui->lineEdit_3->text();
    QString Qte = ui->lineEdit_4->text();

    ConnectOpen();

    QSqlQuery Query;

    Query.prepare("INSERT INTO ProduitTable (IdProduit, Nom, Prix, Qte) VALUES (:id, :nom, :prix, :qte)");

    Query.bindValue(":id", IdProd);
    Query.bindValue(":nom", NomProd);
    Query.bindValue(":prix", Prix);
    Query.bindValue(":qte", Qte);

    if (Query.exec()) {
        ui->label_5->setText("Insertion faite!!");
        ConnectClose();
    } else {
        qDebug() << "Error executing query:" << Query.lastError().text();
        ui->label_5->setText("Insertion erroné!!");

    }



}

