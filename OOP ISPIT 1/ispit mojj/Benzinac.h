#pragma once
#include "Automobil.h"

class Benzinac : public Automobil
{
private:
	float zapremina;
	float prosekPot;
	float utrosenoGor;
public:
	Benzinac();
	Benzinac(const char* oznaka, int km,float _zapremina, float _prosekPot, float _utrosenoGor);
	~Benzinac() override {}
	Benzinac(const Benzinac& gg);
	int getkm() { return km; }
	char* tablica() {return oznaka;}
	void PovecajKilometrazu(int kmm) { km += kmm; }
	//int zapreminaa()  { return zapremina * (prosekPot + km); }
	virtual void prikazi(ostream& izlaz) const override;
	
};

