#ifndef PALETAPROSIRENA_H
#define PALETAPROSIRENA_H
#include "Paleta.h"

class PaletaProsirena : public Paleta {
private:
    float masaJedneDaske;
    int brojDasaka;
    float sirinaSvihDasaka;
public:
    PaletaProsirena();
    PaletaProsirena(float _masaJedneDaske, int _brojDasaka, float _sirinaSvihDasaka);
    PaletaProsirena(const PaletaProsirena& gg);
    ~PaletaProsirena();

    int getMasa() const override;
    void Prikazi(std::ostream& izlaz) const override;
    friend std::istream& operator>>(std::istream& ulaz, PaletaProsirena& p);
};
#endif