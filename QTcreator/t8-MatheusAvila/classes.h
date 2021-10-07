#ifndef CLASSES_H
#define CLASSES_H
#include <string>
#include <QTextStream>

using namespace std;

class Cliente
{
private:
    QString m_name;
    QString m_telefone;
    QString m_adress;

public:
    Cliente() : m_name(""),  m_telefone(""), m_adress("") {};
    ~Cliente() {};
    Cliente(QString name, QString telefone, QString adress) : m_name(name), m_telefone(telefone), m_adress(adress) {};

    QString GetNome() const { return m_name; };
    QString GetTelefone() const { return m_telefone; };
    QString GetAdress() const { return m_adress; };
};

class Pedidos
{
protected:
    float m_valor;
    QString m_dataentrega;
    Cliente *m_cliente;

public:
    Pedidos() : m_cliente(NULL), m_valor(0), m_dataentrega("") {};
    ~Pedidos() {};
    Pedidos(Cliente *cliente, float valor, QString data) : m_cliente(cliente), m_valor(valor), m_dataentrega(data)  {};
    float operator--()
    {
        return m_valor;
    }
    QString operator++()
    {
        return m_dataentrega;
    }
    QString operator&()
    {
        return m_cliente->GetNome();
    }
    QString operator()()
    {
        return m_cliente->GetTelefone();
    }
    QString operator+()
    {
        return m_cliente->GetAdress();
    }
};

class Canecas : public Pedidos
{
protected:
    QString m_tema;
public:
    Canecas () : m_tema("") {};
    ~Canecas() {};
    Canecas (Cliente *cliente, float valor, QString data, QString tema) : Pedidos(cliente, valor=30, data), m_tema(tema) {};
    QString GetTema() const { return m_tema; };

};

class Agendas : public Pedidos
{
protected:
    QString m_capa;
public:
    Agendas () : m_capa("") {};
    ~Agendas() {};
    Agendas (Cliente *cliente, float valor, QString data, QString capa) : Pedidos(cliente, valor=60, data), m_capa(capa) {};
    QString GetCapa() const { return m_capa; };

};

class BoxPascoa : public Pedidos
{
protected:
    QString m_content;
public:
    BoxPascoa () : m_content("") {};
    ~BoxPascoa() {};
    BoxPascoa (Cliente *cliente, float valor, QString data, QString conteudo) : Pedidos(cliente, valor=55, data), m_content(conteudo) {};
    QString GetContent() const { return m_content; };

};

class BoxBirthday : public Pedidos
{
protected:
    QString m_nameage;
    QString m_tema;
public:
    BoxBirthday () : m_nameage(""), m_tema("") {};
    ~BoxBirthday() {};
    BoxBirthday (Cliente *cliente, float valor, QString data, QString nomeidade, QString tema) : Pedidos(cliente, valor=110, data), m_nameage(nomeidade), m_tema(tema) {};
    QString GetNameAndAge() const { return m_nameage; };
    QString GetTema() const { return m_tema; };

};


#endif // CLASSES_H
