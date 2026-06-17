#include "Novcanica.h"

Novcanica::Novcanica()
{
    vrednost = 0;
    kolicina = 0;
}

Novcanica::Novcanica(int _vrednost, int _kolicina)
{
    vrednost = _vrednost;
    kolicina = _kolicina;
}

Novcanica::~Novcanica()
{
}

Novcanica::Novcanica(const Novcanica& gg)
{
    vrednost = gg.vrednost;
    kolicina = gg.kolicina;
}

void Novcanica::prikazi(ostream& izlaz) const
{
    izlaz << "Vrednost: " << vrednost << "Kolicina: " << kolicina << endl;
}

ostream& operator<<(ostream& izlaz, const Novcanica& n)
{
    n.prikazi(izlaz);
    return izlaz;
}
