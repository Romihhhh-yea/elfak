#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
class IspitniMaterijal
{
protected:
	int oznaka;
	int tezina;
	char* savladan;
public:
	IspitniMaterijal();
	IspitniMaterijal(int _oznaka, int _tezina, const char* _savladan = "NE");
	virtual ~IspitniMaterijal();
	IspitniMaterijal(const IspitniMaterijal& gg);

	int getOznaka() const {
		return oznaka;
	}

	const char* getSavladan() const {
		return savladan;
	}
	void setSavladan(const char* _savladan) {
		delete[] savladan;
		savladan = new char[strlen(_savladan) + 1];
		strcpy(savladan, _savladan);
	}
	virtual float vremeSavladavanja(float _vJedinicno) const = 0;
	friend std::ostream& operator<<(std::ostream& izlaz, const IspitniMaterijal& im);
	virtual  void prikazi(std::ostream& izlaz) const = 0;
};

