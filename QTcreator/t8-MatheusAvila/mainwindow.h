#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
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
    void on_actionVer_Pedidos_triggered();

    void on_actionAbout_triggered();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_pushclear2_clicked();

    void on_pushclear1_clicked();

    void on_save1_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void loadTextFile();
    void closeEvent (QCloseEvent *event);
};

#endif // MAINWINDOW_H
