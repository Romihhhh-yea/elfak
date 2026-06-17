#pragma once
#include <iostream>
using namespace std;
#include "Predmet.h"

class DragoKamenje : public Predmet {
private:
	double cistoca;
	char* boja;
	int brStranica;
	double masa;
public:
	DragoKamenje();
	DragoKamenje(const char* _naziv, double _cistoca, const char* _boja, int _brStranica, double _masa);
	~DragoKamenje();
	DragoKamenje(const DragoKamenje& gg);
	double vrednost() const override;
	void prikazi(ostream& izlaz) const override;
	double getMasa() const override { return masa; }
};