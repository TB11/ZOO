#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unistd.h>//potrzebne do funkcji sleep

using namespace std;



class Zwierze//klasa abstrakcyjna
{
    friend class Zoo;
private:

protected:
    string nazwa;
    uint32_t masa;

public:
    Zwierze() {};
    virtual ~Zwierze() {};
    virtual void daj_glos() const = 0;
    virtual void show () = 0;


};

class Koza : public Zwierze
{

public:
    Koza()
    {
        nazwa = "Koza";
        masa = 40 + rand() % 30;
    };
    ~Koza() {};
    virtual void daj_glos() const
    {
        cout << "Meeeeee!" << endl;
    };
    virtual void show ()
    {
        cout << "gatunek: " << nazwa << ", masa: " << masa << "kg" << endl;
    };

};

class Gnu : public Zwierze
{
public:
    Gnu()
    {
        nazwa = "Gnu";
        masa = 100 + rand() % 60;
    };
    ~Gnu() {};
    virtual void daj_glos() const
    {
        cout << "Mhmm?" << endl;
    };
    virtual void show ()
    {
        cout << "gatunek: " << nazwa << ", masa: " << masa << "kg" << endl;
    };
};

class Zebra : public Zwierze
{
public:
    Zebra()
    {
        nazwa = "Zebra";
        masa = 170 + rand() % 40;
    };
    ~Zebra() {};
    virtual void daj_glos() const
    {
        cout << "IIIhhhaaahhaaa!" << endl;
    };
    virtual void show ()
    {
        cout << "gatunek: " << nazwa << ", masa: " << masa << "kg" << endl;
    };
};

class Forfiter : public Zwierze
{
public:
    Forfiter()
    {
        nazwa = "Forfiter";
        masa = 160 + rand() % 60;
    };
    ~Forfiter() {};
    virtual void daj_glos() const
    {
        cout << "Uciekaj k** stąd, szwagier" << endl;
    };
    virtual void show ()
    {
        cout << "gatunek: " << nazwa << ", masa: " << masa << "kg" << endl;
    };
};


class ZwierzeFactory
{

public:
    static Zwierze* create_zwierze()
    {
        uint32_t losowo = rand() % 4;
        if (losowo == 0)
            return  new Koza();
        else if (losowo == 1)
            return  new Gnu();
        else if (losowo == 2)
            return  new Zebra();
        else
            return  new Forfiter();
    };
};

class Zoo
{
private:
    vector <Zwierze*> Zwierzeta;//bo maja pokazywac inne klasy konkretnego gatunku a nie obiekty klasy Zwierze, Zwierze nie moze byc obiektem
    uint32_t waga = 0;

public:
    Zoo() {};
    ~Zoo() {};
    void dodaj (Zwierze* a)
    {
        if(waga <=2000)
        {Zwierzeta.push_back(a);
        waga += a->masa; cout << "Tworze zwierzaka" << endl;}
        else
        cout << "Przekroczono wage: " << waga << " kg" << endl;

    };
    virtual void show ()
    {
        for (vector<Zwierze*>::iterator i = Zwierzeta.begin(); i != Zwierzeta.end(); ++i)
        {
            cout<< "Gatunek: "<< (*i)->nazwa << ", masa: " << (*i)->masa  << " kg;  "; (*i)->daj_glos();
        }
        cout << "liczba zwierzat: "<< Zwierzeta.size() << ";  "<<  "calkowita waga: " << waga << " kg" << endl;
    };
};


int main()
{
    Zoo moje;

    for (uint32_t i = 0; i < 15; ++i)
    {
        moje.dodaj(ZwierzeFactory::create_zwierze());
        sleep(1);
    }

    moje.show();

    return 0;
}
