#include "BundlePacks.h"

#include <string>
#include <vector>
#include <iostream>

BundlePacks::BundlePacks(std::string nume, std::vector<Joc> Jocuri, double pret)
{
    this->nume = nume;
    for(Joc i : Jocuri)
    {
        this->Jocuri.push_back(i);
    }
    this->pret = pret;
}

std::ostream& operator << (std::ostream& st, const BundlePacks &x) {

    std::cout<<"Nume: "<<x.nume<<"\n";
    std::cout<<"Oferta contine "<<x.Jocuri.size()<<" jocuri:\n";
    for(auto i : x.Jocuri)
    {
        std::cout<<i.Getnume()<<"\n";
    }
    std::cout<<"Pret: "<<x.pret;

    return st;
}
