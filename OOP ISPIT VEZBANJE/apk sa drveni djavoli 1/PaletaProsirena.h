#pragma once
#include <iostream>
using namespace std;
class PaletaProsirena
{
private:
	float masa;
	int broj;
	float sirina;
public:
	PaletaProsirena();
	PaletaProsirena(int _masa, int _broj, int _sirina);
	operator int() const;
	friend ostream& operator<<(ostream& izlaz, const PaletaProsirena& p);
	void prikazi(ostream& izlaz) const;
	bool operator>(const PaletaProsirena& p) const;
	PaletaProsirena& operator-(const PaletaProsirena& p)const;
	
};

