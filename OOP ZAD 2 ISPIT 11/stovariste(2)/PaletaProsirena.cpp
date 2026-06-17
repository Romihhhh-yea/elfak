#include "PaletaProsirena.h"

PaletaProsirena::PaletaProsirena()
{
	masaJedne = 0;
	broj = 0;
	sirina = 0;

}

PaletaProsirena::PaletaProsirena(float _masaJedne, int _broj, float _sirina) : Paleta2()
{
	masaJedne = _masaJedne;
	broj = _broj;
	sirina = _sirina;
}

PaletaProsirena::~PaletaProsirena()
{
}

PaletaProsirena::PaletaProsirena(const PaletaProsirena& gg) : Paleta2(gg)	
{
	masaJedne = gg.masaJedne;
	broj = gg.broj;
	sirina = gg.sirina;
}

ostream& operator<<(ostream& izlaz, const PaletaProsirena& pp)
{
	izlaz << "Masa jedne: " << pp.masaJedne << "Broj dasaka: " << pp.broj << "Sirina: " << pp.sirina << endl;
	return izlaz;
}
