#ifndef PARLEZALJKISADODATKOM_H
#define PARLEZALJKISADODATKOM_H
#include "ParLezaljki.h"

class ParLezaljkiSaDodatkom : public ParLezaljki {
private:
    int brDodatnihLezaljki; // bdl iz teksta
public:
    ParLezaljkiSaDodatkom();
    ParLezaljkiSaDodatkom(int _redniBroj, int _red, float _cenaLezaljki, float _cenaNapitaka, int _brDodatnihLezaljki);
    ParLezaljkiSaDodatkom(const ParLezaljkiSaDodatkom& gg);
    ~ParLezaljkiSaDodatkom();

    float svotaZaNaplatu() const override;
    void Prikazi() const override;
};
#endif

