#include "matrix.h"
#include <iostream>

// contrutor default - cria uma matriz vazia com nRows = nCols = 0
Matrix::Matrix()
{
    nRows = nCols = 0;
}

// contrutor parametrico 1 - cria uma matriz com nRows  = rows, nCols = cols e
// com todos os elementos iguais a 0.0 (double)
Matrix::Matrix(int rows, int cols)
{
    nCols = cols;
    nRows = rows;

    m = new double *[rows];

    for (int i = 0; i < rows; i++)
    {
        m[i] = new double[cols];
        for (int j = 0; j < cols; j++)
        {
            m[i][j] = j;
        }
    }
}

// destrutor
Matrix::~Matrix()
{
    for (int i = 0; i <= nRows; i++)
    {
        delete[] m[i];
    };

    delete[] m;
}

// obtem o numero de linhas
int Matrix::getRows() const
{
    return nRows;
}

// obtem o numero de colunas
int Matrix::getCols() const
{
    return nCols;
}

// torna a matriz transposta
void Matrix::transpose()
{
    double **aux;

    aux = new double *[nCols];

    for (int k = 0; k < nCols; k++)
    {
        aux[k] = new double[nRows];
        for (int l = 0; l < nRows; l++)
        {
            aux[k][l] = 9;
        }
    };

    for (int i = 0; i < nCols; i++)
    {
        for (int j = 0; j < nRows; j++)
        {
            aux[i][j] = m[j][i];
        }
    };

    const int n = nRows;
    nRows = nCols;
    nCols = n;

    m = aux;
}

// imprime o conteudo da matriz
void Matrix::print() const
{
    for (int i = 0; i < nRows; i++)
    {
        std::cout << "[";
        for (int j = 0; j < nCols; j++)
        {
            if (j != nCols - 1)
            {
                std::cout << m[i][j] << " ,";
            }
            else
            {
                std::cout << m[i][j];
            };
        };
        std::cout << "]"
                  << "\n";
    };
}