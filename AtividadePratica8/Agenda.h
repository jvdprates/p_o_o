#ifndef AGENDA_H
#define AGENDA_H

#include <iostream>
#include <vector>
#include "Amigo.h"
#include "Conhecido.h"

using std::vector;

class Agenda{
    private:
        vector<Amigo> amigos;
        vector<Conhecido> conhecidos;
        int numAmigos;
        int numConhecidos;

    public:
        Agenda(int numero);
        vector<Amigo, Conhecido> getPessoas() const;
        int getnAmigos() const;
        int getnConhecidos() const;
        void addInformacoes();
        void imprimeAniversarios() const;
        void imprimeEmail() const;
};

#endif