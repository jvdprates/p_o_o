#ifndef BUSINESSTRAVELER_H
#define BUSINESSTRAVELER_H

#include <iostream>
#include "Traveler.h"
#include "Pager.h"
#include <string>

using std::string;

class BusinessTraveler : public Traveler
{
    Pager p;
public:
    BusinessTraveler(string msg = "1"): Traveler(msg), p(Pager(msg)){};
    BusinessTraveler(const BusinessTraveler &that)
    {
        this->p = that.p;
        this->get_mensagem() = that.get_mensagem();
    }
    BusinessTraveler &operator=(const BusinessTraveler &Bt)
    {
        this->p = Bt.p;
        this->get_mensagem() = Bt.get_mensagem();
        return *this;
    }
};

#endif