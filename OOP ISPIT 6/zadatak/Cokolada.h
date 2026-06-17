#include <iostream> 
#include "Poklon.h"
#include <fstream>
using namespace std;
class Cokolada : public Poklon {
private:
	int procenatKakaa;
public:
	Cokolada();
	Cokolada(double _cena, int _brojMasnica, int _procenatKakaa);
	Cokolada(const Cokolada& og);
	~Cokolada() {}
	void prikazi(ostream& izlaz) const override;

	int vratiBrojMasnica() const override;
};