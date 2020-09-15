#include <iostream>
#include "Matrix.h"
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::string;

const void printMatrix(string &name, Matrix &X)
{
    cout << "Matriz " << name << ": " << endl;
    cout << X << endl;
}

const void askToFinalize(bool &terminateIt)
{
    char finInput;
    while (1)
    {
        cout << "Reiniciar o programa ? (S - sim,  N - Nao): ";
        cin >> finInput;
        if (finInput != 'S' && finInput != 'N')
        {
            cout << "Entrada invalida!" << endl;
        }
        else
        {
            if (finInput == 'N')
            {
                terminateIt = true;
            }
            break;
        }
    }
    if (!terminateIt)
    {
        cout << "Reiniciando programa..." << endl;
    }
};

int main()
{
    cout << "Inicializando Programa Teste" << endl;
    bool terminateIt = false;
    string aux;

    while (!terminateIt)
    {
        cout << "Matriz A gerada a partir do arquivo source.txt: " << endl;
        ifstream myFile;
        Matrix a(myFile);
        string aux = "A";
        printMatrix(aux, a);

        cout << "Linhas de A: " << a.getRows() << endl;
        cout << "Colunas de A: " << a.getCols() << endl;

        cout << "(Criar nova Matriz B)" << endl;
        Matrix b;
        cin >> b;

        aux = "B";
        printMatrix(aux, b);

        cout << "Matriz C = B" << endl;

        Matrix c = b;
        aux = "C";
        printMatrix(aux, c);

        cout << "Transformando C em matriz zero" << endl;
        c.zeros();
        printMatrix(aux, c);

        cout << "Transformando C em matriz unitaria" << endl;
        c.ones();
        printMatrix(aux, c);

        cout << "Transformando C em matriz identidade" << endl;
        c.unit();
        printMatrix(aux, c);

        askToFinalize(terminateIt);
    }

    cout << "Finalizando Programa Teste" << endl;
    return 0;
}