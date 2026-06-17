#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
class Skladiste {
private:
	T* niz;
	int maxEl;
	int trBr;
public:
	Skladiste(int _maxEl) {
		trBr = 0;
		maxEl = _maxEl;
		niz = new T[maxEl];
	}
	~Skladiste() {
		delete[] niz;
	}
	void Dodaj(T el) {
		
		if (trBr >= maxEl) throw "Greska: Ilijin cmar pun";
			niz[trBr++] = el; 
	}
	void Preuzmi(int indeks, int kolicina) {
		if (indeks <= 0 || indeks > trBr) throw "Nepostojeci podatak";
		if (kolicina < 0) throw "Ne moze";
		for (int i = 0; i < trBr; i++) {
			if (indeks - 1 == i)
				niz[i] -= kolicina;
			if (niz[i] <= 0) {
				for (int j = i; j < trBr - 1; j++) {
					niz[j] = niz[j+1];
				}
				trBr--;
			}
		}
	}
	int UkupnaMasa() {
		int suma = 0;
		for (int i = 0; i < trBr; i++)
		{
			suma += niz[i];
		}
		return suma;
	}
	int BrojSaVecomKolicinom(int vrednost) {
		int count = 0;
		for (int i = 0; i < trBr; i++) {
			if (niz[i] > vrednost) {
				count++;
			}
		}
		return count;
	}
	void NajViseManje(int pocetak, int kraj, T _min, T _max) {
		for (int i = pocetak-1; i < kraj-1; i++) {
			if (niz[i] < _min) {
				_min = niz[i];
			}
			if (niz[i] > _max) {
				_max = niz[i];
			}
		}
	}
	void Sacuvaj(const char* imeFajla) const {
		ofstream fajl(imeFajla);
		for (int i = 0; i < trBr; i++){
			fajl << niz[i];
	}
		fajl.close();

	}
	friend ostream& operator<<(ostream& izlaz, const Skladiste<T>& s) {
		for (int i = 0; i < s.trBr; i++) {
			izlaz << s.niz[i];
		}
		return izlaz;
	}
};
