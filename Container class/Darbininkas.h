#pragma once
#include <string>
#include "Detale.h"

using namespace std;
class Darbininkas
{
public:
	Darbininkas(void);
	~Darbininkas(void) {};
	string duotiVarda() { return vardas; }
	void deti(string vard, Detale B, int dataIN[3]);
	int datos[100][3];
	int DuotiI() { return index; }
	void Padidinti() { index++; }
	Detale DuotiDetale(int i) { return A[i]; }
	void PapildytiDetales(int i, Detale B, int dataIN[3]);
	double Uzdirbo();
	Detale imti(int i);
	int Pagamino();
	Detale A[100];
	int duotiDienas() { return dienos;  }
private:
	string vardas;
	int index;
	int dienos;
};

