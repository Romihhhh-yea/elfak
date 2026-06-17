#include "PaletaDzak.h"

PaletaDzak::PaletaDzak()
    : Paleta(), klasa('A'), masaMaterijala(0), cenaPoKg(0) {
}

PaletaDzak::PaletaDzak(int _oznaka, int _masaPalete, char _klasa,
    float _masaMaterijala, float _cenaPoKg)
    : Paleta(_oznaka, _masaPalete)
{
    klasa = _klasa;
    masaMaterijala = _masaMaterijala;
    cenaPoKg = _cenaPoKg;
}

PaletaDzak::PaletaDzak(const PaletaDzak& gg)
    : Paleta(gg)
{
    klasa = gg.klasa;
    masaMaterijala = gg.masaMaterijala;
    cenaPoKg = gg.cenaPoKg;
}

PaletaDzak::~PaletaDzak() {}

float PaletaDzak::UkupnaMasa() const {
    return GetMasaPalete() + masaMaterijala;
}

float PaletaDzak::Vrednost() const {
    return masaMaterijala * cenaPoKg;
}

void PaletaDzak::Ispisi(std::ostream& out) const {
    out << "DZAK "
        << GetOznaka() << " "
        << GetMasaPalete() << " "
        << klasa << " "
        << masaMaterijala << " "
        << cenaPoKg;
}
