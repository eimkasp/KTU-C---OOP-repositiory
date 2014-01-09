#ifndef Tekstas_H
#define Tekstas_H

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Tekstas : public vector<string> {
public:
	Tekstas() { };
	Tekstas(const string & eilute, char* skyriklis1);
	Tekstas(const string & eilute, char* skyriklis1, char* skyriklis2, char* skyriklis3);
};


#endif