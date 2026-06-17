#include "Saonice.h"
#include "PaketicHrana.h"
#include "PaketicIgracke.h"
#include <cstring>
#include <typeinfo>
#include <iostream>
#include <fstream>
using namespace std;
Saonice::Saonice() {
	maxEl = 10;
	top = 0;
	niz = new Paketic * [maxEl];
}
Saonice::Saonice(int _maxEl) {
	maxEl = _maxEl;
	top = 0;
	niz = new Paketic * [maxEl];
}
Saonice::Saonice(const Saonice& s) {
	maxEl = s.maxEl;
	top = s.top;
	niz = new Paketic * [maxEl];
	for (int i = 0; i < top; i++) {
		if (typeid(*s.niz[i]) == typeid(PaketicHrana))
			niz[i] = new PaketicHrana(*((PaketicHrana*)s.niz[i]));
		else
			niz[i] = new PaketicIgracke(*((PaketicIgracke*)s.niz[i]));

	}
}
Saonice::~Saonice() {
	for (int i = 0; i < top; i++)
		delete niz[i];
	delete[] niz;
}
void Saonice::Add(Paketic* p) {
	niz[top++] = p;

}
double Saonice::SrednjaCena() const {
	double suma = 0;
	for (int i = 0; i < top; i++) {
		suma += niz[i]->cena();
	}
	return suma / top;
}
Paketic* Saonice::Najtezi() const {
	int idx = 0;
	for (int i = 1; i < top; i++) {
		if (niz[i]->tezina() > niz[idx]->tezina()) {
			idx = i;
		}
	}
	return niz[idx];
}
void Saonice::IzbaciPoAdresi(const char* adr) {
	for (int i = 0; i < top; i++) {
		if (strcmp(niz[i]->getAdresa(), adr) == 0) {
			delete niz[i];
			for(int j = i;j<top - 1;j++){
				niz[j] = niz[j + 1];
			}
			top--;
			i--;
		}
	}
}
void Saonice::Save(const char* filename) const {
	ofstream izlaz(filename);
	if (izlaz.good()) {
		izlaz << *this;
		izlaz.close();
	}
}
ostream& operator<<(ostream& izlaz, const Saonice& s) {
	for (int i = 0; i < s.top; i++) {
		izlaz << *s.niz[i] << endl;
	}
	return izlaz;
}