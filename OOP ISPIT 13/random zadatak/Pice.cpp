#include "Pice.h"

Pice::Pice() : zapremina(0), broj(0) {}

Pice::Pice(double z, int b) : zapremina(z), broj(b) {}

Pice::Pice(const Pice& p) {
    zapremina = p.zapremina;
    broj = p.broj;
}

Pice::~Pice() {}

std::ostream& operator<<(std::ostream& out, const Pice& p) {
    p.prikazi(out);
    return out;
}

