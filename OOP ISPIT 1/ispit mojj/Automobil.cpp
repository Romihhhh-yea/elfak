#include "Automobil.h"
#include <string.h>
Automobil::Automobil()
{
	oznaka = nullptr;
	km = 0;
}

Automobil::Automobil(const char* _oznaka, int _km)
{
	oznaka = new char[strlen(_oznaka) + 1];
	strcpy(oznaka, _oznaka);
	km = _km;
}

Automobil::~Automobil()
{
	delete[] oznaka;
}

Automobil::Automobil(const Automobil& gg)
{
	oznaka = new char[strlen(gg.oznaka) + 1];
	strcpy(oznaka, gg.oznaka);
	km = gg.km;
}

void Automobil::prikazi(ostream& izlaz) const
{
	izlaz << "Oznaka: " << oznaka << "Kilometraza" << km;
}

ostream& operator<<(ostream& izlaz, const Automobil& a)
{
	p.prikazi(izlaz);
}
