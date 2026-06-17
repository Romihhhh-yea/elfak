#include "Benzinac.h"

Benzinac::Benzinac()
{
	zapremina = 0;
	prosekPot = 0;
	utrosenoGor = 0;
}

Benzinac::Benzinac(const char* oznaka, int km,float _zapremina, float _prosekPot, float _utrosenoGor) : Automobil(oznaka,km)
{
	zapremina = _zapremina;
	prosekPot = _prosekPot;
	utrosenoGor = _utrosenoGor;
}

Benzinac::Benzinac(const Benzinac& gg) : Automobil(gg)
{
	zapremina = gg.zapremina;
	prosekPot = gg.prosekPot;
	utrosenoGor = gg.utrosenoGor;
}

void Benzinac::prikazi(ostream& izlaz) const
{
	Automobil::prikazi(izlaz);
	izlaz << "Zapremina: " << zapremina << "Prosek potrosnje: " << prosekPot << "Utroseno gorivo: " << utrosenoGor;
}
