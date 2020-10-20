#ifndef AMIGO_H
#define AMIGO_H

#include <iostream>
#include "Pessoa.h"

class Amigo : public Pessoa{
    private:
        string aniversario;
    public:
        Amigo(): aniversario("indefinido"){Pessoa();};
        string getAniversario() const;
        void setAniversario(string s);
};

#endif