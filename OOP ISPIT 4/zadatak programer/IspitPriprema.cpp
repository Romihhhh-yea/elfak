#include "IspitPriprema.h"
#include <typeinfo>

void IspitPriprema::zauzmiMem(int _maxEl)
{
    trBr = 0;
    maxEl = _maxEl;
    niz = new IspitniMaterijal * [maxEl];
    for (int i = 0; i < maxEl; i++) {
        niz[i] = nullptr;
    }
}

void IspitPriprema::oslobodiMem()
{
    if(niz != nullptr)
        for (int i = 0; i < trBr; i++) {
            if (niz[i] != nullptr)
                delete niz[i];
        }
    delete[] niz;
}

IspitPriprema::IspitPriprema()
{
    trBr = 0;
    maxEl = 0;
    niz = nullptr;
}

IspitPriprema::IspitPriprema(int _maxEl)
{
    zauzmiMem(_maxEl);
}

IspitPriprema::~IspitPriprema()
{
    oslobodiMem();
}

IspitPriprema::IspitPriprema(const IspitPriprema& gg)
{
    zauzmiMem(gg.maxEl);

    for (int i = 0; i < gg.trBr; i++) {
        if (typeid(*gg.niz[i]) == typeid(Lekcija)) {
            Dodaj(new Lekcija(*dynamic_cast<Lekcija*>(gg.niz[i])));
        }
        else
            Dodaj(new Zadatak(*dynamic_cast<Zadatak*>(gg.niz[i])));
        
    }
}

void IspitPriprema::Dodaj(IspitniMaterijal* novi)
{
    if (trBr < maxEl) {
        niz[trBr++] = novi;
    }
}

void IspitPriprema::Obrisi(int oznakaa)
{
    for (int i = 0; i < trBr; i++) {
        if (niz[i]->getOznaka() == oznakaa && niz[i]->getSavladan() == false)
            delete niz[i];

        for (int j = i; j < trBr - 1; j++) {
            niz[j] = niz[j + 1];
        }
        trBr--;
    }
}

void IspitPriprema::Savladaj(int oznakaa)
{
    for (int i = 0; i < trBr; i++) {
        if (niz[i]->getOznaka() == oznakaa) {
            niz[i]->setSavladan();
        }
    }
}

int IspitPriprema::UkupnoSavladanih()
{
    int br = 0;
    for (int i = 0; i < trBr; i++) {
        if (niz[i]->getSavladan() == true) {
            br++;
        }
    }
    return br;
}

float IspitPriprema::UkupnoVreme(int vreme)
{
    float ukupno = 0;
    for (int i = 0; i < trBr; i++) {
        ukupno += niz[i]->vremeSavladavanja(vreme);
    }
    
    return ukupno;
}

void IspitPriprema::VratiNaj(int vreme, IspitniMaterijal** min, IspitniMaterijal** max)
{
    *min = niz[0];
    *max = niz[0];
    for (int i = 1; i < trBr; i++) {
        if (niz[i]->vremeSavladavanja(vreme) > (*max)->vremeSavladavanja(vreme)) {
            *max = niz[i];
        }
        if (niz[i]->vremeSavladavanja(vreme) < (*min)->vremeSavladavanja(vreme)) {
            *min = niz[i];
        }
    }
}

ostream& operator<<(ostream& izlaz, const IspitPriprema& ip)
{
    for (int i = 0; i < ip.trBr; i++) {
        izlaz << *(ip.niz[i]) << endl;
    }
    return izlaz;
}

