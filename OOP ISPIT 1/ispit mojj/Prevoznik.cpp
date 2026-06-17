#include "Prevoznik.h"

void Prevoznik::zauzmiMem(int _maxEl)
{
    trBr = 0;
    maxEl = _maxEl;
    niz = new Automobil * [maxEl];
    for (int i = 0; i < maxEl; i++) {
        niz[i] = nullptr;
    }
    
}

void Prevoznik::oslobodiMem()
{
        for (int i = 0; i < trBr; i++) {
            delete niz[i];
    }
    delete[] niz;
}

Prevoznik::Prevoznik()
{
    niz = nullptr;
    trBr = 0;
    maxEl = 0;
}

Prevoznik::Prevoznik(int _maxEl)
{
    zauzmiMem(maxEl);
}

Prevoznik::~Prevoznik()
{
    oslobodiMem();
}

Prevoznik::Prevoznik(const Prevoznik& gg)
{
    zauzmiMem(gg.maxEl);
    for (int i = 0; i < gg.trBr; i++) {
        if (typeid(*gg.niz[i]) == typeid(Hibrid))
            Dodaj(new Hibrid(*dynamic_cast<Hibrid*>(gg.niz[i])));
        else
            Dodaj(new Benzinac(*dynamic_cast<Benzinac*>(gg.niz[i])));
    }
}

Automobil* Prevoznik::Dodaj(Automobil* novi)
{
    if (trBr < maxEl)
        niz[trBr++] = novi;
}

void Prevoznik::IzbaciPoKm(int km)
{
    for (int i = 0; i < trBr; i++) {
        if (niz[i]->getkm() > km) {
            for (int j = i; j < trBr - 1; j++) {
                niz[j] = niz[j + 1];
           }
        }
    }
}

int Prevoznik::UkupnaKilometraza()
{
    int uk = 0;
    for (int i = 0; i < trBr; i++) {
        uk += niz[i]->getkm();
    }
    return uk;
}

void Prevoznik::ObavljenaVoznja(const char* tablice, int kmm)
{
   /* for (int i = 0; i < trBr; i++) {
        if (strcmp(niz[i]->tablica(), tablice) == 0)
            niz[i]->getkm += 
    }*/
}

void Prevoznik::VratiNajDuzinuGorivo(Automobil** pMinDuzina, Automobil** pMinPotrosio)
{
    *pMinDuzina = niz[0];
    *pMinPotrosio = niz[0];
    for (int i = 0; i < trBr; i++) {

    }
}

void Prevoznik::prikazi(ostream& izlaz) const
{
    for (int i = 0; i < trBr; i++) {
        izlaz << *niz[i] << endl;
    }
}

ostream& operator<<(ostream& izlaz, const Prevoznik& p)
{
    p.prikazi(izlaz);
}
