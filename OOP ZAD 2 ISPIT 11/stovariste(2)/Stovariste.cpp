#include "Stovariste.h"

void Stovariste::zauzmiMem(int _maxEl)
{
    trBr = 0;
    maxEl = _maxEl;
    niz = new Paleta * [_maxEl];
    for (int i = 0; i < maxEl; i++) {
        niz[i] = nullptr;
    }
}

void Stovariste::oslobodiMem()
{
    for (int i = 0; i < trBr; i++) {
        delete niz[i];
    }
    delete[] niz;
}

Stovariste::Stovariste()
{
    niz = nullptr;
    maxEl = 0;
    trBr = 0;
}

Stovariste::Stovariste(int _maxEl)
{
    zauzmiMem(_maxEl);
}

Stovariste::~Stovariste()
{
    oslobodiMem();
}

Stovariste::Stovariste(const Stovariste& gg)
{
    zauzmiMem(gg.maxEl);

    for (int i = 0; i < gg.trBr; i++) {
        if (typeid(*gg.niz[i]) == typeid(PaletaDzak))
            Dodaj(new PaletaDzak(*dynamic_cast<PaletaDzak*>(gg.niz[i])));
        else
            Dodaj(new PaletaPlocice(*dynamic_cast<PaletaPlocice*>(gg.niz[i])));
    }
}

void Stovariste::Dodaj(Paleta* nov)
{
    if (trBr < maxEl)
        niz[trBr++] = nov;
}

Paleta* Stovariste::Preuzmi(int broj)
{
    for (int i = 0; i < trBr; i++) {
        if (niz[i]->getOznaka() == broj) {
            Paleta* zaVracanje = niz[i]; // Èuvamo adresu palete

            // Pomeramo ostale palete ulevo da popunimo rupu
            for (int j = i; j < trBr - 1; j++) {
                niz[j] = niz[j + 1];
            }

            trBr--; // Smanjujemo broj elemenata tek nakon pomeranja
            return zaVracanje; // Vraæamo pokazivaè main-u (NE radimo delete ovde!)
        }
    }
    return nullptr; // Ako nije naðena
}

int Stovariste::UkupnaMasa()
{
    int ukupno = 0;
    for (int i = 0; i < trBr; i++) {
        ukupno += niz[i]->getMasa();
    }
    return ukupno;
}

int Stovariste::UkupnaVrednost()
{
    int ukupno = 0;
    for (int i = 0; i < trBr; i++) {
        ukupno += niz[i]->getCena();
    }
    return ukupno;
}

int Stovariste::BrojSaVredIzmedju(int dole, int gore)
{
    int broj = 0;
    for (int i = 0; i < trBr; i++) {
        if (niz[i]->getCena() > dole && niz[i]->getCena() < gore)
            broj++;
    }
    return broj;
}

void Stovariste::VratiNajMasuVrednost(Paleta** pMaxMasa, Paleta** pMaxVred)
{
    *pMaxMasa = niz[0];
    *pMaxVred = niz[0];
    for (int i = 1; i < trBr; i++) {
        if (niz[i]->getMasa() > (*pMaxMasa)->getMasa())
            *pMaxMasa = niz[i];
        if (niz[i]->getCena() > (*pMaxVred)->getCena())
            *pMaxVred = niz[i];
    }
}

ostream& operator<<(ostream& izlaz, const Stovariste& s)
{
    for (int i = 0; i < s.trBr; i++) {
        izlaz << *s.niz[i] << endl;
    }
    return izlaz;
}
