#pragma once
#include <iostream>
using namespace std;
class IspitniMaterijal
{
protected:
	int oznaka;
	float tezina;
	bool savladan;
	
public:
	IspitniMaterijal();
	IspitniMaterijal(int _oznaka,float _tezina,bool _savladan = false);
	virtual ~IspitniMaterijal() {}
	IspitniMaterijal(const IspitniMaterijal& gg);
	virtual int getOznaka() { return oznaka; } ;
	virtual bool getSavladan() { return savladan; }
	virtual void setSavladan() { savladan = true; }
	virtual int vremeSavladavanja(int vreme) = 0;

	virtual void prikazi(ostream& izlaz) const = 0;
	friend ostream& operator<<(ostream& izlaz, const IspitniMaterijal& im);
};

