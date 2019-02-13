#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Значение по умолчанию
    ui->Info->setText("0");
    ui->Info->setReadOnly(true);
    ui->Info->setMaxLength(16);

    ui->Num_spinBox->setMaximum(65536);
    ui->Num_spinBox->setMinimum(-65536);

    num_10 = 0;

    ui->btnOk->setStyleSheet("QPushButton { background-color: lightgreen;}");

}
//============================================================
MainWindow::~MainWindow()
{
    delete ui;
}
//============================================================
// Обработка преобразования в двоичную систему
void MainWindow::on_btnOk_clicked()
{
    num_10 = ui->Num_spinBox->text().toInt();

    QString r;

    for (int i = 0; i < 16; i++)
    {
        r = ((num_10 & (1<<i))? "1" : "0") + r;
     }

    ui->Info->setText(r);

//    ui->Info->setText(QString("%1").arg(num_10,8,2, QLatin1Char('0')));

}
//============================================================
