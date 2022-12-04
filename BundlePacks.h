#ifndef BUNDLEPACKS_H
#define BUNDLEPACKS_H

#include "Joc.h"
#include <string>
#include <vector>

class BundlePacks
{
    private:
        std::string nume;
        std::vector<Joc> Jocuri;
        double pret;
    public:
        BundlePacks(){};
        BundlePacks(std::string, std::vector<Joc>, double);
        ~BundlePacks(){};
        std::string getNume() {return this->nume;}
        std::vector<Joc> getJocuri() {return this->Jocuri;}
        double getPret() {return this->pret;}
        friend std::ostream& operator << (std::ostream&, const BundlePacks &);
        friend void optiuniBundlePack(std::vector<User> &users, std::vector<Comanda> &comenzi, const BundlePacks &bundlePack, User &user);
        friend void listaOferte(const std::vector<Joc> Jocuri, std::vector<User> &users, std::vector<Comanda> &comenzi, const std::vector<BundlePacks> &bundlePacks, User &user);

};

#endif // BUNDLEPACKS_H
