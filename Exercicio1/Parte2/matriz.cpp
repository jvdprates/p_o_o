#include "matriz.h"
#include <iostream>
#include <vector>

using std::cout;

//Parte 2.1
void MATRIZ_H::inicializaMatriz(Matriz &X, int ls, int cs)
{
    X.nLinhas = ls;
    X.nColunas = cs;

    X.m = new double *[ls];
    for (int i = 0; i < ls; i++)
    {
        X.m[i] = new double[ls];
        for (int j = 0; j < cs; j++)
        {
            X.m[i][j] = 0;
        }
    }
};

//Parte 2.2
void MATRIZ_H::apagaMatriz(Matriz &X)
{
    for (int i = 0; i < X.nLinhas; i++)
    {
        cout << "[";
        for (int j = 0; j < X.nColunas; j++)
        {
            if (j != X.nColunas - 1)
            {
                cout << X.m[i,j] << " ,";
            }
            else
            {

                cout << X.m[i, j];
            }
        }
        cout << "]";
    }
};

//Parte 2.3
void MATRIZ_H::transposta(Matriz &X){

};

//Parte 2.4
Matriz *MATRIZ_H::multiplica_por_cte(Matriz &X, double k){

};

//Parte 2.5
void MATRIZ_H::imprimeMatriz(Matriz &X){

};