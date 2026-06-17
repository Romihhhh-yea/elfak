#include "Jabuka.h"

Jabuka::Jabuka() : Predmet()
{
	masa = 0;
	Ks = 0;
	Kk = 0;
	boja = nullptr;
}

Jabuka::Jabuka(const char* _naziv, double _masa, double _Ks, double _Kk, const char* _boja) : Predmet(_naziv)
{
	masa = _masa;
	Ks = _Ks;
	Kk = _Kk;
	boja = new char[strlen(_boja) + 1];
	strcpy(boja, _boja);
}

Jabuka::Jabuka(const Jabuka& gg) : Predmet(gg)
{
	masa = gg.masa;
	Ks = gg.Ks;
	Kk = gg.Kk;
	boja = new char[strlen(gg.boja) + 1];
	strcpy(boja, gg.boja);
}

Jabuka::~Jabuka()
{
	if (boja != nullptr)
		delete[] boja;
}

double Jabuka::vrednost() const
{
	double proizvodK = Ks * Kk;
	double R = 1000;
	if (Ks < 0.5 && Kk < 0.5)
		R = 0;
	return R * proizvodK * masa;
}

void Jabuka::prikazi(ostream& izlaz) const {
	Predmet::prikazi(izlaz);
	izlaz << "Boja: " << boja << endl;
	izlaz << "Ks: " << Ks << endl;
	izlaz << "Kk: " << Kk << endl;
	izlaz << "Masa: " << masa << endl;
}