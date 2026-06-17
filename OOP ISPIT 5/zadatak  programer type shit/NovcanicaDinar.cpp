#include "NovcanicaDinar.h"

NovcanicaDinar::NovcanicaDinar()
{
}

NovcanicaDinar::NovcanicaDinar(int _vrednost, int _kolicina) : Novcanica(_vrednost,_kolicina)
{
}

NovcanicaDinar::~NovcanicaDinar()
{
}

NovcanicaDinar::NovcanicaDinar(const NovcanicaDinar& gg) : Novcanica(gg)
{
}

void NovcanicaDinar::prikazi(ostream& izlaz) const
{
	izlaz << "Vrednost: " << vrednost << " Kolicina: " << kolicina << endl;
}
