#pragma once
#include "Novcanica.h"
class NovcanicaStrana : public Novcanica
{
private:
	char* oznaka;
	int kurs;
public:
	NovcanicaStrana();
	NovcanicaStrana(int _vrednost, int _kolicina, const char* _oznaka,int _kurs);
	~NovcanicaStrana() override;
	NovcanicaStrana(const NovcanicaStrana& gg);

	virtual void prikazi(ostream& izlaz) const override;

};

