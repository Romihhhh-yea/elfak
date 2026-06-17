#pragma once
#include <iostream>
using namespace std;

class NovcanicaValuta
{
private:
	char* valuta;
	int vrednost;
	int kurs;
public:
	NovcanicaValuta();
	NovcanicaValuta(const char* valuta, int vrednost, int kurs);
	NovcanicaValuta(const NovcanicaValuta& og);
	~NovcanicaValuta();
	friend ostream& operator<<(ostream& izlaz, const NovcanicaValuta& nv);
	friend istream& operator>>(istream& ulaz, NovcanicaValuta& nv);
	bool operator==(const NovcanicaValuta& nv) const;
	operator int() const;
};