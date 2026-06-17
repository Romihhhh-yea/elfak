#pragma once
#include "Lezaljka.h"
class ParLezaljkiSaDodatkom : public Lezaljka
{
private:
	int dodatneLez;
public:
	ParLezaljkiSaDodatkom();
	ParLezaljkiSaDodatkom(int _rednibr, int _red, int _cena, int _vrednostpica, int _dodatneLez);
	~ParLezaljkiSaDodatkom() {}
	ParLezaljkiSaDodatkom(const ParLezaljkiSaDodatkom& gg);
	virtual int svotaZaNaplatu() const override;
	int getRedniBr() { return rednibr; }
	virtual void Prikazi(ostream& izlaz) const override;
	int getVrednostPica() { return vrednostpica; }
};

