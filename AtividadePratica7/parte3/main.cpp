#include <iostream>
#include "BusinessTraveler.h"

#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
    Traveler traveler1("Traveler1"), traveler2("Traveler2");
    Pager pager1("Pager1"), pager2("Pager2");
    BusinessTraveler bt1("BusinessTraveler1"), bt2("BusinessTraveler2");

    cout << traveler1.get_mensagem() << " = " << traveler2.get_mensagem() << " ? " << endl;
    cout << pager1.get_mensagem() << endl;
    cout << bt1.get_mensagem() << endl;
    
};