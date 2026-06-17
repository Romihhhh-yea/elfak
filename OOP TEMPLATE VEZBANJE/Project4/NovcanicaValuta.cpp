#pragma once
#include "NovcanicaValuta.h"
#include <cstring>

NovcanicaValuta::NovcanicaValuta()
{
	valuta = nullptr;
	vrednost = 0;
	kurs = 0;
}
NovcanicaValuta::NovcanicaValuta(const char* valuta, int vrednost, int kurs)
{
	this->kurs = kurs;
	this->vrednost = vrednost;
	this->valuta = new char[strlen(valuta) + 1];
	strcpy(this->valuta, valuta);
}
NovcanicaValuta::NovcanicaValuta(const NovcanicaValuta& og)
{
	this->kurs = og.kurs;
	this->vrednost = og.vrednost;
	this->valuta = new char[strlen(og.valuta) + 1];
	strcpy(this->valuta, og.valuta);
}
NovcanicaValuta::~NovcanicaValuta()
{
	delete[] valuta;
}
ostream& operator<<(ostream& izlaz, const NovcanicaValuta& nv)
{
	izlaz << nv.valuta << nv.vrednost << nv.kurs;
	return izlaz;
}
istream& operator>>(istream& ulaz, NovcanicaValuta& nv)
{
	char buffer[100];
	if (ulaz >> buffer)
	{
		delete[] nv.valuta;
		if (buffer != nullptr)
		{
			nv.valuta = new char[strlen(buffer) + 1];
			strcpy(nv.valuta, buffer);
		}
		ulaz >> nv.vrednost >> nv.kurs;
	}
	return ulaz;
}
bool NovcanicaValuta::operator==(const NovcanicaValuta& nv) const
{
	if (this->valuta == nv.valuta && this->vrednost == nv.vrednost)
		return 1;
	return 0;
}
NovcanicaValuta::operator int() const
{
	return (int)this->vrednost;
}