#ifndef PAGER_H
#define PAGER_H

#include <iostream>
#include <string>

using std::string;

class Pager{
    string mensagem;
public:
    Pager(): mensagem(){};
    Pager(string msg): mensagem(msg){};
    Pager(const Pager& that){this->mensagem = that.mensagem;}
    Pager operator=(const Pager &p){return Pager(p.get_mensagem());}
    string get_mensagem()const {return this->mensagem;}
};

#endif