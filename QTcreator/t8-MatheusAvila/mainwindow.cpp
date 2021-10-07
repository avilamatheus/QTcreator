#include "mainwindow.h"
#include "notepad.h"
#include "about.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "classes.h"
#include <vector>
#include <QDir>

vector<Cliente*>myListOfClientes;
vector<Canecas*>myListOfCanecas;
vector<Agendas*>myListOfAgendas;
vector<BoxPascoa*>myListOfBoxes;
vector<BoxBirthday*>myListOfBoxBirthday;

QString pedidos="../t8-MatheusAvila/pedidos.txt";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Scrap Sweet Personalizados");
    ui->line_temacaneca->setEnabled(false);
    ui->line_capa->setEnabled(false);
    ui->line_pascoa->setEnabled(false);
    ui->line_aniver1->setEnabled(false);
    ui->line_aniver2->setEnabled(false);
    ui->save1->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent (QCloseEvent *event)
{
    for(size_t i=0; i<myListOfCanecas.size(); i++)
    {
        delete myListOfCanecas.at(i);
    }
    for(size_t i=0; i<myListOfAgendas.size(); i++)
    {
        delete myListOfAgendas.at(i);
    }
    for(size_t i=0; i<myListOfBoxes.size(); i++)
    {
        delete myListOfBoxes.at(i);
    }
    for(size_t i=0; i<myListOfBoxBirthday.size(); i++)
    {
        delete myListOfBoxBirthday.at(i);
    }
    for(size_t i=0; i<myListOfClientes.size(); i++)
    {
        delete myListOfClientes.at(i);
    }
}

void MainWindow::on_actionVer_Pedidos_triggered()
{
     Notepad note;
     note.setModal(true);
     note.exec();
}

void MainWindow::on_actionAbout_triggered()
{
    About about;
    about.setModal(true);
    about.exec();
}

void MainWindow::on_radioButton_clicked()
{
    ui->line_temacaneca->setEnabled(true);
    ui->line_capa->setEnabled(false);
    ui->line_capa->clear();
    ui->line_pascoa->setEnabled(false);
    ui->line_pascoa->clear();
    ui->line_aniver1->setEnabled(false);
    ui->line_aniver2->setEnabled(false);
    ui->line_aniver1->clear();
    ui->line_aniver2->clear();
    ui->save1->setEnabled(true);
}

void MainWindow::on_radioButton_2_clicked()
{
    ui->line_temacaneca->setEnabled(false);
    ui->line_temacaneca->clear();
        ui->line_capa->setEnabled(true);
        ui->line_pascoa->setEnabled(false);
        ui->line_pascoa->clear();
        ui->line_aniver1->setEnabled(false);
        ui->line_aniver2->setEnabled(false);
        ui->line_aniver1->clear();
        ui->line_aniver2->clear();
        ui->save1->setEnabled(true);
}

void MainWindow::on_radioButton_3_clicked()
{
    ui->line_temacaneca->setEnabled(false);
    ui->line_temacaneca->clear();
        ui->line_capa->setEnabled(false);
        ui->line_capa->clear();
        ui->line_pascoa->setEnabled(true);
        ui->line_aniver1->setEnabled(false);
        ui->line_aniver2->setEnabled(false);
        ui->line_aniver1->clear();
        ui->line_aniver2->clear();
        ui->save1->setEnabled(true);
}

void MainWindow::on_radioButton_4_clicked()
{
    ui->line_temacaneca->setEnabled(false);
     ui->line_temacaneca->clear();
        ui->line_capa->setEnabled(false);
        ui->line_capa->clear();
        ui->line_pascoa->setEnabled(false);
        ui->line_pascoa->clear();
        ui->line_aniver1->setEnabled(true);
        ui->line_aniver2->setEnabled(true);
        ui->save1->setEnabled(true);
}


void MainWindow::on_pushclear2_clicked()
{
    ui->line_data->clear();
    ui->line_pascoa->clear();
    ui->line_temacaneca->clear();
    ui->line_capa->clear();
    ui->line_aniver1->clear();
    ui->line_aniver2->clear();
    ui->line_temacaneca->setEnabled(false);
    ui->line_capa->setEnabled(false);
    ui->line_pascoa->setEnabled(false);
    ui->line_aniver1->setEnabled(false);
    ui->line_aniver2->setEnabled(false);

}

void MainWindow::on_pushclear1_clicked()
{
    ui->line_nome->clear();
    ui->line_telefone->clear();
    ui->line_endereco->clear();
}


void MainWindow::on_save1_clicked()
{
    static int i = 0;
    if (ui->radioButton->isChecked() == true)
    {
        static int j = 0;
        QFile arquivo(pedidos);
        if(!arquivo.open(QFile::Append|QFile::Text))
        {
             QMessageBox::warning(this, "ERRO", "Erro ao abrir o arquivo");
        }
        QTextStream saida(&arquivo);
        QString nome = ui->line_nome->text();
        QString telefone = ui->line_telefone->text();
        QString endereco = ui->line_endereco->text();
        QString data = ui->line_data->text();
        QString tema = ui->line_temacaneca->text();
        float valor;
        myListOfClientes.push_back(new Cliente(nome, telefone, endereco));
        Canecas caneca(myListOfClientes.at(i), valor, data, tema);
        myListOfCanecas.push_back(new Canecas(caneca));
        saida << "---------------------------------------------------" << "\n";
        saida << "ITEM DO PEDIDO: CANECA" << "\n";
        saida << "Nome do Cliente: " << myListOfCanecas.at(j)->operator&() << "\n";
        saida << "Telefone do Cliente: " << myListOfCanecas.at(j)->operator()() << "\n";
        saida << "Endereco do Cliente: " << myListOfCanecas.at(j)->operator+() << "\n";
        saida << "Valor: " << myListOfCanecas.at(j)->operator--() << "\n";
        saida << "Data de entrega: " << myListOfCanecas.at(j)->operator++() << "\n";
        saida << "Tema da caneca: " << myListOfCanecas.at(j)->GetTema() << "\n";
        arquivo.flush();
        arquivo.close();
        QMessageBox::information(this,"Pedido feito e salvo em pedidos.txt", "ITEM DO PEDIDO: CANECA \nNome: "+nome+"\nTelefone: "+telefone+"\nEndereço: "+endereco+"\nValor: R$ 30,00""\nData de Entrega: "+data+"\nTema da Caneca: "+tema);
        j = j+1;
    }
    if (ui->radioButton_2->isChecked() == true)
    {
        static int x = 0;

        QFile arquivo(pedidos);
        if(!arquivo.open(QFile::Append|QFile::Text))
        {
             QMessageBox::warning(this, "ERRO", "Erro ao abrir o arquivo");
        }
        QTextStream saida(&arquivo);
        QString nome = ui->line_nome->text();
        QString telefone = ui->line_telefone->text();
        QString endereco = ui->line_endereco->text();
        QString data = ui->line_data->text();
        QString capa = ui->line_capa->text();
        float valor;
        myListOfClientes.push_back(new Cliente(nome, telefone, endereco));
         Agendas agenda(myListOfClientes.at(i), valor, data, capa);
        myListOfAgendas.push_back(new Agendas(agenda));
        saida << "---------------------------------------------------" << "\n";
        saida << "ITEM DO PEDIDO: AGENDA" << "\n";
        saida << "Nome do Cliente: " << myListOfAgendas.at(x)->operator&() << "\n";
        saida << "Telefone do Cliente: " << myListOfAgendas.at(x)->operator()() << "\n";
        saida << "Endereco do Cliente: " << myListOfAgendas.at(x)->operator+() << "\n";
        saida << "Valor: " << myListOfAgendas.at(x)->operator--() << "\n";
        saida << "Data de entrega: " << myListOfAgendas.at(x)->operator++() << "\n";
        saida << "Capa da agenda: " << myListOfAgendas.at(x)->GetCapa() << "\n";
        arquivo.flush();
        arquivo.close();
        QMessageBox::information(this,"Pedido feito e salvo em pedidos.txt", "ITEM DO PEDIDO: AGENDA \nNome: "+nome+"\nTelefone: "+telefone+"\nEndereço: "+endereco+"\nValor: R$ 60,00""\nData de Entrega: "+data+"\nCapa da Agenda: "+capa);
        x = x+1;
    }
    if (ui->radioButton_3->isChecked() == true)
    {
        static int z = 0;

        QFile arquivo(pedidos);
        if(!arquivo.open(QFile::Append|QFile::Text))
        {
             QMessageBox::warning(this, "ERRO", "Erro ao abrir o arquivo");
        }
        QTextStream saida(&arquivo);
        QString nome = ui->line_nome->text();
        QString telefone = ui->line_telefone->text();
        QString endereco = ui->line_endereco->text();
        QString data = ui->line_data->text();
        QString conteudo = ui->line_pascoa->text();
        float valor;
        myListOfClientes.push_back(new Cliente(nome, telefone, endereco));
        BoxPascoa box(myListOfClientes.at(i), valor, data, conteudo);
         myListOfBoxes.push_back(new BoxPascoa(box));
        saida << "---------------------------------------------------" << "\n";
        saida << "ITEM DO PEDIDO: CAIXA DE PASCOA" << "\n";
        saida << "Nome do Cliente: " << myListOfBoxes.at(z)->operator&() << "\n";
        saida << "Telefone do Cliente: " << myListOfBoxes.at(z)->operator()() << "\n";
        saida << "Endereco do Cliente: " << myListOfBoxes.at(z)->operator+() << "\n";
        saida << "Valor: " << myListOfBoxes.at(z)->operator--() << "\n";
        saida << "Data de entrega: " << myListOfBoxes.at(z)->operator++() << "\n";
        saida << "Conteudo da caixa: " << myListOfBoxes.at(z)->GetContent() << "\n";
        arquivo.flush();
        arquivo.close();
        QMessageBox::information(this,"Pedido feito e salvo em pedidos.txt", "ITEM DO PEDIDO: CAIXA DE PASCOA \nNome: "+nome+"\nTelefone: "+telefone+"\nEndereço: "+endereco+"\nValor: R$ 55,00""\nData de Entrega: "+data+"\nConteudo da Caixa: "+conteudo);
        z = z+1;
    }
    if (ui->radioButton_4->isChecked() == true)
    {
        static int y = 0;

        QFile arquivo(pedidos);
        if(!arquivo.open(QFile::Append|QFile::Text))
        {
             QMessageBox::warning(this, "ERRO", "Erro ao abrir o arquivo");
        }
        QTextStream saida(&arquivo);
        QString nome = ui->line_nome->text();
        QString telefone = ui->line_telefone->text();
        QString endereco = ui->line_endereco->text();
        QString data = ui->line_data->text();
        QString nomeidade = ui->line_aniver1->text();
        QString temabox = ui->line_aniver2->text();
        float valor;
        myListOfClientes.push_back(new Cliente(nome, telefone, endereco));
        BoxBirthday boxsurprise(myListOfClientes.at(i), valor, data, nomeidade, temabox);
        myListOfBoxBirthday.push_back(new BoxBirthday(boxsurprise));
        saida << "---------------------------------------------------" << "\n";
        saida << "ITEM DO PEDIDO: CAIXA SURPRESA DE ANIVERSARIO" << "\n";
        saida << "Nome do Cliente: " << myListOfBoxBirthday.at(y)->operator&() << "\n";
        saida << "Telefone do Cliente: " << myListOfBoxBirthday.at(y)->operator()() << "\n";
        saida << "Endereco do Cliente: " << myListOfBoxBirthday.at(y)->operator+() << "\n";
        saida << "Valor: " << myListOfBoxBirthday.at(y)->operator--() << "\n";
        saida << "Data de entrega: " << myListOfBoxBirthday.at(y)->operator++() << "\n";
        saida << "Nome e Idade do(a) aniversariante: " << myListOfBoxBirthday.at(y)->GetNameAndAge() << "\n";
        saida << "Tema da Caixa: " << myListOfBoxBirthday.at(y)->GetTema() << "\n";
        arquivo.flush();
        arquivo.close();
        QMessageBox::information(this,"Pedido feito e salvo em pedidos.txt", "ITEM DO PEDIDO: CAIXA SURPRESA DE ANIVERSARIO \nNome: "+nome+"\nTelefone: "+telefone+"\nEndereço: "+endereco+"\nValor: R$ 110,00""\nData de Entrega: "+data+"\nNome e Idade do(a) aniversariante: "+nomeidade+"\nTema da Caixa: "+temabox);
        y = y+1;
    }
    i = i+1;
    QMessageBox::StandardButton resposta=QMessageBox::question(this,"","Deseja manter os dados do cliente para realizar novo pedido no nome do mesmo ou apagar?", QMessageBox::Yes|QMessageBox::No);
    if(resposta==QMessageBox::Yes)
    {
        on_pushclear2_clicked();
    }
    else
    {
        on_pushclear1_clicked();
        on_pushclear2_clicked();
    }
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::StandardButton resposta=QMessageBox::question(this,"","Tem certeza que deseja fechar o programa?", QMessageBox::Yes|QMessageBox::No);
    if(resposta==QMessageBox::Yes)
    {
         QApplication::quit();
    }
}
