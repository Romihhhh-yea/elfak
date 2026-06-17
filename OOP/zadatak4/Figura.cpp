#include "Figura.h"

Figura::Figura() {
	boja = nullptr;
}
Figura::Figura(const char* _boja) {
	boja = new char[strlen(_boja) + 1];
	strcpy(boja, _boja);
}
Figura::Figura(const Figura& gg) {
	boja = new char[strlen(gg.boja) + 1];
	strcpy(boja, gg.boja);
}
Figura::~Figura() {
	if (boja != nullptr)
		delete[] boja;
}
ostream& operator<<(ostream& izlaz, const Figura& f) {
	f.prikazi(izlaz);
	return izlaz;
}
void Figura::prikazi(ostream& izlaz) const  {
	izlaz << "Boja: " << boja << endl;
}
double Figura::koeficijent() const {
	if (obim() == 0)
		return 0;
	return povrsina() / obim();
}