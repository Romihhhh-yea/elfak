#include "Paleta.h"

Paleta::Paleta() : oznaka(0), masa(0) {}

Paleta::Paleta(int _oznaka, int _masa) {
    oznaka = _oznaka;
    masa = _masa;
}

Paleta::Paleta(const Paleta& gg) {
    oznaka = gg.oznaka;
    masa = gg.masa;
}

Paleta::~Paleta() {}

int Paleta::GetOznaka() const {
    return oznaka;
}

int Paleta::GetMasaPalete() const {
    return masa;
}

std::ostream& operator<<(std::ostream& out, const Paleta& p) {
    p.Ispisi(out);
    return out;
}
