#pragma once
#include <iostream>
using namespace std;
class Novcanica
{
protected:
	int vrednost;
	int kolicina;
public:
	Novcanica();
	Novcanica(int _vrednost, int _kolicina);
	virtual ~Novcanica();
	Novcanica(const Novcanica& gg);

	virtual void prikazi(ostream& izlaz) const = 0 ;
	friend ostream& operator<<(ostream& izlaz, const Novcanica& n);
};

