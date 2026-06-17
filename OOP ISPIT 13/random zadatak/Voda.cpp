#include "Voda.h"

Voda::Voda() : Pice() {}

Voda::Voda(double z, int b) : Pice(z, b) {}

Voda::Voda(const Voda& v) : Pice(v) {}

Voda::~Voda() {}

void Voda::prikazi(std::ostream& out) const {
    out << "Voda: "
        << zapremina << "L, komada: "
        << broj;
}

