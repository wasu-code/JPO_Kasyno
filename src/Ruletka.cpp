#include "Ruletka.h"
#include <time.h>
#include <iostream>

using namespace std;

Ruletka::Ruletka()
{

}

Ruletka::Ruletka(Gracz &G)
{
    srand(time(0));
    Ruletka::wygrana=0;
    //ustal stawke
    cout<<endl<<"Rozpoczales gre w Ruletke"<<endl;
    cout<<endl<<"O jaka stawke chcesz grac?"<<endl<<endl;
    Ruletka::stawka = G.wybor(G.getMoney());
    Ruletka::posiadane = G.getMoney();
    //menu
    Ruletka::menuR();

    G.addMoney(Ruletka::wygrana); //dodaj wygrana do konta
    G.addWygrana(Ruletka::wygrana); //dodaj do sumy wygranych


}


void Ruletka::menuR()
{
    int a=1;
    while (a) {
        cout<<"    Wybierz co chcesz zrobic\n1)obstaw liczbe\n2)obstaw kolor\n3)zakoncz"<<endl;
        switch (Gracz::wybor(3))
        {
        case 1:
            { //wybierz numer//obstaw liczbe x35
                cout<<endl<<"Wybierz na jaki numer obstawiasz"<<endl;
                int x=Gracz::wybor0(36);
                int los=rand()%100 %37;
                cout<<"Wylosowano: "<<los;
                if (x==los) {
                    cout<<"        Wygrana!!! +"<<(Ruletka::stawka*35)<<"$"<<endl;
                    Ruletka::wygrana=Ruletka::wygrana+Ruletka::stawka*35;
                } else {
                    cout<<"        Przegrana"<<endl;
                    Ruletka::wygrana=Ruletka::wygrana-Ruletka::stawka;
                    if (Ruletka::posiadane+Ruletka::wygrana<stawka) {
                        cout<<"Nie stac cie juz na gre o taka stawke"<<endl;
                        a=0;
                    }
                }
                break;
            }
        case 2:
            { //wybierz kolor//obstawm kolor x1
                cout<<"Wybierz na jaki kolor obstawiasz\n1)czarny\n2)czerwony"<<endl;
                int x=Gracz::wybor(2);
                int los=rand()%2 +1;
                if (x==los) {
                    cout<<"        Wygrana!!! +"<<Ruletka::stawka<<"$"<<endl;
                    Ruletka::wygrana=Ruletka::wygrana+Ruletka::stawka;
                } else {
                    cout<<"        Przegrana"<<endl;
                    Ruletka::wygrana=Ruletka::wygrana-Ruletka::stawka;
                    if (Ruletka::posiadane+Ruletka::wygrana<stawka) {
                        cout<<"Nie stac cie juz na gre o taka stawke"<<endl;
                        a=0;
                    }
                }
                break;
            }
        case 3:
            { //zakoncz
                cout<<"Zakonczyles gre na tym stanowisku"<<endl;
                a=0;
                break;
            }
        }
    }
}
