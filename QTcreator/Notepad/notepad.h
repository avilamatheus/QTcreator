#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class NotePad; }
QT_END_NAMESPACE

class NotePad : public QMainWindow
{
    Q_OBJECT

public:
    NotePad(QWidget *parent = nullptr);
    ~NotePad();

private slots:
    void on_quitButton_clicked();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

private:
    Ui::NotePad *ui;
};
#endif // NOTEPAD_H
