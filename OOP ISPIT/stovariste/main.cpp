void zadatak1()
{
    // 2 boda
    int pIDz[] = { 12, 20, 400, 10 };
    Paleta* p1 = new PaletaDzak(pIDz[0], pIDz[1], 'A', pIDz[2], pIDz[3]);
    cout << *p1 << endl;   // p1->Ispisi();

    // 2 boda
    int pIPl[] = { 21, 25, 10, 10, 1, 700 };
    PaletaPloce* p2 = new PaletaPloce(pIPl[0], pIPl[1], 'A', pIPl[2], pIPl[3],
        pIPl[4], pIPl[4]);
    cout << *p2 << endl;   // p2->Ispisi();

    int id[] = { 12, 15, 18, 23, 27, 31, 34, 37 };
    int masaPl[] = { 1, 1, 2, 2, 3, 3, 3, 3 };
    char klasa[] = { 'A', 'B', 'C', 'C', 'C', 'B', 'A', 'A' };
    float masa[] = { 400, 1.5, 500, 2, 300, 2.5, 450, 1.5 };
    int cena[] = { 200, 400, 30, 300, 25, 500, 15, 450 };
    int red[] = { 10, 8, 12, 9 };
    int brojRed[] = { 10, 8, 12, 9 };

    Stovariste* pSto = new Stovariste(10);

    // 2 boda
    for (int i = 0; i < 4; i++)
    {
        pSto->Dodaj(new PaletaDzak(id[2 * i], masaPl[2 * i],
            klasa[2 * i], masa[2 * i], cena[2 * i]));
        pSto->Dodaj(new PaletaPloce(id[2 * i + 1], masaPl[2 * i + 1],
            klasa[2 * i + 1], red[i], brojRed[i],
            masa[2 * i + 1], cena[2 * i + 1]));
    }

    // 1 bod
    cout << *pSto << endl;   // pSto->Ispisi();

    // 3 boda
    int oznaka = 34;
    pSto->Preuzmi(oznaka);
    cout << *pSto << endl;   // pSto->Ispisi();

    // 2 boda
    cout << pSto->UkupnaMasa() << endl;

    // 2 boda
    cout << pSto->UkupnaVrednost() << endl;

    // 2 boda
    int zVredMin = 400, zVredMax = 800;
    cout << pSto->BrojSaVrednoscuIzmedju(zVredMin, zVredMax) << endl;

    // 3 boda
    Paleta* pMaxMasa = nullptr, * pMaxVred;
    pSto->VratiNajMasuVrednost(&pMaxMasa, &pMaxVred);
    cout << *pMaxMasa << endl;   // pMaxMasa->Ispisi();
    cout << *pMaxVred << endl;   // pMaxVred->Ispisi();

    // 1 bod
    delete pSto;
}
