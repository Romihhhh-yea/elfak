#pragma once
#include "Lekcija.h"
#include "IspitniMaterijal.h"
#include "Zadatak.h"
class IspitPriprema
{
private:
	IspitniMaterijal** niz;
	int trBr;
	int maxEl;
	void zauzmiMem(int _maxEl);
	void oslobodiMem();
	public:
	IspitPriprema();
	IspitPriprema(int _maxEl);
	~IspitPriprema();
	IspitPriprema(const IspitPriprema& gg);
	void Dodaj(IspitniMaterijal* novi);
	void Obrisi(int oznakaa);
	void Savladaj(int oznakaa);
	int UkupnoSavladanih();
	float UkupnoVreme(int vreme);
	void VratiNaj(int vreme, IspitniMaterijal** min, IspitniMaterijal** max);
	friend ostream& operator<<(ostream& izlaz, const IspitPriprema& ip);
};

