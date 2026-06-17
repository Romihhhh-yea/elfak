#pragma once
#include <iostream>
using namespace std;
class Lezaljka
{
protected:
	int rednibr;
	int red;
	int cena;
	int vrednostpica;
public:
	Lezaljka();
	Lezaljka(int _rednibr, int _red, int _cena, int _vrednostpica);
	Lezaljka(const Lezaljka& gg);
	virtual ~Lezaljka() {}
	virtual void Prikazi(ostream& izlaz) const = 0;
	virtual int svotaZaNaplatu() const = 0;
	int getVrednostPica() { return vrednostpica; }
	friend ostream& operator<<(ostream& izlaz, const Lezaljka& l);
	int getRedniBr() { return rednibr; }
};

