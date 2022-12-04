#include "Comanda.h"
#include <iostream>

Comanda::Comanda(std::string nume, std::vector<Joc> jocuri, double pret)
{
    this->nume = nume;
    for(auto i : jocuri) this->jocuriComanda.push_back(i);
    this->pret = pret;
}

std::ostream& operator << (std::ostream& st, const Comanda &x) {

    std::cout<<"Nume utilizator: "<<x.nume<<"\n";
    std::cout<<"Comanda contine "<<x.jocuriComanda.size()<<" jocuri:\n";
    for(auto i : x.jocuriComanda)
    {
        std::cout<<i.nume<<"\n";
    }
    std::cout<<"Pret: "<<x.pret;

    return st;
}
