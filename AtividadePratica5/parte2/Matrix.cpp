#include "matrix.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// Constructors

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
            NUMlines++;                   //counts lines
            std::istringstream iss(line); //counts columns
            int columns = 0;
            do
            {
                std::string sub;
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

        std::vector<double> data;

        double aux;
        for (int k = 0; k < this->nCols * this->nRows; k++)
        {
            myFile >> aux;
            //cout << "data[" << k << "] -> " << aux << endl;
            data.push_back(aux);
        }

        int index = 0;
        this->m = new double *[this->nRows];
        for (int i = 0; i < this->nRows; ++i)
        {
            this->m[i] = new double[this->nCols];
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
        cout << "Incapaz de abrir arquivo";
        this->nRows = 0;
        this->nCols = 0;
        this->m = new double *[1];
        this->m[1] = new double[1];
    }
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

// Operators

void Matrix::operator=(const Matrix &that)
{
    cout << "Operador de atribuicao" << endl;
    this->nCols = that.nCols;
    this->nRows = that.nRows;

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

Matrix Matrix::operator+(const Matrix &that) const
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
        cout << "Matrizes tem tamanhos diferentes, soma invalida" << endl;
        return Matrix();
    }
};

Matrix Matrix::operator~()
{
    cout << "Operador de inversao" << endl;

    int auxRows = this->nCols;
    int auxCols = this->nRows;
    Matrix aux(auxRows, auxCols);
    for (int i = 0; i < auxRows; i++)
    {
        for (int j = 0; j < auxCols; j++)
        {
            aux.m[i][j] = this->m[j][i];
        }
    }
    return aux;
};

Matrix Matrix::operator*(const Matrix &that) const
{
    if (this->nCols == that.nRows)
    {

        Matrix aux(this->nRows, that.nCols);

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
        cout << "Matrizes tem tamanhos incompativeis, multiplicacao invalida";
        return Matrix();
    }
};

Matrix Matrix::operator+=(const Matrix &that)
{
    *this = *this + that;
    return *this;
};

Matrix Matrix::operator*=(const Matrix &that)
{
    *this = *this * that;
    return *this;
};

bool Matrix::operator==(const Matrix &that) const
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

istream &operator>>(istream &op, Matrix &that)
{
    int aux;
    while (1)
    {
        cout << "Digite o numero de linhas: ";
        op >> aux;
        if (aux < 0)
        {
            cout << "Input invalido! Comece de novo" << endl;
        }
        else
        {
            that.nRows = aux;
            cout << "Digite o numero de colunas: ";
            op >> aux;
            if (aux < 0)
            {
                cout << "Input invalido! Comece de novo!" << endl;
            }
            else
            {
                that.nCols = aux;
                break;
            }
        }
    }

    delete[] that.m;
    that.m = new double *[that.nCols];

    cout << "Agora preencha sua Matriz de " << that.nCols * that.nRows << " elementos" << endl;
    for (int i = 0; i < that.nRows; i++)
    {
        that.m[i] = new double[that.nRows];
        for (int j = 0; j < that.nCols; j++)
        {
            cout << "Elemento (" << i + 1 << "," << j + 1 << "): ";
            op >> that.m[i][j];
        }
    }
    return op;
}

ostream &operator<<(ostream &op, const Matrix &that)
{
    for (int i = 0; i < that.nRows; i++)
    {
        op << "[";
        for (int j = 0; j < that.nCols; j++)
        {
            if (j != that.nCols - 1)
            {
                op << that.m[i][j] << ", ";
            }
            else
            {
                op << that.m[i][j];
            }
        }
        op << "]" << endl;
    }
    return op;
}

// Basic getters

int Matrix::getRows() const { return this->nRows; };

int Matrix::getCols() const { return this->nCols; };

double Matrix::get(int row, int col) const
{
    if (row <= this->nRows && col <= this->nCols)
    {
        return this->m[row - 1][col - 1];
    }
    else
    {
        return 0;
    }
};

void Matrix::print() const
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

void Matrix::unit()
{
    if (this->nCols < this->nRows)
    {
        //Should grow Cols
        int aux = this->nRows - this->nCols;
        double **oldM = this->m;

        this->nCols += aux;
        this->m = new double *[this->nRows];

        for (int i = 0; i < this->nRows; i++)
        {
            this->m[i] = new double[this->nCols];
        }

        //Delete old m;
        for (int x = 0; x < this->nRows; x++)
        {
            delete oldM[x];
        }

        delete[] oldM;
    }
    else if (this->nRows < this->nCols)
    {
        //Should grow Rows
        int aux = this->nCols - this->nRows;
        double **oldM = this->m;

        this->nRows += aux;
        this->m = new double *[this->nRows];

        for (int i = 0; i < this->nRows; i++)
        {
            this->m[i] = new double[this->nCols];
        }

        //Delete old m;
        for (int x = 0; x < this->nRows - aux; x++)
        {
            delete oldM[x];
        }

        delete[] oldM;
    }

    //Finally transform new m into identity
    for (int i = 0; i < this->nRows; i++)
    {
        for (int j = 0; j < this->nCols; j++)
        {
            if (i == j)
            {

                this->m[i][j] = 1;
            }
            else
            {
                this->m[i][j] = 0;
            }
        }
    }
};

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