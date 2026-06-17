#include "Automobil.h"
#include "Hibrid.h"
#include "Benzinac.h"
#include "Prevoznik.h"
void zadatak1()
{
	// 2 boda
	char t1[] = "NI 111 AB";
	int v1[] = { 10000, 40, 8, 1250 };
	Benzinac* p1 = new Benzinac(t1, v1[0], v1[1], v1[2], v1[3]);
	cout << "Benzinac: " << endl;
	cout << *p1 << endl; //p1->Ispisi();
	// 2 boda
	char t2[] = "NI 111 AH";
	int v2[] = { 20000, 50, 10, 1500, 200 };
	Hibrid* p2 = new Hibrid(t2, v2[0], v2[1], v2[2], v2[3], v2[4]);
	cout << "Hibrid: " << endl;
	cout << *p2 << endl; //p2->Ispisi();
	char rgtab[][10] = { "NI 111 BB", "NI 111 HH", "NI 222 BB", "NI 222 HH", "NI 333 BB",
	"NI 333 HH", "NI 444 BB", "NI 444 HH", "NI 555 BB", "NI 555 HH", };

	int duz[] = { 10000, 40000, 30000, 20000, 50000,

	35000, 25000, 55000, 45000, 15000 };

	float rez[] = { 45, 40, 55, 35, 60,

	35, 55, 65, 45, 40 };

	float pot[] = { 5, 7, 8, 6, 9,

	6, 5, 10, 8, 7 };
	float gor[] = { 450, 2000, 2500, 1000, 4500,

	1100, 1200, 4500, 3500, 800 };

	int el[] = { 200, 250, 300, 200, 250 };
	int brElem = 10;
	Prevoznik* pPrev = new Prevoznik(brElem + 2);
	// 2 boda
	for (int i = 0; i < brElem / 2; i++)
	{
		pPrev->Dodaj(new Benzinac(rgtab[2 * i], duz[2 * i], rez[2 * i], pot[2 * i],

			gor[2 * i]));

		pPrev->Dodaj(new Hibrid(rgtab[2 * i + 1], duz[2 * i + 1], rez[2 * i + 1], pot[i], gor[i],

			el[i]));
	}
	// 1 bod
	cout << "Dodati automobili: " << endl;
	cout << *pPrev << endl; //pPrev.Ispisi();
	// 3 boda
	int kilometraza = 48000;
	pPrev->IzbaciPoKm(kilometraza);
	cout << "Izbaceni Po Kilomertrazi: " << endl;
	cout << *pPrev << endl; //pPrev->Ispisi();
	// 2 boda
	int duzVoznje = 500;
	pPrev->ObavljenaVoznja(rgtab[0], duzVoznje);
	pPrev->ObavljenaVoznja(rgtab[1], duzVoznje);
	cout << "Obavljena Voznja: " << endl;
	cout << *pPrev << endl; //pPrev->Ispisi();
	// 2 boda
	cout << "Ukupna Kilometraza: " << pPrev->UkupnaKilometraza() << endl;

	// 2 boda
	int zDuzina = 570;
	Automobil* pAutoPov = pPrev->NajpovoljnijiAutomobil(zDuzina);
	cout << "Najpovoljniji Automobil: " << endl;
	cout << *pAutoPov << endl;
	// 3 boda
	Automobil* pMinDuzina = nullptr, * pMinPotrosio = nullptr;
	pPrev->VratiNajDuzinuGorivo(&pMinDuzina, &pMinPotrosio);
	cout << "Najmanja duzina i gorivo: " << endl;
	cout << *pMinDuzina << endl; //pMinDuzina->Ispisi();
	cout << *pMinPotrosio << endl; //pMinPotrosio->Ispisi();
	// 1 bod
	delete pPrev;
}

//void zadatak2()
//{
//	int brElemenata = 10;
//	int brojPodataka = 7;
//	// 3 boda
//	// postavljanje i prihvatanje izuzetaka
//	{
//		int kilometraza[] = { 200, 300, 350, 250, 400, 300, 450 };
//		int ucinci[] = { 170, 150, 180, 150, 250, 300, 120 };
//		Ogranak<int> ogranak(brElemenata);
//		// 1 bod
//		for (int i = 0; i < brojPodataka; i++)
//			ogranak.Dodaj(kilometraza[i]);
//		cout << "Dodata vozila: " << endl;
//		cout << ogranak << endl; //ogranak.Ispisi(cout);
//		// 1 bod
//		ogranak.UvecanjeUcinka(ucinci);
//		cout << "Uvecanje Ucinka: " << endl;
//		cout << ogranak << endl; //ogranak.Ispisi(cout);
//		// 1 bod
//		int ukupno = ogranak.UkupniUcinak();
//		cout << "Ukupni Ucinak: " << ukupno << endl;
//		// 1 bod
//		int najUcinak = ogranak.Najefikasnije();
//		cout << "Najefikasnije: " << endl;
//		cout << najUcinak << endl;
//		// 1 bod
//		int zadato = 550, manje = 0, vece = 0;
//		ogranak.NajblizaDva(zadato, manje, vece);
//		cout << "Najbliza Dva: " << endl;
//		cout << manje << " " << vece << endl;
//		// 1 bod
//		char fajl[] = "OgranakPrvi.txt";
//		ogranak.Sacuvaj(fajl);
//		// 1 bod
//		Ogranak<int> ogranakUcitan;
//		ogranakUcitan.Ucitaj(fajl);
//		cout << "Ucitan iz datoteke: " << endl;
//		cout << ogranakUcitan << endl; //ogranakUcitan.Ispisi(cout);
//	}
//
//	{
//		int kilometraza[] = { 200, 300, 350, 250, 400, 300, 450 };
//		float potrosnja[] = { 12.5, 16.5, 14.5, 17.5, 15.5, 12.5, 15.5 };
//		int ucinci[] = { 170, 150, 180, 150, 250, 300, 120 };
//		Ogranak<Vozilo> ogranak(brElemenata);
//		// 1 bod
//		for (int i = 0; i < brojPodataka; i++) {
//			ogranak.Dodaj(Vozilo(kilometraza[i], potrosnja[i]));
//		}
//		// 1 bod
//		cout << "Dodata vozila: " << endl;
//		cout << ogranak << endl; //ogranak.Ispisi(cout);
//		// 2 bod
//		ogranak.UvecanjeUcinka(ucinci);
//		cout << "Uvecanje Ucinka: " << endl;
//		cout << ogranak << endl; //ogranak.Ispisi(cout);
//		// 1 boda
//		int ukupno = ogranak.UkupniUcinak();
//		cout << "Ukupni Ucinak: " << ukupno << endl;
//		// 2 boda
//		Vozilo najUcinak = ogranak.Najefikasnije();
//		cout << "Najefikasnije: " << endl;
//		cout << najUcinak << endl;
//		// 2 boda
//		Vozilo zadato(550, 0.0f), manje, vece;
//		ogranak.NajblizaDva(zadato, manje, vece);
//		cout << "Najbliza Dva: " << endl;
//		cout << manje << endl << vece << endl;
//		// 0 bod
//		char fajl[] = "SkladPr.txt";
//		ogranak.Sacuvaj(fajl);
//		// 1 bod
//		Ogranak<Vozilo> ogranakUcitan;
//		ogranakUcitan.Ucitaj(fajl);
//		cout << "Ucitan iz datoteke: " << endl;
//		cout << ogranakUcitan << endl; //ogranakUcitan.Ispisi(cout);
//	}
//}
void main()
{
	zadatak1();
	//zadatak2();
}