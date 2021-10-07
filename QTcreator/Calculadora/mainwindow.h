#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Sum_clicked();

    void on_Subtraction_clicked();

    void on_Multiplication_clicked();

    void on_Division_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
