#include "Sok.h"
#include <cstring>

Sok::Sok() : Pice(), naziv(nullptr), procenat(0) {}

Sok::Sok(double z, const char* n, int p, double o, int b)
    : Pice(z, b) { 

    this->procenat = p;
    this->odnosCene = o; 

    this->naziv = new char[strlen(n) + 1];
    strcpy(this->naziv, n);
}

Sok::Sok(const Sok& s) : Pice(s), procenat(s.procenat) {
    naziv = new char[strlen(s.naziv) + 1];
    strcpy(naziv, s.naziv);
}

Sok::~Sok() {
    delete[] naziv;
}

void Sok::prikazi(std::ostream& out) const {
    out << "Sok: "
        << naziv << ", "
        << zapremina << "L, komada: "
        << broj
        << ", procenat voca: "
        << procenat;
}

