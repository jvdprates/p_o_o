#include "Agenda.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "Digite o numeros de pessoas que a agenda tera: " << endl;
    int tamanhoAgenda;
    cin >> tamanhoAgenda;
    Agenda agenda1(tamanhoAgenda);
    cout << "A agenda possui "
         << agenda1.getnAmigos()
         << " amigos e "
         << agenda1.getnConhecidos()
         << " conhecidos."
         << endl << endl;
    cout << "Adicione dados a agenda." << endl;
    agenda1.addInformacoes();
    cout << endl;
    cout << "Imprimidos dados: " << endl;
    agenda1.imprimeAniversarios();
    cout << endl << endl;
    agenda1.imprimeEmail();
    return 0;
}