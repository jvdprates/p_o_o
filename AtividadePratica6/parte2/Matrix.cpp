#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "Matrix.h"
#include "Error.cpp"

using namespace std;

// Constructors
template <class T>
Matrix<T>::Matrix() : nRows(0), nCols(0)
{
    cout << "Construtor padrao" << endl;
    this->m = new T *[1];
    this->m[0] = new T[1];
};

template <class T>
Matrix<T>::Matrix(int rows, int cols, const T &value) : nRows(rows), nCols(cols)
{
    cout << "Construtor por parametros" << endl;
    this->m = new T *[rows];
    for (int i = 0; i < rows; i++)
    {
        this->m[i] = new T[cols];
        for (int j = 0; j < cols; j++)
        {
            this->m[i][j] = value;
        }
    }
};

template <class T>
Matrix<T>::Matrix(ifstream &myFile)
{
    cout << "Construtor por arquivo" << endl;
    myFile.open("source.txt");
    if (myFile.is_open())
    {
        cout << "Lendo arquivo" << endl;
        int NUMlines = 0;
        string line;
        this->nRows = 0;
        this->nCols = 0;
        while (getline(myFile, line))
        {
            //cout << line << endl;
            NUMlines++;              //counts lines
            istringstream iss(line); //counts columns
            int columns = 0;
            do
            {
                T sub;
                iss >> sub;
                if (sub.length())
                    ++columns;
            } while (iss);

            if (this->nCols < columns)
            {
                this->nCols = columns;
            }
        }
        this->nRows = NUMlines;

        // cout << "Ive counted - " << this->nCols << " - total columns!" << endl;
        // cout << "Ive counted - " << this->nRows << " - total lines!" << endl;

        myFile.clear();  //clear EOF
        myFile.seekg(0); //return to the beggining of file

        std::vector<T> data;

        double aux;
        for (int k = 0; k < this->nCols * this->nRows; k++)
        {
            myFile >> aux;
            //cout << "data[" << k << "] -> " << aux << endl;
            data.push_back(aux);
        }

        int index = 0;
        this->m = new T *[this->nRows];
        for (int i = 0; i < this->nRows; ++i)
        {
            this->m[i] = new T[this->nCols];
            for (int j = 0; j < this->nCols; ++j)
            {
                //cout << "setting data[" << index << "] -> " << aux << endl;
                this->m[i][j] = data[index];
                //cout << "data set!" << endl;
                index++;
            }
        }
        myFile.close();
    }
    else
    {
        this->nRows = 0;
        this->nCols = 0;
        this->m = new double *[1];
        this->m[1] = new double[1];
        throw Error("Incapaz de abrir arquivo");
    }
};

template <class T>
Matrix<T>::Matrix(const Matrix<T> &that) : nRows(that.nRows), nCols(that.nCols)
{
    cout << "Construtor por copia" << endl;
    this->m = new T *[this->nRows];
    for (int i = 0; i < this->nRows; i++)
    {
        this->m[i] = new T[this->nCols];
        for (int j = 0; j < this->nCols; j++)
        {
            this->m[i][j] = that.m[i][j];
        }
    }
};

template <class T>
Matrix<T>::~Matrix()
{
    cout << "Destrutor" << endl;
    for (int i = 0; i < this->nRows; i++)
    {
        delete this->m[i];
    }

    delete[] this->m;
};

// Operators

template <class T>
void Matrix<T>::operator=(const Matrix<T> &that)
{
    cout << "Operador de atribuicao" << endl;
    this->nCols = that.nCols;
    this->nRows = that.nRows;

    this->m = new T *[this->nRows];
    for (int i = 0; i < this->nRows; i++)
    {
        this->m[i] = new T[this->nCols];
        for (int j = 0; j < this->nCols; j++)
        {
            this->m[i][j] = that.m[i][j];
        }
    }
};

template <class T>
T &Matrix<T>::operator()(int &row, int &col)
{
    if (0 < row && row < this->nRows && 0 < col && 0 < this->nCols)
    {
        return this->m[row - 1][col - 1];
    }
    else
    {
        throw Error("Entrada invalida! Erro!");
    }
};

template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &that) const
{
    cout << "Operador de soma" << endl;
    if (this->nCols == that.nCols && this->nRows == that.nRows)
    {
        Matrix result(this->nRows, this->nCols);
        for (int i = 0; i < result.nRows; i++)
        {
            for (int j = 0; j < result.nCols; j++)
            {
                result.m[i][j] = this->m[i][j] + that.m[i][j];
            }
        }
        return result;
    }
    else
    {
        throw Error("Matrizes tem tamanhos diferentes, soma invalida");
    }
};

template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &that) const
{
    cout << "Operador de subtracao" << endl;
    if (this->nCols == that.nCols && this->nRows == that.nRows)
    {
        Matrix<T> result(this->nRows, this->nCols);
        for (int i = 0; i < result.nRows; i++)
        {
            for (int j = 0; j < result.nCols; j++)
            {
                result.m[i][j] = this->m[i][j] - that.m[i][j];
            }
        }
        return result;
    }
    else
    {
        throw Error("Matrizes tem tamanhos diferentes, subtracao invalida");
    }
};

template <class T>
Matrix<T> Matrix<T>::operator~()
{
    cout << "Operador de inversao" << endl;

    int auxRows = this->nCols;
    int auxCols = this->nRows;
    Matrix<T> aux(auxRows, auxCols);
    for (int i = 0; i < auxRows; i++)
    {
        for (int j = 0; j < auxCols; j++)
        {
            aux.m[i][j] = this->m[j][i];
        }
    }
    return aux;
};

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &that) const
{
    if (this->nCols == that.nRows)
    {

        Matrix<T> aux(this->nRows, that.nCols);

        for (int i = 0; i < this->nRows; i++)
        {
            for (int j = 0; j < this->nCols; j++)
            {
                double totalSum = 0;
                for (int k = 0; k < this->nCols; k++)
                {
                    totalSum += this->m[i][k] * that.m[k][j];
                }
                aux.m[i][j] = totalSum;
            }
        }
        return aux;
    }
    else
    {
        throw Error("Matrizes tem tamanhos incompativeis, multiplicacao invalida");
    }
};

template <class T>
Matrix<T> Matrix<T>::operator+=(const Matrix<T> &that)
{
    *this = *this + that;
    return *this;
};

template <class T>
Matrix<T> Matrix<T>::operator-=(const Matrix<T> &that)
{
    *this = *this - that;
    return *this;
};

template <class T>
Matrix<T> Matrix<T>::operator*=(const Matrix<T> &that)
{
    *this = *this * that;
    return *this;
};

template <class T>
bool Matrix<T>::operator==(const Matrix<T> &that) const
{
    if (this->nCols == that.nCols && this->nRows == that.nRows)
    {
        for (int i = 0; i < this->nRows; i++)
        {
            for (int j = 0; j < this->nCols; j++)
            {
                if (this->m[i][j] != that.m[i][j])
                {
                    cout << "Tem pelo menos um elemento diferente!" << endl;
                    return false;
                }
            }
        }
        return true;
    }
    else
    {
        cout << "Tem tamanhos diferentes!" << endl;
        return false;
    }
};

template <class T>
bool Matrix<T>::operator!=(const Matrix<T> &that) const
{
    if (this->nCols == that.nCols && this->nRows == that.nRows)
    {
        for (int i = 0; i < this->nRows; i++)
        {
            for (int j = 0; j < this->nCols; j++)
            {
                if (this->m[i][j] != that.m[i][j])
                {
                    cout << "Tem pelo menos um elemento diferente!" << endl;
                    return true;
                }
            }
        }
        return false;
    }
    else
    {
        cout << "Tem tamanhos diferentes!" << endl;
        return true;
    }
};

// template <class T>
// istream &operator>>(istream &op, Matrix<T> &that)
// {
//     int aux;
//     while (1)
//     {
//         cout << "Digite o numero de linhas: ";
//         op >> aux;
//         if (aux < 0)
//         {
//             cout << "Input invalido! Comece de novo" << endl;
//         }
//         else
//         {
//             that.nRows = aux;
//             cout << "Digite o numero de colunas: ";
//             op >> aux;
//             if (aux < 0)
//             {
//                 cout << "Input invalido! Comece de novo!" << endl;
//             }
//             else
//             {
//                 that.nCols = aux;
//                 break;
//             }
//         }
//     }

//     delete[] that.m;
//     that.m = new T *[that.nRows];

//     cout << "Agora preencha sua Matriz de " << that.nCols * that.nRows << " elementos" << endl;
//     for (int i = 0; i < that.nRows; i++)
//     {
//         that.m[i] = new T[that.nCols];
//         for (int j = 0; j < that.nCols; j++)
//         {
//             cout << "Elemento (" << i + 1 << "," << j + 1 << "): ";
//             op >> that.m[i][j];
//         }
//     }
//     return op;
// }

// template <class T>
// ostream &operator<<(ostream &op, const Matrix<T> &that)
// {
//     for (int i = 0; i < that.nRows; i++)
//     {
//         op << "[";
//         for (int j = 0; j < that.nCols; j++)
//         {
//             if (j != that.nCols - 1)
//             {
//                 op << that.m[i][j] << ", ";
//             }
//             else
//             {
//                 op << that.m[i][j];
//             }
//         }
//         op << "]" << endl;
//     }
//     return op;
// }

// Basic getters
template <class T>
int Matrix<T>::getRows() const { return this->nRows; };

template <class T>
int Matrix<T>::getCols() const { return this->nCols; };

template <class T>
T Matrix<T>::get(int row, int col) const
{
    if (row <= this->nRows && col <= this->nCols)
    {
        return this->m[row - 1][col - 1];
    }
    else
    {
       throw Error("Entrada invalida! Impossivel buscar elemento");
    }
};

template <class T>
void Matrix<T>::print() const
{
    cout << endl;
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

template <class T>
void Matrix<T>::unit()
{
    if (this->nCols != this->nRows)
    {
        for (int i = 0; i < this->nRows; i++)
        {
            for (int j = 0; j < this->nCols; j++)
            {
                if (i == j)
                {

                    this->m[i][j] = T(1);
                }
                else
                {
                    this->m[i][j] = T(0);
                }
            }
        }
    }
    else
    {
        throw Error("Matriz nao e quadrada! nao pode se tornar identidade");
    }
};

template <class T>
void Matrix<T>::zeros()
{
    for (int i = 0; i < this->nRows; i++)
    {
        for (int j = 0; j < this->nCols; j++)
        {
            this->m[i][j] = T(0);
        }
    }
};

template <class T>
void Matrix<T>::ones()
{
    for (int i = 0; i < this->nRows; i++)
    {
        for (int j = 0; j < this->nCols; j++)
        {
            this->m[i][j] = T(1);
        }
    }
};