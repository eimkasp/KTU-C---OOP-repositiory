#pragma once
#include <string>
using namespace std;

class Prenumeratorius {
private:
	string pavarde;
	string adresas;
	int gatvesSk;
	int lPradzia;
	int lIlgis;
	string lKodas;
	int lKiekis;
	int lPabaiga;
public:
	Prenumeratorius() : pavarde(""), adresas(""), gatvesSk(0), lPradzia(0), lIlgis(0), lKodas(""), lKiekis(0), lPabaiga(0) {}
	Prenumeratorius(string, string, int, int, int, string, int) : pavarde(pavarde), adresas(adresas), gatvesSk(gatvesSk), lPradzia(lPradzia), lIlgis(lIlgis), lKodas(lKodas), lKiekis(lKiekis), lPabaiga(lPabaiga) {}
	string ImtiPavarde() { return pavarde; };
	string ImtiAdresas() { return adresas; };
	int ImtiGatvesSk() { return gatvesSk; };
	int Imtilpradzia() { return lPradzia; };
	int ImtilIlgis() { return lIlgis; };
	string ImtilKodas() { return lKodas; };
	int ImtilKiekis() { return lKiekis; };
	int ImtilPabaiga() { return lPabaiga; };
	void DetiPavarde(string pavarde) { Prenumeratorius::pavarde = pavarde; };
	void DetiAdresas(string adresas) { Prenumeratorius::adresas = adresas; };
	void DetiGatvesSk(int gatvesSk) { Prenumeratorius::gatvesSk = gatvesSk; };
	void DetilPradzia(int lPradzia) { Prenumeratorius::lPradzia = lPradzia; };
	void DetilIlgis(int lIlgis) { Prenumeratorius::lIlgis = lIlgis; };
	void DetilKodas(string lKodas) { Prenumeratorius::lKodas = lKodas; };
	void DetilKiekis(int lKiekis) { Prenumeratorius::lKiekis = lKiekis; };
	void DetilPabaiga(int lPabaiga) { Prenumeratorius::lPabaiga = lPabaiga; };
};

