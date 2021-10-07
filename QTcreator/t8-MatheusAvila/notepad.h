#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QDialog>

namespace Ui {
class Notepad;
}

class Notepad : public QDialog
{
    Q_OBJECT

public:
    explicit Notepad(QWidget *parent = nullptr);
    ~Notepad();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Notepad *ui;
};

#endif // NOTEPAD_H
