#include "modification.h"
#include "ui_modification.h"

modification::modification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modification)
{
    ui->setupUi(this);
}

modification::~modification()
{
    delete ui;
}

void modification::on_pushButton_clicked()
{
    AjouterProd conn;

    QString id = ui->lineEdit->text();
    QString Nom = ui->lineEdit_2->text();
    QString Prix = ui->lineEdit_3->text();
    QString Qte = ui->lineEdit_4->text();

    conn.ConnectOpen();

    QSqlQuery Query;
    Query.prepare("UPDATE ProduitTable SET Nom = :nom, Prix = :prix, Qte = :qte WHERE IdProduit = :id");

    Query.bindValue(":nom", Nom);
    Query.bindValue(":prix", Prix);
    Query.bindValue(":qte", Qte);
    Query.bindValue(":id", id);

    if (Query.exec()) {
        ui->label_5->setText("Bien faite!!");
        conn.ConnectClose();
    } else {
        qDebug() << "Error executing query:" << Query.lastError().text();
        ui->label_5->setText("Errone!!");

    }

}

