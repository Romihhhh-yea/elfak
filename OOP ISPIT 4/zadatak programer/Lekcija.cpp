#include "Lekcija.h"

Lekcija::Lekcija() : IspitniMaterijal()
{
	tezina = 0;
}

Lekcija::Lekcija(int _oznaka, float _tezina, float _duzina, bool _savladan) : IspitniMaterijal(_oznaka,_tezina,_savladan)
{
	tezina = _tezina;
}

Lekcija::~Lekcija()
{
}

Lekcija::Lekcija(const Lekcija& gg) : IspitniMaterijal(gg)
{
	tezina = gg.tezina;
}

void Lekcija::prikazi(ostream& izlaz) const
{
	IspitniMaterijal::prikazi(izlaz);
	izlaz << "Tezina: " << tezina;
}
int Lekcija::vremeSavladavanja(int vreme)
{
	return duzina * tezina * vreme;
}
