#pragma once


using namespace std;

class Detale
{
public:
	Detale();
	virtual ~Detale();
	int duotiKieki() { return kiekis; };
	double duotiKaina() { return kaina; };
	string duotiKoda() { return kodas; };
	void deti(string kodasOut, string pavadinimasOut, double kainaOut, int kiekisOut);
	
private:
	int indeksas;
	int kiekis;
	double kaina;
	string kodas;
	string pavadinimas;
};

