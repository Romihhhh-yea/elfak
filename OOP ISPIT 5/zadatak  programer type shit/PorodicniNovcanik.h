#pragma once
#include "Novcanica.h"
#include "NovcanicaDinar.h"
#include "NovcanicaStrana.h"
#include <iostream>
class PorodicniNovcanik
{
private:
	Novcanica** niz;
	int trBr;
	int maxEl;
	void zauzmiMem(int _maxEl);
	void oslobodiMem();
public:
	PorodicniNovcanik();
	PorodicniNovcanik(int _maxEl);
	~PorodicniNovcanik();
	PorodicniNovcanik(const PorodicniNovcanik& gg);
	void Dodaj(Novcanica* nova);

	void prikazi(ostream& izlaz);
	friend ostream& operator<<(ostream& izlaz, const PorodicniNovcanik& pn);
};

