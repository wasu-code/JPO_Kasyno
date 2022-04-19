#ifndef BLACKJACK_H
#define BLACKJACK_H
#include "Gracz.h"


class BlackJack : public Gracz
{
    public:
        BlackJack();
        BlackJack(Gracz &G);
        virtual ~BlackJack();
        void menuBJ();
        //


        void losojKarte(char kto_);//wylosuj z talii i dopisz do tab || losuj pozycjê z talii by wybraæ kartê, jeœli brak losuj jeszcze raz
        int oblicz(char kto_);//sprawdz czy <21 =21 >21(wygrana=0) || uwzgledn9enie assa
        void pokazKarty();
        void pokazKarty(int ile, char kto_);
        void wyniki();//ruch krupiera i podsumowanie
        //double getStawka();

    protected:

    private:
        int talia[10] = {4,4,4,4,4,4,4,4,4,16};
                       //A,2,3,4,5,6,7,8,9,10|J|Q|K//
                      //4asy, 4*2, 4*3...4*9, 16*10,
        int tabG[11] = {0,0,0,0,0,0,0,0,0,0,0};
        int tabK[11] = {0,0,0,0,0,0,0,0,0,0,0};
        double stawka;
        double posiadane;
};

#endif // BLACKJACK_H
