#include "sppression.h"
#include "ui_sppression.h"

Sppression::Sppression(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sppression)
{
    ui->setupUi(this);
    AjouterProd conn;
    if (conn.ConnectOpen())
       qDebug() << "Connectee";
    else
        qDebug() << "Non connecte";
}

Sppression::~Sppression()
{
    delete ui;
}

void Sppression::on_pushButton_clicked()
{
        AjouterProd conn;
        QString Id = ui->lineEdit->text();


        conn.ConnectOpen();

       QSqlQuery* Query = new QSqlQuery(conn.database);
       Query->prepare("SELECT IdProduit, Nom, Prix, Qte FROM ProduitTable WHERE IdProduit ='"+Id+"' ");
       if (Query->exec()){
           ui->label_2->setText("Suppression du produit est faite");
       }
       else {
           ui->label_2->setText("Probleme");
       }


       conn.ConnectClose();
}

