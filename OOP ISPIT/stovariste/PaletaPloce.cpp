#include "PaletaPloce.h"

PaletaPloce::PaletaPloce()
    : Paleta(), klasa('A'), brojVrsta(0), brojPlocicaPoVrsti(0),
    masaJednePlocice(0), cenaJednePlocice(0) {
}

PaletaPloce::PaletaPloce(int _oznaka, int _masaPalete, char _klasa,
    int _brojVrsta, int _brojPlocicaPoVrsti,
    float _masaJednePlocice, float _cenaJednePlocice)
    : Paleta(_oznaka, _masaPalete)
{
    klasa = _klasa;
    brojVrsta = _brojVrsta;
    brojPlocicaPoVrsti = _brojPlocicaPoVrsti;
    masaJednePlocice = _masaJednePlocice;
    cenaJednePlocice = _cenaJednePlocice;
}

PaletaPloce::PaletaPloce(const PaletaPloce& gg)
    : Paleta(gg)
{
    klasa = gg.klasa;
    brojVrsta = gg.brojVrsta;
    brojPlocicaPoVrsti = gg.brojPlocicaPoVrsti;
    masaJednePlocice = gg.masaJednePlocice;
    cenaJednePlocice = gg.cenaJednePlocice;
}

PaletaPloce::~PaletaPloce() {}

float PaletaPloce::UkupnaMasa() const {
    return GetMasaPalete() +
        brojVrsta * brojPlocicaPoVrsti * masaJednePlocice;
}

float PaletaPloce::Vrednost() const {
    return brojVrsta * brojPlocicaPoVrsti * cenaJednePlocice;
}

void PaletaPloce::Ispisi(std::ostream& out) const {
    out << "PLOCE "
        << GetOznaka() << " "
        << GetMasaPalete() << " "
        << klasa << " "
        << brojVrsta << " "
        << brojPlocicaPoVrsti << " "
        << masaJednePlocice << " "
        << cenaJednePlocice;
}
