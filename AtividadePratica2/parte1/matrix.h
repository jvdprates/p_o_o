#include <iostream>
#pragma once

class Matrix
{
private:
    double **m; // m é um array 2D a ser implementado como um pointer de pointers
    int nRows;  // numero de linhas
    int nCols;  //  numero de colunas

public:
    // Construtores
    Matrix();
    Matrix(int rows, int cols);
    // destrutor
    ~Matrix();

    // basic getters
    int getRows() const;
    int getCols() const;

    // other methods
    void transpose();
    void print() const;
};