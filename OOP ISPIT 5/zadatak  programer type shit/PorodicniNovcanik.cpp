#include "PorodicniNovcanik.h"
#include <typeinfo>
void PorodicniNovcanik::zauzmiMem(int _maxEl)
{
	maxEl = _maxEl;
	trBr = 0;
	niz = new Novcanica * [maxEl];
	for (int i = 0; i < maxEl; i++) {
		niz[i] = nullptr;
	}
}

void PorodicniNovcanik::oslobodiMem()
{
	if (niz != nullptr)
		for (int i = 0; i < trBr; i++)
			if (niz[i] != nullptr)
				delete niz[i];
	delete niz;
}

PorodicniNovcanik::PorodicniNovcanik()
{
	niz = nullptr;
	maxEl = 0;
	trBr = 0;
}

PorodicniNovcanik::PorodicniNovcanik(int _maxEl)
{
	zauzmiMem(_maxEl);
}

PorodicniNovcanik::~PorodicniNovcanik()
{
	oslobodiMem();
}

PorodicniNovcanik::PorodicniNovcanik(const PorodicniNovcanik& gg)
{
	maxEl = gg.maxEl;
	zauzmiMem(maxEl);
	for (int i = 0; i < gg.trBr; i++) {
		if (typeid(*gg.niz[i]) == typeid(NovcanicaDinar));
		
	}
}

void PorodicniNovcanik::Dodaj(Novcanica* nova)
{
	if(trBr<maxEl)
		niz[trBr++] = nova;
}

void PorodicniNovcanik::prikazi(ostream& izlaz)
{
}

ostream& operator<<(ostream& izlaz, const PorodicniNovcanik& pn)
{
	for (int i = 0; i < pn.trBr; i++) {
		izlaz << pn.niz[i] << endl;
	}
	return izlaz;
}