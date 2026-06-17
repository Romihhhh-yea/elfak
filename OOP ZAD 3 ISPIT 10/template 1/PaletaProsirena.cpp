#include "PaletaProsirena.h"

PaletaProsirena::PaletaProsirena() : Paleta() {
    masaJedneDaske = 0.0f;
    brojDasaka = 0;
    sirinaSvihDasaka = 0.0f;
}

PaletaProsirena::PaletaProsirena(float _masaJedneDaske, int _brojDasaka, float _sirinaSvihDasaka)
    : Paleta(0) {
    masaJedneDaske = _masaJedneDaske;
    brojDasaka = _brojDasaka;
    sirinaSvihDasaka = _sirinaSvihDasaka;
    masaDrvnogMaterijala = (int)(brojDasaka * masaJedneDaske);
}

PaletaProsirena::PaletaProsirena(const PaletaProsirena& gg) : Paleta(gg) {
    masaJedneDaske = gg.masaJedneDaske;
    brojDasaka = gg.brojDasaka;
    sirinaSvihDasaka = gg.sirinaSvihDasaka;
}

PaletaProsirena::~PaletaProsirena() {}

int PaletaProsirena::getMasa() const {
    return (int)(brojDasaka * masaJedneDaske);
}

void PaletaProsirena::Prikazi(std::ostream& izlaz) const {
    izlaz << getMasa() << "(" << masaJedneDaske << "," << brojDasaka << "," << sirinaSvihDasaka << ")";
}
std::istream& operator>>(std::istream& ulaz, PaletaProsirena& p) {
    char kanta; // Za preskakanje (, ) i zareza
    int ukupna;
    ulaz >> ukupna >> kanta >> p.masaJedneDaske >> kanta >> p.brojDasaka >> kanta >> p.sirinaSvihDasaka >> kanta;
    p.masaDrvnogMaterijala = ukupna;
    return ulaz;
}