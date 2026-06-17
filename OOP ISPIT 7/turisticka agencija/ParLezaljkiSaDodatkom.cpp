#include "ParLezaljkiSaDodatkom.h"

ParLezaljkiSaDodatkom::ParLezaljkiSaDodatkom() : ParLezaljki() {
    brDodatnihLezaljki = 0;
}

ParLezaljkiSaDodatkom::ParLezaljkiSaDodatkom(int _redniBroj, int _red, float _cenaLezaljki, float _cenaNapitaka, int _brDodatnihLezaljki)
    : ParLezaljki(_redniBroj, _red, _cenaLezaljki, _cenaNapitaka) {
    brDodatnihLezaljki = _brDodatnihLezaljki;
}

ParLezaljkiSaDodatkom::ParLezaljkiSaDodatkom(const ParLezaljkiSaDodatkom& gg) : ParLezaljki(gg) {
    brDodatnihLezaljki = gg.brDodatnihLezaljki;
}

ParLezaljkiSaDodatkom::~ParLezaljkiSaDodatkom() {}

float ParLezaljkiSaDodatkom::svotaZaNaplatu() const {
    // Formula iz teksta: cenaLezaljki * (1 + 0.4 * bdl) + cenaNapitaka umanjena za (40 - 2*br - 5*bdl)%
    float faktorCene = 1.0f + 0.4f * (float)brDodatnihLezaljki;
    float procenatPica = (40.0f - 2.0f * (float)red - 5.0f * (float)brDodatnihLezaljki) / 100.0f;
    return (cenaLezaljki * faktorCene) + (cenaNapitaka * (1.0f - procenatPica));
}

void ParLezaljkiSaDodatkom::Prikazi() const {
    ParLezaljki::Prikazi();
    std::cout << " | Dodatnih: " << brDodatnihLezaljki << " | Naplata: " << svotaZaNaplatu();
}
