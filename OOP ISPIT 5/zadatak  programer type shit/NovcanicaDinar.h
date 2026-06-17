#pragma once
#include "Novcanica.h"
class NovcanicaDinar : public Novcanica
{
private:
public:
	NovcanicaDinar();
	NovcanicaDinar(int _vrednost, int _kolicina);
	~NovcanicaDinar() override;
	NovcanicaDinar(const NovcanicaDinar& gg);

	virtual void prikazi(ostream& izlaz) const override;

};

