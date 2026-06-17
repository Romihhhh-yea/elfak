#pragma once
#include "Pice.h"
#include "Sok.h"
#include "Voda.h"
#include <iostream>
using namespace std;
class Skladiste
{
private:
	Pice** niz;
	int maxEl;
	int trBr;
	void zauzmimem(int _maxEl);
	void oslobodimem();
public:
	Skladiste();
	Skladiste(int _maxEl);
	~Skladiste();
	Skladiste(const Skladiste& gg);

	friend ostream& operator<<(ostream& izlaz,const Skladiste& s);
	void prikazi(ostream& izlaz);
	void Dodaj(Pice* p);
	void Izdvoji(Pice* p, int kolicina);
};

