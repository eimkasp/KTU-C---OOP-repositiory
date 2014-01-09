#include "Funkcijos.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

//Zodziu dazniu radimas.
void Funkcijos::RastiZodziuDaznius(map<string, int> & zodziaisk, vector<string> & sakiniai) {
	
	// skaido eilutes i zodzius
	vector<string> zodziai;
	for (unsigned int i = 0; i < sakiniai.size(); i++) {
		size_t paskutinis = 0;
		size_t esamas = sakiniai[i].find_first_of(" ");
		while (esamas != string::npos) {
			if (esamas != paskutinis)
				zodziai.push_back(sakiniai[i].substr(paskutinis, esamas - paskutinis));
			paskutinis = esamas + 1;
			esamas = sakiniai[i].find_first_of(" ", paskutinis);
		}
		if (paskutinis < sakiniai[i].length())
			zodziai.push_back(sakiniai[i].substr(paskutinis, esamas - paskutinis));
	}
	// pasalina simbolius (skyriklius), kurie yra nereikalingi
	char chars[] = ",?!";
	for (vector<string>::iterator i = zodziai.begin(); i < zodziai.end(); i++) {
		for (unsigned int y = 0; y < strlen(chars); ++y){
			i->erase(remove(i->begin(), i->end(), chars[y]), i->end());
		}
	}

	//padaro mazasias raides ið didziuju
	for (vector<string>::iterator i = zodziai.begin(); i != zodziai.end(); i++){
		transform(i->begin(), i->end(), i->begin(), ::tolower);
	}
	//skaiciuoja zodziu daznius
	for (vector<string>::iterator i = zodziai.begin(); i < zodziai.end(); i++)
		zodziaisk[*i] ? zodziaisk[*i]++ : zodziaisk[*i] = 1;

};

//Zodziu dazniu surikiavimas pagal ilgi
void Funkcijos::ZodziuDazniuSarasas(map<string, int> & zodziaisk, vector<ZodziuDaznis> & sarasas) {


	// sudaro sarasa, kurie ilgiausi
	for (int i = 0; i < zodziaisk.size(); i++) {
		map<string, int>::iterator begin = zodziaisk.begin();
		map<string, int>::iterator end = zodziaisk.end();
		string max = begin->first;
		int maxint = begin->second;
		int maxilgis = begin->first.size();
		for (begin; begin != end; begin++) {
			if (begin->first.size() >= maxilgis && find(sarasas.begin(), sarasas.end(), ZodziuDaznis(begin->first, begin->second)) == sarasas.end()){
				max = begin->first;
				maxint = begin->second;
				maxilgis = begin->first.size();
			}
		}
		//jeigu toks yra, jo nededa. Jeigu yra, ji deda.
		if (find(sarasas.begin(), sarasas.end(), ZodziuDaznis(max, maxint)) == sarasas.end())
			sarasas.push_back(ZodziuDaznis(max, maxint));
	}
};

//Zodziu dazniu surikiavimas pagal pasikartojima.
void Funkcijos::ZodziuDazniuSarasas(map<string, int> & zodziaisk, vector<ZodziuDaznis> & sarasas, int i) {

	//sudaro sarasa, kurie kartojasi
	for (int i = 0; i < zodziaisk.size(); i++) {
		map<string, int>::iterator begin = zodziaisk.begin();
		map<string, int>::iterator end = zodziaisk.end();
		string max = begin->first;
		int maxint = begin->second;
		for (begin; begin != end; begin++) {
			if (begin->second >= maxint && find(sarasas.begin(), sarasas.end(), ZodziuDaznis(begin->first, begin->second)) == sarasas.end()){
				max = begin->first;
				maxint = begin->second;
			}
		}
		// jeigu tokio nera, jo nededa. Jeigu yra, tai deda
		if (find(sarasas.begin(), sarasas.end(), ZodziuDaznis(max, maxint)) == sarasas.end())
			sarasas.push_back(ZodziuDaznis(max, maxint));
	}
};


//Teksto lygiavimas.
stringstream Funkcijos::Lygiuoti(vector<string> eilutes) {
	stringstream stream;
	vector<vector<string>> eilzod;
	// suskaido pagal zodzius
	for (unsigned int i = 0; i < eilutes.size(); i++) {
		vector<string> eilute;
		size_t paskutinis = 0;
		size_t esamas = eilutes[i].find_first_of(" ");
		while (esamas != string::npos) {
			if (esamas != paskutinis)
				eilute.push_back(eilutes[i].substr(paskutinis, esamas - paskutinis));
			paskutinis = esamas + 1;
			esamas = eilutes[i].find_first_of(" ", paskutinis);
		}
		if (paskutinis < eilutes[i].length())
			eilute.push_back(eilutes[i].substr(paskutinis, esamas - paskutinis));
		eilzod.push_back(eilute);
	}

	vector<int> ilgiausi;
	int maxzod = 0;
	// suranda ilgiausia eilute
	for (unsigned int i = 0; i < eilzod.size(); i++) {
		eilzod[i].size() > maxzod ? maxzod = eilzod[i].size() : maxzod = maxzod;
	}
	// suranda ilgiausius zodzius stulpelyje
	for (unsigned int i = 0; i < maxzod; i++) {
		int maxilgis = 0;
		for (unsigned int g = 0; g < eilzod.size(); g++) {
			if (i < eilzod[g].size()) {
				eilzod[g][i].size() > maxilgis ? maxilgis = eilzod[g][i].size() : maxilgis = maxilgis;
			}
		}
		ilgiausi.push_back(maxilgis);
	}

	// lygiuoja zodzius pagal ilgiausia zodi stulpelyje
	for (unsigned int i = 0; i < eilzod.size(); i++) {
		for (unsigned int g = 0; g < eilzod[i].size(); g++) {
			string zodis = eilzod[i][g];
			size_t kiek = ilgiausi[g] - zodis.size() + 2;
			const char* sp = " ";
			for (int i = 0; i < kiek; i++)
				zodis.append(sp);
			stream << zodis;
		}
		stream << endl;
	}

	return stream;
};