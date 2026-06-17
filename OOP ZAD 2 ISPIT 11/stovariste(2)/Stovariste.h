#pragma once
#include "Paleta.h"
#include "PaletaDzak.h"
#include "PaletaPlocice.h"
#include <typeinfo>
class Stovariste
{
private:
	Paleta** niz;
	int trBr;
	int maxEl;
	void zauzmiMem(int _maxEl);
	void oslobodiMem();
public:
	Stovariste();
	Stovariste(int _maxEl);
	~Stovariste();
	Stovariste(const Stovariste& gg);
	friend ostream& operator<<(ostream& izlaz, const Stovariste& s);
	void prikazi(ostream& izlaz) const;
	void Dodaj(Paleta* nov);
	Paleta* Preuzmi(int broj);
	int UkupnaMasa();
	int UkupnaVrednost();
	int BrojSaVredIzmedju(int dole, int gore);
	void VratiNajMasuVrednost(Paleta** pMaxMasa, Paleta** pMaxVred);
};

