#pragma once
#include <iostream>
using namespace std;
class Automobil
{
protected:
	char* oznaka;
	int km;
public:
	Automobil();
	Automobil(const char* oznaka, int km);
	virtual ~Automobil();
	Automobil(const Automobil& gg);
	int getkm() { return km; }
	virtual void prikazi(ostream& izlaz) const = 0;
	void PovecajKilometrazu(int kmm) { km += kmm; }
	friend ostream& operator<<(ostream& izlaz, const Automobil& a);
};

