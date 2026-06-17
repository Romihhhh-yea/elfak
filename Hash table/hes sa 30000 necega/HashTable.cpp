#include "HashTable.h"

HashTabela::HashTabela(int velicina)
{
	this->velicina = velicina;
	primarni = new Birac * [velicina];
	sinonimi = new Birac * [velicina];
	sledeci = new int[velicina];
	for (int i = 0; i < velicina; i++) {
		primarni[i] = nullptr;
		sinonimi[i] = nullptr;
	}

}

HashTabela::~HashTabela()
{
	delete[] sledeci;
	delete[] primarni;
	delete[] sinonimi;
}

int HashTabela::hashFunkcija(char* jmbg)
{
	int suma = 0;

	for (int i = 0; i < 13; i++) {
		suma =  suma * 31 +(jmbg[i] - '0');
	}
	return abs(suma % velicina);
}

void HashTabela::dodajBiraca(char* jmbg, char* ime, char* prezime)
{
	int indeks = hashFunkcija(jmbg);
	if (primarni[indeks] == nullptr) {
		primarni[indeks] = new Birac(jmbg, ime, prezime);
	}
	else {
		int sledeciSlobodni = sledeci[lrmp];
		sledeci[indeks] = lrmp;
		sinonimi[lrmp] = new Birac(jmbg, ime, prezime);
		lrmp = sledeci[lrmp];
	}
}
