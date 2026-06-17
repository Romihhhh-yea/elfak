#pragma once
#include "Paleta.h"
class PaletaPlocice : public Paleta
{
private:
	char klasa;
	int brVrste;
	int kolicina;
	int masaJedne;
	int cena;
public:
	PaletaPlocice();
	PaletaPlocice(int _oznaka, int _masa, const char _klasa, int _brVrste, int _kolicina,int _masaJedne,int _cena);
	~PaletaPlocice() override;
	PaletaPlocice(const PaletaPlocice& gg);
	virtual int getOznaka() override { return oznaka; }
	virtual int getMasa() override { return masa + (kolicina*masaJedne); }
	int getCena() override { return cena; }

	void prikazi(ostream& izlaz) const override;
};

