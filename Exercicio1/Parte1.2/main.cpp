#include <iostream>
#include <fstream>
#include "string"
#include <vector>

using namespace std;

void readVector(vector<int> list)
{
    cout << "[";
    for (int u = 0; u < list.size(); u++)
    {
        if (u != list.size() - 1)
        {
            cout << list[u] << ",";
        }
        else
        {
            cout << list[u];
        }
    }
    cout << "]"
         << "\n";
}

int main()
{
    int i = 0;
    vector<int> list;
    bool terminateIt = false;
    int previousNum = -1;
    int currentNum;
    int numCounter = 0;
    char response;

    while (!terminateIt)
    {
        list = {};
        i = 0;
        previousNum = -1;
        numCounter = 0;

        vector<int> result;
        cout << "Insira uma sequencia de numeros: (digite -1 para parar) "
             << "\n";
        while (i != -1)
        {
            cin >> i;
            if (i != -1)
            {
                list.push_back(i);
            }
        }

        cout << "Seu vetor digitado e: ";
        readVector(list);

        for (int j = 0; j < list.size(); j++)
        {

            currentNum = list[j];


            if ((currentNum != previousNum) && previousNum != -1)
            {
                result.push_back(numCounter);
                result.push_back(previousNum);
                numCounter = 0;
            }

            numCounter++;

            if (j == list.size() - 1)
            {
                result.push_back(numCounter);
                result.push_back(currentNum);
            }

            previousNum = currentNum;
        }

        cout << "O vetor resultado comprimido e: ";
        readVector(result);

        while (1)
        {
            cout << "Deseja finalizar o programa ou repetir com um novo vetor? (R - reiniciar, F - finalizar) - "
                 << "\n";
            cin >> response;
            if (response != 'R' && response != 'F')
            {
                cout << "Comando invalido!, repetindo pergunta..."
                     << "\n";
            }
            else if (response == 'F')
            {
                cout << "Finalizando programa... Ate mais!"
                     << "\n";
                terminateIt = true;
                break;
            }
            else
            {
                cout << "Reiniciando..."
                     << "\n";
                break;
            }
        };
    }

    return 0;
}