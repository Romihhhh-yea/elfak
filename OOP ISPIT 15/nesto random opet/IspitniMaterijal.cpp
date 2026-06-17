#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
// ... ostali include-ovi
#include "IspitniMaterijal.h"
#include <cstring>
IspitniMaterijal::IspitniMaterijal() {
	oznaka = 0;
	tezina = 0;
	savladan = nullptr;
}

IspitniMaterijal::IspitniMaterijal(int _oznaka, int _tezina, const char* _savladan) {
	oznaka = _oznaka;
	tezina = _tezina;
	savladan = new char[strlen(_savladan) + 1];
	strcpy(savladan, _savladan);

}
IspitniMaterijal::~IspitniMaterijal() {
	delete[] savladan;
}
IspitniMaterijal::IspitniMaterijal(const IspitniMaterijal& gg) {
	oznaka = gg.oznaka;
	tezina = gg.tezina;
	savladan = new char[strlen(gg.savladan) + 1];
	strcpy(savladan, gg.savladan);
}

std::ostream& operator<<(std::ostream& izlaz, const IspitniMaterijal& im) {
	im.prikazi(izlaz);
	return izlaz;
}
void IspitniMaterijal::prikazi(std::ostream& izlaz) const {
	izlaz << "Oznaka: " << oznaka << "Tezina: " << tezina << "Savladan: " << savladan;
}

