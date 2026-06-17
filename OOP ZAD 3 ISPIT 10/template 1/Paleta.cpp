#include "Paleta.h"

Paleta::Paleta() { masaDrvnogMaterijala = 0; }
Paleta::Paleta(int _masaDrvnogMaterijala) { masaDrvnogMaterijala = _masaDrvnogMaterijala; }
Paleta::Paleta(const Paleta& gg) { masaDrvnogMaterijala = gg.masaDrvnogMaterijala; }
Paleta::~Paleta() {}

void Paleta::smanjiMasu(int _iznos) {
    if (_iznos <= masaDrvnogMaterijala) masaDrvnogMaterijala -= _iznos;
    else masaDrvnogMaterijala = 0;
}

void Paleta::Prikazi(std::ostream& izlaz) const {
    izlaz << masaDrvnogMaterijala;
}

std::ostream& operator<<(std::ostream& izlaz, const Paleta& p) {
    p.Prikazi(izlaz);
    return izlaz;
}
std::istream& operator>>(std::istream& ulaz, Paleta& p) {
    ulaz >> p.masaDrvnogMaterijala;
    return ulaz;
}