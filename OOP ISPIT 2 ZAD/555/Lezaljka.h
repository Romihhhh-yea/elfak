#pragma once
#include <iostream>
using namespace std;
class Lezaljka
{
private:
	int br;
	int cena;
public:
	Lezaljka();
	Lezaljka(int _br, int _cena);

	friend ostream& operator<<(ostream& izlaz, const Lezaljka& l);
	friend istream& operator>>(istream& ulaz,Lezaljka& l);
	operator int() const;

};

