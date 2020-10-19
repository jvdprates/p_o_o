#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>

using std::string;

class Pessoa {
    private:
        string nome;
        int idade;

    public:
        Pessoa():nome("Indefinido"), idade(0){};
        Pessoa(string pNome, int pIdade):nome(pNome), idade(pIdade){};
        string getNome() const;
        int getIdade() const;
        void setNome(string s);
        void setIdade(int n);
};

#endif