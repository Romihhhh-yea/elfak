#pragma once
#include "Paleta.h"
#include <iostream>
class Stovariste {
private:
	Paleta** niz;
	int kapacitet;
	int trBr;
public:
	Stovariste();
	Stovariste(int _kapacitet);
	~Stovariste();
	Stovariste(const Stovariste& gg);
	void Dodaj(Paleta* p);
	void Preuzmi(int oznaka);
	float UkupnaMasa(){}
	float UkupnaVrednost() {}

	void Ispisi(std::ostream& out) const;
	friend std::ostream& operator<<(std::ostream& out, const Stovariste& s);

};
