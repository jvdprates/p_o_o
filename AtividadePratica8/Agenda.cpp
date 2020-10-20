#include "Agenda.h"
#include <time.h>

using std::cout;
using std::endl;
using std::cin;

Agenda::Agenda(int numero): numAmigos(0), numConhecidos(0)
{
    int valor;
    srand(time(NULL));
    for(int i = 0; i < numero; i++)
    {
        valor = (rand() % 2) + 1;
        if(valor == 1)
        {
            this->numAmigos += 1;
        }
        else
        {
            this->numConhecidos += 1;
        }
    }
    for(int j = 0; j < this->numAmigos; j++){
        Amigo novoAmigo;
        this->amigos.push_back(novoAmigo);
    };
    for(int k = 0; k < this->numConhecidos; k++){
        Conhecido novoConhecido;
        this->conhecidos.push_back(novoConhecido);
    };
};

void Agenda::addInformacoes()
{
    string texto;
    int num;
    cout << "Primeiro os Amigos:" << endl << endl;
    for(int i = 0; i < this->numAmigos; i++)
    {
        cout << "Nome do Amigo: ";
        cin >> texto;
        this->amigos[i].setNome(texto);
        cout << "Idade do Amigo: ";
        cin >> num;
        this->amigos[i].setIdade(num);
        cout << "Aniversario no formato DIA/MES/ANO: ";
        cin >> texto;
        this->amigos[i].setAniversario(texto);
    }
    cout << endl << endl;
    cout << "Dados dos Conhecidos:" << endl << endl;
    for(int j = 0; j < this->numConhecidos; j++)
    {
        cout << "Nome do Conhecido: ";
        cin >> texto;
        this->conhecidos[j].setNome(texto);
        cout << "Idade do Conhecido: ";
        cin >> num;
        this->conhecidos[j].setIdade(num);
        cout << "Email: ";
        cin >> texto;
        this->conhecidos[j].setEmail(texto);
    }
};

void Agenda::imprimeAniversarios() const
{
    cout << "NOME --> ANIVERSARIO" << endl;
    for(int i = 0; i < this->numAmigos; i++)
    {
        cout << this->amigos[i].getNome();
        cout << " --> ";
        cout << this->amigos[i].getAniversario();
        cout << endl;
    }
}

void Agenda::imprimeEmail() const
{
    cout << "NOME --> EMAIL" << endl;
    for(int j = 0; j < this->numConhecidos; j++)
    {
        cout << this->conhecidos[j].getNome();
        cout << " --> ";
        cout << this->conhecidos[j].getEmail();
        cout << endl;
    }
};

int Agenda::getnAmigos() const
{
    return this->numAmigos;
};

int Agenda::getnConhecidos() const
{
    return this->numConhecidos;
};
