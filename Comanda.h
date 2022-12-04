#ifndef COMANDA_H
#define COMANDA_H

#include "Joc.h"

class Comanda
{
    private:
        std::string nume;
        std::vector<Joc> jocuriComanda;
        double pret;
    public:
        Comanda(){};
        Comanda(std::string, std::vector<Joc>, double);
        ~Comanda(){};
        friend std::ostream& operator << (std::ostream&, const Comanda &);
        friend void saveComenzi(std::vector<Comanda>);
};

#endif // COMANDA_H
