#include "Matrix.cpp"
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
    Matrix<double> doub(5,5,2.5);
    Matrix<int> in(3,3,7);
    Matrix<char> cha(3,3,'a');
    while(!terminateIt){
        doub.print();
        in.print();
        cha.print();
        try {
            double a = doub.get(6,6);
            int b = in.get(3,2);
            char c = cha.get(5,2);

            cout << "a: " << a << endl;
            cout << "b: " << b << endl;
            cout << "c: " << c << endl;

        } catch(Error e){
            cout << "Error: ";
            e.print();
        }
        askToFinalize(terminateIt);
    }
    cout << "Finalizando programa..." << endl;
    return 0;
}