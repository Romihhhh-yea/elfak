#include "Hibrid.h"

Hibrid::Hibrid()
{
	zapremina = 0;
	prosekPot = 0;
	utrosenoGor = 0;
	elektricnaDuzina = 0;
}

Hibrid::Hibrid(const char* oznaka, int km, float _zapremina, float _prosekPot, float _utrosenoGor, int _elektricnaDuzina)
{
	zapremina = _zapremina;
	prosekPot = _prosekPot;
	utrosenoGor = _utrosenoGor;
	elektricnaDuzina = _elektricnaDuzina;
}


Hibrid::Hibrid(const Hibrid& gg)
{
	zapremina = gg.zapremina;
	prosekPot = gg.prosekPot;
	utrosenoGor = gg.utrosenoGor;
	elektricnaDuzina = gg.elektricnaDuzina;
}

void Hibrid::prikazi(ostream& izlaz) const
{
	Automobil::prikazi(izlaz);
	izlaz << "Zapremina: " << zapremina << "Prosek potrosnje: " << prosekPot << "Utroseno gorivo: " << utrosenoGor << "Duzina puta koju vozilo moze da predje na elektricni pogon: " << elektricnaDuzina;
}
