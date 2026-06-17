#pragma once
#include <iostream>
using namespace std;
class Paleta
{
protected:
	int oznaka;
	int masa;
public:
	Paleta(); 
	Paleta(int _oznaka, int _masa);
	virtual ~Paleta();
	Paleta(const Paleta& gg);
	virtual int getOznaka() { return oznaka; }
	virtual int getMasa() { return masa; }
	virtual int getCena() = 0;
	virtual void prikazi(ostream& izlaz) const = 0;
	friend ostream& operator<<(ostream& izlaz, const Paleta& p);
};



