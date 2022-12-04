#include "User.h"

#include <string>
#include <vector>

User::User(std::string uId, std::string Pwd, int memorie, std::vector<Joc> instalate, std::vector<Joc> detinute, std::vector<int> comenzi)
{
    this->username = uId;
    this->password = Pwd;
    this->jocuriInstalate = instalate;
    this->jocuriDetinute = detinute;
    this->memorie = memorie;
    this->comenzi = comenzi;
}
