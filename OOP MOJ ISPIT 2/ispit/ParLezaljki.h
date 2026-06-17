#pragma once
#include "Lezaljka.h"
#include <iostream>
using namespace std;
class ParLezaljki : public Lezaljka
{
public:
	ParLezaljki();
	ParLezaljki(int _rednibr, int _red, int _cena, int _vrednostpica);
	virtual ~ParLezaljki() {}
	ParLezaljki(const ParLezaljki& gg);
	int getRedniBr() { return rednibr; }
	int getVrednostPica() { return vrednostpica; }
	virtual int svotaZaNaplatu() const override;
	virtual void Prikazi(ostream& izlaz) const override;
};

