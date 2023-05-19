#include "pathwindow.h"
#include "ui_pathwindow.h"

PathWindow::PathWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PathWindow)
{
    ui->setupUi(this);
}

PathWindow::~PathWindow()
{
    delete ui;
}
