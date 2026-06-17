#include "KaficSaPlazom.h"
void KaficSaPlazom::zauzmimem(int _maxEl) {
	trBr = 0;
	maxEl = _maxEl;
	niz = new Lezaljka * [maxEl];
	for (int i = 0; i < trBr; i++) {
		niz[i] = nullptr;
	}
}
void KaficSaPlazom::oslobodimem() {
	if (niz != nullptr)
		for (int i = 0; i < maxEl; i++)
			if (niz[i] != nullptr)
				delete niz[i];

				delete[] niz;
}
KaficSaPlazom::KaficSaPlazom() {
	niz = nullptr;
	trBr = 0;
	maxEl = 0;
}
KaficSaPlazom::KaficSaPlazom(int _maxEl) {
	trBr = 0;
	maxEl = _maxEl;
	niz = new Lezaljka*[maxEl];
}
KaficSaPlazom::~KaficSaPlazom() {
	oslobodimem();
}
KaficSaPlazom::KaficSaPlazom(const KaficSaPlazom& gg) {
	zauzmimem(gg.maxEl);
	
	for (int i = 0; i < gg.trBr; i++) {
		if (typeid(*gg.niz[i]) == typeid(ParLezaljki))
			Dodaj(new ParLezaljki(*dynamic_cast<ParLezaljki*>(gg.niz[i])));
		else
			Dodaj(new ParLezaljkiSaDodatkom(*dynamic_cast<ParLezaljkiSaDodatkom*>(gg.niz[i]));

	}

}
void KaficSaPlazom::Dodaj(Lezaljka* l) {
	if (trBr < maxEl)
		niz[trBr++] = l;
}
void KaficSaPlazom::Oslobodi(int l) {
	for (int i = 0; i < trBr; i++) {
		if (l == niz[i]->getRedniBr()) {
			for (int j = i; j < trBr - 1; j++) {
				niz[j + 1] = niz[j];
			}
		}
	}
}
int KaficSaPlazom::UkupnoLezaljki() {
	return trBr;
}
int KaficSaPlazom::UkupnaSvotaNovca() {
	int suma = 0;
	for (int i = 0; i < trBr; i++) {
		suma += niz[i]->svotaZaNaplatu();
	}
	return suma;
}
ostream& operator<<(ostream& izlaz, const KaficSaPlazom& l) {
	l.Prikazi(izlaz);
	return izlaz;
}
void KaficSaPlazom::Prikazi(ostream& izlaz)const  {
	for (int i = 0; i < trBr; i++) {
		izlaz << *niz[i];
	}
}
void KaficSaPlazom::VratiNajskuplje(ParLezaljki** pMaxCena, ParLezaljki** pMaxNapitak) const{
	if (trBr == 0) return;

	float najvecaSvota = -1;
	int najvecaCenaPica = -1;

	Lezaljka* pobednikCena = nullptr;
	Lezaljka* pobednikPice = nullptr;

	for (int i = 0; i < trBr; i++) { 
		if (niz[i]->svotaZaNaplatu() > najvecaSvota) {
			najvecaSvota = niz[i]->svotaZaNaplatu();
			pobednikCena = niz[i];
		}

		if (niz[i]->getVrednostPica() > najvecaCenaPica) {
			najvecaCenaPica = niz[i]->getVrednostPica();
			pobednikPice = niz[i];
		}
	}

	*pMaxCena = (ParLezaljki*)pobednikCena;
	*pMaxNapitak = (ParLezaljki*)pobednikPice;
}