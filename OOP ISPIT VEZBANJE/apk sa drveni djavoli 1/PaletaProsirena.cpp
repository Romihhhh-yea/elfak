#include "PaletaProsirena.h"
PaletaProsirena::PaletaProsirena() {
	masa = 0;
	broj = 0;
	sirina = 0;
}
PaletaProsirena::PaletaProsirena(int _masa, int _broj, int _sirina) {
	masa = _masa;
	broj = _broj;
	sirina = _sirina;
}
PaletaProsirena::operator int()const  {
	return (int)masa * broj;
} 
void PaletaProsirena::prikazi(ostream& izlaz) const {
	izlaz << masa << broj << sirina;
}
ostream& operator<<(ostream& izlaz, const PaletaProsirena& p) {
	p.prikazi(izlaz);
	return izlaz;
}
bool PaletaProsirena::operator>(const PaletaProsirena& p)const {
	return masa > p.masa;
}
PaletaProsirena& PaletaProsirena::operator-(const PaletaProsirena& p) const  {
	return masa - p.masa;
}
