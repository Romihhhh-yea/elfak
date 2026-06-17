#pragma once
#include "IspitniMaterijal.h"
class Zadatak : public IspitniMaterijal
{
private:
	int brLinija;
public:
	Zadatak();
	Zadatak(int _oznaka, float _tezina,int _brLinija, bool _savladan = false);
	~Zadatak() override;
	Zadatak(const Zadatak& gg);
	virtual int vremeSavladavanja(int vreme);

	void prikazi(ostream& izlaz) const override;
};

