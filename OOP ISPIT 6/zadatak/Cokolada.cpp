#include <iostream>
#include <fstream>
#include "Cokolada.h"
using namespace std;
Cokolada::Cokolada() : Poklon() {
	procenatKakaa = 0;
}
Cokolada::Cokolada(double _cena, int _brojMasnica, int _procenatKakaa) : Poklon(_cena,_brojMasnica) {
	procenatKakaa = _procenatKakaa;
}
Cokolada::Cokolada(const Cokolada& og) : Poklon(og) {
	procenatKakaa = og.procenatKakaa;
}

void Cokolada::prikazi(ostream& izlaz) const {
	Poklon::prikazi(izlaz);
	izlaz << "Procenat Kakaa: " << procenatKakaa << endl;

}
int Cokolada::vratiBrojMasnica() const {
	return 2 * brojMasnica;
}