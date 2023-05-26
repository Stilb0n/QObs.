#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pathwindow.h"
#include "fileeditor.cpp"
#include <QString>
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
    PathWindow path_window;
    path_window.setModal(true);
    path_window.exec();

}

void MainWindow::on_pushButton_2_clicked()
{
    QString path2 = ui->path->text();
    QString TextIn;
      FileEditor obj1(path2.toStdString());

    EditChecker z1;
    ExsistingChecker x;
    observer y;
    obj1.Attach(&z1);
    obj1.Attach(&x);
    obj1.Attach(&y);
   TextIn = obj1.Write("faaaf");
    PathWindow path_window;
    path_window.setModal(true);
    path_window.exec();
}
