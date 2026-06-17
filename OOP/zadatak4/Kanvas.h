#pragma once
#include <iostream>
#include "Figura.h"
// #include "Pravougaonik.h"
// #include "Kvadrat.h"
using namespace std;
class Kanvas
{
private:
	Figura** niz;
	int maxEl;
	int trBr;
	void oslobodimem();
	void zauzmimem(int _maxEl);
public:
	Kanvas();
	Kanvas(int _maxEl);
	Kanvas(const Kanvas& gg);
	~Kanvas();

	void Add(Figura* f);
	friend ostream& operator<<(ostream& izlaz, const Kanvas& k);
	double UkupnaPovrsina() const;
	double UkupanObim() const;
	void Max(Figura** pmax, int* ind);
	Kanvas* PrebacitiPoBoji(const char* boja);

	inline int BrojFigura() const { return maxEl; }
};

