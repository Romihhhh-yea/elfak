#include "Zadatak.h"

Zadatak::Zadatak() : IspitniMaterijal()
{
	brLinija = 0;
}

Zadatak::Zadatak(int _oznaka, float _tezina, int _brLinija, bool _savladan) : IspitniMaterijal(_oznaka, _tezina, _savladan)
{
	brLinija = _brLinija;
}

Zadatak::~Zadatak()
{
}

Zadatak::Zadatak(const Zadatak& gg) : IspitniMaterijal(gg)
{
	brLinija = gg.brLinija;
}

int Zadatak::vremeSavladavanja(int vreme)
{
	return brLinija * tezina * vreme * 0.05;
}

void Zadatak::prikazi(ostream& izlaz) const
{
	IspitniMaterijal::prikazi(izlaz);
	izlaz << "Broj linija: " << brLinija;
}
