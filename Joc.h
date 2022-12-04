#ifndef JOC_H
#define JOC_H

#include<string>
#include <vector>

class User;
class Comanda;
class BundlePacks;
class Joc
{
    private:
        std::string nume;
        std::string categorie;
        int dimensiune;
        double pret;
        int vanzari;
        bool instalat;
    public:
        Joc();
        Joc(std::string, std::string, int, double, int, bool);
        virtual ~Joc(){}
        friend std::ostream& operator << (std::ostream& st, const Joc &);
        friend void vizualizareCatalogPerCategrii(const std::vector<Joc>);
        friend void afisareJocuriDinCategorie(const std::vector<Joc>, std::string);
        friend void saveUsers(std::vector<User>);
        friend Joc getGameByNames(std::vector<Joc>, std::string);
        friend Joc getGameByName(std::vector<Joc>, std::string);
        std::string Getnume() { return nume; }
        void Setnume(std::string val) { nume = val; }
        std::string Getcategorie() { return categorie; }
        void Setcategorie(std::string val) { categorie = val; }
        int Getdimensiune() { return dimensiune; }
        void Setdimensiune(int val) { dimensiune = val; }
        double Getpret() { return pret; }
        void Setpret(double val) { pret = val; }
        int Getvanzari() { return vanzari; }
        void Setvanzari(int val) { vanzari = val; }
        bool Getinstalat() { return instalat; }
        void Setinstalat(bool val) { instalat = val; }
        friend std::ostream& operator << (std::ostream& st, const Comanda &x);
        friend std::ostream& operator << (std::ostream& st, const BundlePacks &x);
        friend void optiuniJoc(Joc &, User &);
        friend void jocuriUser(User &);
        friend std::vector<User> getUsers(std::vector<Joc> Jocuri);
        friend void printFindThis(std::string, std::vector<Joc>, std::vector<User> &, std::vector<Comanda> &, User &);
        friend void listaJocuri(std::vector<Joc>, std::vector<User> &, std::vector<Comanda> &, User &);
        friend void saveComenzi(std::vector<Comanda>);
        friend std::vector<BundlePacks> getBundlePacks(std::vector<Joc>);
        friend void optiuniBundlePack(std::vector<User> &users, std::vector<Comanda> &comenzi, const BundlePacks &bundlePack, User &user);

};

#endif // JOC_H
