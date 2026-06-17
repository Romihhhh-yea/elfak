#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
using namespace std;

class LekcijaNormalna
{
private:
	char* naziv;
	int duzinaStranica;
	int tezina;
public:
	LekcijaNormalna();
	LekcijaNormalna(const char* _naziv, int _duzinaStranica, int _tezina);
	~LekcijaNormalna();
	LekcijaNormalna(const LekcijaNormalna& gg);
	operator float() {
		return (float)tezina;
	}
	
	friend ostream& operator<<(ostream& izlaz, const LekcijaNormalna& ln);

};

