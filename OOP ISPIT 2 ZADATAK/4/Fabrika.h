#pragma once
#include "Sokovi.h"
#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
class Fabrika {
private:
	T* niz;
	int maxEl;
	int trBr;
public:
	Fabrika(int _maxEl) {
		trBr = 0;
		maxEl = _maxEl;
		niz = new T[maxEl];
	}
	~Fabrika() {
		if (niz != nullptr)
			for (int i = 0; i < maxEl; i++) {
				delete niz[i];
			}
	
		delete[] niz;
	}
	void Dodaj(T podatak) {
		if (trBr == maxEl) {
			throw "Kolekcija je puna";
		}
		niz[trBr++] = podatak;

		for (int i = 0; i < trBr - 1; i++) {
			for (int j = 0 j < trBr - 1 - i; j++) {
				if (niz[j+1] < niz[j]) {
					T temp = niz[j];
					niz[j] = niz[j + 1];
					niz[j + 1] = temp;
				}
			}
		}
	}
	void Izbaci(T podatak) {
		bool nadjen = false;
		for (int i = 0; i < trBr; i++) {
			if (niz[i] == podatak) {
				nadjen = true;
				for (int j = i; j < trBr - 1; j++) {
					niz[j] = niz[j+1]
				}
				trBr--;
			}
		}
	 }
	if (!nadjen) {
		throw"Greska:Pice sa zadatom zapreminom ne postoji";
	}
	float Ukupno() {
		suma = 0;
		for (int i = 0; i < trBr; i++) {
			suma += (float)niz[i];
		}
		return suma;
	}
	void Sacuvaj(const char* putanja) {
		ofstream fajl(putanja);
		if (!fajl) throw "Greska";
		for (int i = 0; i < trBr; i++) {
			fajl << niz[i];
		}
		fajl.close();
	}
	/*void Ucitaj(const char* putanja) {
		ifstream fajl(putanja);
		if (!fajl) throw "Greska: Fajl ne postoji!";

		int broj;
		fajl >> broj;

		delete[] niz;
		niz = new T[maxEl];
		trBr = 0;

		for (int i = 0; i < broj; i++) {
			T privremeni;
			fajl >> privremeni;
			Dodaj(privremeni);
		}
		fajl.close();
	}*/
	/*void Ucitaj(const char* putanja) {
		ifstream fajl(putanja);
		if (!fajl) throw "Greska: ";
		int broj;
		fajl >> broj;
		delete[] niz;
		niz = new T[maxEl];
		trBr = 0
		for (int i = 0; i < trBr; i++) {
			T privremeni;
			fajl >> privremeni;
			Dodaj(privremeni);
		}
		fajl.close();
	}*/
	
	void Ucitaj(const char* putanja) {
		ifstream fajl(putanja);
		if (!fajl) throw " Greska:";
			int broj;
			fajl >> broj;
			delete[] niz;
			niz = new T[maxEl];
			trBr = 0;
			for (int i = 0; i < trBr; i++) {
				T privremeni;
				fajl >> privremeni;
				Dodaj(privremeni);

			}
			fajl.close();
	}
	
	template <typename T>
	istream& operator>>(istream& ul, Fabrika<T>& f) {
		int broj;
		ul >> broj;
		for (int i = 0; i < broj; i++) {
			T privremeni;
			ul >> privremeni;
			f.Dodaj(privremeni);
		}
		return ul;
	}
	template <typename T>
	ostream& operator<<(ostream& izlaz, const Fabrika<T>& f) {
		izlaz << f.trBr << endl;
		for (int i = 0; i < f.trBr; i++) {
			izlaz << f.niz[i] << endl;
		}
		return izlaz;
	}
};
