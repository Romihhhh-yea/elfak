#include "NovcanicaStrana.h"
#include <cstring>
NovcanicaStrana::NovcanicaStrana()
{
	oznaka = nullptr;
	kurs = 0;
}

NovcanicaStrana::NovcanicaStrana(int _vrednost, int _kolicina, const char* _oznaka, int _kurs) : Novcanica(_vrednost,_kolicina)
{
	oznaka = new char[strlen(_oznaka) + 1];
	strcpy(oznaka, _oznaka);
	kurs = _kurs;
}

NovcanicaStrana::~NovcanicaStrana()
{
	delete[] oznaka;
}

NovcanicaStrana::NovcanicaStrana(const NovcanicaStrana& gg) : Novcanica(gg)
{
	oznaka = new char[strlen(gg.oznaka) + 1];
	strcpy(oznaka,gg.oznaka);
	kurs = gg.kurs;
}

void NovcanicaStrana::prikazi(ostream& izlaz) const
{
	izlaz << "Oznaka: " << oznaka << " Kurs: " << kurs;
}
