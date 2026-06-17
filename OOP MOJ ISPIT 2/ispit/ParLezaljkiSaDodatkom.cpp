#include "ParLezaljkiSaDodatkom.h"
ParLezaljkiSaDodatkom::ParLezaljkiSaDodatkom() : Lezaljka() {
	dodatneLez = 0;
}
ParLezaljkiSaDodatkom::ParLezaljkiSaDodatkom(int _rednibr, int _red, int _cena, int _vrednostpica, int _dodatneLez) : Lezaljka(_rednibr, _red, _cena, _vrednostpica) {
	dodatneLez = _dodatneLez;
}
ParLezaljkiSaDodatkom::ParLezaljkiSaDodatkom(const ParLezaljkiSaDodatkom& gg) : Lezaljka(gg) {
	dodatneLez = gg.dodatneLez;
}

void ParLezaljkiSaDodatkom::Prikazi(ostream& izlaz)const  {
	Lezaljka::Prikazi(izlaz);
	izlaz << "Dodatne lezaljke: " << dodatneLez;
}
int ParLezaljkiSaDodatkom::svotaZaNaplatu() const  {
	float popustNaPice = (40.0 - 2.0 * red - 5.0 * dodatneLez) / 100.0;

	float novaCenaLezaljki = cena * (1.0 + 0.4 * dodatneLez);
	float novaCenaPica = vrednostpica * (1.0 - popustNaPice);

	return novaCenaLezaljki + novaCenaPica;
}
