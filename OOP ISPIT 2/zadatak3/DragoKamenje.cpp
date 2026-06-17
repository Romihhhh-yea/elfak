#pragma once
#include "DragoKamenje.h"
DragoKamenje::DragoKamenje() : Predmet() {
	cistoca = 0;
	brStranica = 0;
	boja = nullptr;
	masa = 0;
}
DragoKamenje::DragoKamenje(const char* _naziv, double _cistoca, const char* _boja, int _brStranica,double _masa) : Predmet(_naziv) {
	cistoca = _cistoca;
	brStranica = _brStranica;
	boja = new char[strlen(_boja) + 1];
	strcpy(boja, _boja);
	masa = _masa;
}
DragoKamenje::DragoKamenje(const DragoKamenje& gg) : Predmet(gg) {
	cistoca = gg.cistoca;
	brStranica = gg.brStranica;
	boja = new char[strlen(gg.boja) + 1];
	strcpy(boja, gg.boja);
	masa = gg.masa;
}
DragoKamenje::~DragoKamenje() {
	if (boja != nullptr)
		delete[] boja;
}
void DragoKamenje::prikazi(ostream& izlaz) const {
	Predmet::prikazi(izlaz);
	izlaz << "Cistoca: " << cistoca << endl;
	izlaz << "Boja: " << boja << endl;
	izlaz << "Broj Stranica: " << brStranica << endl;
	izlaz << "Masa: " << masa << endl;
}
double DragoKamenje::vrednost() const {
	return masa * cistoca;
}