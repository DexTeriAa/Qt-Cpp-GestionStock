#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButton_clicked()
{

    ajoutP = new AjouterProd(this);
    ajoutP->show();
}


void MainWindow::on_pushButton_3_clicked()
{

    afficher = new Affichage(this);
    afficher->show();
}


void MainWindow::on_pushButton_4_clicked()
{
    supprimer = new Sppression(this);
    supprimer->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    modifier = new modification(this);
    modifier->show();
}

