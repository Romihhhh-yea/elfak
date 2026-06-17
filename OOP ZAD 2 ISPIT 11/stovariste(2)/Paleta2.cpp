#include "Paleta2.h"

Paleta2::Paleta2()
{
    masa = 0;
}

Paleta2::Paleta2(int _masa)
{
    masa = _masa;
}

Paleta2::~Paleta2()
{
}

Paleta2::Paleta2(const Paleta2& gg)
{
    masa = gg.masa;
}

ostream& operator<<(ostream& izlaz, const Paleta2& p2)
{
    izlaz << "Masa: " << p2.masa << endl;
    return izlaz;
}
