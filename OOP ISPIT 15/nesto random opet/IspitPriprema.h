#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "IspitniMaterijal.h"
#include <iostream>
using namespace std;
class IspitPriprema {
private:
    IspitniMaterijal** niz; // double pointer
    int trBr;              // trenutni broj
    int maxEl;             // maksimalan broj

public:
    // 1. Default konstruktor
    IspitPriprema();

    // 2. Konstruktor sa parametrima
    IspitPriprema(int _maxEl);

    // 3. Copy konstruktor (nadimak ip)
    IspitPriprema(const IspitPriprema& gg);

    // 4. Destruktor
    ~IspitPriprema();

    // Osnovne metode iz teksta zadatka
    void Dodaj(IspitniMaterijal* _novi);   //
    void Obrisi(int _oznaka);  
    void Savladaj(int _oznaka);
    float UkupnoVreme(float _vJed) const;
    int UkupnoSavladanih() const;
    void VratiNaj(float _vJed, IspitniMaterijal** _min, IspitniMaterijal** _max);
    // Operator za ispis Boss klase
    friend std::ostream& operator<<(std::ostream& izlaz, const IspitPriprema& ip);
};