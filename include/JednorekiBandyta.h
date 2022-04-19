#ifndef JEDNOREKIBANDYTA_H
#define JEDNOREKIBANDYTA_H
#include "Gracz.h"


class JednorekiBandyta : public Gracz
{
    public:
        JednorekiBandyta();
        JednorekiBandyta(Gracz &G);
        virtual ~JednorekiBandyta();
        int menuJB();
        int wyniki();//wylosuj sumbole i sprawdz wygrana; dodaj lub odejmij
                    //0-przegrana, 1 wygrana lub nic
        void zmienStawke();

    protected:

    private:
        double stawka;
        double wygrana;
        double posiadane;
        char tab[6]={'*','#','+','o','I','@'};
        bool gra;
};

#endif // JEDNOREKIBANDYTA_H
