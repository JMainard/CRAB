#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
///
/// \author Mainard Jérémy
/// \date 2019-11-20
///
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
