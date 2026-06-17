#pragma once
#include <iostream>
#include "ParLezaljki.h"
#include "ParLezaljkiSaDodatkom.h"
#include "ParLezaljki.h"
class KaficSaPlazom {
private:
	Lezaljka** niz;
	int maxEl;
	int trBr;
	void zauzmimem(int _maxEl);
	void oslobodimem();
public:
	KaficSaPlazom();
	KaficSaPlazom(int _maxEl);
	~KaficSaPlazom();
	KaficSaPlazom(const KaficSaPlazom& gg);

	void Dodaj(Lezaljka* l);
	void Oslobodi(int l);
	int UkupnoLezaljki();
	int UkupnaSvotaNovca();
	void VratiNajskuplje(ParLezaljki** pMaxCena, ParLezaljki** pMaxNapitak) const ;
	friend ostream& operator<<(ostream& izlaz, const KaficSaPlazom& l);
	void Prikazi(ostream& izlaz) const;
};