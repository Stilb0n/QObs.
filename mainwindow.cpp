#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pathwindow.h"
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
