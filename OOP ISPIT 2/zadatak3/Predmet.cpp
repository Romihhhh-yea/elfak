#include "Predmet.h"


Predmet::Predmet() {
	
	naziv = nullptr;

}
Predmet::Predmet(const char* _naziv) {

	naziv = new char[strlen(_naziv) + 1];
	strcpy(naziv, _naziv);
}
Predmet::Predmet(const Predmet& gg) {

	naziv = new char[strlen(gg.naziv) + 1];
	strcpy(naziv, gg.naziv);
}
Predmet::~Predmet() {
	if (naziv != nullptr)
		delete[] naziv;
}
void Predmet::prikazi(ostream& izlaz) const {
	izlaz << "Naziv: " << naziv << endl;
}
ostream& operator<<(ostream& izlaz, const Predmet& p) {
	p.prikazi(izlaz);
	return izlaz;
}

