#pragma once
#include "IspitniMaterijal.h"
class Lekcija : public IspitniMaterijal
{
private:
	float duzina;
public:
	Lekcija();
	Lekcija(int _oznaka, float _tezina, float _duzina, bool _savladan = false);
	~Lekcija() override;
	Lekcija(const Lekcija& gg);
	void prikazi(ostream& izlaz) const override;
	virtual int vremeSavladavanja(int vreme);
};

