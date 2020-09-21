#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template <class T>
T fibonnacci(int n)
{
    if (n <= 0) {
        cout << "Erro! - entrada invalida!" << endl;
        return T(-1);
    }
    ;
    T aux1 = 1, aux2 = 1;
    if (n == 1 || n == 2)
    {
        return aux2;
    }
    T fib = 1;
    for (int i = 3; i <= n; i++)
    {
        fib = aux1 + aux2;
        aux1 = aux2;
        aux2 = fib;
    }
    return fib;
};

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
    cout << "Inicializando programa de teste da funcao de Fibbonacci..." << endl;;
    bool terminateIt = false;

    while (!terminateIt)
    {
        int input;
        cout << "Digite n para encontrar o n-esimo numero de fibbonacci: ";
        cin >> input;
        int inter = fibonnacci<int>(input);
        int lon = fibonnacci<long>(input);
        int floa = fibonnacci<float>(input);
        cout << "int: " << inter << endl;
        cout << "long: " << lon << endl;
        cout << "float: " << floa << endl;

        askToFinalize(terminateIt);
    }
    cout << "Finalizando programa.." << endl;
    return 0;
}