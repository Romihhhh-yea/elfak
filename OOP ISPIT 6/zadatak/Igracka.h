#pragma once
#include <iostream>
#include "Poklon.h"

class Igracka : public Poklon {
private:
	char* tipMaterijala;
public:
	Igracka();
	Igracka(double _cena, int _brojMasnica, const char* _tipMaterijala);
	Igracka(const Igracka& og);
	~Igracka();
	void prikazi(ostream& izlaz) const;
	int vratiBrojMasnica() const;
};