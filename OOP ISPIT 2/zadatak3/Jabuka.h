#pragma once
#include "Predmet.h"
class Jabuka : public Predmet{
private:
	double masa;
	double Ks;
	double Kk;
	char* boja;
public:
	Jabuka();
	Jabuka(const char* _naziv, double _masa, double _Ks, double _Kk, const char* _boja);
	Jabuka(const Jabuka& gg);
	~Jabuka() override;
	double vrednost() const override;
	void prikazi(ostream& izlaz) const override;
	double getMasa() const override { return masa; }
};

