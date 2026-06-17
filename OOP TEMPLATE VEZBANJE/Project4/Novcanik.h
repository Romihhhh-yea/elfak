#pragma once

#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
class Novcanik
{
private:
	T* niz;
	int kapacitet;
	int trenutno;
public:
	Novcanik(int kapacitet)
	{
		this->kapacitet = kapacitet;
		niz = new T[this->kapacitet];
		trenutno = 0;
	}
	~Novcanik()
	{
		delete[] niz;
	}
	void Dodaj(T el)
	{
		if (trenutno >= kapacitet)
			throw "Kolekcija puna";
		niz[trenutno++] = el;
	}
	void Izbaci(int indeks)
	{
		if (indeks < 1 || indeks > trenutno)
			throw "Nepostojeci podatak";
		for (int i = indeks - 1; i < trenutno - 1; i++)
			niz[i] = niz[i + 1];
		trenutno--;
	}
	float Ukupno()
	{
		if (trenutno == 0)
			throw "Kolekcija je prazna";
		float s = 0;
		for (int i = 0; i < trenutno; i++)
			suma += (float)niz[i];
		return suma;
	}
	int UkupniBrojVrednost(int vrednost, float &ukupnaVrednost)
	{
		if (trenutno == 0)
			throw "Kolekcija prazna";
		int br = 0;
		for (int i = 0; i < trenutno; i++)
			if (niz[i].vrednost == vrednost)
			{
				br++;
				ukupnaVrednost += vrednost;
			}
		return br;
	}
	int NajmanjeNovcanica(int svota)
	{
		float s = 0;
		int br = 0;
		for (int i = 0; i < trenutno; i++)
		{
			s += (float)niz[i]; 
			br++;
			if (s >= svota)
				return br;
		}
		return 0;
	}
	void Sacuvaj(const char* filename)
	{
		ofstream f(filename);
		if (!filename)
			throw "greska";
		for (int i = 0; i < trenutno; i++)
			f << niz[i];
		f.close();
	}
	void Ucitaj(const char* filename)
	{
		ifstream f(filename);
		if (!f)
			throw "PICKA OVELIKA [{}]";
		int trenutno = 0;
		T pom;
		while (f >> pom && trenutno < kapacitet)
			niz[trenutno++] = pom;
		f.close();
	}
	friend ostream& operator<<(ostream& izlaz, const Novcanik<T>& n)
	{
		for (int i = 0; i < trenutno; i++)
			izlaz << niz[i] << endl;
		return izlaz;
	}
};