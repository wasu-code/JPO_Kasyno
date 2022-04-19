#include "BlackJack.h"
#include <iostream>
#include <time.h>
#include <unistd.h>

using namespace std;

BlackJack::BlackJack() {

}

BlackJack::BlackJack(Gracz &G) /*: Gracz()*/
{

    cout<<endl<<"Rozpoczales gre w BlackJack"<<endl;
    cout<<endl<<"O jaka stawke chcesz grac?"<<endl<<endl;
    BlackJack::stawka = G.wybor(G.getMoney());
    BlackJack::posiadane=G.getMoney();
    //


    srand(time(0));
    //dwie karty dla krupiera
    BlackJack::losojKarte('K');
    BlackJack::losojKarte('K');
    //dwie twoje
    BlackJack::losojKarte('G');
    BlackJack::losojKarte('G');


    BlackJack::menuBJ();

    G.setMoney(G.getMoney()+BlackJack::stawka);


    G.addWygrana(BlackJack::stawka);
}

BlackJack::~BlackJack()
{
    //dtor
}

void BlackJack::menuBJ() {
    int a=1,b=1;
    while (a) {
        cout<<endl<<"   Twoj ruch:\n1)hit\n2)stand\n3)double down\n4)Zakoncz gre w BlackJack'a"<<endl;

        //karty
        cout<<"Twoje Karty: ";
        BlackJack::pokazKarty(11,'G');
        cout<<endl<<"Karty Krupiera: ";
        BlackJack::pokazKarty(1,'K');
        cout<<endl;

        switch (Gracz::wybor(4)) {
        case 1:
            {
                //losoj,oblicz
                BlackJack::losojKarte('G');//losuje i zapisuje do tabG
                if (BlackJack::oblicz('G')>21) {
                    cout<<"        Przegrana"<<endl;
                    BlackJack::stawka=0-BlackJack::stawka;
                    a=0;
                    cout<<"Twoje Karty: ";
                    BlackJack::pokazKarty(11,'G');
                    cout<<endl<<"Karty Krupiera: ";
                    BlackJack::pokazKarty(11,'K');
                } else if (BlackJack::oblicz('G')==21) {
                    BlackJack::wyniki();
                    //+?
                    a=0;
                } else {/*gra toczy sie dalej*/}
                break;
            }
        case 2:
            {
                //oblicz
                BlackJack::wyniki();//oblicz i porownaj wyniki G i K
                a=0;
                break;
            }
        case 3:
            {
                if (b==1 && BlackJack::posiadane>=2*BlackJack::stawka) {//tylko w pierwszej
                //stawka*2, losoj,oblicz
                BlackJack::stawka=BlackJack::stawka*2;
                BlackJack::losojKarte('G');
                BlackJack::wyniki();
                a=0;
                } else {
                    cout<<"Ta akcje mozna wykonac tylko w pierwszej rundzie i maj¹c wystarczajaca ilosc srodkow"<<endl;
                }
                break;
            }
        case 4:
            {
                //przerwij wykonywanie menu
                a=0;
                break;
            }

        }
        b++;
    }
}



void BlackJack::losojKarte(char kto_)
{

    int i;
    //losowanie karty z talii, jesli nie ma takiej to jeszcze raz
    do {
        i=rand()%10;
    } while (talia[i]<=0);
    //gdy wylosowano
    if (kto_=='G') { //Gracz
        cout<<endl<<"Wylosowana karta: "<<i+1<<endl;
        for (int n=0;n<11;n++) {
            if (tabG[n]==0) {
              tabG[n]=i+1;
              break;
            }
        }
    }
    if (kto_=='K') { //Krupier
        for (int n=0;n<11;n++) {
            if (tabK[n]==0) {
              tabK[n]=i+1;
              break;
            }
        }
    }


    talia[i]--;
}

int BlackJack::oblicz(char kto_)
{

    //sprawdz czy <21 =21 >21(wygrana=0) || uwzgledn9enie assa
    int sumaKart=0;
    int iloscAs=0;

    if (kto_=='G') {
        //oblicz sume kart z Asem jako 1 i ilosc asow
        for (int i=0;i<11;i++) {
            if (BlackJack::tabG[i]==1) {
                iloscAs++;
            }
            sumaKart=sumaKart+BlackJack::tabG[i];

        }
        //dodanie asow +10
        for (int i=0;i<iloscAs;i++) {
            if (sumaKart+10<=21) {
                sumaKart=sumaKart+10;
            }
        }
    }
    if (kto_=='K') {
        //oblicz sume kart z Asem jako 1 i ilosc asow
        for (int i=0;i<11;i++) {
            if (BlackJack::tabK[i]==1) {
                iloscAs++;
            }
            sumaKart=sumaKart+BlackJack::tabK[i];

        }
        //dodanie asow +10
        for (int i=0;i<iloscAs;i++) {
            if (sumaKart+10<=21) {
                sumaKart=sumaKart+10;
            }
        }
    }


    return sumaKart;
}

void BlackJack::pokazKarty(int ile, char kto_) {
    if (kto_=='G') {
        //czytaj tabG; wyswietl 1 jako A, 0 jako ""
        for (int i=0;i<ile;i++) {
            if (BlackJack::tabG[i]==1) {
                cout<<'A';
            } else if (BlackJack::tabG[i]==0) {
                cout<<"";
            } else {
                cout<<BlackJack::tabG[i];
            }
            cout<<" ";
        }
    }
    if (kto_=='K') {
        //czytaj tabG; wyswietl 1 jako A, 0 jako ""
        for (int i=0;i<ile;i++) {
            if (BlackJack::tabK[i]==1) {
                cout<<'A';
            } else if (BlackJack::tabK[i]==0) {
                cout<<"";
            } else {
                cout<<BlackJack::tabK[i];
            }
            cout<<" ";
        }
    }
}

void BlackJack::pokazKarty() {
    BlackJack::pokazKarty(11,'G');
}

void BlackJack::wyniki() { //ruch krupiera i podsumowanie
    while (BlackJack::oblicz('K')<=16) {
        BlackJack::losojKarte('K');
    }
    if (BlackJack::oblicz('G')>21) {
        cout<<"        Przegrana"<<endl;
        BlackJack::stawka=0-BlackJack::stawka;
        cout<<"Twoje Karty: ";
        BlackJack::pokazKarty(11,'G');
        cout<<endl<<"Karty Krupiera: ";
        BlackJack::pokazKarty(11,'K');
    } else if (BlackJack::oblicz('K')>21) {
        cout<<"        Wygrana!"<<endl;
        cout<<"Twoje Karty: ";
        BlackJack::pokazKarty(11,'G');
        cout<<endl<<"Karty Krupiera: ";
        BlackJack::pokazKarty(11,'K');
        //+?zwiekszenie stawki
    } else {
        //sprawdzenie kto ma wiecej
        if (BlackJack::oblicz('G')==BlackJack::oblicz('K')) {
            cout<<"        Remis"<<endl;
            BlackJack::stawka=0;
            cout<<"Twoje Karty: ";
            BlackJack::pokazKarty(11,'G');
            cout<<endl<<"Karty Krupiera: ";
            BlackJack::pokazKarty(11,'K');
        } else if (BlackJack::oblicz('G')<BlackJack::oblicz('K')) {
            cout<<"        Przegrana"<<endl;
            BlackJack::stawka=0-BlackJack::stawka;
            cout<<"Twoje Karty: ";
            BlackJack::pokazKarty(11,'G');
            cout<<endl<<"Karty Krupiera: ";
            BlackJack::pokazKarty(11,'K');
        } else {
            cout<<"        Wygrana"<<endl;
            cout<<"Twoje Karty: ";
            BlackJack::pokazKarty(11,'G');
            cout<<endl<<"Karty Krupiera: ";
            BlackJack::pokazKarty(11,'K');
            //+
        }
    }
}
/*
double BlackJack::getStawka() {
    return BlackJack::stawka;
}
*/
