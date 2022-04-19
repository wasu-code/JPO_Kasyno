#include <iostream>
#include "Gracz.h"
#include "BlackJack.h"
#include <cstdlib>
#include <time.h>
#include "JednorekiBandyta.h"
#include "Ruletka.h"

using namespace std;


int main()
{
    cout << "Witamy w Naszym Kasynie!" << endl;

    Gracz * G = new Gracz;
    string name;
    cout<<"Podaj imie: "<<endl;
    //cin>>name;
    getline(cin,name);
    G->setName(name);
    cout<<"Witaj "<<G->getName()<<endl;
    srand(time(0));
    G->setMoney(rand()%1000+100);






while (true) {
    cout<<endl<<"-------------------------------"<<endl;
    cout<<endl;
    cout<<"posiadane: "<<G->getMoney()<<" $"<<endl;
    cout<<"Wybierz gre\n1)BlackJack\n2)Jednoreki Bandyta\n3)Ruletka\n4)Wyjscie"<<endl;

    switch (G->wybor(4)) {
    case 1:
        {
            BlackJack * BJ = new BlackJack(*G);
            delete BJ;
            break;
        }
    case 2:
        {
            JednorekiBandyta * JB = new JednorekiBandyta(*G);
            delete JB;
            break;
        }
    case 3:
        {
            Ruletka * R = new Ruletka(*G);
            delete R;
            break;
        }
    case 4:
        {
            cout<<"Zapraszamy Ponownie!";
            cout<<endl<<"Twoja calkowita wygrana: "<<G->getWygrana()<<endl;
            G->Ranking();
            return 0;
            break;
        }
    }
}


    return 0;
}
