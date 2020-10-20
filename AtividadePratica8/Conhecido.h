#ifndef CONHECIDO_H
#define CONHECIDO_H

#include <iostream>
#include "Pessoa.h"

class Conhecido : public Pessoa{
    private:
        string email;
    public:
        Conhecido(): email("indefinido"){Pessoa();};
        string getEmail() const;
        void setEmail(string s);
};

#endif