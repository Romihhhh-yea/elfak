#pragma once
#include "Predmet.h"
using namespace std;
class ZlatnaPoluga : public Predmet{
private:
	double masa;
	double stepenCistoce;
public:
	ZlatnaPoluga();
	ZlatnaPoluga(const char* _naziv, double _masa, double _stepenCistoce);
	ZlatnaPoluga(const ZlatnaPoluga& gg);
	~ZlatnaPoluga() override{}

	double vrednost() const override;
	void prikazi(ostream& izlaz) const override;
	double getMasa() const override { return masa; }
};

