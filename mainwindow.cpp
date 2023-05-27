#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pathwindow.h"
#include "fileeditor.cpp"
#include <QString>
#include <QMessageBox>
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
    QString path2 = ui->path->text();

    FileEditor obj1(path2.toStdString());
    QString OUT;
    QString EDIT;
    EditChecker z1;
    ExsistingChecker x;
    observer y;
    obj1.Attach(&z1);
    obj1.Attach(&x);
    obj1.Attach(&y);
    obj1.Write("изменение");
        OUT = x.FEx;
    EDIT = z1.FEd;
    OUT = OUT + " " + EDIT;
    QMessageBox::information(this,"Проверка на существование",OUT);

}

void MainWindow::on_pushButton_2_clicked()
{
    QString path2 = ui->path->text();

      FileEditor obj1(path2.toStdString());
    QString OUT;
    EditChecker z1;
    ExsistingChecker x;
    observer y;
    obj1.Attach(&z1);
    obj1.Attach(&x);
    obj1.Attach(&y);

    OUT = x.FEx;
    QMessageBox::information(this,"Проверка на существование",OUT);
    /*PathWindow path_window;
    path_window.setModal(true);
    path_window.exec();*/
}
