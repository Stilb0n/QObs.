#include "mainwindow.h"
#include <iostream>
#include <fstream>
#include "fileeditor.cpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  //  MainWindow w;
   // w.show();

    setlocale(LC_ALL, "Russian");

        FileEditor obj("C:\\101\\infiile.txt");
        EditChecker a1;
        ExsistingChecker b;
        observer c;
        obj.Attach(&a1);
        obj.Attach(&b);
        obj.Attach(&c);
    //	obj.OpenFile("C:\\101\\infile.txt");

        obj.Write("faaaf");
//QLabel* label2 = new QLabel("Файл не сущетсвует");
//label2->show();
  return a.exec();
        //"C:\\101\\infile.txt"
}
