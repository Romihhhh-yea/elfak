#pragma once
#include "Paleta.h"
class PaletaDzak : public Paleta
{
private:
	char klasa;
	int masaMat;
	int cena;
public:
	PaletaDzak();
	PaletaDzak(int _oznaka, int _masa,char _klasa, int _masaMat, int _cena);
	~PaletaDzak() override;
	virtual int getOznaka() override { return oznaka; }
	virtual int getMasa() override { return masa + masaMat; }
	int getCena() override { return cena; }
	PaletaDzak(const PaletaDzak& gg);

	void prikazi(ostream& izlaz) const override;

};

