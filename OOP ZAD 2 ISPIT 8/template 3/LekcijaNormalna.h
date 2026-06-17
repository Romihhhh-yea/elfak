#pragma once
#include <iostream>
using namespace std;
class LekcijaNormalna
{
private:
	char* naziv;
	int duzina;
	float tezina; 
public:
	LekcijaNormalna();
	LekcijaNormalna(const char* _naziv, int _duzina, float _tezina);
	 ~LekcijaNormalna();
	 LekcijaNormalna(const LekcijaNormalna& gg);

	 operator float();

	 LekcijaNormalna& operator=(const LekcijaNormalna& ln);
	 friend std::ostream& operator<<(std::ostream& izlaz, const LekcijaNormalna& l);
	 friend istream& operator>>(istream& ulaz, LekcijaNormalna& l);

	
};

