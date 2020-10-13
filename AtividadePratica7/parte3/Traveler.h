#ifndef TRAVELER_H
#define TRAVELER_H

#include <iostream>
#include <string>

using std::string;

class Traveler{
    string mensagem;
public:
    Traveler(): mensagem(){};
    Traveler(string msg): mensagem(msg){};
    Traveler(const Traveler& that){this->mensagem = that.mensagem;}
    Traveler operator= (const Traveler &t){return Traveler(t.get_mensagem());}
    string get_mensagem()const {return this->mensagem;}
};

#endif