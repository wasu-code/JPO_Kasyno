#ifndef GRACZ_H
#define GRACZ_H
#include <string>


class Gracz
{
    public:
        Gracz();
        double getMoney();
        void setMoney(double m_);
        void addMoney(double m_);
        void setName(std::string n_);
        std::string getName();

        int wybor(int maks);
        int wybor0(int maks);

        void Ranking();
        void addWygrana(double ile_);
        double getWygrana();

    protected:
        double wygrana;

    private:
        double money;
        std::string name;
        double lacznaWygrana;
};

#endif // GRACZ_H
