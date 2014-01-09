#include "Tekstas.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//Duomenu isskirstymas pagal tris skyriklius.
Tekstas::Tekstas(const string & eilute, char* skyriklis1, char* skyriklis2, char* skyriklis3) {
	size_t paskutinis = 0;
	size_t esamas1 = eilute.find_first_of(skyriklis1);
	size_t esamas2 = eilute.find_first_of(skyriklis2);
	size_t esamas3 = eilute.find_first_of(skyriklis3);
	size_t esamas;
	//suranda arciausiai esanti skirikli
	if (esamas1 < esamas2 && esamas1 < esamas3)
		esamas = esamas1;
	else if (esamas2 < esamas1 && esamas2 < esamas3)
		esamas = esamas2;
	else if (esamas3 < esamas1 && esamas3 < esamas2)
		esamas = esamas3;
	else
		esamas = esamas1;


	//isskiria sakinius
	while (esamas != string::npos) {
		if (esamas != paskutinis)
			push_back(eilute.substr(paskutinis, esamas - paskutinis));
		paskutinis = esamas + 2;
		esamas = eilute.find_first_of(skyriklis1, paskutinis);
		esamas1 = eilute.find_first_of(skyriklis1, paskutinis);
		esamas2 = eilute.find_first_of(skyriklis2, paskutinis);
		esamas3 = eilute.find_first_of(skyriklis3, paskutinis);
		if (esamas1 < esamas2 && esamas1 < esamas3)
			esamas = esamas1;
		else if (esamas2 < esamas1 && esamas2 < esamas3)
			esamas = esamas2;
		else if (esamas3 < esamas1 && esamas3 < esamas2)
			esamas = esamas3;

	}
	if (paskutinis < eilute.length())
		push_back(eilute.substr(paskutinis, esamas - paskutinis));

	char chars[] = "\n.";
	for (vector<string>::iterator i = this->begin(); i < this->end(); i++) {
		for (unsigned int y = 0; y < strlen(chars); ++y){
			i->erase(remove(i->begin(), i->end(), chars[y]), i->end());
		}
	}

}


//Duomenu isskirstymas pagal viena skyrikli.
Tekstas::Tekstas(const string & eilute, char* skyriklis1) {
	size_t paskutinis = 0;
	size_t esamas = eilute.find_first_of(skyriklis1);
	while (esamas != string::npos) {
		if (esamas != paskutinis)
			push_back(eilute.substr(paskutinis, esamas - paskutinis));
		paskutinis = esamas + 1;
		esamas = eilute.find_first_of(skyriklis1, paskutinis);
	}
	//likusio sakinio idejimas
	if (paskutinis < eilute.length())
		push_back(eilute.substr(paskutinis, esamas - paskutinis));

	//istrina eilutes pabaigos simbolius(skyriklius)
	char chars[] = "\n";
	for (vector<string>::iterator i = this->begin(); i < this->end(); i++) {
		i->erase(remove(i->begin(), i->end(), chars[0]), i->end());
	}
};
