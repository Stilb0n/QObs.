#ifndef PATHWINDOW_H
#define PATHWINDOW_H

#include <QDialog>

namespace Ui {
class PathWindow;
}

class PathWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PathWindow(QWidget *parent = nullptr);
    ~PathWindow();

private:
    Ui::PathWindow *ui;
};

#endif // PATHWINDOW_H
