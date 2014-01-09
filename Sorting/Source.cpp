#include "MyForm.h"

// Read data
void nuskaitytiLeidini(Leidinys Leid[], int & i) {
	string kodas, pavadinimas;
	double menKaina;
	i = 0;
	ifstream leidinys(Cl);

	// Skaitome faila iki failo pabaigos
	while (!leidinys.eof()) {
		leidinys >> kodas >> pavadinimas >> menKaina;
		Leid[i].DetiKodas(kodas);
		Leid[i].DetiPavadinimas(pavadinimas);
		Leid[i].DetiMenKaina(menKaina);
		i++;
	}
	leidinys.close();
}

void nuskaitytiPrenumeratoriu(Prenumeratorius Pre[], int & n) {
	string pavarde, adresas, lKodas;
	int lPradzia, lIlgis, lKiekis, gatvesSk;
	n = 0;

	// Skaitome faila iki failo pabaigos
	ifstream prenumeratorius(Cp);
	while (!prenumeratorius.eof()) {
		prenumeratorius >> pavarde >> adresas >> gatvesSk >> lPradzia >> lIlgis >> lKodas >> lKiekis;
		Pre[n].DetiPavarde(pavarde);
		Pre[n].DetiAdresas(adresas);
		Pre[n].DetiGatvesSk(gatvesSk);
		Pre[n].DetilPradzia(lPradzia);
		Pre[n].DetilIlgis(lIlgis);
		Pre[n].DetilKodas(lKodas);
		Pre[n].DetilKiekis(lKiekis);
		n++;
	}
	prenumeratorius.close();
}

void nustatytiBendrasiasLeidiniuPajamas(Leidinys Leid[], Prenumeratorius Pre[], int i, int n) {
	for (int a = 0; a < i; a++){
		for (int l = 0; l < n; l++) {
			if (Leid[a].ImtiKodas() == Pre[l].ImtilKodas()) {
				Leid[a].DetiBendrosiosPajamos(Leid[a].ImtiMenKaina() * Pre[l].ImtilKiekis() * Pre[l].ImtilIlgis() + Leid[a].ImtiBendrosiosPajamos());
			}
		}
	}

	// Irasome duomenis
	ofstream fr(Cr);
	for (int a = 0; a < i; a++){
		fr << Leid[a].ImtiPavadinimas() << " " << Leid[a].ImtiBendrosiosPajamos() << endl;
	}
	fr.close();
}

void sarasasLeidiniuMazesniuUzVidPajamas(Leidinys Leid[], Prenumeratorius Pre[], int i, int n) {
	Leidinys Sarasas[Max];
	Leidinys tmp;
	int j = 0;
	bool bk = true;
	int count = 0;
	double pajamuSuma = 0;
	double pajamuVidurkis;
	for (int a = 0; a < i; a++) {
		pajamuSuma = Leid[a].ImtiBendrosiosPajamos() + pajamuSuma;
	}
	if (i != -1) {
		pajamuVidurkis = pajamuSuma / i;
	}

	// Tikriname ar pajamos mazesnes uz vidutines
	for (int a = 0; a < i; a++) {
		if (Leid[a].ImtiBendrosiosPajamos() < pajamuVidurkis) {
			Sarasas[count] = Leid[a];
			count++;
		}
	}
	while (bk) {
		bk = false;
		j++;
		for (int a = 0; a < count - 1; a++) {

			// Rikuojame sarasa pagal abecele
			if (Sarasas[a] > Sarasas[a + 1]) {
				tmp = Sarasas[a];
				Sarasas[a] = Sarasas[a + 1];
				Sarasas[a + 1] = tmp;
				bk = true;
			}
		}
	}
	ofstream fr(Cr, ios::app);
	// Isvedami duomenys ir faila
	fr << endl;
	fr << "Leidiniai kuriu bendrosios pajamos mazesnes uz vidutines" << endl;
	for (int a = 0; a < count; a++) {
		fr << Sarasas[a].ImtiPavadinimas() << endl;
	}
	fr << endl;
	fr.close();
}

void prenumeratoriuSarasas(Leidinys Leid[], Prenumeratorius Pre[], int i, int n, int menesis, string pavadinimasOUT) {
	string leidinioPavadinimas = pavadinimasOUT;
	int leidinioMenesis = menesis;
	Prenumeratorius Prenumeratoriai[Max];
	int kiek = 0;
	
	// Kada baigiasi prenumerata
	for (int l = 0; l < n; l++) {
		Pre[l].DetilPabaiga(Pre[l].Imtilpradzia() + Pre[l].ImtilIlgis());
	}
	for (int a = 0; a < i; a++) {
		if (Leid[a].ImtiPavadinimas() == leidinioPavadinimas)
		for (int l = 0; l < n; l++) {
			if (Leid[a].ImtiKodas() == Pre[l].ImtilKodas())
			if ((leidinioMenesis >= Pre[l].Imtilpradzia()) && (leidinioMenesis < Pre[l].ImtilPabaiga())) {
				Prenumeratoriai[kiek] = Pre[l];
				kiek++;
			}
		}
	}


	// Isvedame rezultatus
	ofstream fr(Cr, ios::app);
	fr << endl;
	fr << "Leidinio " << leidinioPavadinimas<< " prenumeratoriai " << leidinioMenesis << " menesi:"  << endl;
	for (int p = 0; p < kiek; p++) {
		fr << Prenumeratoriai[p].ImtiPavarde() << endl;
	}
	fr << endl;
	fr.close();
}

void kiekvienoMenesioDidziausiosPajamos(Leidinys Leid[], Prenumeratorius Pre[], int i, int n) {
	int metai = 13;
	int pradzia = 1;
	Leidinys Max[Max];
	for (pradzia; pradzia < metai; pradzia++) {
		double didziausias = 0;
		for (int l = 0; l < n; l++) {

			// Jei prenumerata patenka i menesi
			if ((pradzia >= Pre[l].Imtilpradzia()) && (pradzia < Pre[l].ImtilPabaiga()))
			for (int a = 0; a < i; a++) {
				if ((Leid[a].ImtiKodas() == Pre[l].ImtilKodas()) && (Leid[a].ImtiBendrosiosPajamos() > didziausias)) {
					didziausias = Leid[a].ImtiBendrosiosPajamos();
					Max[pradzia] = Leid[a];
				}
			}
		}
	}
	// Irasome duomenis
	ofstream fr(Cr, ios::app);
	fr << "Kiekvieno menesio didziausiu pajamu leidinys: " << endl;

	// Einame pre visus metu menesius
	for (int pradzia = 1; pradzia < metai; pradzia++){
		fr << pradzia << " " << Max[pradzia].ImtiPavadinimas() << endl;
	}
	fr << endl;
	fr.close();
}
