#pragma once
#include <iostream>
#include "Lezaljka.h"
using namespace std;

template <typename T>
class Plaza {
private:
	T** mat;
	int brRedova;
	int brKolona;
public:
	Plaza(int r, int k)
	{
		brRedova = r;
		brKolona = k;
		mat = new T * [brRedova];
		for (int i = 0; i < brRedova; i++)
		{
			mat[i] = new T[brKolona];
			for (int j = 0; j < brKolona; j++)
			{
				mat[i][j] = T();
			}
		}
	} 
	~Plaza() {
		for (int i = 0; i < trBr; i++) {
			delete[] mat[i];
		}
		delete[] mat;
	}
	void Dodaj( int r,int k ,T podatak) {
		if (trBr >= maxEl) throw "Greska";
		mat[r][k] = podatak;
	}
	void Oslobodi(int r,int k) {
		if (mat == nullptr || r < 0 && k < 0 && r > trBr && k > trBr)throw "Ne postojeci";
		for (int i = 0; i < brRedova; i++) {
			if
		}
	}
	float Ukupno() const {
		float suma = 0;
		for (int i = 0; i < brRedova; i++) {
			for (int j = 0; j < brKolona; j++) {
				suma += (float)mat[i][j];
			}
		}
		return suma;
	}
};
