#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

#include "Joc.h"

class User
{
    private:
        std::string username;
        std::string password;
        int memorie; //mb
        //nu avem nevoie de int nrJocuriInstalate pentru ca avem vectorul de jocrui
        std::vector<Joc> jocuriInstalate;
        std::vector<Joc> jocuriDetinute;
        std::vector<int> comenzi;

    public:
        User(){};
        User(std::string, std::string, int, std::vector<Joc>, std::vector<Joc>, std::vector<int>);
        virtual ~User(){}
        friend void saveUsers(std::vector<User>);
        friend User registerUser(std::vector<User>&, int );
        friend User loginUser(std::vector<User>, int);
        friend void istoricComenzi(const User& user, const Comanda& comenzi);
        friend void istoricComenzi(const User& user,const std::vector<Comanda> &comenzi);
        friend void jocuriUser(User &);
        friend void optiuniJoc(Joc &, User &);
        friend void actualizareUser(std::vector<User> &, const User);
        friend void printFindThis(std::string, std::vector<Joc>, std::vector<User> &, std::vector<Comanda> &, User &);
        friend void optiuniBundlePack(std::vector<User> &users, std::vector<Comanda> &comenzi, const BundlePacks &bundlePack, User &user);
};

#endif // USER_H
