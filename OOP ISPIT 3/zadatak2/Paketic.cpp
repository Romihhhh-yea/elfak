#include "Paketic.h"
#include <cstring>
using namespace std;
Paketic::Paketic() {
	adresa = nullptr;
	boja =   nullptr;
}
Paketic::Paketic(const char* _adresa, const char* _boja) {
	adresa = new char[strlen(_adresa) + 1];
	strcpy(adresa, _adresa);
	boja = new char[strlen(_boja) + 1];
	strcpy(boja, _boja);
}
Paketic::Paketic(const Paketic& gg) {
	adresa = new char[strlen(gg.adresa) + 1];
	strcpy(adresa, gg.adresa);
	boja = new char[strlen(gg.boja) + 1];
	strcpy(boja, gg.boja);
}
Paketic::~Paketic() {
	delete[] adresa;
	delete[] boja;
}
void Paketic::prikazi(ostream& izlaz) const {
	izlaz << "Adresa: " << adresa << endl;
	izlaz << "Boja: " << boja << endl;
}
ostream& operator<<(std::ostream& izlaz, const Paketic& p) {
	p.prikazi(izlaz);
	return izlaz;
}
const char* Paketic::getAdresa() const {
	return adresa;
}