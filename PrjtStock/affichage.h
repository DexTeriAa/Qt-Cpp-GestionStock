#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "ajouterprod.h"

namespace Ui {
class Affichage;
}

class Affichage : public QDialog
{
    Q_OBJECT

public:
    explicit Affichage(QWidget *parent = nullptr);
    ~Affichage();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Affichage *ui;

};

#endif // AFFICHAGE_H
