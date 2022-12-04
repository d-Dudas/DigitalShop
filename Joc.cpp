#include "Joc.h"
#include <iostream>
#include <windows.h>

#define blue 1
#define green 2
#define red 4
#define cyan 11
#define gold 6
#define white 15

void SetColors(int value){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  value);
}
Joc::Joc(std::string nume, std::string categorie, int dimensiune, double pret, int vanzari, bool instalat)
{
    this->nume = nume;
    this->categorie = categorie;
    this->dimensiune = dimensiune;
    this->pret = pret;
    this->vanzari = vanzari;
    this->instalat = instalat;
}
Joc::Joc(){
this->nume = "";
    this->categorie = "";
    this->dimensiune = 0;
    this->pret = 0;
    this->vanzari = 0;
    this->instalat = 0;
}

std::ostream& operator << (std::ostream& st, const Joc &x) {
    SetColors(gold);
    std::cout<<"Nume: ";
    SetColors(cyan);
    std::cout<<x.nume<<std::endl;
        SetColors(gold);
    std::cout<<"Categorie: ";
    SetColors(cyan);
    std::cout<<x.categorie<<std::endl;
    SetColors(gold);
    std::cout<<"Pret: ";
    SetColors(cyan);
    std::cout<<x.pret<<std::endl;
    SetColors(gold);
    std::cout<<"Dimensiune: ";
SetColors(cyan);
    std::cout<<x.dimensiune<<std::endl;
    SetColors(gold);
    std::cout<<"Nr. vanzari: ";
    SetColors(cyan);
    std::cout<<x.vanzari<<std::endl;
    std::cout<<std::endl;
SetColors(white);
    return st;
}
