#include "ZlatnaPoluga.h"
ZlatnaPoluga::ZlatnaPoluga() : Predmet() {
	masa = 0;
	stepenCistoce = 0;
}
ZlatnaPoluga::ZlatnaPoluga(const char* _naziv, double _masa, double _stepenCistoce) : Predmet(_naziv) {
	masa = _masa;
	stepenCistoce = _stepenCistoce;

}
ZlatnaPoluga::ZlatnaPoluga(const ZlatnaPoluga& gg) : Predmet(gg) {
	masa = gg.masa;
	stepenCistoce = gg.stepenCistoce;
}

double ZlatnaPoluga::vrednost() const {
	
	return masa * (stepenCistoce / 24.0);
}
void ZlatnaPoluga::prikazi(ostream& izlaz) const {
	Predmet::prikazi(izlaz);
	izlaz << "Masa: " << masa << endl;
	izlaz << "Stepen cistoce: " << stepenCistoce << endl;
}
