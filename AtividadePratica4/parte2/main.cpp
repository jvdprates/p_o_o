#include <iostream>
#include "Matrix.h"
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;

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

    while (!terminateIt)
    {
        cout << "Matriz A gerada a partir do arquivo source.txt: " << endl;
        ifstream myFile;
        Matrix a(myFile);
        a.print();

        cout << "Linhas de A: " << a.getRows() << endl;
        cout << "Colunas de A: " << a.getCols() << endl;

        int rows, cols;
        double value;
        cout << "(Criar nova Matriz B)" << endl;
        cout << "Digite o numero de linhas de B: ";
        cin >> rows;
        cout << "Digite o numero de colunas de B: ";
        cin >> cols;
        cout << "Digite um valor real para prencher B: ";
        cin >> value;

        Matrix b(rows, cols, value);
        b.print();

        cout << "Matriz C = B" << endl;

        Matrix c = b;
        c.print();

        cout << "Transformando C em matriz zero" << endl;
        c.zeros();
        c.print();

        cout << "Transformando C em matriz unitaria" << endl;
        c.ones();
        c.print();

        cout << "Transformando C em matriz identidade" << endl; 
        c.unit();
        c.print();

        cout << "Digite uma linha de A" << endl;
        cin >> rows;
        cout << "Digite uma coluna de A" << endl;
        cin >> cols;
        cout << "O elemento [" << rows << "," << cols << "] de A e : " << a.get(rows,cols) << endl;

        askToFinalize(terminateIt);
    }

    cout << "Finalizando Programa Teste" << endl;
    return 0;
}