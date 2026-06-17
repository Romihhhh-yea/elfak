#include <iostream>
#include <cstring>
class Birac {
private:
	char* jmbg;
	char* ime;
	char* prezime;

public:
	Birac(char* jmbg, char* ime, char* prezime) {
		this->jmbg = new char[strlen(jmbg) + 1];
		strcpy(this->jmbg, jmbg);
		this->ime = new char[strlen(ime) + 1];
		strcpy(this->ime, ime);
		this->prezime = new char[strlen(prezime) + 1];
		strcpy(this->prezime, prezime);
	}
	~Birac() {
		delete[] jmbg;
		delete[] ime;
		delete[] prezime;
	}
};