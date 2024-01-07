#ifndef SPPRESSION_H
#define SPPRESSION_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "ajouterprod.h"

namespace Ui {
class Sppression;
}

class Sppression : public QDialog
{
    Q_OBJECT

public:
    explicit Sppression(QWidget *parent = nullptr);
    ~Sppression();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Sppression *ui;
};

#endif // SPPRESSION_H
