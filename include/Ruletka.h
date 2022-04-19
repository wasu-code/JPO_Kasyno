#ifndef RULETKA_H
#define RULETKA_H
#include "Gracz.h"


class Ruletka : public Gracz
{
    public:
        Ruletka();
        Ruletka (Gracz &G);
        void menuR();

    protected:

    private:
        double wygrana;
        double posiadane;
        double stawka;

};

#endif // RULETKA_H
