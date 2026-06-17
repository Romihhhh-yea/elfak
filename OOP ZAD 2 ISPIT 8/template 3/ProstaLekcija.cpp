#include "ProstaLekcija.h"

// 1. Default konstruktor
ProstaLekcija::ProstaLekcija() {
    tezina = 0;
}

// 2. Konstruktor sa parametrom
ProstaLekcija::ProstaLekcija(int _tezina) {
    tezina = _tezina;
}

// 3. Destruktor
// Posto nema dinamicke memorije, ovde ne radimo nista (prazan je)
ProstaLekcija::~ProstaLekcija() {
}

// 4. Copy konstruktor
ProstaLekcija::ProstaLekcija(const ProstaLekcija& gg) {
    tezina = gg.tezina;
}
std::ostream& operator<<(std::ostream& izlaz, const ProstaLekcija& l) {
    izlaz << l.tezina << endl;
}
