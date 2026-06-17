#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
// ... ostali include-ovi
#include "IspitPriprema.h"

// 1. Default konstruktor
IspitPriprema::IspitPriprema() {
    maxEl = 10;
    trBr = 0;
    niz = new IspitniMaterijal * [maxEl];
}

// 2. Konstruktor sa parametrima
IspitPriprema::IspitPriprema(int _maxEl) {
    maxEl = _maxEl;
    trBr = 0;
    niz = new IspitniMaterijal * [maxEl];
}

// 3. Copy konstruktor (nadimak ip)
IspitPriprema::IspitPriprema(const IspitPriprema& gg) {
    maxEl = gg.maxEl;
    trBr = gg.trBr;
    niz = new IspitniMaterijal * [maxEl];

    for (int i = 0; i < trBr; i++) {
        // Ovde bi idealno išao poziv virtuelne funkcije kopiraj() 
        // ali ako je nemate u zadatku, prepisuju se adrese (shallow copy)
        niz[i] = gg.niz[i];
    }
}

// 4. Destruktor (KLJUÈNO ZA ISPIT)
IspitPriprema::~IspitPriprema() {
    for (int i = 0; i < trBr; i++) {
        delete niz[i]; // Brišemo svaki konkretan materijal (Lekciju/Zadatak)
    }
    delete[] niz; // Brišemo sam niz pokazivaèa
}

// Funkcija za dodavanje na kraj kolekcije
void IspitPriprema::Dodaj(IspitniMaterijal* _novi) {
    if (trBr < maxEl) {
        niz[trBr++] = _novi;
    }
    else {
        // Možeš i da baciš exception ako je niz pun
        throw "Greska: Kolekcija je puna";
    }
}

// Operator za ispis celog niza
std::ostream& operator<<(std::ostream& izlaz, const IspitPriprema& ip) {
    for (int i = 0; i < ip.trBr; i++) {
        izlaz << *(ip.niz[i]) << std::endl;
    }
    return izlaz;
}
void IspitPriprema::Obrisi(int _oznaka) {
    for (int i = 0; i < trBr; i++) {
        if (niz[i]->getOznaka() == _oznaka) {
            if (strcmp(niz[i]->getSavladan(), "DA") != 0) {
                delete niz[i];
                for (int j = i; j < trBr - 1; j++)
                    niz[j] = niz[j + 1];
                trBr--;
                return;
            }

        }
    }
}
void IspitPriprema::Savladaj(int _oznaka) {
    for (int i = 0; i < trBr; i++) {
        if (niz[i]->getOznaka() == _oznaka) {
            niz[i]->setSavladan("Da");
            return;
        }
    }
}
float IspitPriprema::UkupnoVreme(float _vJed) const {
    float suma = 0;
    for (int i = 0; i < trBr; i++) {
        suma += niz[i]->vremeSavladavanja(_vJed);
    }
    return suma;
}
int IspitPriprema::UkupnoSavladanih() const {
    int brojac = 0;
    for (int i = 0; i < trBr; i++) {
        if (strcmp(niz[i]->getSavladan(), "DA") == 0) 
            brojac++;
    }
    return brojac;
}
void IspitPriprema::VratiNaj(float _vJed, IspitniMaterijal** _min, IspitniMaterijal** _max) {
    *_min = niz[0];
    *_max = niz[0];
    for (int i = 0; i < trBr; i++) {
        if (niz[i]->vremeSavladavanja(_vJed) < (*_min)->vremeSavladavanja(_vJed))
            *_min = niz[i];
    
    if (niz[i]->vremeSavladavanja(_vJed) > (*_min)->vremeSavladavanja(_vJed))
        *_max = niz[i];
}
};
