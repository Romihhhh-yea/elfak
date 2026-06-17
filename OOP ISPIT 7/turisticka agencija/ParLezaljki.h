#ifndef PARLEZALJKI_H
#define PARLEZALJKI_H
#include "Lezaljka.h"

class ParLezaljki : public Lezaljka {
public:
    ParLezaljki();
    ParLezaljki(int _redniBroj, int _red, float _cenaLezaljki, float _cenaNapitaka);
    ParLezaljki(const ParLezaljki& gg);
    ~ParLezaljki();

    float svotaZaNaplatu() const override;
    void Prikazi() const override;
};
#endif
