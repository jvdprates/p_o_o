#include "matrix.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Matrix::Matrix() : nRows(0), nCols(0)
{
    cout << "Construtor padrao" << endl;
    this->m = new double *[1];
    this->m[0] = new double[1];
};

Matrix::Matrix(int rows, int cols, const double &value) : nRows(rows), nCols(cols)
{
    cout << "Construtor por parametros" << endl;
    this->m = new double *[rows];
    for (int i = 0; i < rows; i++)
    {
        this->m[i] = new double[cols];
        for (int j = 0; j < cols; j++)
        {
            this->m[i][j] = value;
        }
    }
};

Matrix::Matrix(ifstream &myFile)
{
    cout << "Construtor por arquivo" << endl;
};

Matrix::Matrix(const Matrix &that) : nRows(that.nRows), nCols(that.nCols)
{
    cout << "Construtor por copia" << endl;
    this->m = new double *[this->nRows];
    for (int i = 0; i < this->nRows; i++)
    {
        this->m[i] = new double[this->nCols];
        for (int j = 0; j < this->nCols; j++)
        {
            this->m[i][j] = that.m[i][j];
        }
    }
};

Matrix::~Matrix()
{
    cout << "Destrutor" << endl;
    for (int i = 0; i < this->nRows; i++)
    {
        delete this->m[i];
    }

    delete[] this->m;
};

int Matrix::getRows() const { return this->nRows; };

int Matrix::getCols() const { return this->nCols; };

double Matrix::get(int row, int col) const
{
    if (row <= this->nRows && col <= this->nCols)
    {
        return this->m[row][col];
    }
    else
    {
        return 0;
    }
};

void Matrix::print() const
{
    for (int i = 0; i < this->nRows; i++)
    {
        cout << "[";
        for (int j = 0; j < this->nCols; j++)
        {
            if (j != this->nCols - 1)
            {
                cout << this->m[i][j] << " ,";
            }
            else
            {
                cout << this->m[i][j];
            }
        }
        cout << "]" << endl;
    }
};

void Matrix::unit(){};

void Matrix::zeros()
{
    for (int i = 0; i < this->nRows; i++)
    {
        this->m[i] = new double[this->nCols];
        for (int j = 0; j < this->nCols; j++)
        {
            this->m[i][j] = 0;
        }
    }
};

void Matrix::ones()
{
    for (int i = 0; i < this->nRows; i++)
    {
        this->m[i] = new double[this->nCols];
        for (int j = 0; j < this->nCols; j++)
        {
            this->m[i][j] = 1;
        }
    }
};