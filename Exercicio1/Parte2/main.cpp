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
    for (int i = 0; i < X.nLinhas; i++)
    {
        delete[] X.m[i];
    };

    delete [] X.m;
};

//Parte 2.3
void transposta(Matriz &X){

};

//Parte 2.4
Matriz multiplica_por_cte(Matriz &X, double k){

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
    Matriz m;
    inicializaMatriz(m, 5, 5);
    imprimeMatriz(m);
    apagaMatriz(m);
    cout << "Matriz apagada! " << "\n";
    imprimeMatriz(m);
    return 0;
};