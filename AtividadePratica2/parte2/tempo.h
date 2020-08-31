#include <iostream>
#ifndef Tempo_h
#define Tempo_h

class Tempo
{
private:
    //Guarda o valor de dias salvos no tempo
    int dia;
    //Guarda o valor de horas salvos no tempo
    int hora;
    //Guarda o valor de minutos salvos no tempo
    int min;
    //Guarda o valor de segundos salvos no tempo
    int seg;

public:
    //Construtor que cria tempo determinado
    Tempo(int = 0, int = 0, int = 0, int = 0); //Argumentos default
    //Destrutor padrao
    ~Tempo();
    //Corrige consistencia do tempo
    void checkConsis(Tempo &X);
    //Soma um tempo com outro
    Tempo sum(Tempo &A) const;
    //Imprime o tempo na tela
    void print() const;
    //Incrementa o tempo em n segundos
    void increment(int n, bool reverse);
};

#endif