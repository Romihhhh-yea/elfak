#include "Kanvas.h"
void Kanvas::oslobodimem() {
	if (niz != nullptr) {
		for (int i = 0; i < maxEl; i++)
			if (niz[i] != nullptr) {
				delete niz[i];
				niz[i] = nullptr;
			}
		delete[] niz;
		niz = nullptr;
	}
}
void Kanvas::zauzmimem(int _maxEl) {
	trBr = 0;
	maxEl = _maxEl;
	niz = new Figura * [maxEl];
	for (int i = 0; i < maxEl; i++)
		niz[i] = nullptr;
}

Kanvas::Kanvas(const Kanvas& gg) {
	zauzmimem(gg.maxEl);

	for (int i = 0; i < gg.trBr; i++) {
		if (typeid(*gg.niz[i]) == typeid(Pravougaonik)) {
			Add(new Pravougaonik(*dynamic_cast<Pravougaonik*>(gg.niz[i])));
		}
		else
			Add(new Krug(*dynamic_cast<Krug*>(gg.niz[i])));
	}
}

double Kanvas::UkupanObim() const {

	double obim = 0;
	for (int i = 0; i < trBr; i++) {
		obim += niz[i]->obim();
	}
	return obim;
}
double Kanvas::UkupnaPovrsina() const {

	double povrsina = 0;
	for (int i = 0; i < trBr; i++) {
		povrsina += niz[i]->povrsina();
	}
	return povrsina;
}
void Kanvas::Add(Figura* f) {
	if (trBr < maxEl) {
		niz[trBr++] = f;
	}
}

void Kanvas::Max(Figura** pmax, int* ind) {
	if (trBr == 0) {
		return;
	}
	*ind = 0;
	for (int i = 1; i < trBr; i++) {
		if (niz[i]->koeficijent() > niz[*ind]->koeficijent())
			*ind = i;
	}
	*pmax = niz[*ind];

}

Kanvas* Kanvas::PrebacitiPoBoji(const char* boja) {
	Kanvas* novi = new Kanvas(maxEl);

	for (int i = 0; i < trBr;i++ ) {
		if (strcmp(niz[i]->getBoja(), boja) == 0) {
			novi->Add(niz[i]);

			for (int j = i; j < trBr - 1; j++)
				niz[j] = niz[j + 1];
			trBr--;        
		}
		else {
			i++;          
		}
	}
	return novi;
}
ostream& operator<<(ostream& izlaz, const Kanvas& k) {
	for (int i = 0; i < k.trBr; i++) {
		k.niz[i]->prikazi(izlaz);
		return izlaz;
	}
}