#include <iostream>

/*Como criar um Lambda (funcao dentro de funcao): 

    auto function = [](){
        std::cout << "sua funcao" << "\n";
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
        X.m[i] = new double[cs];
        for (int j = 0; j < cs; j++)
        {
            if (j < 2)
            {
                X.m[i][j] = 0;
            }
            else
            {
                X.m[i][j] = 2;
            }
        }
    }
};

Matriz copiarMatriz(Matriz X){
    Matriz B;
    inicializaMatriz(B, X.nLinhas, X.nColunas);
    for (int i = 0; i < X.nLinhas; i++){
        for (int j = 0; j < X.nColunas; j++){
            B.m[i][j] = X.m[i][j];
        }
    }
    return B;
}

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

    Matriz newMatriz;
    newMatriz.nLinhas = X.nColunas;
    newMatriz.nColunas = X.nLinhas;
    newMatriz.m = new double *[newMatriz.nLinhas];
    for (int h = 0; h < newMatriz.nLinhas; h++)
    {   
        newMatriz.m[h] = new double[newMatriz.nColunas];
    }

    for (int i = 0; i < newMatriz.nLinhas; i++)
    {
        for (int j = 0; j < newMatriz.nColunas; j++)
        {
            newMatriz.m[i][j] = X.m[j][i];
        }
    }

    apagaMatriz(X);

    X = newMatriz;
};

//Parte 2.4
Matriz multiplica_por_cte(Matriz &X, double k)
{
    Matriz newMatriz = copiarMatriz(X);
    for (int i = 0; i < newMatriz.nLinhas; i++)
    {
        for (int j = 0; j < newMatriz.nColunas; j++)
        {
            newMatriz.m[i][j] = k * newMatriz.m[i][j];
        }
    }
    return newMatriz;
};

//Parte 2.5
void imprimeMatriz(Matriz &X)
{
    for (int i = 0; i < X.nLinhas; i++)
    {
        std::cout << "[";
        for (int j = 0; j < X.nColunas; j++)
        {
            if (j != X.nColunas - 1)
            {
                std::cout << X.m[i][j] << " ,";
            }
            else
            {

                std::cout << X.m[i][j];
            }
        }
        std::cout << "]"
             << "\n";
    }
};

int main()
{
    /*bool terminateIt = false;
    Matriz m;
    Matriz r;
    int lenght;
    int height;
    char choice;

    while (!terminateIt)
    {
        std::cout << "Digite o nO de linhas da matriz desejada: ";
        cin >> lenght;
        std::cout << "Digite o nO de colunas da matriz desejada: ";
        cin >> height;
        std::cout << "Inicializando"
             << "\n";
        inicializaMatriz(m, lenght, height);
        std::cout << "Imprimindo inicializado"
             << "\n";
        imprimeMatriz(m);
        std::cout << "Multiplicando por 4"
             << "\n";
        r = multiplica_por_cte(m, 4);
        std::cout << "Imprimindo resultado"
             << "\n";
        imprimeMatriz(r);
        std::cout << "Calculando transposta"
             << "\n";
        transposta(m);
        std::cout << "Imprimindo transposta"
             << "\n";
        imprimeMatriz(m);
        std::cout << "Apagando matriz"
             << "\n";
        apagaMatriz(m);
        std::cout << "Imprimindo resultado"
             << "\n";
        imprimeMatriz(m);

        while (true)
        {
            std::cout << "(R - reiniciar programa, F - Finalizar programa)"
                 << "\n";
            cin >> choice;
            if (choice != 'R' && choice != 'F')
            {
                std::cout << "Comando invalido! digite novamente"
                     << "\n";
            }
            else if (choice == 'F')
            {
                std::cout << "Finalizando programa... Ate mais!"
                     << "\n";
                terminateIt = true;
                break;
            }
            else
            {
                std::cout << "Reiniciando programa..."
                     << "\n";
                break;
            }
        };
    };
    return 0;*/

    //Parte 2.6
    Matriz A, B, R;

    std::cout<<"A:: "<<std::endl;
    inicializaMatriz(A,2,3);
    imprimeMatriz(A);
    
    std::cout<<"Transposta de A:: "<<std::endl;
    transposta(A);
    imprimeMatriz(A);
    apagaMatriz(A);

    std::cout<<std::endl<<"B:: "<<std::endl;
    inicializaMatriz(B,4,4);
    imprimeMatriz(B);
    
    std::cout<<std::endl<<"R = k*B "<<std::endl;
    R = multiplica_por_cte(B,5); 
    imprimeMatriz(R);
    
    apagaMatriz(B);
    apagaMatriz(R);

    return 0;
};