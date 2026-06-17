#include "ParLezaljki.h"
ParLezaljki::ParLezaljki() : Lezaljka(){

}
ParLezaljki::ParLezaljki(int _rednibr, int _red, int _cena, int _vrednostpica) : Lezaljka(_rednibr, _red, _cena, _vrednostpica) {

}
ParLezaljki::ParLezaljki(const ParLezaljki& gg) : Lezaljka(gg) {

}
void ParLezaljki::Prikazi(ostream& izlaz) const {
	Lezaljka::Prikazi(izlaz);
}
int ParLezaljki::svotaZaNaplatu() const {
	float popustNaPice = (40.0 - 2.0 * red) / 100.0;
	return cena + vrednostpica * (1.0 - popustNaPice);
}
