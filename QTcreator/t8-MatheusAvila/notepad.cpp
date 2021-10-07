#include "notepad.h"
#include "ui_notepad.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
QString pedidos1="../t8-MatheusAvila/pedidos.txt";

Notepad::Notepad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Notepad)
{
    ui->setupUi(this);
    setWindowTitle("Scrap Sweet Personalizados - Pedidos");
    ui->pushButton_2->setEnabled(false);
}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::on_pushButton_clicked()
{

    QFile arquivo(pedidos1);
    if(!arquivo.open(QFile::ReadOnly|QFile::Text))
    {
         QMessageBox::warning(this, "ERRO", "Erro ao abrir o arquivo");
    }
    QTextStream entrada(&arquivo);
    QString texto=entrada.readAll();
    ui->textEdit->setPlainText(texto);
    arquivo.close();
    ui->pushButton->setText("Arquivo Aberto.");
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_2->setText("Salvar");

}

void Notepad::on_pushButton_2_clicked()
{

    QFile arquivo(pedidos1);
    if(!arquivo.open(QFile::WriteOnly|QFile::Text))
    {
         QMessageBox::warning(this, "ERRO", "Erro ao abrir o arquivo");
    }
    QTextStream saida(&arquivo);
    QString texto=ui->textEdit->toPlainText();
    saida << texto;
    arquivo.flush();
    arquivo.close();
    ui->textEdit->clear();
    ui->pushButton->setText("Abrir");
    ui->pushButton_2->setText("Arquivo Salvo.");
    ui->pushButton_2->setEnabled(false);
}
