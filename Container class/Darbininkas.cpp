#include "Darbininkas.h"


Darbininkas::Darbininkas(void)
{
	index = 0;
}

void Darbininkas::deti(string vard, Detale B, int dataIN[3])
{
	vardas = vard;
	dienos = 0;
	A[index] = B;
	datos[index][0] = dataIN[0];
	datos[index][1] = dataIN[1];
	datos[index][2] = dataIN[2];
	dienos++;
	/*A[index].data[0] = dataIN[0];
	A[index].data[1] = dataIN[1];
	A[index].data[2] = dataIN[2];*/
	//A[index].detiData(data);
	index++;
}

void Darbininkas::PapildytiDetales(int i, Detale B, int dataIN[3]) 
{
	bool diena_yra = false;
	for (int i = 0; i < dienos && !diena_yra; i++)
	{
		if (dataIN[0] == datos[i][0] && dataIN[1] == datos[i][1] && dataIN[2] == datos[i][2])
		{
			diena_yra = true;
		}
	}
	if (!diena_yra)
	{
		datos[index][0] = dataIN[0];
		datos[index][1] = dataIN[1];
		datos[index][2] = dataIN[2];
		dienos++;
	}
	A[index] = B;
	index++;
}

double Darbininkas::Uzdirbo() 
{
	double rezultatas = 0;
	for(int g = 0; g < index; g++)
	{
		rezultatas += A[g].duotiKaina() * A[g].duotiKieki();
	}

	return rezultatas;
}

int Darbininkas::Pagamino() 
{
	double rezultatas = 0;
	for(int g = 0; g < index; g++)
	{
		rezultatas += A[g].duotiKieki();
	}

	return rezultatas;
}

Detale Darbininkas::imti(int i)
{
	return A[i];
}
