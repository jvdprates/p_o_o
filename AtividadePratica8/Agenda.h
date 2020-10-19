#ifndef AGENDA_H
#define AGENDA_H

#include <iostream>
#include <vector>
#include "Amigo.h"
#include "Conhecido.h"

using std::vector;

class Agenda {
    private:
        vector<Pessoa, Conhecido, Amigo> pessoas;

    public:
        Agenda(int numero){};
        vector<Pessoa, Conhecido, Amigo> getPessoas() const;
        void addInformacoes();
        void imprimeAniversarios() const;
        void imprimeEmail() const;
};

#endif