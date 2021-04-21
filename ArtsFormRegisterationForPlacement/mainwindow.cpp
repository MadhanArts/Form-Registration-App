#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QFileDialog>

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
    if(ui->lineEdit->text() == "")
    {
        QMessageBox::information(this, "Form", "Enter Name...");
        return;
    }
    if(ui->lineEdit_4->text() == "")
    {
        QMessageBox::information(this, "Form", "Enter Register Number...");
        return;
    }
    if(ui->lineEdit_3->text() == "")
    {
        QMessageBox::information(this, "Form", "Enter Email...");
        return;
    }
    else
    {
        QRegularExpression re("^[a-zA-Z0-9+_.-]+@[a-zA-Z0-9.-]+$");
        QRegularExpressionMatch match = re.match(ui->lineEdit_3->text());
        bool hasMatch = match.hasMatch();
        if (!hasMatch)
        {
           QMessageBox::information(this,"Form","Invalid Email Format");
           return;
        }
    }
    if(ui->plainTextEdit->toPlainText() == "")
    {
        QMessageBox::information(this, "Form", "Intro is Missing...");
        return;
    }

    QMessageBox::information(this, "Form", ui->lineEdit->text() + " is successfully registered");
}

void MainWindow::on_pushButton_3_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open Resume", "C://", "PDF File(*.pdf)");
}
