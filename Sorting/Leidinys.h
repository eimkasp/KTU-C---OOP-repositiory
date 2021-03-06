#pragma once
#include <string>
#include "Prenumeratorius.h"
using namespace std;

class Leidinys {
private:
	string kodas;		// Must be same format in both(Leidinys and Prenumeratorius) classes, this is connection variable.
	string pavadinimas;
	double menKaina;
	double bendrosiosPajamos;
public:
	// Constructor
	Leidinys() : kodas(""), pavadinimas(""), menKaina(0), bendrosiosPajamos(0) {}
	Leidinys(string, string, double, double) : kodas(kodas), pavadinimas(pavadinimas), menKaina(menKaina), bendrosiosPajamos(bendrosiosPajamos) {}
	/* Get/Set functions */
	string ImtiKodas() { return kodas; }
	string ImtiPavadinimas() { return pavadinimas; }
	double ImtiMenKaina() { return menKaina; }
	double ImtiBendrosiosPajamos() { return bendrosiosPajamos; }
	void DetiKodas(string kodas) { Leidinys::kodas = kodas; };
	void DetiPavadinimas(string pavadinimas) { Leidinys::pavadinimas = pavadinimas; };
	void DetiMenKaina(double menKaina) { Leidinys::menKaina = menKaina; };
	void DetiBendrosiosPajamos(double bendrosiosPajamos) { Leidinys::bendrosiosPajamos = bendrosiosPajamos; };

	/* Operator overlay to compare strings of magazines names to simplify general logic in functions*/
	bool operator > (const Leidinys & kitas){
		if (pavadinimas > kitas.pavadinimas)
		{
			return true;
		}
	}
};

