#include "Paleta.h"

Paleta::Paleta()
{
    oznaka = 0;
    masa = 0;
}

Paleta::Paleta(int _oznaka, int _masa)
{
    oznaka = _oznaka;
    masa = _masa;
}

Paleta::~Paleta()
{
}

Paleta::Paleta(const Paleta& gg)
{
    oznaka = gg.oznaka;
    masa = gg.masa;
}

void Paleta::prikazi(ostream& izlaz) const
{
    izlaz << "Oznaka: " << oznaka << "Masa" << masa << " ";
}

ostream& operator<<(ostream& izlaz, const Paleta& p)
{
    p.prikazi(izlaz);
    return izlaz;
}
