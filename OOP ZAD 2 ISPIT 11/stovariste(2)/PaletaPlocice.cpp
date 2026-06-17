#include "PaletaPlocice.h"

PaletaPlocice::PaletaPlocice() : Paleta()
{
	 klasa = ' ';
	 brVrste = 0;
	 kolicina = 0;
	 masaJedne = 0;
}

PaletaPlocice::PaletaPlocice(int _oznaka, int _masa, const char _klasa, int _brVrste, int _kolicina, int _masaJedne, int _cena) : Paleta(_oznaka, _masa)
{
	klasa = _klasa;
	brVrste = _brVrste;
	kolicina = _kolicina;
	masaJedne = _masaJedne;
	cena = _cena;
}

PaletaPlocice::~PaletaPlocice()
{
}

PaletaPlocice::PaletaPlocice(const PaletaPlocice& gg) : Paleta(gg)
{
	klasa = gg.klasa;
	brVrste = gg.brVrste;
	kolicina = gg.kolicina;
	masaJedne = gg.masaJedne;
	cena = gg.cena;
}

void PaletaPlocice::prikazi(ostream& izlaz) const
{
	Paleta::prikazi(izlaz);
	izlaz << "Klasa: " << klasa << "Broj vrste: " << brVrste << "Kolicina: " << kolicina << "Masa jedne: " << masaJedne <<  "Cena: " << cena << " ";
}
