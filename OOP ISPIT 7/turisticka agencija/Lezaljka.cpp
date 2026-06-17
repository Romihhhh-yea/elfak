#include "Lezaljka.h"

Lezaljka::Lezaljka() {
    redniBroj = 0;
    red = 0;
    cenaLezaljki = 0.0f;
    cenaNapitaka = 0.0f;
}

Lezaljka::Lezaljka(int _redniBroj, int _red, float _cenaLezaljki, float _cenaNapitaka) {
    redniBroj = _redniBroj;
    red = _red;
    cenaLezaljki = _cenaLezaljki;
    cenaNapitaka = _cenaNapitaka;
}

Lezaljka::Lezaljka(const Lezaljka& gg) {
    redniBroj = gg.redniBroj;
    red = gg.red;
    cenaLezaljki = gg.cenaLezaljki;
    cenaNapitaka = gg.cenaNapitaka;
}

Lezaljka::~Lezaljka() {
}

void Lezaljka::Prikazi() const {
    std::cout << "R.br: " << redniBroj << ", Red: " << red
        << ", Cena lezaljki: " << cenaLezaljki
        << ", Cena napitaka: " << cenaNapitaka;
}

std::ostream& operator<<(std::ostream& izlaz, const Lezaljka& l) {
    l.Prikazi();
    return izlaz;
}
