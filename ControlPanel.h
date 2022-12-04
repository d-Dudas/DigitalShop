#ifndef ControlPanel_H
#define ControlPanel_H


#include <iostream>
#include <string>
#include "Joc.h"
#include "User.h"
#include "BundlePacks.h"
#include <vector>
#include <fstream>
#include <windows.h>
#include<conio.h>
using namespace std;
#define blue 1
#define green 2
#define red 4
#define cyan 9
#define gold 6
#define white 15
void Meniu();
void citireJoc();
void afisare();
vector<Joc> getGames();
void StergeJoc();
void EditeazaJoc();
void Editeaza(Joc&);
void StergeOferta();
Joc getGameByName(vector<Joc>, string);


void SetColor(int value){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  value);
}

Joc getGameByName(std::vector<Joc> Jocuri, std::string numeJoc)
{
    for(auto x : Jocuri)
    {
        if(x.nume == numeJoc) return x;
    }
}



void scriereJoc(){
ofstream m;
SetColor(red);
cout<<"<====";
SetColor(10);
cout<<"  Introdu Joc  ";
SetColor(red);
cout<<"====>\n";
m.open("jocuri.txt",ios::app);
string vanzari="0";
string st;
getline(cin,st);
m<<vanzari<<"\n";
cout<<endl;
SetColor(gold);
cout<<"nume:";
SetColor(white);
getline(cin,st);
m<<st<<"\n";
SetColor(gold);

cout<<endl<<"categorie:";
SetColor(white);
getline(cin,st);
m<<st<<"\n";
SetColor(gold);
cout<<endl<<"dimensiune:";
SetColor(white);
getline(cin,st);
m<<st<<"\n";
SetColor(gold);
cout<<endl<<"pret:";
SetColor(white);
getline(cin,st);
m<<st<<"\n";
st="false";
m<<st<<"\n";
system("CLS");
m.close();
Meniu();
}

void EditeazaJoc(){
vector <Joc> JOCURI;
SetColor(red);
cout<<"<====";
SetColor(10);
cout<<"  Editare Jocuri  ";
SetColor(red);
cout<<"====>\n";
JOCURI=getGames();
SetColor(red);
cout<<"0)";
SetColor(white);
cout<<"Meniu\n";
for(int i=0; i < JOCURI.size();i++)
    {SetColor(green);cout<<i+1<<")"<<JOCURI[i].Getnume()<<"\n";}

int alegere;
do{
    SetColor(gold);
    cout<<"Alege:";
SetColor(white);
    cin>>alegere;
}while((alegere<0)||(alegere>JOCURI.size()));
if(alegere==0)system("CLS");
else {system("CLS");Editeaza(JOCURI[alegere-1]);}

ofstream m;
m.open("jocuri.txt",ios::trunc);
for(int i=0; i < JOCURI.size();i++)
{
m<<JOCURI[i].Getvanzari()<<"\n";
m<<JOCURI[i].Getnume()<<"\n";
m<<JOCURI[i].Getcategorie()<<"\n";
m<<JOCURI[i].Getdimensiune()<<"\n";
m<<JOCURI[i].Getpret()<<"\n";
m<<"false\n";
}
m.close();
Meniu();
}

void Editeaza(Joc &JOCURI){
SetColor(red);
cout<<"<====";
SetColor(10);
cout<<"  Editeaza Jocul  ";
SetColor(red);
cout<<"====>\n";
cout<<JOCURI;
SetColor(red);
cout<<"0)";
SetColor(blue);
cout<<"Meniu\n";
SetColor(green);
cout<<"1)";
SetColor(blue);
cout<<"Nume\n";
SetColor(green);
cout<<"2)";
SetColor(blue);
cout<<"Categorie\n";
SetColor(green);
cout<<"3)";
SetColor(blue);
cout<<"Dimensiune\n";
SetColor(green);
cout<<"4)";
SetColor(blue);
cout<<"Pret\n";
int alg;
do{SetColor(gold);
    cout<<"Alegere:";
    SetColor(white);
    cin>>alg;

}while((alg<0)||(alg>4));
if(alg==0){system("CLS");Meniu();}
if(alg==1){
        string st;
        cout<<"NUME:";
        getline(cin,st);
        getline(cin,st);
        JOCURI.Setnume(st);
        system("CLS");
}
if(alg==2)
    {
        string st;
        cout<<"Categorie:";
        getline(cin,st);
        getline(cin,st);
        JOCURI.Setcategorie(st);
        system("CLS");
}
if(alg==3)
    {
        string st;
        cout<<"Dimensiune:";
        getline(cin,st);
        getline(cin,st);
        JOCURI.Setdimensiune(stoi(st));
        system("CLS");
}
if(alg==4)
    {
        string st;
        cout<<"Pret:";
        getline(cin,st);
        getline(cin,st);
        JOCURI.Setpret(stoi(st));
        system("CLS");
}
}

void StergeJoc(){
SetColor(red);
cout<<"<====";
SetColor(10);
cout<<"  Sterge Joc  ";
SetColor(red);
cout<<"====>\n";
vector <Joc> JOCURI;
JOCURI=getGames();
SetColor(red);
cout<<"0)";
SetColor(white);
cout<<"Meniu\n";
for(int i=0; i < JOCURI.size();i++)
    {SetColor(green);cout<<i+1<<")";
    SetColor(blue);
    cout<<JOCURI[i].Getnume()<<"\n";}

int alegere;
do{SetColor(gold);
    cout<<"Alege:";
    SetColor(white);
    cin>>alegere;
}while((alegere<0)||(alegere>JOCURI.size()));
if(alegere==0){system("CLS");Meniu();}
else{
    JOCURI.erase(JOCURI.begin()+alegere-1);
}
system("CLS");
ofstream m;
m.open("jocuri.txt",ios::trunc);

for(int i=0; i < JOCURI.size();i++)
{
m<<JOCURI[i].Getvanzari()<<"\n";
m<<JOCURI[i].Getnume()<<"\n";
m<<JOCURI[i].Getcategorie()<<"\n";
m<<JOCURI[i].Getdimensiune()<<"\n";
m<<JOCURI[i].Getpret()<<"\n";
m<<"false\n";
}
m.close();
Meniu();
}


vector<Joc> getGames(){
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
        if(sinstalat == "true") instalat = true;
        else instalat = false;

        Joc joc(nume, categorie, dimensiune, pret, vanzari, instalat);
        gamesList.push_back(joc);
    }

    return gamesList;
}


void administrareJoc(){
SetColor(red);
cout<<"<====";
SetColor(10);
cout<<"  Administrare Jocuri  ";
SetColor(red);
cout<<"====>\n";
SetColor(red);
cout<<"0)";
SetColor(cyan);
cout<<"Meniu\n";
SetColor(green);cout<<"1)";
SetColor(cyan);
cout<<"Adauga joc\n";
SetColor(green);
cout<<"2)";
SetColor(cyan);
cout<<"Sterge joc\n";
SetColor(green);
cout<<"3)";
SetColor(cyan);
cout<<"Editeaza jocuri\n";
int decizie;
do{SetColor(gold);
        cout<<"Alege:";
        SetColor(white);
cin>>decizie;
}while((decizie<0)&&(decizie>3));
system("CLS");
if(decizie==0){system("CLS");Meniu();}
if(decizie==1)
    scriereJoc();
if(decizie==2)
    StergeJoc();
if(decizie==3)
    EditeazaJoc();
}

void AdaugaOferta(){
SetColor(red);
cout<<"<====";
SetColor(10);
cout<<"  Adauga Oferta  ";
SetColor(red);
cout<<"====>\n";
    string st;
    ofstream m;
getline(cin,st);
m.open("bundlePacks.txt",ios::app);
SetColor(gold);
cout<<"Nume oferta: ";
SetColor(white);
getline(cin,st);
m<<st<<"\n";
SetColor(gold);
cout<<"numar jocuri in oferta: ";
SetColor(white)     ;
getline(cin,st);
int nr=stoi(st);
m<<st<<"\n";
for(int i=0;i<nr;i++)
{SetColor(gold);
    cout<<"Nume Joc: ";
    SetColor(white);
    getline(cin,st);
    m<<st<<"\n";
    }
    SetColor(gold);
    cout<<"Pret: ";
    SetColor(white);
    getline(cin,st);
    m<<st<<"\n";
    m.close();
system("CLS");
Meniu();
}



void administrareOferte(){
SetColor(red);
cout<<"<====";
SetColor(10);
cout<<"  Administrare Oferte  ";
SetColor(red);
cout<<"====>\n";
SetColor(red);
cout<<"0)";
SetColor(cyan);
cout<<"Meniu\n";
SetColor(green);
cout<<"1)";
SetColor(cyan);
cout<<"Adauga oferte\n";
SetColor(green);
cout<<"2)";
SetColor(cyan);
cout<<"Sterge oferte\n";

int decizie;
do{SetColor(gold);
        cout<<"Alege:";
        SetColor(white);
cin>>decizie;
}while((decizie<0)&&(decizie>2));
system("CLS");
if(decizie==0)Meniu();
if(decizie==1){system("CLS");AdaugaOferta();}
if(decizie==2){system("CLS");StergeOferta();}

}


void StergeOferta(){
std::vector<Joc> Jocuri = getGames();
SetColor(red);
cout<<"<====";
SetColor(10);
cout<<"  Sterge Oferte  ";
SetColor(red);
cout<<"====>\n";
ifstream file("bundlePacks.txt");
string nume;
SetColor(red);
cout<<"0)";
SetColor(white);
cout<<"Meniu\n";
SetColor(blue);
while(getline(file,nume))
{cout<<nume<<endl;
string st;
int nr;
 getline(file,st);
 nr=stoi(st);
 for(int i=0;i<nr;i++)
    getline(file,st);
getline(file,st);
}
string st;
file.close();
ifstream f("bundlePacks.txt");
cin.ignore();
SetColor(green);
cout<<"Nume:";
SetColor(white);
getline(cin,st);
ofstream out("Bundle.txt");
while(getline(f,nume)){
    if(nume!=st){
        string replacement;
        out<<nume<<"\n";
        getline(f,replacement);
        out<<replacement<<"\n";
        int nr=stoi(replacement);
        for(int i=0;i<nr;i++){
            getline(f,replacement);
        out<<replacement<<"\n";
        }
        getline(f,replacement);
        out<<replacement<<"\n";
    }
    else{
        string replacement;
        getline(f,replacement);
        int nr=stoi(replacement);
        for(int i=0;i<nr;i++){
            getline(f,replacement);
        }
        getline(f,replacement);
    }

}
f.close();
out.close();
if(remove("bundlePacks.txt"))cout<<"Sters\n";
if(rename("Bundle.txt","bundlePacks.txt"))cout<<"Redenumit\n";
system("PAUSE");
system("CLS");
Meniu();
}

void topGames(){
SetColor(red);
cout<<"<====";
SetColor(10);
cout<<"  TOP Games  ";
SetColor(red);
cout<<"====>\n";
vector<Joc> Jocuri=getGames();
for(int i=0;i<Jocuri.size()-1;i++)
    for(int j=i+1;j<Jocuri.size();j++)
    {
        if(Jocuri[i].Getvanzari()<Jocuri[j].Getvanzari()){
            Joc aux=Jocuri[i];
            Jocuri[i]=Jocuri[j];
            Jocuri[j]=aux;
        }
    }
for(auto i:Jocuri)
    cout<<i;
system("PAUSE");
system("CLS");
Meniu();

}


void Meniu(){
system("cls");
SetColor(red);
cout<<"<====";
SetColor(10);
cout<<"  MENIU  ";
SetColor(red);
cout<<"====>\n";
SetColor(green);
cout<<"1)";
SetColor(cyan);
cout<<" Administrare jocuri\n";
SetColor(green);
cout<<"2}";
SetColor(cyan);
cout<<"Administrare oferte\n";
SetColor(green);
cout<<"3)";
SetColor(cyan);
cout<<"vizualizare top games\n";
SetColor(red);
cout<<"0)";
SetColor(cyan);
cout<<"Exit\n";
int decizie;
do{SetColor(gold);
        cout<<"Alege:";
    SetColor(white);
cin>>decizie;
}while((decizie<0)||(decizie>3));
system("CLS");
if(decizie==1)administrareJoc();
if(decizie==2)administrareOferte();
if(decizie==3)topGames();
}

int student1()
{
Meniu();

    return 0;
}
#endif
