#include "PaketicIgracke.h"

PaketicIgracke::PaketicIgracke() : Paketic() {
    brojIgracaka = 0;
    tezinaJedne = 0;
    cenaJedne = 0;
}

PaketicIgracke::PaketicIgracke(const char* adresa, const char* boja,
    int _brojIgracaka, double _tezinaJedne, double _cenaJedne)
    : Paketic(adresa, boja) {
    brojIgracaka = _brojIgracaka;
    tezinaJedne = _tezinaJedne;
    cenaJedne = _cenaJedne;
}

PaketicIgracke::PaketicIgracke(const PaketicIgracke& gg) : Paketic(gg) {
    brojIgracaka = gg.brojIgracaka;
    tezinaJedne = gg.tezinaJedne;
    cenaJedne = gg.cenaJedne;
}

PaketicIgracke::~PaketicIgracke() {
}

double PaketicIgracke::tezina() const {
    return brojIgracaka * tezinaJedne;
}

double PaketicIgracke::cena() const {
    return brojIgracaka * cenaJedne;
}

void PaketicIgracke::prikazi(std::ostream& izlaz) const {
    Paketic::prikazi(izlaz);
    izlaz << "Broj igracaka: " << brojIgracaka << std::endl;
    izlaz << "Tezina jedne igracke: " << tezinaJedne << std::endl;
    izlaz << "Cena jedne igracke: " << cenaJedne << std::endl;
}
