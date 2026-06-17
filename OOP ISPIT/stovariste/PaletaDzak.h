#pragma once
#include "Paleta.h"

class PaletaDzak : public Paleta {
protected:
    char klasa;
    float masaMaterijala;
    float cenaPoKg;

public:
    PaletaDzak();
    PaletaDzak(int _oznaka, int _masaPalete, char _klasa,
        float _masaMaterijala, float _cenaPoKg);
    PaletaDzak(const PaletaDzak& gg);
    virtual ~PaletaDzak();

    float UkupnaMasa() const override;
    float Vrednost() const override;
    void Ispisi(std::ostream& out) const override;
};
