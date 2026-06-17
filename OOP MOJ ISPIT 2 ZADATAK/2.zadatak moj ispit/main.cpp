//void zadatak1()
//{
//	// 2 boda
//	int plDz[] = { 12, 20, 400, 10 };
//	Paleta* p1 = new PaletaDzak(plDz[0], plDz[1], 'A', plDz[2], plDz[3]);
//	cout << *p1 << endl; //p1->Ispisi();
//	// 2 boda
//	int plPL[] = { 21, 25, 10, 10, 1, 700 };
//	PaletaPlocice* p2 = new PaletaPlocice(plPL[0], plPL[1], 'A', plPL[2], plPL[3],
//		plPL[4], plPL[4]);
//
//	cout << *p2 << endl; //p2->Ispisi();
//	int id[] = { 12, 15, 18, 23, 27, 31, 34, 37 };
//	int masaPl[] = { 1, 1, 1, 2, 2, 3, 3, 3 };
//	char klasa[] = { 'A', 'B', 'C', 'C', 'B', 'A', 'B', 'A' };
//	float masa[] = { 400, 1.5, 500, 2, 300, 2.5, 450, 1.5 };
//	int cena[] = { 20, 400, 30, 300, 25, 500, 15, 450 };
//	int red[] = { 10, 8, 12, 9 };
//	int brojRed[] = { 10, 8, 12, 9 };
//	Stovariste* pSto = new Stovariste(10);
//	// 2 boda
//	for (int i = 0; i < 4; i++)
//	{
//		pSto->Dodaj(new PaletaDzak(id[2 * i], masaPl[2 * i],
//			klasa[2 * i], masa[2 * i], cena[2 * i]));
//		pSto->Dodaj(new PaletaPlocice(id[2 * i + 1], masaPl[2 * i + 1],
//
//			klasa[2 * i + 1], red[i], brojRed[i], masa[2 * i + 1], cena[2 * i + 1]));
//
//	}
//	// 1 bod
//	cout << *pSto << endl; //pSto.Ispisi();
//	// 3 boda
//	int oznaka = 34;
//	pSto->Preuzmi(oznaka);
//	cout << *pSto << endl; //pSto->Ispisi();
//	// 2 boda
//	cout << pSto->UkupnaMasa() << endl;
//	// 2 boda
//	cout << pSto->UkupnaVrednost() << endl;
//	// 2 boda
//	int zVredMin = 400, zVredMax = 800;
//	cout << pSto->BrojSaVredIzmedju(zVredMin, zVredMax) << endl;
//	// 3 boda
//	Paleta* pMaxMasa = nullptr, * pMaxVred = nullptr;
//	pSto->VratiNajMasuVrednost(&pMaxMasa, &pMaxVred);
//	cout << *pMaxMasa << endl; //pMaxMasa->Ispisi();
//	cout << *pMaxVred << endl; //pMaxVred->Ispisi();
//	// 1 bod
//	delete pSto;
//}
#include "PaletaProsirena.h"
#include "Skladiste.h"
void zadatak2()
{
	int brElemenata = 10;
	int brojPodataka = 7;
	// 3 boda
	// postavljanje i prihvatanje izuzetaka
	{
		int masa[] = { 200, 300, 350, 250, 400, 300, 450 };
		Skladiste<int> skladiste(brElemenata);
		// 1 bod
		for (int i = 0; i < brojPodataka; i++)
			skladiste.Dodaj(masa[i]);
		cout << skladiste << endl; //skladiste.Ispisi(cout);
		// 1 bod
		skladiste.Preuzmi(5, 200);
		cout << skladiste << endl; //skladiste.Ispisi(cout);
		skladiste.Preuzmi(5, 100);
		cout << skladiste << endl; //skladiste.Ispisi(cout);
		// 1 bod
		int ukupno = skladiste.UkupnaMasa();
		cout << ukupno << endl;
		// 1 bod
		int zMasa = 2;
		int broj = skladiste.BrojSaVecomKolicinom(zMasa);
		cout << broj << endl;
		// 1 bod
		int min = 0, max = 0;
		skladiste.NajViseManje(2, 4, min, max);
		cout << min << " " << max << endl;
		// 1 bod
		//char fajl[] = "SkladOs.txt";
		//skladiste.Sacuvaj(fajl);
		//// 1 bod
		//Skladiste<int> skladisteUcitano;
		//skladisteUcitano.Ucitaj(fajl);
		//cout << skladisteUcitano << endl; //skladisteUcitano.Ispisi(cout);
	}
	{
		float masa[] = { 20, 30, 20, 60, 35, 55, 30 };
		int broj[] = { 40, 40, 30, 30, 20, 20, 20 };
		float sirina[] = { 20, 50, 25, 60, 30, 50, 35 };
		Skladiste<PaletaProsirena> skladiste(brElemenata);
		// 1 bod
		for (int i = 0; i < brojPodataka; i++) {
			skladiste.Dodaj(PaletaProsirena(masa[i], broj[i], sirina[i]));
		}
		// 1 bod
		cout << skladiste << endl; //skladiste.Ispisi(cout);
		// 1 bod
		skladiste.Preuzmi(4, 300);
		cout << skladiste << endl; //skladiste.Ispisi(cout);
		skladiste.Preuzmi(4, 400);
		cout << skladiste << endl; //skladiste.Ispisi(cout);
		// 2 boda
		float ukupno = skladiste.UkupnaMasa();
		cout << ukupno << endl;
		// 2 boda
		int zMasa = 2;
		int brojVK = skladiste.BrojSaVecomKolicinom(zMasa);
		cout << brojVK << endl;

		// 2 boda
		PaletaProsirena min, max;
		skladiste.NajViseManje(1, 4, min, max);
		cout << min << " " << max << endl;
		// 0 bod
		//char fajl[] = "SkladPr.txt";
		//skladiste.Sacuvaj(fajl);
		//// 1 bod
		//Skladiste<PaletaProsirena> skladisteUcitano;
		//skladisteUcitano.Ucitaj(fajl);
		//cout << skladisteUcitano << endl; //skladisteUcitano.Ispisi(cout);
	}
}
void main()
{
	//zadatak1();
	zadatak2();
}