#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
// ... ostali include-ovi
#include "Zadatak.h"

Zadatak::Zadatak() : IspitniMaterijal() {
    brLinijaKoda = 0;
}

Zadatak::Zadatak(int _oznaka, float _tezina, int _brLinija, const char* _savladan)
    : IspitniMaterijal(_oznaka, _tezina, _savladan) {
    brLinijaKoda = _brLinija;
}

Zadatak::Zadatak(const Zadatak& z) : IspitniMaterijal(z) {
    brLinijaKoda = z.brLinijaKoda;
}

Zadatak::~Zadatak() {}

float Zadatak::vremeSavladavanja(float _vJedinicno) const {
    return brLinijaKoda * tezina * _vJedinicno * 0.05f;
}

void Zadatak::prikazi(std::ostream& izlaz) const {
    IspitniMaterijal::prikazi(izlaz);
    izlaz << " | Linija koda: " << brLinijaKoda;
}