#include "ParLezaljki.h"

ParLezaljki::ParLezaljki() : Lezaljka() {}
ParLezaljki::ParLezaljki(int _redniBroj, int _red, float _cenaLezaljki, float _cenaNapitaka)
    : Lezaljka(_redniBroj, _red, _cenaLezaljki, _cenaNapitaka) {
}
ParLezaljki::ParLezaljki(const ParLezaljki& gg) : Lezaljka(gg) {}
ParLezaljki::~ParLezaljki() {}

float ParLezaljki::svotaZaNaplatu() const {
    float procenat = (40.0f - 2.0f * (float)red) / 100.0f;
    return cenaLezaljki + (cenaNapitaka * (1.0f - procenat));
}

void ParLezaljki::Prikazi() const {
    Lezaljka::Prikazi();
    std::cout << " | Tip: Obicne | Naplata: " << svotaZaNaplatu();
}
