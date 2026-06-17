#include "PaletaDzak.h"

PaletaDzak::PaletaDzak() : Paleta()
{
	klasa = ' ';
	masaMat = 0;
	cena = 0;
}

PaletaDzak::PaletaDzak(int _oznaka, int _masa,char _klasa, int _masaMat, int _cena) : Paleta(_oznaka, _masa)
{
	klasa = _klasa;
	masaMat = _masaMat;
	cena = _cena;
}

PaletaDzak::~PaletaDzak()
{
}

PaletaDzak::PaletaDzak(const PaletaDzak& gg) : Paleta(gg)
{
	klasa = gg.klasa;
	masaMat = gg.masaMat;
	cena = gg.cena;
}

void PaletaDzak::prikazi(ostream& izlaz) const
{
	Paleta::prikazi(izlaz);
	izlaz << "Klasa: " << klasa << "Masa materijala: " << masaMat << "Cena: " << cena << " ";
}
