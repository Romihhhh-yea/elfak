#pragma once
#include <iostream>
using namespace std;
class ProstaLekcija
{
private:
	float tezina;
public:
	ProstaLekcija();
	ProstaLekcija(int _tezina);
	~ProstaLekcija();
	ProstaLekcija(const ProstaLekcija& gg);
	friend std::ostream& operator<<(std::ostream& izlaz, const ProstaLekcija& l);


};

