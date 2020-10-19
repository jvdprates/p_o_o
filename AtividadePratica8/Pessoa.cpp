#include "Pessoa.h"

string Pessoa::getNome() const{
    return this->nome;
}

int Pessoa::getIdade() const{
    return this->idade;
}

void Pessoa::setNome(string s){
    this->nome = s;
};

void Pessoa::setIdade(int n){
    this->idade = n;
};