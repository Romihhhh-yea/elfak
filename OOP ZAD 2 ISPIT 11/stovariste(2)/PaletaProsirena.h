#pragma once
#include "Paleta2.h"
class PaletaProsirena : public Paleta2
{
private:
	float masaJedne;
	int broj;
	float sirina;
public:
	PaletaProsirena();
	PaletaProsirena(float _masaJedne, int _broj, float _sirina);
	~PaletaProsirena();
	PaletaProsirena(const PaletaProsirena& gg);
	int getMasaPalete() { return (int)(broj*masaJedne); }
	int getBroj() { return broj; }
	friend ostream& operator<<(ostream& izlaz, const PaletaProsirena& pp);
	void operator=(int vrednost) {
		if (vrednost == 0) {
			this->broj = 0;
			this->masaJedne = 0;
			// i ostali atributi na nulu
		}
	}
	void operator-=(int kolicinaMase) {
		// Moramo da izraèunamo koliko dasaka treba skinuti
		// Na primer, ako skidamo 300kg, a daska je 10kg -> skidamo 30 dasaka
		int brojDasakaZaUklanjanje = kolicinaMase / (int)masaJedne;

		if (brojDasakaZaUklanjanje > broj) {
			broj = 0; // Ne možeš imati negativan broj dasaka
		}
		else {
			broj -= brojDasakaZaUklanjanje;
		}
	}
	operator int() const { return (int)(broj * masaJedne); }
};

