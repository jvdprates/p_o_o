#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>

using std::ifstream;
using std::istream;
using std::ostream;

template <class T>
class Matrix
{
private:
    T **m; // m é um array 2D a ser implementado como um pointer de pointers
    int nRows;  // Numero de linhas
    int nCols;  // Numero de colunas

public:
    // Constructors

    // Contrutor default - cria uma matriz vazia com nRows = nCols = 0
    Matrix<T>();
    // Contrutor parametrico 1 - cria uma matriz com nRows  = rows, nCols = cols e
    // com todos os elementos iguais a 0.0 (double)
    Matrix<T>(int rows, int cols, const T &value);
    // Construtor parametrico 2 - cria uma matriz com os dados fornecidos pelo arquivo texto myFile.
    Matrix<T>(ifstream &myFile);
    // Contrutor de copia
    Matrix<T>(const Matrix<T> &that);
    // Destrutor
    ~Matrix<T>();

    // Operators

    // Assignment operator
    void operator=(const Matrix<T> &);
    // Change element operator
    T &operator()(int &, int &);
    // Sum operator
    Matrix<T> operator+(const Matrix<T> &) const;
    // Sub operator
    Matrix<T> operator-(const Matrix<T> &) const;
    // Invert Matrix<T>
    Matrix<T> operator~();
    // Multiply Matrix<T>
    Matrix<T> operator*(const Matrix<T> &) const;
    // Assignment as sum of Matrix<T> operator
    Matrix<T> operator+=(const Matrix<T> &);
    // Assignment as sub of Matrix<T> operator
    Matrix<T> operator-=(const Matrix<T> &);
    // Assignment as product of Matrix<T> operator
    Matrix<T> operator*=(const Matrix<T> &);
    // Check equality
    bool operator==(const Matrix<T> &) const;
    // Check inequality
    bool operator!=(const Matrix<T> &) const;
    // Istream operator
    friend istream &operator>>(istream &, Matrix<T> &);
    // Ostream operator
    friend ostream &operator<<(ostream &, const Matrix<T> &);

    // Basic Getters

    // Obtem o numero de linhas
    int getRows() const;
    // Obtem o numero de colunas
    int getCols() const;
    // Obtem um elemento específico na posição (row,col). Obs: deve checar consistencia
    T get(int row, int col) const;

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