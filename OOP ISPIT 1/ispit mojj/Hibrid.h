#pragma once
#include "Automobil.h"


class Hibrid :
    public Automobil
{
private:
	float zapremina;
	float prosekPot;
	float utrosenoGor;
	int elektricnaDuzina;
public:
	Hibrid();
	Hibrid(const char* oznaka, int km, float _zapremina, float _prosekPot, float _utrosenoGor, int _elektricnaDuzina);
	~Hibrid() override {}
	Hibrid(const Hibrid& gg);
	char* tablica() { return oznaka; }
	int getkm() { return km; }
	//int zapremina(){ return zapremina * (prosekPot + km/elektricnaDuzina); }
	virtual void prikazi(ostream& izlaz) const override;
};

