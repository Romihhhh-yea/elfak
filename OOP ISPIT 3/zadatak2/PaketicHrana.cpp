#include <iostream>
#include "PaketicHrana.h"
using namespace std;

PaketicHrana::PaketicHrana() : Paketic() {
	brojCokolada = 0;
	ukupnaTezinaCokolade = 0;
	cenaPoKg = 0;
}
PaketicHrana::PaketicHrana(const char* adresa, const char* boja, int _brojCokolada, double _ukupnaTezinaCokolade, double _cenaPoKg) : Paketic(adresa,boja){
	brojCokolada = _brojCokolada;
	ukupnaTezinaCokolade = _ukupnaTezinaCokolade;
	cenaPoKg = _cenaPoKg;
}
PaketicHrana::PaketicHrana(const PaketicHrana& gg) : Paketic(gg) {
	brojCokolada = gg.brojCokolada;
	ukupnaTezinaCokolade = gg.ukupnaTezinaCokolade;
	cenaPoKg = gg.cenaPoKg;
}
PaketicHrana::~PaketicHrana() {}

double PaketicHrana::tezina() const {
	return ukupnaTezinaCokolade;
}

double PaketicHrana::cena() const {
	return ukupnaTezinaCokolade * cenaPoKg;
}

void PaketicHrana::prikazi(std::ostream& izlaz) const {
	Paketic::prikazi(izlaz);
	izlaz << "Broj cokolada: " << brojCokolada << std::endl;
	izlaz << "Ukupna tezina cokolade: " << ukupnaTezinaCokolade << std::endl;
	izlaz << "Cena po kg: " << cenaPoKg << std::endl;
}