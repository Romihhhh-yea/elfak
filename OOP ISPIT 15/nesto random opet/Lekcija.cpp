#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
// ... ostali include-ovi
#include "Lekcija.h"

Lekcija::Lekcija() : IspitniMaterijal() {
    duzina = 0;
}

Lekcija::Lekcija(int _oznaka, int _tezina, float _duzina, const char* _savladan)
    : IspitniMaterijal(_oznaka, _tezina, _savladan) { 
    duzina = _duzina;
}

Lekcija::Lekcija(const Lekcija& gg) : IspitniMaterijal(gg) {
    duzina = gg.duzina;
}

Lekcija::~Lekcija() {} 

float Lekcija::vremeSavladavanja(float _vJedinicno) const {
    return duzina * tezina * _vJedinicno;
}

void Lekcija::prikazi(std::ostream& izlaz) const {
    IspitniMaterijal::prikazi(izlaz);
    izlaz << "Duzina: " << duzina;
}