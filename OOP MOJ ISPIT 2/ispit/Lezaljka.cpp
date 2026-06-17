#include "Lezaljka.h"
Lezaljka::Lezaljka() {
	rednibr = 0;
	red = 0;
	cena = 0;
	vrednostpica = 0;
}
Lezaljka::Lezaljka(int _rednibr, int _red, int _cena, int _vrednostpica) {
	rednibr = _rednibr;
	red = _red;
	cena = _cena;
	vrednostpica = _vrednostpica;
}
Lezaljka::Lezaljka(const Lezaljka& gg) {
	rednibr = gg.rednibr;
	red = gg.red;
	cena = gg.cena;
	vrednostpica = gg.vrednostpica;

}
ostream& operator<<(ostream& izlaz, const Lezaljka& l) {
	l.Prikazi(izlaz);
	return izlaz;
}
void Lezaljka::Prikazi(ostream& izlaz) const {
	izlaz << "Redni broj:" << rednibr << "Red: " << red << "Cena: " << cena << "Vrednost pica: " << vrednostpica;
}
