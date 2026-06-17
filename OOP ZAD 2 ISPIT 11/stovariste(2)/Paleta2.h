#pragma once
#include <iostream>
using namespace std;
class Paleta2
{
protected:
	int masa;
public:
	Paleta2();
	Paleta2(int _masa);
	~Paleta2();
	Paleta2(const Paleta2& gg);
	int masaPalete() { return masa; }

	friend ostream& operator<<(ostream& izlaz, const Paleta2& p2);
};

