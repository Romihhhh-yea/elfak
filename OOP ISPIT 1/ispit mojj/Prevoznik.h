#pragma once
#include "Automobil.h"
#include "Hibrid.h"
#include "Benzinac.h"

class Prevoznik
{
private:
	Automobil** niz;
	int trBr;
	int maxEl;
	void zauzmiMem(int _maxEl);
	void oslobodiMem();
public:
	Prevoznik();
	Prevoznik(int _maxEl);
	~Prevoznik();
	Prevoznik(const Prevoznik& gg);
	Automobil* Dodaj(Automobil* novi);
	void IzbaciPoKm(int km);
	int UkupnaKilometraza();
	void ObavljenaVoznja(const char* tablice, int kmm);
	void VratiNajDuzinuGorivo(Automobil** pMinDuzina, Automobil** pMinPotrosio);

	void prikazi(ostream& izlaz) const;
	friend ostream& operator<<(ostream& izlaz, const Prevoznik& p);
};

