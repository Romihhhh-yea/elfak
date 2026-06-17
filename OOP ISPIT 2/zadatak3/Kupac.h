#pragma once
#include "Predmet.h"
#include <iostream>
using namespace std;
class Kupac{
private:
	Predmet** niz;
	int trBr;
	int maxBr;
	void oslobodimem();
	void zauzmimem(int _maxBr);
public:
	Kupac();
	Kupac(int maxBr);
	Kupac(const Kupac& gg);
	~Kupac();

	friend ostream& operator<<(ostream& izlaz, const Kupac& k);
	
	void prikazi(ostream& izlaz) const;
	void Add(Predmet* p);
	double prosecnaVrednost() const;
	Predmet* najvrednijiPoJediniciMase() const;
};


