#include <iostream>
#include <string>
#include "Joc.h"
#include "User.h"
#include "Comanda.h"
#include "BundlePacks.h"
#include <vector>
#include <fstream>
#include <windows.h>
#include<conio.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define ENTER 13

void SetColore(int value) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}

void gotoxy(short a, short b) //Custom gotoxy() function
{
    COORD coordinates; //Data type of co-ordinates
    coordinates.X = a; //Assign value to X- Co-ordinate
    coordinates.Y = b; //Assign value to Y Co-ordinate

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), coordinates);

}

std::vector<BundlePacks> getBundlePacks(std::vector<Joc> Jocuri)
{
    std::vector<BundlePacks> bundlePacks;
    std::ifstream file("bundlePacks.txt");
    std::string nume;
    std::string numeJoc;
    std::vector<Joc> jocuriPack;
    std::string spret;
    double pret;
    std::string snrJocuri;
    int nrJocuri;
    while (std::getline(file, nume))
    {
        std::getline(file, snrJocuri);
        nrJocuri = stoi(snrJocuri);
        for (int i = 0; i < nrJocuri; i++)
        {
            std::getline(file, numeJoc);
            jocuriPack.push_back(getGameByNames(Jocuri, numeJoc));
        }
        std::getline(file, spret);
        pret = stod(spret);
        BundlePacks pack(nume, jocuriPack, pret);
        bundlePacks.push_back(pack);
        jocuriPack = {};
    }
    file.close();

    return bundlePacks;
}

std::vector<Comanda> getComenzi(std::vector<Joc> Jocuri)
{
    std::vector<Comanda> comenzi;
    std::ifstream file("comenzi.txt");
    std::string nume;
    std::string numeJoc;
    std::vector<Joc> jocuriComanda;
    std::string spret;
    double pret;
    std::string snrJocuri;
    int nrJocuri;
    while (std::getline(file, nume))
    {
        std::getline(file, snrJocuri);
        nrJocuri = stoi(snrJocuri);
        for (int i = 0; i < nrJocuri; i++)
        {
            std::getline(file, numeJoc);
            jocuriComanda.push_back(getGameByNames(Jocuri, numeJoc));
        }
        std::getline(file, spret);
        pret = stod(spret);
        Comanda comanda(nume, jocuriComanda, pret);
        comenzi.push_back(comanda);
        jocuriComanda = {};
    }
    file.close();

    return comenzi;
}

std::vector<Joc> getGame() {
    std::vector<Joc> gamesList;
    std::ifstream file("jocuri.txt");
    std::string nume;
    std::string categorie;
    std::string sdimensiune;
    int dimensiune;
    std::string spret;
    double pret;
    std::string svanzari;
    int vanzari;
    std::string sinstalat;
    bool instalat;

    while (std::getline(file, svanzari))
    {
        vanzari = stoi(svanzari);
        std::getline(file, nume);
        std::getline(file, categorie);
        std::getline(file, sdimensiune);
        dimensiune = stoi(sdimensiune);
        std::getline(file, spret);
        pret = stod(spret);
        std::getline(file, sinstalat);
        if (sinstalat == "true") instalat = true;
        else instalat = false;

        Joc joc(nume, categorie, dimensiune, pret, vanzari, instalat);
        gamesList.push_back(joc);
    }

    return gamesList;
}

std::vector<User> getUsers(std::vector<Joc> Jocuri)
{
    std::vector<User> usersList;
    std::ifstream file("users.txt");
    std::string username;
    std::string password;
    std::string smemorie;
    int memorie;
    std::string snrJocuriInstalate;
    int nrJocuriInstalate;
    std::string snrJocuriDetinute;
    int nrJocuriDetinute;
    std::string snrComenzi;
    int nrComenzi;
    std::string numeJoc;
    std::vector<Joc> jocuriInstalate;
    std::vector<Joc> jocuriDetinute;
    std::vector<int> comenzi;
    std::string scomanda;
    int comanda;

    while (std::getline(file, username))
    {
        std::getline(file, password);
        std::getline(file, smemorie);
        memorie = stoi(smemorie);
        std::getline(file, snrJocuriInstalate);
        nrJocuriInstalate = stoi(snrJocuriInstalate);
        for (int i = 0; i < nrJocuriInstalate; i++)
        {
            std::getline(file, numeJoc);
            jocuriInstalate.push_back(getGameByNames(Jocuri, numeJoc));
            jocuriInstalate.back().instalat = true;
        }
        std::getline(file, snrJocuriDetinute);
        nrJocuriDetinute = stoi(snrJocuriDetinute);
        for (int i = 0; i < nrJocuriDetinute; i++)
        {
            std::getline(file, numeJoc);
            jocuriDetinute.push_back(getGameByNames(Jocuri, numeJoc));
            for (auto k : jocuriInstalate)
            {
                if (k.nume == jocuriDetinute.back().nume) {
                    jocuriDetinute.back().instalat = true;
                }
            }
        }
        std::getline(file, snrComenzi);
        nrComenzi = stoi(snrComenzi);
        for (int i = 0; i < nrComenzi; i++)
        {
            std::getline(file, scomanda);
            comanda = stoi(scomanda);
            comenzi.push_back(comanda);
        }

        User user(username, password, memorie, jocuriInstalate, jocuriDetinute, comenzi);
        usersList.push_back(user);
        comenzi = {};
        jocuriInstalate = {};
        jocuriDetinute = {};
    }

    return usersList;
}

void saveUsers(std::vector<User> users) {
    std::ofstream writeFile;
    writeFile.open("users.txt");
    for (auto i : users)
    {
        writeFile << i.username << "\n";
        writeFile << i.password << "\n";
        writeFile << i.memorie << "\n";
        writeFile << i.jocuriInstalate.size() << "\n";
        for (auto j : i.jocuriInstalate)
        {
            writeFile << j.nume << "\n";
        }
        writeFile << i.jocuriDetinute.size() << "\n";
        for (auto j : i.jocuriDetinute)
        {
            writeFile << j.nume << "\n";
        }
        writeFile << i.comenzi.size() << "\n";
        for (auto j : i.comenzi)
        {
            writeFile << j << "\n";
        }
    }

    writeFile.close();
}

void saveComenzi(std::vector<Comanda> comenzi) {
    std::ofstream writeFile;
    writeFile.open("comenzi.txt");
    for (Comanda i : comenzi)
    {
        writeFile << i.nume << "\n";
        writeFile << i.jocuriComanda.size() << "\n";
        for (Joc j : i.jocuriComanda)
        {
            writeFile << j.nume << "\n";
        }
        writeFile << i.pret << "\n";
    }

    writeFile.close();
}

void optiuniJoc(Joc joc) {
    system("cls");
    std::cout << joc;
    int optiuneAleasa;
    SetColore(9); std::cout << "Press any key to continue.\n"; SetColore(7);
    optiuneAleasa =  _getch();
}

void afisareJocuriDinCategorie(const std::vector<Joc> Jocuri, std::string categorie) {
    system("cls");
    for (int i = 0; i < Jocuri.size(); i++) {
        if (Jocuri[i].categorie == categorie) { SetColore(9); std::cout << i + 1 << ") "; SetColore(7); std::cout << Jocuri[i] << std::endl; }
    }
    SetColore(12); std::cout << "0) Exit" << std::endl; SetColore(7);
    int jocAles;
    SetColore(9); std::cout << "INPUT: "; SetColore(7); std::cin >> jocAles; std::cin.ignore();
    jocAles--;
    std::cout << std::endl;
    if (jocAles >= 0) optiuniJoc(Jocuri[jocAles]);
}

void vizualizareCatalogPerCategorii(const std::vector<Joc> Jocuri) {
    system("cls");
    std::vector<std::string> categorii = { "MOBA", "SANDBOX", "FPS" };
    std::cout << "CATEGORIILE DE JOCURI:" << std::endl << std::endl;
    for (int i = 0; i < categorii.size(); i++) {
        SetColore(9); std::cout << i + 1 << ") "; SetColore(7); std::cout << categorii[i] << std::endl;
    }

    SetColore(12); std::cout << "0) Exit"; SetColore(7);
    int categorieAleasa;
    SetColore(9); std::cout << std::endl << "INPUT: "; SetColore(7); std::cin >> categorieAleasa; std::cin.ignore();
    categorieAleasa--;
    if (categorieAleasa != -1)
        afisareJocuriDinCategorie(Jocuri, categorii[categorieAleasa]);
}

void detaliiBundlePack(const BundlePacks pack)
{
    system("cls");
    std::cout << pack;
    int exit;
    SetColore(9); std::cout << "\nPress any key to continue."; SetColore(7);
    exit =  _getch();
}

void catalogOferte(std::vector<BundlePacks> bundlePacks)
{
    system("cls");
    for (int i = 0; i < bundlePacks.size(); i++)
    {
        SetColore(9); std::cout << i + 1 << ")"; SetColore(7); std::cout << bundlePacks[i].getNume() << "\n";
    }
    int ofertaAleasa;
    SetColore(12); std::cout << "0) Exit\n";
    SetColore(9); std::cout << "INPUT: "; SetColore(7); std::cin >> ofertaAleasa; std::cin.ignore(); ofertaAleasa--;
    if (ofertaAleasa != -1)
    {
        detaliiBundlePack(bundlePacks[ofertaAleasa]);
    }
}

void Catalog(const std::vector<Joc> Jocuri, const std::vector<BundlePacks> bundlePacks)
{
    int optiuneMeniu = 1;
    int keyInput;
    int cond = 1;
    while (cond) {
        system("cls");
        if (optiuneMeniu == 1)
        {
            std::cout << "________________________________________________\n";
            std::cout << "|                                              |\n";
            std::cout << "|                 "; SetColore(2); std::cout << ">>Catalog"; SetColore(7); std::cout << "                    |\n";
            std::cout << "|                    Oferte                    |\n";
            std::cout << "|               Inapoi in meniu                |\n";
            std::cout << "|                                              |\n";
            std::cout << "------------------------------------------------\n";
        }
        if (optiuneMeniu == 2)
        {
            std::cout << "________________________________________________\n";
            std::cout << "|                                              |\n";
            std::cout << "|                   Catalog                    |\n";
            std::cout << "|                  "; SetColore(2); std::cout << ">>Oferte"; SetColore(7); std::cout << "                    |\n";
            std::cout << "|               Inapoi in meniu                |\n";
            std::cout << "|                                              |\n";
            std::cout << "------------------------------------------------\n";
        }
        if (optiuneMeniu == 3)
        {
            std::cout << "________________________________________________\n";
            std::cout << "|                                              |\n";
            std::cout << "|                   Catalog                    |\n";
            std::cout << "|                    Oferte                    |\n";
            std::cout << "|             "; SetColore(2); std::cout << ">>Inapoi in meniu"; SetColore(7); std::cout << "                |\n";
            std::cout << "|                                              |\n";
            std::cout << "------------------------------------------------\n";
        }
        keyInput =  _getch();
        if (keyInput == KEY_UP)
        {
            if (optiuneMeniu == 1) optiuneMeniu = 3;
            else optiuneMeniu--;
        }
        else if (keyInput == KEY_DOWN)
        {
            if (optiuneMeniu == 3) optiuneMeniu = 1;
            else optiuneMeniu++;
        }
        else if (keyInput == ENTER)
        {
            switch (optiuneMeniu)
            {
            case 1:
                vizualizareCatalogPerCategorii(Jocuri);
                break;
            case 2:
                catalogOferte(bundlePacks);
            case 3:
                cond = 0;
                break;
            }
        }
    }
}

long hashPassword(std::string password)
{
    std::hash <std::string> hash;
    unsigned long hashedPassword = 1065148159544519853;
    unsigned long hashedPasswordGuess = hash(password);
    return hashedPasswordGuess;
}

int getMemorie()
{
    return 524288;
}

User registerUser(std::vector<User>& users, int error = 0)
{
    std::string username;
    std::string password;
    std::string confirmPassword;
    int optiuneMeniu = 1;
    int keyInput;
    int cond = 1;
    while (cond) {
        system("cls");
        if (optiuneMeniu == 1)
        {
            std::cout << "________________________________________________\n";
            std::cout << "|                                              |\n";
            std::cout << "|     "; SetColore(2); std::cout << ">>Username:"; SetColore(7); std::cout << " " << username;
            for (int i = 0; i < 29 - username.length(); i++) std::cout << " ";
            std::cout << "|\n";
            std::cout << "|       Password: ";
            if (password.length() > 1) std::cout << "******                       |\n";
            else std::cout << "                             |\n";
            std::cout << "|       Confirm password: ";
            if (confirmPassword.length() > 1) std::cout << "******               |\n";
            else std::cout << "                     |\n";
            std::cout << "|                                              |\n";
            std::cout << "|       Register                               |\n";
            std::cout << "|                                              |\n";
            std::cout << "------------------------------------------------\n";
        }
        if (optiuneMeniu == 2)
        {
            std::cout << "________________________________________________\n";
            std::cout << "|                                              |\n";
            std::cout << "|       Username: " << username;
            for (int i = 0; i < 29 - username.length(); i++) std::cout << " ";
            std::cout << "|\n";
            std::cout << "|     "; SetColore(2); std::cout << ">>Password:"; SetColore(7); std::cout << " ";
            if (password.length() > 1) std::cout << "******                       |\n";
            else std::cout << "                             |\n";
            std::cout << "|       Confirm password: ";
            if (confirmPassword.length() > 1) std::cout << "******               |\n";
            else std::cout << "                     |\n";
            std::cout << "|                                              |\n";
            std::cout << "|       Register                               |\n";
            std::cout << "|                                              |\n";
            std::cout << "------------------------------------------------\n";
        }
        if (optiuneMeniu == 3)
        {
            std::cout << "________________________________________________\n";
            std::cout << "|                                              |\n";
            std::cout << "|       Username: " << username;
            for (int i = 0; i < 29 - username.length(); i++) std::cout << " ";
            std::cout << "|\n";
            std::cout << "|       Password: ";
            if (password.length() > 1) std::cout << "******                       |\n";
            else std::cout << "                             |\n";
            std::cout << "|     "; SetColore(2); std::cout << ">>Confirm password:"; SetColore(7); std::cout << " ";
            if (confirmPassword.length() > 1) std::cout << "******               |\n";
            else std::cout << "                     |\n";
            std::cout << "|                                              |\n";
            std::cout << "|       Register                               |\n";
            std::cout << "|                                              |\n";
            std::cout << "------------------------------------------------\n";
        }
        if (optiuneMeniu == 4)
        {
            std::cout << "________________________________________________\n";
            std::cout << "|                                              |\n";
            std::cout << "|       Username: " << username;
            for (int i = 0; i < 29 - username.length(); i++) std::cout << " ";
            std::cout << "|\n";
            std::cout << "|       Password: ";
            if (password.length() > 1) std::cout << "******                       |\n";
            else std::cout << "                             |\n";
            std::cout << "|       Confirm password: ";
            if (confirmPassword.length() > 1) std::cout << "******               |\n";
            else std::cout << "                     |\n";
            std::cout << "|                                              |\n";
            std::cout << "|     "; SetColore(2); std::cout << ">>Register"; SetColore(7); std::cout << "                               |\n";
            std::cout << "|                                              |\n";
            std::cout << "------------------------------------------------\n";
        }
        SetColore(12);
        if (error == 1) std::cout << "Deja există un utilizator cu acest username.\n";
        if (error == 2) std::cout << "Campuri goale sau input-uri invalide.\n";
        if (error == 3) std::cout << "Parolele nu coincid.\n";
        SetColore(7);
        gotoxy(-1, -1);
        keyInput =  _getch();
        if (keyInput == KEY_UP)
        {
            if (optiuneMeniu == 1) optiuneMeniu = 4;
            else optiuneMeniu--;
        }
        else if (keyInput == KEY_DOWN)
        {
            if (optiuneMeniu == 4) optiuneMeniu = 1;
            else optiuneMeniu++;
        }
        else if (keyInput == ENTER)
        {
            switch (optiuneMeniu)
            {
            case 1:
                gotoxy(18, 2);
                std::getline(std::cin, username);
                for (auto i : users) {
                    if (i.username == username) { error = 1; username = ""; password = ""; confirmPassword = ""; }
                }
                break;
            case 2:
                gotoxy(18, 3);
                std::getline(std::cin, password);
                break;
            case 3:
                gotoxy(26, 4);
                std::getline(std::cin, confirmPassword);
                break;
            case 4:
                if (username.size() < 2 || password.size() < 2 || confirmPassword.size() < 2) { error = 2; username = ""; password = ""; confirmPassword = ""; } //campuri goale
                if (password != confirmPassword) { error = 3; username = ""; password = ""; confirmPassword = ""; } //parolele nu coincid
                password = std::to_string(hashPassword(password));
                User user(username, password, getMemorie(), {}, {}, {});
                users.push_back(user);
                saveUsers(users);
                return user;
            }
            if (optiuneMeniu == 4) optiuneMeniu = 1;
            else optiuneMeniu++;
        }
    }
}

User loginUser(std::vector<User> users, int error = 0)
{
    User loginThisUser;
    int found = 0;
    std::string username = " ";
    std::string password = " ";
    int okToLogin = 0;
    int optiuneMeniu = 1;
    int keyInput;
    int cond = 1;
    while (cond) {
        system("cls");
        if (optiuneMeniu == 1)
        {
            std::cout << "________________________________________________\n";
            std::cout << "|                                              |\n";
            std::cout << "|     "; SetColore(2); std::cout << ">>Username:"; SetColore(7); std::cout << " " << username;
            for (int i = 0; i < 29 - username.length(); i++) std::cout << " ";
            std::cout << "|\n";
            std::cout << "|       Password: ";
            if (password.length() > 1) std::cout << "******                       |\n";
            else std::cout << "                             |\n";
            std::cout << "|                                              |\n";
            std::cout << "|       Log in                                 |\n";
            std::cout << "|       Register                               |\n";
            std::cout << "|                                              |\n";
            std::cout << "------------------------------------------------\n";
        }
        if (optiuneMeniu == 2)
        {
            std::cout << "________________________________________________\n";
            std::cout << "|                                              |\n";
            std::cout << "|       Username: " << username;
            for (int i = 0; i < 29 - username.length(); i++) std::cout << " ";
            std::cout << "|\n";
            std::cout << "|     "; SetColore(2); std::cout << ">>Password:"; SetColore(7); std::cout << " ";
            if (password.length() > 1) std::cout << "******                       |\n";
            else std::cout << "                             |\n";
            std::cout << "|                                              |\n";
            std::cout << "|       Log in                                 |\n";
            std::cout << "|       Register                               |\n";
            std::cout << "|                                              |\n";
            std::cout << "------------------------------------------------\n";
        }
        if (optiuneMeniu == 3)
        {
            std::cout << "________________________________________________\n";
            std::cout << "|                                              |\n";
            std::cout << "|       Username: " << username;
            for (int i = 0; i < 29 - username.length(); i++) std::cout << " ";
            std::cout << "|\n";
            std::cout << "|       Password: ";
            if (password.length() > 1) std::cout << "******                       |\n";
            else std::cout << "                             |\n";
            std::cout << "|                                              |\n";
            std::cout << "|     "; SetColore(2); std::cout << ">>Log in"; SetColore(7); std::cout << "                                 |\n";
            std::cout << "|       Register                               |\n";
            std::cout << "|                                              |\n";
            std::cout << "------------------------------------------------\n";
        }
        if (optiuneMeniu == 4)
        {
            std::cout << "________________________________________________\n";
            std::cout << "|                                              |\n";
            std::cout << "|       Username: " << username;
            for (int i = 0; i < 29 - username.length(); i++) std::cout << " ";
            std::cout << "|\n";
            std::cout << "|       Password: ";
            if (password.length() > 1) std::cout << "******                       |\n";
            else std::cout << "                             |\n";
            std::cout << "|                                              |\n";
            std::cout << "|       Log in                                 |\n";
            std::cout << "|     "; SetColore(2); std::cout << ">>Register"; SetColore(7); std::cout << "                               |\n";
            std::cout << "|                                              |\n";
            std::cout << "------------------------------------------------\n";
        }
        SetColore(12);
        if (error == 1) std::cout << "Nu am gasit un utilizator cu acest username.\n";
        if (error == 2) std::cout << "Parola incorecta.\n";
        if (error == 3) std::cout << "Campuri incomplete sau date gresite.\n";
        SetColore(7);
        keyInput =  _getch();
        if (keyInput == KEY_UP)
        {
            if (optiuneMeniu == 1) optiuneMeniu = 4;
            else optiuneMeniu--;
        }
        else if (keyInput == KEY_DOWN)
        {
            if (optiuneMeniu == 4) optiuneMeniu = 1;
            else optiuneMeniu++;
        }
        else if (keyInput == ENTER)
        {
            switch (optiuneMeniu)
            {
            case 1:
                gotoxy(18, 2);
                std::getline(std::cin, username);
                for (auto i : users)
                {
                    if (i.username == username)
                    {
                        loginThisUser = i;
                        found = 1;
                    }
                }
                if (found == 0) { error = 1; username = ""; password = ""; };
                break;
            case 2:
                gotoxy(18, 3);
                std::getline(std::cin, password);
                password = std::to_string(hashPassword(password));
                if (loginThisUser.password != password) { error = 2; username = ""; password = ""; }
                else okToLogin = 1;
                break;
            case 3:
                if (okToLogin == 1) return loginThisUser;
                else { error = 3; username = ""; password = ""; }
                break;
            case 4:
                loginThisUser = registerUser(users);
                return loginThisUser;
            }
            if (optiuneMeniu == 3) optiuneMeniu = 1;
            else optiuneMeniu++;
        }

    }
}

Joc getGameByNames(std::vector<Joc> Jocuri, std::string numeJoc)
{
    for (auto x : Jocuri)
    {
        if (x.nume == numeJoc) return x;
    }
}

void istoricComenzi(const User& user, const std::vector<Comanda>& comenzi)
{
    int cond = 1;
    while (cond)
    {
        system("cls");
        if (user.comenzi.size() == 0)
        {
            SetColore(12); std::cout << "Inca nu ati facut comenzi."; SetColore(9);
            std::cout << "\n\n Press anything to continue.";
            SetColore(7);

            cond =  _getch();
            cond = 0;
        }
        else
        {
            for (int i : user.comenzi)
            {
                std::cout << "Comanda numarul: " << i + 1 << ";\n";
            }
            int nrComanda;
            std::cout << "Introduceti nr comenzii pentru afisarea detaliilor, sau introduceti 0 pentru a va reintoarce in meniu.\n";
            SetColore(9); std::cout << "INPUT: "; SetColore(7); std::cin >> nrComanda; std::cin.ignore();
            nrComanda--;
            if (nrComanda == -1) return;
            for (auto i : user.comenzi)
            {
                if (i == nrComanda) std::cout << std::endl << comenzi[nrComanda];
            }
            std::cout << std::endl;
            SetColore(12); std::cout << "0) Return to menu\n"; SetColore(9);
            std::cout << "1) Raman in istoric comenzi\nINPUT: "; SetColore(7);
            std::cin >> cond; std::cin.ignore();
            if (cond != 0 && cond != 1) cond = 0;
        }
    }
}

void optiuniJoc(Joc& joc, User& user) {
    int cond = 1;
    int error = 0;
    while (cond)
    {
        system("cls");
        std::cout << joc;
        std::cout << user.jocuriInstalate.size() << std::endl;
        if (error == 1)
        {
            SetColore(12);
            std::cout << "Dimensiunea jocului este mai mare decat memoria disponibila.\n";
            SetColore(7);
        }
        SetColore(2); if (joc.instalat == false) std::cout << "1) Instalare\n";
        else { SetColore(12); std::cout << "1) Dezinstalare\n"; }
        SetColore(12); std::cout << "0) Exit\n";
        int optiuneAleasa;
        SetColore(9); std::cout << "INPUT: "; SetColore(7); std::cin >> optiuneAleasa; std::cin.ignore();
        if (optiuneAleasa == 1)
        {
            if (joc.instalat == false)
            {
                if (joc.dimensiune <= user.memorie)
                {
                    joc.instalat = true;
                    user.jocuriInstalate.push_back(joc);
                }
                else error = 1;
            }
            else
            {
                joc.instalat = false;
                for (int i = 0; i < user.jocuriInstalate.size(); i++)
                {
                    if (joc.nume == user.jocuriInstalate[i].nume) user.jocuriInstalate.erase(user.jocuriInstalate.begin() + i);
                }
            }
        }
        else if (optiuneAleasa == 0) cond = 0;
    }

}

void jocuriUser(User& user)
{
    int cond = 1;
    int idJoc;
    while (cond)
    {
        system("cls");
        for (int i = 0; i < user.jocuriDetinute.size(); i++)
        {
            SetColore(9); std::cout << i + 1 << ") "; SetColore(7); std::cout << user.jocuriDetinute[i].nume << "\n";
        }
        SetColore(12); std::cout << "0) Exit\n";
        SetColore(9); std::cout << "INPUT: "; SetColore(7); std::cin >> idJoc; std::cin.ignore();
        idJoc--;
        if (idJoc == -1) cond = 0;
        else
            optiuniJoc(user.jocuriDetinute[idJoc], user);

    }
    std::cout << user.jocuriInstalate.size();
}

void actualizareUser(std::vector<User>& users, const User user)
{
    int poz = -1;
    for (int i = 0; i < users.size(); i++) if (users[i].username == user.username) { poz = i; break; }
    if (poz != -1)
    {
        users.erase(users.begin() + poz);
        users.insert(users.begin() + poz, user);
    }
    else
    {
        users.push_back(user);
    }
}

int logged = 0;

void listaJocuri(std::vector<Joc> Jocuri, std::vector<User>& users, std::vector<Comanda>& comenzi, User& user)
{
    system("cls");
    int input;
    for (int i = 0; i < Jocuri.size(); i++)
    {
        SetColore(9); std::cout << i + 1 << ") ";  SetColore(7); std::cout << Jocuri[i] << "\n\n";
    }
    SetColore(12); std::cout << "0) Exit\n";
    SetColore(9); std::cout << "INPUT: "; SetColore(7); std::cin >> input; std::cin.ignore();
    input--;
    if (input == -1) return;
    printFindThis(Jocuri[input].nume, Jocuri, users, comenzi, user);
}

void printFindThis(std::string findThis, std::vector<Joc> Jocuri, std::vector<User>& users, std::vector<Comanda>& comenzi, User& user)
{
    system("cls");
    int found = 0;
    int om;
    Joc joc;
    for (auto i : Jocuri) if (i.nume == findThis) { std::cout << i; found = 1; joc = i; break; }
    SetColore(12); if (found == 0) std::cout << "Jocul nu a fost gasit.\n";
    SetColore(7);
    found = 0;
    for (auto j : user.jocuriDetinute) if (j.nume == joc.nume) found = 1;
    SetColore(2); if (found == 1) std::cout << "Acest joc se afla deja in lista voastra de jocuri.\n";
    else std::cout << "1) Cumparare\n";
    SetColore(12);
    std::cout << "0) Exit\n";
    SetColore(9); std::cout << "INPUT: "; SetColore(7); std::cin >> om; std::cin.ignore();
    if (om == 1 && found == 0)
    {
        user.jocuriDetinute.push_back(joc);
        user.jocuriDetinute.back().instalat = false;
        Comanda c(user.username, { joc }, joc.pret);
        comenzi.push_back(c);
        int sizeComenzi = comenzi.size();
        sizeComenzi--;
        user.comenzi.push_back(sizeComenzi);

        actualizareUser(users, user);
        saveUsers(users);
    }
    else return;
}

void findGameByName(const std::vector<Joc> Jocuri, std::vector<User>& users, std::vector<Comanda>& comenzi, User& user)
{
    int cond = 1;
    int optiuneMeniu = 1;
    std::string findThis;
    int keyInput;
    while (cond)
    {
        system("cls");
        if (optiuneMeniu == 1)
        {
            std::cout << "________________________________________________\n";
            std::cout << "|                                              |\n";
            std::cout << "|        "; SetColore(2); std::cout << ">>Search:"; SetColore(7); std::cout << " ";
            if (findThis.size() < 1) std::cout << "                            ";
            else { std::cout << findThis; for (int i = 0; i < 28 - findThis.size(); i++) std::cout << " "; }
            std::cout << "|\n";
            std::cout << "|                                              |\n";
            std::cout << "|                     Search                   |\n";
            std::cout << "|                                              |\n";
            std::cout << "------------------------------------------------\n";
        }
        if (optiuneMeniu == 2)
        {
            std::cout << "________________________________________________\n";
            std::cout << "|                                              |\n";
            std::cout << "|          Search: ";
            if (findThis.size() < 1) std::cout << "                            ";
            else { std::cout << findThis; for (int i = 0; i < 28 - findThis.size(); i++) std::cout << " "; }
            std::cout << "|\n";
            std::cout << "|                                              |\n";
            std::cout << "|                   "; SetColore(2); std::cout << ">>Search"; SetColore(7); std::cout << "                   |\n";
            std::cout << "|                                              |\n";
            std::cout << "------------------------------------------------\n";
        }
        keyInput =  _getch();
        if (keyInput == KEY_UP)
        {
            if (optiuneMeniu == 1) optiuneMeniu = 2;
            else optiuneMeniu--;
        }
        else if (keyInput == KEY_DOWN)
        {
            if (optiuneMeniu == 2) optiuneMeniu = 1;
            else optiuneMeniu++;
        }
        else if (keyInput == ENTER)
        {
            switch (optiuneMeniu)
            {
            case 1:
                gotoxy(19, 2);
                std::getline(std::cin, findThis);
                break;
            case 2:
                if (findThis.size() > 0)
                {
                    printFindThis(findThis, Jocuri, users, comenzi, user);
                    cond = 0;
                }
                break;
            }
            optiuneMeniu++;
        }
    }
}

void optiuniBundlePack(std::vector<User>& users, std::vector<Comanda>& comenzi, const BundlePacks& bundlePack, User& user)
{
    std::cout << bundlePack;
    std::cout << "\n\n";
    int disponibil = 1, alegere;
    for (auto i : user.jocuriDetinute)
    {
        for (auto j : bundlePack.Jocuri)
        {
            if (i.nume == j.nume)
            {
                disponibil = 0;
                break;
            }
        }
    }
    if (disponibil == 0)
    {
        SetColore(12); std::cout << "Aceasta oferta nu mai este disponibila pentru dumneavoastra, deoarece deja detineti unu sau mai multe jocuri din oferta.\n";
    }
    else
    {
        SetColore(2); std::cout << "1) Cumparare\n";
    }
    SetColore(12); std::cout << "0) Exit\n";
    SetColore(9); std::cout << "INPUT: "; SetColore(7); std::cin >> alegere; std::cin.ignore();
    if (alegere == 1 && disponibil == 1)
    {
        for (auto i : bundlePack.Jocuri) user.jocuriDetinute.push_back(i);
        Comanda comanda(bundlePack.nume, bundlePack.Jocuri, bundlePack.pret);
        comenzi.push_back(comanda);
        user.comenzi.push_back(comenzi.size() - 1);
    }
}

void listaOferte(const std::vector<Joc> Jocuri, std::vector<User>& users, std::vector<Comanda>& comenzi, const std::vector<BundlePacks>& bundlePacks, User& user)
{
    system("cls");
    for (int i = 0; i < bundlePacks.size(); i++)
    {
        SetColore(9); std::cout << i + 1 << ")"; SetColore(7); std::cout << bundlePacks[i].nume << "\n";
    }
    int ofertaAleasa;
    SetColore(12); std::cout << "0) Exit\n";
    SetColore(9); std::cout << "INPUT: "; SetColore(7); std::cin >> ofertaAleasa; std::cin.ignore(); ofertaAleasa--;
    if (ofertaAleasa != -1)
    {
        optiuniBundlePack(users, comenzi, bundlePacks[ofertaAleasa], user);
    }
}

void discover(const std::vector<Joc> Jocuri, std::vector<User>& users, std::vector<Comanda>& comenzi, const std::vector<BundlePacks>& bundlePacks, User& user)
{
    int optiuneMeniu = 1;
    int keyInput;
    int cond = 1;
    while (cond) {
        system("cls");
        if (optiuneMeniu == 1)
        {
            std::cout << "________________________________________________\n";
            std::cout << "|                                              |\n";
            std::cout << "|          "; SetColore(2); std::cout << ">>Cauta jocuri dupa nume"; SetColore(7); std::cout << "            |\n";
            std::cout << "|                 Lista jocuri                 |\n";
            std::cout << "|                    Oferte                    |\n";
            std::cout << "|               Inapoi in meniu                |\n";
            std::cout << "|                                              |\n";
            std::cout << "------------------------------------------------\n";
        }
        if (optiuneMeniu == 2)
        {
            std::cout << "________________________________________________\n";
            std::cout << "|                                              |\n";
            std::cout << "|            Cauta jocuri dupa nume            |\n";
            std::cout << "|               "; SetColore(2); std::cout << ">>Lista jocuri"; SetColore(7); std::cout << "                 |\n";
            std::cout << "|                    Oferte                    |\n";
            std::cout << "|               Inapoi in meniu                |\n";
            std::cout << "|                                              |\n";
            std::cout << "------------------------------------------------\n";
        }
        if (optiuneMeniu == 3)
        {
            std::cout << "________________________________________________\n";
            std::cout << "|                                              |\n";
            std::cout << "|            Cauta jocuri dupa nume            |\n";
            std::cout << "|                 Lista jocuri                 |\n";
            std::cout << "|                  "; SetColore(2); std::cout << ">>Oferte"; SetColore(7); std::cout << "                    |\n";
            std::cout << "|               Inapoi in meniu                |\n";
            std::cout << "|                                              |\n";
            std::cout << "------------------------------------------------\n";
        }
        if (optiuneMeniu == 4)
        {
            std::cout << "________________________________________________\n";
            std::cout << "|                                              |\n";
            std::cout << "|            Cauta jocuri dupa nume            |\n";
            std::cout << "|                 Lista jocuri                 |\n";
            std::cout << "|                    Oferte                    |\n";
            std::cout << "|             "; SetColore(2); std::cout << ">>Inapoi in meniu"; SetColore(7); std::cout << "                |\n";
            std::cout << "|                                              |\n";
            std::cout << "------------------------------------------------\n";
        }
        keyInput =  _getch();
        if (keyInput == KEY_UP)
        {
            if (optiuneMeniu == 1) optiuneMeniu = 4;
            else optiuneMeniu--;
        }
        else if (keyInput == KEY_DOWN)
        {
            if (optiuneMeniu == 4) optiuneMeniu = 1;
            else optiuneMeniu++;
        }
        else if (keyInput == ENTER)
        {
            switch (optiuneMeniu)
            {
            case 1:
                findGameByName(Jocuri, users, comenzi, user);
                break;
            case 2:
                listaJocuri(Jocuri, users, comenzi, user);
                break;
            case 3:
                listaOferte(Jocuri, users, comenzi, bundlePacks, user);
            case 4:
                cond = 0;
                break;
            }
        }
    }
}

int student2()
{
    std::vector<Joc> Jocuri = getGame();
    std::vector<User> users = getUsers(Jocuri);
    std::vector<Comanda> comenzi = getComenzi(Jocuri);
    std::vector<BundlePacks> bundlePacks = getBundlePacks(Jocuri);
    //for(auto i : Jocuri) std::cout<<i;
    //vizualizareCatalogPerCategrii(Jocuri);
    //registerUser(users);
    //User user = loginUser(users);
    int optiuneMeniu = 1;
    int keyInput;
    User user;
    while (1) {
        system("cls");
        if (logged == 0)
        {
            if (optiuneMeniu == 1)
            {
                std::cout << "________________________________________________\n";
                std::cout << "|                                              |\n";
                std::cout << "|               "; SetColore(2); std::cout << ">>Catalog"; SetColore(7); std::cout << "                      |\n";
                std::cout << "|                  Login                       |\n";
                std::cout << "|                 Register                     |\n";
                std::cout << "|                                              |\n";
                std::cout << "------------------------------------------------\n";
            }
            if (optiuneMeniu == 2)
            {
                std::cout << "________________________________________________\n";
                std::cout << "|                                              |\n";
                std::cout << "|                 Catalog                      |\n";
                std::cout << "|                "; SetColore(2); std::cout << ">>Login"; SetColore(7); std::cout << "                       |\n";
                std::cout << "|                 Register                     |\n";
                std::cout << "|                                              |\n";
                std::cout << "------------------------------------------------\n";
            }
            if (optiuneMeniu == 3)
            {
                std::cout << "________________________________________________\n";
                std::cout << "|                                              |\n";
                std::cout << "|                 Catalog                      |\n";
                std::cout << "|                  Login                       |\n";
                std::cout << "|               "; SetColore(2); std::cout << ">>Register"; SetColore(7); std::cout << "                     |\n";
                std::cout << "|                                              |\n";
                std::cout << "------------------------------------------------\n";
            }
            keyInput =  _getch();
            if (keyInput == KEY_UP)
            {
                if (optiuneMeniu == 1) optiuneMeniu = 3;
                else optiuneMeniu--;
            }
            else if (keyInput == KEY_DOWN)
            {
                if (optiuneMeniu == 3) optiuneMeniu = 1;
                else optiuneMeniu++;
            }
            else if (keyInput == ENTER)
            {
                switch (optiuneMeniu)
                {
                case 1:
                    Catalog(Jocuri, bundlePacks);
                    break;
                case 2:
                    user = loginUser(users);
                    logged = 1;
                    optiuneMeniu = 1;
                    break;
                case 3:
                    user = registerUser(users);
                    logged = 1;
                    optiuneMeniu = 1;
                    break;
                }
            }
        }
        else
        {
            if (optiuneMeniu == 1)
            {
                std::cout << "________________________________________________\n";
                std::cout << "|                                              |\n";
                std::cout << "|               "; SetColore(2); std::cout << ">>Catalog"; SetColore(7); std::cout << "                      |\n";
                std::cout << "|              Istoric Comenzi                 |\n";
                std::cout << "|                 Discover                     |\n";
                std::cout << "|               Jocurile mele                  |\n";
                std::cout << "|                                              |\n";
                std::cout << "------------------------------------------------\n";
            }
            if (optiuneMeniu == 2)
            {
                std::cout << "________________________________________________\n";
                std::cout << "|                                              |\n";
                std::cout << "|                 Catalog                      |\n";
                std::cout << "|            "; SetColore(2); std::cout << ">>Istoric Comenzi"; SetColore(7); std::cout << "                 |\n";
                std::cout << "|                 Discover                     |\n";
                std::cout << "|               Jocurile mele                  |\n";
                std::cout << "|                                              |\n";
                std::cout << "------------------------------------------------\n";
            }
            if (optiuneMeniu == 3)
            {
                std::cout << "________________________________________________\n";
                std::cout << "|                                              |\n";
                std::cout << "|                 Catalog                      |\n";
                std::cout << "|              Istoric Comenzi                 |\n";
                std::cout << "|               "; SetColore(2); std::cout << ">>Discover"; SetColore(7); std::cout << "                     |\n";
                std::cout << "|               Jocurile mele                  |\n";
                std::cout << "|                                              |\n";
                std::cout << "------------------------------------------------\n";
            }
            if (optiuneMeniu == 4)
            {
                std::cout << "________________________________________________\n";
                std::cout << "|                                              |\n";
                std::cout << "|                 Catalog                      |\n";
                std::cout << "|              Istoric Comenzi                 |\n";
                std::cout << "|                 Discover                     |\n";
                std::cout << "|             "; SetColore(2); std::cout << ">>Jocurile mele"; SetColore(7); std::cout << "                  |\n";
                std::cout << "|                                              |\n";
                std::cout << "------------------------------------------------\n";
            }
            keyInput =  _getch();
            if (keyInput == KEY_UP)
            {
                if (optiuneMeniu == 1) optiuneMeniu = 4;
                else optiuneMeniu--;
            }
            else if (keyInput == KEY_DOWN)
            {
                if (optiuneMeniu == 4) optiuneMeniu = 1;
                else optiuneMeniu++;
            }
            else if (keyInput == ENTER)
            {
                switch (optiuneMeniu)
                {
                case 1:
                    Catalog(Jocuri, bundlePacks);
                    break;
                case 2:
                    istoricComenzi(user, comenzi);
                    break;
                case 3:
                    discover(Jocuri, users, comenzi, bundlePacks, user);
                    break;
                case 4:
                    jocuriUser(user);
                }
            }
        }
        if (logged == 1)actualizareUser(users, user);

        saveUsers(users);
        saveComenzi(comenzi);

    }
    //afisareJocuriDinCategorie(Jocuri, "FPS");
    //std::cout<<hashPassword("abecedar123");
};

