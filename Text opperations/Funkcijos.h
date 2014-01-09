#ifndef Funkcijos_H
#define Funkcijos_H

#include <string>
#include <map>
#include <vector>
#include <sstream>
#include "ZodziuDaznis.h"

using namespace std;

class Funkcijos {
public:
	string RastiIlgiausiaSakini(vector<string> sakiniai, int & simb);
	int RastiIlgiausioSakinioEilute(string sakinys, vector<string> eilutes, int & zod);
	void RastiZodziuDaznius(map<string, int> & zodziaisk, vector<string> & sakiniai);
	void ZodziuDazniuSarasas(map<string, int> & zodziaisk, vector<ZodziuDaznis> & sarasas);
	void ZodziuDazniuSarasas(map<string, int> & zodziaisk, vector<ZodziuDaznis> & sarasas, int i);
	stringstream Lygiuoti(vector<string> eilutes);
};

#endif