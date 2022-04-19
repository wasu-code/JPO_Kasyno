#include "JednorekiBandyta.h"
#include <time.h>
#include <iostream>

using namespace std;

JednorekiBandyta::JednorekiBandyta() {

}

JednorekiBandyta::JednorekiBandyta(Gracz &G)
{
    srand(time(0));
    JednorekiBandyta::gra=1;
    JednorekiBandyta::wygrana=0;
    //ustal stawke
    cout<<endl<<"Rozpoczales gre w Jednorekiego Bandyte"<<endl;
    cout<<endl<<"O jaka stawke chcesz grac?"<<endl<<endl;
    JednorekiBandyta::stawka = G.wybor(G.getMoney());
    JednorekiBandyta::posiadane = G.getMoney();

    //graj

    //menu - wybierz nowa stawke, graj dalej, zakoncz

    //wygrana-ile zarobiono, stawka-o ile teraz gramy
    //ranking

    /*while (G.getMoney+JednorekiBandyta::wygrana>stawka) {
        menuJB();
    }*/
    while (JednorekiBandyta::gra!=0) {
        if (G.getMoney()+JednorekiBandyta::wygrana>=stawka) {
            menuJB();
        } else {
            cout<<endl<<"Nie stac Cie juz na taka stawke"<<endl;
            //+menu czy zmienic stawke czy wyjsc
            break;
        }
    }
    G.addMoney(JednorekiBandyta::wygrana);
    G.addWygrana(JednorekiBandyta::wygrana);
}

JednorekiBandyta::~JednorekiBandyta()
{
    //dtor
}

int JednorekiBandyta::menuJB() {
    cout<<endl<<"Stawka: "<<JednorekiBandyta::stawka<<" $";
    cout<<endl<<"   Twoj ruch:\n1)Graj\n2)Zmien stawke\n3)Zakoncz gre w Jednorekiego Bandyte"<<endl;

    switch (Gracz::wybor(3)) {
    case 1:
        {
        wyniki();
        break;
        }
    case 2:
        {
         JednorekiBandyta::zmienStawke();
         break;
        }
    case 3:
        {
        cout<<"Zakonczyles gre na tym stanowisku"<<endl;
        JednorekiBandyta::gra=0;
        break;
        }
    }

}

int JednorekiBandyta::wyniki() {
    //wylosuj sumbole i sprawdz wygrana; dodaj lub odejmij
    int los1,los2,los3;

    cout<<"           -------"<<endl;
    cout<<"Wylosowane: ";
    los1= rand()%10 %6;
    los2= rand()%10 %6;
    los3= rand()%10 %6;
    cout<<tab[los1]<<" ";
    cout<<tab[los2]<<" ";
    cout<<tab[los3]<<" ";
    cout<<endl<<"           -------"<<endl;

    if (los1==los2 && los2==los3) {
        cout<<endl<<"        Wygrana! Wszystkie 3!!"<<endl;
        JednorekiBandyta::wygrana=JednorekiBandyta::wygrana+stawka;
    } else if (los1==los2 || los2==los3 || los1==los3) {
        cout<<endl<<"        Nie tym razem"<<endl;
    } else {
        cout<<endl<<"        Przegrana!"<<endl;
        JednorekiBandyta::wygrana=JednorekiBandyta::wygrana-stawka;
        return 0;
    }
    return 1;
}

void JednorekiBandyta::zmienStawke() {
    double nowaStawka;
    if (JednorekiBandyta::posiadane+JednorekiBandyta::wygrana>0) {
        cout<<"Podaj nowa stawke: "<<endl;
        nowaStawka=Gracz::wybor(JednorekiBandyta::posiadane+JednorekiBandyta::wygrana);
    } else {
        cout<<"Nie posiadasz juz pieniedzy"<<endl;
    }
    JednorekiBandyta::stawka=nowaStawka;
}
