#include "Matrix.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

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
    cout << "Iniciando programa teste de Matrizes..." << endl;
    bool terminateIt = false;
    Matrix<double> doub(5,5,15.6);
    Matrix<int> in(5,5,8);
    Matrix<char> cha(5,5,'a');
    while(!terminateIt){
        doub.print();
        in.print();
        cha.print();
        askToFinalize(terminateIt);
    }
    cout << "Finalizando programa...";
    return 0;
}