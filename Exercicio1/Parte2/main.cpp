#include <iostream>

using namespace std;

/*Como criar um Lambda (funcao dentro de funcao): 

    auto function = [](){
        cout << "sua funcao" << "\n";
    }

*/

typedef struct
{
    //Array que salva os elementos da matriz.
    double **m;
    //Numero de linhas da matriz.
    int nLinhas;
    //Numero de colunas da matriz.
    int nColunas;
} Matriz;

//Parte 2.1
void inicializaMatriz(Matriz &X, int ls, int cs)
{
    X.nLinhas = ls;
    X.nColunas = cs;

    X.m = new double *[ls];
    for (int i = 0; i < ls; i++)
    {
        X.m[i] = new double[ls];
        for (int j = 0; j < cs; j++)
        {

            X.m[i][j] = 0;
        }
    }
};

//Parte 2.2
void apagaMatriz(Matriz &X)
{
    for (int i = 0; i <= X.nLinhas; i++)
    {
        delete[] X.m[i];
    };

    delete[] X.m;
};

//Parte 2.3
void transposta(Matriz &X)
{

    double aux;

    for (int i = 0; i < X.nLinhas; i++)
    {
        for (int j = i; j < X.nColunas; j++)
        {
            if (j != i)
            {
                aux = X.m[i][j];
                X.m[i][j] = X.m[j][i];
                X.m[j][i] = aux;
            }
        }
    }
};

//Parte 2.4
Matriz multiplica_por_cte(Matriz &X, double k)
{
    for (int i = 0; i < X.nLinhas; i++)
    {
        for (int j = 0; j < X.nColunas; j++)
        {
            X.m[i][j] = k * X.m[i][j];
        }
    }
    return X;
};

//Parte 2.5
void imprimeMatriz(Matriz &X)
{
    for (int i = 0; i < X.nLinhas; i++)
    {
        cout << "[";
        for (int j = 0; j < X.nColunas; j++)
        {
            if (j != X.nColunas - 1)
            {
                cout << X.m[i][j] << " ,";
            }
            else
            {

                cout << X.m[i][j];
            }
        }
        cout << "]"
             << "\n";
    }
};

int main()
{
    bool terminateIt = false;
    Matriz m;
    Matriz r;
    int size;
    char choice;

    while (!terminateIt)
    {
        cout << "Digite o tamanho da matriz quadrada desejada: ";
        cin >> size;
        cout << "Inicializando"
             << "\n";
        inicializaMatriz(m, size, size);
        cout << "Imprimindo inicializado"
             << "\n";
        imprimeMatriz(m);
        cout << "Multiplicando por 4"
             << "\n";
        r = multiplica_por_cte(m, 4);
        cout << "Imprimindo resultado"
             << "\n";
        imprimeMatriz(r);
        cout << "Calculando transposta"
             << "\n";
        transposta(m);
        cout << "Imprimindo transposta"
             << "\n";
        imprimeMatriz(m);
        cout << "Apagando matriz"
             << "\n";
        apagaMatriz(m);
        cout << "Imprimindo resultado"
             << "\n";
        imprimeMatriz(m);

        while (true)
        {
            cout << "(R - reiniciar programa, F - Finalizar programa)"
                 << "\n";
            cin >> choice;
            if (choice != 'R' && choice != 'F')
            {
                cout << "Comando invalido! digite novamente"
                     << "\n";
            }
            else if (choice == 'F')
            {
                cout << "Finalizando programa... Ate mais!"
                     << "\n";
                terminateIt = true;
                break;
            }
            else
            {
                cout << "Reiniciando programa..."
                     << "\n";
                break;
            }
        };
    };
    return 0;
};