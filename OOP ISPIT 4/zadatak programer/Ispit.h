#pragma once
#include "LekcijaNormlana.h"
template <typename T>
class Ispit {
private:
	T* niz;
	int trBr;
	int maxEl;
public:
	Ispit() {
		niz = nullptr;
		trBr = 0;
		maxEl = 0;
	}
	Ispit(int _maxEl) {
		trBr = 0;
		maxEl = _maxEl;
		niz = new T[maxEl];
	}
	~Ispit() {
		delete[] niz;
	}
	friend ostream& operator<<(ostream& izlaz, const Ispit<T>& is) {
		for (int i = 0; i < is.trBr; i++) {
			izlaz << is.niz[i] << endl;
		}
		return izlaz;
	}
	void Dodaj(T novi) {
		if (trBr < maxEl) {
			niz[trBr++] = novi;
		}
	}
	float Ukupno() {
		float ukupno = 0;
		for (int i = 0; i < trBr; i++) {
			ukupno += (float)niz[i];
		}
		return ukupno;
	}
	int UkupniBrojVrednost(int vrednost,float &ukupnaVrednost) {
		int br = 0;
		ukupnaVrednost = 0;
		for (int i = 0; i < trBr; i++) {
			if ((float)niz[i] > vrednost) {
				ukupnaVrednost += (float)niz[i];
				br++;
			}
		}
		return br;
	}
	void minMax(int dole, int gore, T& min, T& max) {
		min = niz[dole];
		max = niz[dole];
		for (int i = dole;i < gore; i++) {
			if ((float)niz[i] > (float)max) max = niz[i];
			if ((float)niz[i] < (float)min) min = niz[i];
		}
	}
	void Izbaci(int od, int broj) {
		
			for (int i = od; i < trBr - broj; i++) {
				niz[i] = niz[i + broj];
				
			}
		trBr -= broj;
	}
};
