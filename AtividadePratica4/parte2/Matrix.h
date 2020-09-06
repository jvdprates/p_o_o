#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>

using std::ifstream;

class Matrix
{
private:
    double **m; // m é um array 2D a ser implementado como um pointer de pointers
    int nRows;  // Numero de linhas
    int nCols;  // Numero de colunas

public:
    // Constructors

    // Contrutor default - cria uma matriz vazia com nRows = nCols = 0
    Matrix();
    // Contrutor parametrico 1 - cria uma matriz com nRows  = rows, nCols = cols e
    // com todos os elementos iguais a 0.0 (double)
    Matrix(int rows, int cols, const double &value = 0.0);
    // Construtor parametrico 2 - cria uma matriz com os dados fornecidos pelo arquivo texto myFile.
    Matrix(ifstream &myFile);
    // Contrutor de copia
    Matrix(const Matrix &that);
    // Destrutor
    ~Matrix();

    // Basic Getters

    // Obtem o numero de linhas
    int getRows() const;
    // Obtem o numero de colunas
    int getCols() const;
    // Obtem um elemento específico na posição (row,col). Obs: deve checar consistencia
    double get(int row, int col) const;

    // Other Methods

    // Imprime o conteudo da matriz
    void print() const;
    // Faz com que a matriz torne-se uma matriz identidade quadrada com sua maior dimensao original
    void unit();
    // Faz com que a matriz torne-se uma matriz nula
    void zeros();
    // Faz com que a matriz torne-se uma matriz cujos elementos sao iguaia a 1
    void ones();
};

#endif