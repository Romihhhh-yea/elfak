#include "Lezaljka.h"
Lezaljka::Lezaljka() {
	cena = 0;
	br = 0;
}
Lezaljka::Lezaljka(int _br,int _cena) {
	br = _br;
	cena = _cena;

}

ostream& operator<<(ostream& izlaz,const Lezaljka& l) {
	izlaz << l.br << " " << l.cena;
	return izlaz;
}
istream& operator>>(istream& ulaz, Lezaljka& l) {
	ulaz >> l.br >> l.cena;
	return ulaz;
}
Lezaljka::operator int() const {
	return (int)br;
}