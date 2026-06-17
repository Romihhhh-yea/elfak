#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Skladiste
{
private:
	T* niz;
	int maxEl;
	int trBr;
public:
	Skladiste() {
		niz = nullptr;
		maxEl = 0;
		trBr = 0;
	}
	Skladiste(int _maxEl)
	{
		maxEl = _maxEl;
		niz = new T[maxEl];
		trBr = 0;
	}
	~Skladiste() {
		if (niz != nullptr)
			delete[] niz;
	}
	Skladiste(const Skladiste<T>& gg) {
		maxEl = gg.maxEl;
		trBr = gg.trBr;
		niz = new T[maxEl];
		for (int i = 0; i < trBr; i++)
			niz[i] = gg.niz[i];
	}
	void Dodaj(T novi) {
		for (int i = 0; i < maxEl; i++) {
			if (niz[i].masaPalete() == 0) {
				niz[i] = novi;
				return;
			}
		}
		throw "Skladiste je puno!";
	}

	friend ostream& operator<<(ostream& izlaz, const Skladiste<T>& s) {
		for (int i = 0; i < s.maxEl; i++) {
			izlaz << s.niz[i] << endl;
		}
		return izlaz;
	}
	void Preuzmi(int broj, int kolicina) {
		if (broj < 0 || broj >= maxEl) throw "Greska: Nepostojeca pozicija!";
		niz[broj] -= kolicina;
		if (niz[broj].masaPalete() == 0) {
			T pomocna = niz[broj];
			for (int i = 0; i < trBr - 1; i++) {
				niz[i] = niz[i + 1];
			}
			niz[trBr - 1] = pomocna;
		}
	}
	int UkupnaMasa() {
		int ukupno = 0;
		for (int i = 0; i < trBr; i++) {
			ukupno += niz[i].masaPalete();
		}
		return ukupno;
	}
	int BrojSaVecomKolicinom(int kolicina) {
		int broj = 0;
		for (int i = 0; i < trBr; i++) {
			if (niz[i].masaPalete() > kolicina)
				broj++;
		}
		return broj;
	}
	void NajViseManje(int dGornja, int gGornja, T& minElem, T& maxElem) {
		bool nadjenPrvi = false;
		int privremeniMin = 0;
		int privremeniMax = 0;

		for (int i = 0; i < maxEl; i++) {
			int m = (int)niz[i]

			// Proveravamo da li je paleta u opsegu (npr. izmeðu 2 i 4)
			if (m >= dGornja && m <= gGornja) {
				if (!nadjenPrvi) {
					privremeniMin = m;
					privremeniMax = m;
					nadjenPrvi = true;
				}
				else {
					if (m < privremeniMin) privremeniMin = m;
					if (m > privremeniMax) privremeniMax = m;
				}
			}
		}

		if (!nadjenPrvi) {
			throw "Nema paleta u tom opsegu!";
		}

		// Na samom kraju "upisujemo" rezultate u originale iz main-a
		minElem = privremeniMin;
		maxElem = privremeniMax;
	}
};