#include "Gracz.h"
#include <iostream>
#include <fstream>
//#include <stdio.h>

using namespace std;

Gracz::Gracz()
{
    Gracz::lacznaWygrana=0;
}


double Gracz::getMoney() {
    return Gracz::money;
}

void Gracz::setMoney(double m_) {
    Gracz::money=m_;
}

void Gracz::addMoney(double m_){
    Gracz::money=Gracz::money+m_;
}

void Gracz::setName(std::string n_) {
    Gracz::name=n_;
}

std::string Gracz::getName() {
    return Gracz::name;
}





int Gracz::wybor(int maks) {
    int wybrana;
    cout<<">>";
    cin>>wybrana;
    while (cin.fail() || wybrana>maks || wybrana<=0) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"/!\\ Blad. Wybierz liczbe zalkowita z zakresu od 1 do "<<maks<<endl;
        cin>>wybrana;
    }
    cin.clear();
    cin.ignore(1000,'\n');
    return wybrana;
}

int Gracz::wybor0(int maks) {
    int wybrana;
    cout<<">>";
    cin>>wybrana;
    while (cin.fail() || wybrana>maks || wybrana<0) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"/!\\ Blad. Wybierz liczbe zalkowita z zakresu od 0 do "<<maks<<endl;
        cin>>wybrana;
    }
    cin.clear();
    cin.ignore(1000,'\n');
    return wybrana;
}

void Gracz::Ranking() {
    double stawka=Gracz::lacznaWygrana;
    string name=Gracz::name;
    string * kto=new string[101];
    double * ile=new double[101];
    //zape³niæ zerami
    for (int i=0;i<101;i++) {
        kto[i]="---";
        ile[i]=0;
    }


    //odczyt po lini//zapisaæ do tab 101
    ifstream plik("top100.txt");
    string k;
    double l;
    int licznik=0;
    for (int i=0;i<100;i++) {
        while (!plik.eof()) {
            getline(plik,k);
            kto[licznik]=k;

            getline(plik,k);

            l=atof(k.c_str());


            ile[licznik]=l;

            licznik++;
        }
    }
    plik.close();

    /*for (int i=0;i<101;i++) {
        cout<<kto[i]<<endl;
        cout<<ile[i]<<endl;
    }*/


    //dopisaæ stawka i name do tab
    kto[100]=name;
    ile[100]=stawka;
    //zapisaæ do pliku segreguj¹c od najwieksej
    double najw;;
    int index;
    ofstream zapis("top100.temp");
    for (int i=0;i<100;i++) {
        najw=0;
        for (int j=0;j<101;j++) {
            if (ile[j]>=najw) {
                najw=ile[j];
                index=j;
            }
        }
        zapis<<kto[index];
        zapis<<endl;
        zapis<<ile[index];
        zapis<<endl;
        ile[index]=0;//by nie powtarzac
        kto[index]="---";
    }
    zapis.close();
    //delete and rename
    if (remove("top100.txt") == 0){
            rename("top100.temp","top100.txt");
        }
    delete[] kto;
    delete[] ile;
}

void Gracz::addWygrana(double ile_) {
    Gracz::lacznaWygrana=Gracz::lacznaWygrana+ile_;
}

double Gracz::getWygrana()
{
    return Gracz::lacznaWygrana;
}
