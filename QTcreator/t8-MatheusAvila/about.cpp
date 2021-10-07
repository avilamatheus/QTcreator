#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    setWindowTitle("About");
    QPixmap pix("../t8-MatheusAvila/mats.jpg");
     int w = ui->label_picture->width();
     int h = ui->label_picture->height();
     ui->label_picture->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

About::~About()
{
    delete ui;
}
