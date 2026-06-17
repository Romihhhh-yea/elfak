#include "IspitniMaterijal.h"

IspitniMaterijal::IspitniMaterijal()
{
    oznaka = 0;
    tezina = 0;
    savladan = false;
}

IspitniMaterijal::IspitniMaterijal(int _oznaka, float _tezina, bool _savladan)
{
    oznaka = _oznaka;
    tezina = _tezina;
    savladan = _savladan;
}

IspitniMaterijal::IspitniMaterijal(const IspitniMaterijal& gg)
{
    oznaka = gg.oznaka;
    tezina = gg.tezina;
    savladan = gg.savladan;
}

void IspitniMaterijal::prikazi(ostream& izlaz) const
{
    izlaz << "Oznaka: " << oznaka << " Tezina: " << tezina << " Savladan: " << (savladan ?  "Da" : "Ne");
}

ostream& operator<<(ostream& izlaz, const IspitniMaterijal& im)
{
    im.prikazi(izlaz);
    return izlaz;
}
