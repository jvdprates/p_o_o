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
    cout << "]";
}

int main()
{
    int i = 0;
    vector<int> list;

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

    cout << "Seu vetor resultante e: ";
    readVector(list);

    return 0;
}