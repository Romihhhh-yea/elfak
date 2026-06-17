#include "PaletaProsirena.h"

PaletaProsirena::PaletaProsirena() 
{
    masaDaske = 0;
    kolicina = 0;
    sirinaSvih = 0;
}

PaletaProsirena::PaletaProsirena(float _masaDaske, int _kolicina, float _sirinaSvih) 
{
    masaDaske = _masaDaske;
    kolicina = _kolicina;
    sirinaSvih = _sirinaSvih;
}

PaletaProsirena::PaletaProsirena(const PaletaProsirena& gg) 
{
    masaDaske = gg.masaDaske;
    kolicina = gg.kolicina;
    sirinaSvih = gg.sirinaSvih;
}

PaletaProsirena::~PaletaProsirena()
{
}

ostream& operator<<(ostream& izlaz, const PaletaProsirena& p)
{
    izlaz << "Masa Daske: " << p.masaDaske << " Kolicina: " << p.kolicina << " Sirina svih: " << p.sirinaSvih;
    return izlaz;
}
