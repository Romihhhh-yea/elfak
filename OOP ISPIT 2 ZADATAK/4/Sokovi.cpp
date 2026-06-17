#include "Sokovi.h"
Sokovi::Sokovi() {
	naziv = nullptr;
	zapremina = 0;
	procenat = 0;
}
Sokovi::Sokovi(const char* _naziv, float _zapremina, int _procenat) {
	if (_naziv != nullptr) {
		naziv = new char[strlen(_naziv) + 1];
		strcpy(naziv, _naziv);
	}
	else {
		naziv = nullptr;
	}
	zapremina = _zapremina;
	procenat = _procenat;
}
Sokovi::~Sokovi() {
	delete[] naziv;
}
Sokovi::Sokovi(const Sokovi& gg) {
	if (gg.naziv != nullptr) {
		naziv = new char[strlen(gg.naziv) + 1];
		strcpy(naziv, gg.naziv);
	}
	else {
		naziv = nullptr;
	}
	zapremina = gg.zapremina;
	procenat = gg.procenat;
}
Sokovi::operator float() const {
	return zapremina;
}
void Sokovi::prikazi(ostream& izlaz) const {
	izlaz << "Naziv: " << naziv << "Zapremina" << zapremina << "Procenat: " << procenat;
}
ostream& operator<<(ostream& izlaz, const Sokovi& s) {
	s.prikazi(izlaz);
	return izlaz;
}
Sokovi& Sokovi::operator=(const Sokovi& s) {
	if (this != &s) {
		delete[] naziv;
		if (s.naziv != nullptr) {
			naziv = new char[strlen(s.naziv) + 1];
			strcpy(naziv, s.naziv);
		}
		else {
			naziv = nullptr;
		}
		zapremina = s.zapremina;
		procenat = s.procenat;
	}
	return *this;
}
bool Sokovi::operator==(const Sokovi& s) const  {
	return zapremina == s.zapremina && procenat == s.procenat && strcmp(naziv, s.naziv) == 0;
}
bool Sokovi::operator<(const Sokovi& s) const {
	return zapremina < s.zapremina;
}
istream& operator>>(istream& ulaz, Sokovi& s) {
    char buffer[100]; // Privremeno mesto za naziv
    
    // Èitamo redom: zapremina, procenat, pa naziv
    if (ulaz >> s.zapremina >> s.procenat >> buffer) {
        // Obavezno oslobaðamo staru memoriju pre nego što dodelimo novu
        delete[] s.naziv;
        s.naziv = new char[strlen(buffer) + 1];
        strcpy(s.naziv, buffer);
    }
    return ulaz;
}