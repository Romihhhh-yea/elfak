#pragma once
#include "Paleta.h"

class PaletaPloce : public Paleta {
protected:
    char klasa;
    int brojVrsta;
    int brojPlocicaPoVrsti;
    float masaJednePlocice;
    float cenaJednePlocice;

public:
    PaletaPloce();
    PaletaPloce(int _oznaka, int _masaPalete, char _klasa,
        int _brojVrsta, int _brojPlocicaPoVrsti,
        float _masaJednePlocice, float _cenaJednePlocice);
    PaletaPloce(const PaletaPloce& gg);
    virtual ~PaletaPloce();

    float UkupnaMasa() const override;
    float Vrednost() const override;
    void Ispisi(std::ostream& out) const override;
};
