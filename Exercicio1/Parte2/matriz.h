//matriz.h
#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct
{
    //Array bidimensional que salva os elementos da matriz.
    double **m;

    //Numero de linhas da matriz.
    int nLinhas;

    //Numero de colunas da matriz.
    int nColunas;

    //Cria uma nova matriz X preenchida com 0s.
    void inicializaMatriz(Matriz &X, int ls, int cs);

    //Libera a memoria ocupada pela matriz X.
    void apagaMatriz(Matriz &X);

    //transforma a matriz X em sua transposta.
    void transposta(Matriz &X);

    //Retorna matriz X multiplicada por K.
    Matriz multiplica_por_cte(Matriz &X, double k);

    //Imprime a matriz X no console.
    void imprimeMatriz(Matriz &X);

} Matriz;

#endif