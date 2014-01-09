#include "MyForm.h"

// Randame darbininkus kurie gamino brangiausias ir pigiausias detles
void min_max_ikainis(Darbininkas A[], int i)
{
	// Didziausio ir maziausio bendro ikainio detales kintamieji
	double min = DBL_MAX;
	double max = -1;
	int min_index;
	int max_index;

	// Individualaus darbininko maziausio ir didziausio ikainio kintamieji
	double d_max;
	double d_min;

	for (int j = 0; j < i; j++)
	{
		d_max = -1;
		d_min = DBL_MAX;
		//Randamas darbininko didziausias maziausias ikainis
		for (int g = 0; g < A[j].DuotiI(); g++)
		{
			if (A[j].DuotiDetale(g).duotiKaina() < d_min)
			{
				d_min = A[j].DuotiDetale(g).duotiKaina();
			}
			if (A[j].DuotiDetale(g).duotiKaina() > d_max)
			{
				d_max = A[j].DuotiDetale(g).duotiKaina();
			}
		}


		// Tikriname ar tai ekstremumai bendrame sarase
		if (d_min < min)
		{
			min = d_min;
			min_index = j;
		}

		if (d_max > max)
		{
			max = d_max;
			max_index = j;
		}
	}

	// Isvedame gautus rezultatus
	ofstream fr("Rezultatai.txt", ios::app);
	fr << "------------------ 4 Dalis -------------------" << endl;
	fr << "Darbininkas gamines didziausio ikainio detale: " << endl;
	fr << A[max_index].duotiVarda() << " Pagamino detaliu: " << pagamino_detaliu(A[max_index]) << endl;
	fr << "Darbininkas gamines maziausio ikainio detale: " << endl;
	fr << A[min_index].duotiVarda() << " Pagamino detaliu: " << pagamino_detaliu(A[min_index]) << endl;
	fr << "Kartu jie pagamino detaliu: " << pagamino_detaliu(A[min_index]) + pagamino_detaliu(A[max_index]) << endl;
}

// Suskaiciuojame bendra pagaminta detaliu skaiciu individualiam darbininkui
int pagamino_detaliu(Darbininkas A)
{
	// Gauname kiek darbininkas gamino detaliu
	int n = A.DuotiI();
	int kiekis;
	for (int j = 0; j < n; j++)
	{
		// Kaupiame ju kieki
		kiekis += A.DuotiDetale(j).duotiKieki();
	}
	return kiekis;
}


// Funkcija skaiciuoja vidutini pagamintu detaliu kieki ir uzdarbi
void vidurkis(Darbininkas A[], int i)
{
	ofstream fr("Rezultatai.txt", ios::app);
	fr << "------------------ 5 Dalis -------------------" << endl;
	for (int n = 0; n < i; n++)
	{
		fr << A[n].duotiVarda() << " Vidutiniskai uzdirbo: "
			<< A[n].Uzdirbo() / A[n].duotiDienas() << " Vidutiniskai pagamino detaliu: "
			<< (double)pagamino_detaliu(A[n]) / A[n].duotiDienas() << endl;
	}
}

void maziau_nei_vidurkis(Darbininkas A[], int i)
{
	int detaliuSk = 0;
	double tempKaina;
	double vidurkis;
	double verte = 0;
	bool maziau = false;
	ofstream fr("Rezultatai.txt", ios::app);
	fr << "------------------ 6 Dalis -------------------" << endl;
	fr << "Darbininkai gamine detales kuriu verte mazesne uz vidurki" << endl;
	for (int n = 0; n < i; n++)
	{
		detaliuSk += pagamino_detaliu(A[n]);
		verte += A[n].Uzdirbo();
	}

	vidurkis = verte / detaliuSk;
	fr << "Detales kainos vidurkis: " << vidurkis << endl;
	for (int n = 0; n < i; n++)
	{
		maziau = false;
		for (int j = 0; j < A[n].DuotiI(); j++)
		{
			tempKaina = A[n].DuotiDetale(j).duotiKaina();
			if (tempKaina < vidurkis)
			{
				maziau = true;
			}
		}
		if (maziau)
		{
			fr << A[n].duotiVarda() << " Uzdirbo: " << A[n].Uzdirbo() << endl;
		}
	}

}


void menesis_min_max(Darbininkas A[], int i, int menesioNum)
{
	int min = INT_MAX;
	int max = INT_MIN;
	int min_index;
	int min_d = INT_MAX;
	int max_d = INT_MIN;

	int max_index = -1;
	bool tinka_menesis = false;

	// Tikriname ar darbininkas atitinka menesio kriteriju
	for (int n = 0; n < i; n++)
	{
		tinka_menesis = false;
		for (int j = 0; j < A[n].DuotiI() && !tinka_menesis; j++)
		{
			if (A[n].datos[j][1] == menesioNum)
			{
				tinka_menesis = true;
			}
		}


		// Tikriname ar darbininko pagamintu detaliu kiekis yra kuris nors is ekstremumu
		if (tinka_menesis)
		{
			if (pagamino_detaliu(A[n]) > max)
			{
				max = pagamino_detaliu(A[n]);
				max_index = n;
			}

			if (pagamino_detaliu(A[n]) < min)
			{
				min = pagamino_detaliu(A[n]);
				min_index = n;
			}
		}
	}

	// Isvedame rezultatus
	ofstream fr("Rezultatai.txt", ios::app);
	fr << "------------------ 7 Dalis -------------------" << endl;
	if (max_index != -1)
	{
		fr << menesioNum << " menesi daugiausiai detaliu pagamino: " << A[max_index].duotiVarda() << " uzdirbo: " << A[max_index].Uzdirbo() << endl;
		fr << menesioNum << " menesi maziausiai detaliu pagamino: " << A[min_index].duotiVarda() << " uzdirbo: " << A[min_index].Uzdirbo() << endl;
	}
	else {
		fr << "Si menesi niekas nedirbo" << endl;
	}
	}

void nedirbo(Darbininkas A[], int i)
{
	ofstream fr("Rezultatai.txt", ios::app);

	// sukuriame darbinius kintamuosius skaiciavimams
	int tarpas = 0;
	int max = INT_MIN;
	int max_index;
	fr << "------------------ 8 Dalis -------------------" << endl;
	bool tinka = false;
	for (int j = 0; j < i; j++)
	{
		tinka = false;
		tarpas = 0;
		// Tikriname ar darbininkas dirbo bent 2 dienas
		if (A[j].duotiDienas() > 1)
		{
			tinka = true;
		}

		if (tinka)
		{
			for (int g = 0; g+1 < A[j].duotiDienas(); g++)
			{
				// Skaiciuojame koks buvo didziausias intervalas tarp nedarbo dienu;
				tarpas = A[j].datos[g + 1][0] * 365 + A[j].datos[g + 1][1] * 30 + A[j].datos[g + 1][2];
				tarpas -= A[j].datos[g][0] * 365 + A[j].datos[g][1] * 30 + A[j].datos[g][2]; // Paverciame metus ir menesius i dienas
				

				// jei salyga atitinka issaugome tinkama rezultata
				if (tarpas > max)
				{
					max = tarpas;
					max_index = j;
				}
			}
		}

	}
	// Irasome rezultata
	fr << "Ilgiausiai nedirbes darbininkas: " << A[max_index].duotiVarda() << endl;
}


// Daugiausiai maziausiai  uzdirbe darbininkai
void Min_Max(Darbininkas D[], int i)
{
	// Sukuriame pradinius kintamuosius
	int min_index, max_index;
	double min = 999999, max = DBL_MIN;

	// Tikriname kiek uzdirbo kiekvienas darbininkas
	for (int j = 0; j < i; j++)
	{

		//Patikriname ar atitinka salyga bent vienam is ekstremumu
		if (D[j].Uzdirbo() > max)
		{
			max = D[j].Uzdirbo();
			max_index = j;
		}

		if (D[j].Uzdirbo() < min)
		{
			min = D[j].Uzdirbo();
			min_index = j;
		}
	}

	ofstream fr("Rezultatai.txt");
	fr << "------------------ 1 Dalis -------------------" << endl;
	// Daugiausiai uzdirbusio darbininko isvedimas
	fr << "Daugiausiai uzdirbo: " << endl;
	fr << setw(10) << D[max_index].duotiVarda() << endl;
	fr << "Dirbta dienu: " << D[max_index].duotiDienas() << endl;
	fr << "Pagaminta detaliu: " << D[max_index].Pagamino() << endl;
	fr << "Uzdirbo: " << D[max_index].Uzdirbo() << endl << endl;

	// Maziausiai uzdirbusio darbininko isvedimas
	fr << "Maziausiai uzdirbo: " << endl << D[min_index].duotiVarda() << endl;
	fr << "Dirbta dienu: " << D[min_index].duotiDienas() << endl;
	fr << "Pagaminta detaliu: " << D[min_index].Pagamino() << endl;
	fr << "Uzdirbo: " << D[min_index].Uzdirbo() << endl << endl;
}

void min_max_detales(Darbininkas A[], int i)
{
	// Sudarome unikaliu detaliu masyva
	Detale U[100];
	int kiekiai[100];

	// Masyvo dydis kuriame kaupiame unikalias detales
	int detaliu_skaicius = 0;
	string laikinas_kodas;
	// Loginis kintamasis patikrinti ar detale jau yra masyve
	bool detale_yra = false;

	// Didziausios maziausios detales paieskos kintamieji
	int kiekis;
	int min_kiekis;
	int max_kiekis;
	int min_index;
	int max_index;

	// Formuojamas unikaliu detaliu rinkinys
	for (int j = 0; j < i; j++)
	{
		for (int g = 0; g < A[j].DuotiI(); g++)
		{
			laikinas_kodas = A[j].DuotiDetale(g).duotiKoda();
			for (int f = 0; f < detaliu_skaicius && !detale_yra; f++)
			{
				// Tikrinama ar detale jau egzistuoja masyve
				if (laikinas_kodas == U[f].duotiKoda())
				{
					detale_yra = true;
				}
			}
			if (!detale_yra)
			{
				U[detaliu_skaicius] = A[j].DuotiDetale(g);
				detaliu_skaicius++;
			}
			detale_yra = false;
		}
	}

	ofstream fr("Rezultatai.txt", ios::app);
	fr << "------------------ 2 Dalis -------------------" << endl;
	int f;
	// Skaiciuojame kiek kokios detales pagaminta
	for (int j = 0; j < detaliu_skaicius; j++)
	{
		kiekiai[j] = 0;
		for (int g = 0; g < i; g++)
		{
			f = A[g].DuotiI();
			for (int o = 0; o < f; o++)
			{
				if (U[j].duotiKoda() == A[g].DuotiDetale(o).duotiKoda())
				{

					kiekiai[j] += A[g].DuotiDetale(o).duotiKieki();
				}
			}
		}
		fr << U[j].duotiKoda() << " " << kiekiai[j] << endl;
	}
}

void vienos_rusies(Darbininkas A[], int i)
{
	int suma = 0;
	int detaliu_kiekis = 0;
	ofstream fr("Rezultatai.txt", ios::app);
	fr << "------------------ 3 Dalis -------------------" << endl;
	fr << "Darbininkai gamine tik vienos rusies detales: " << endl;
	Detale Unikali[100];
	int tinkamu_index[100];
	int darbininku_sk = 0;
	int detaliuSk = 0;
	bool detale_yra = false;

	// Atrenkame darbininkus kurie gamino tik vienos rusies detales
	for (int j = 0; j < i; j++)
	{
		detaliuSk = 0;
		int f = A[j].DuotiI(); // Detaliu skaicius pas darbininka
		for (int g = 0; g < f; g++)
		{
			detale_yra = false;	// Nustaome numatytaja reiksme kintamajam
			for (int o = 0; o < detaliuSk && !detale_yra; o++)
			{
				// Tikriname ar detale jau egzistuoja unikaliu detaliu masyve
				if (A[j].DuotiDetale(g).duotiKoda() != Unikali[o].duotiKoda())
				{
					detale_yra = false;
				}
				else {
					detale_yra = true;
				}
			}

			// Pridedame jei neegzistuoja
			if (!detale_yra)
			{
				Unikali[detaliuSk] = A[j].DuotiDetale(g);
				detaliuSk++;
			}
		}

		// Jei darbininkas gamino tik 1 detale, irasome i faila;
		if (detaliuSk == 1)
		{
			detaliu_kiekis = 0;
			tinkamu_index[darbininku_sk] = j;
			for (int t = 0; t < A[j].DuotiI(); t++)
			{
				detaliu_kiekis += A[j].DuotiDetale(t).duotiKieki();
			}
			darbininku_sk++;
			fr << A[j].duotiVarda() << " " << detaliu_kiekis << endl;
			suma += detaliu_kiekis;
		}
	}
	fr << "Visi bendrai pagamino detaliu: " << endl;
	fr << suma << endl;
}

void nurodyraDetale(Darbininkas A[], int i, string det)
{
	int min = INT_MAX, min_index;
	int max = INT_MIN, max_index;
	bool tinka = false;
	int j;
	int temp_kiekis = 0;
	for (int n = 0; n < i; n++)
	{
		tinka = false;
		j = A[n].DuotiI();
		temp_kiekis = 0;
		for (int g = 0; g < j; g++)
		{
			if (A[n].DuotiDetale(g).duotiKoda() == det)
			{
				tinka = true;
				temp_kiekis += A[n].DuotiDetale(g).duotiKieki();
			}

			if (tinka)
			{
				if (temp_kiekis < min)
				{
					min = temp_kiekis;
					min_index = n;
				}
				if (temp_kiekis > max)
				{
					max = temp_kiekis;
					max_index = n;
				}
			}
		}

	}

	ofstream fr("Rezultatai.txt", ios::app);
	fr << "------------------ 9 Dalis -------------------" << endl;
	fr << det << " Detales daugiausiai pagamino: " << A[max_index].duotiVarda() << " uzdribo" << A[max_index].Uzdirbo() << endl;
	fr << det << " Detales maziausiai pagamino: " << A[min_index].duotiVarda() << " uzdribo" << A[min_index].Uzdirbo() << endl;
}

void ilgiausiaiGaminama(Darbininkas A[], int i)
{
	int max = 0, max_index;
	int max_kiekis;
	int kiekis = 0;
	int dienos = 0;;
	Detale U[100];
	// Masyvo dydis kuriame kaupiame unikalias detales
	int detaliu_skaicius = 0;
	string laikinas_kodas;
	// Loginis kintamasis patikrinti ar detale jau yra masyve
	bool detale_yra = false;
	// Formuojamas unikaliu detaliu rinkinys
	for (int j = 0; j < i; j++)
	{
		for (int g = 0; g < A[j].DuotiI(); g++)
		{
			laikinas_kodas = A[j].DuotiDetale(g).duotiKoda();
			for (int f = 0; f < detaliu_skaicius && !detale_yra; f++)
			{
				// Tikrinama ar detale jau egzistuoja masyve
				if (laikinas_kodas == U[f].duotiKoda())
				{
					detale_yra = true;
				}
			}
			if (!detale_yra)
			{
				U[detaliu_skaicius] = A[j].DuotiDetale(g);
				detaliu_skaicius++;
			}
			detale_yra = false;
		}
	}
	int f;
	for (int j = 0; j < detaliu_skaicius; j++)
	{
		int kiekis = 0;
		int dienos = 0;
		for (int n = 0; n < i; n++)
		{
			f = A[n].DuotiI();
			for (int t = 0; t < f; t++)
			{
				if (A[n].DuotiDetale(t).duotiKoda() == U[j].duotiKoda())
				{
					kiekis += A[n].DuotiDetale(t).duotiKieki();
					dienos++;
				}
			}
		}
		if (dienos > max)
		{
			max_kiekis = kiekis;
			max = dienos;
			max_index = j;
		}
	}

	int max_d = INT_MIN;
	int max_d_index;
	int kiekis_d = 0;

	for (int o = 0; o < i; o++)
	{
		kiekis_d = 0;
		for (int p = 0; p < A[o].DuotiI(); p++)
		{
			if (A[o].DuotiDetale(p).duotiKoda() == U[max_index].duotiKoda())
			{
				kiekis_d += A[o].DuotiDetale(p).duotiKieki();
			}
		}
		if (kiekis_d > max_d)
		{
			max_d = kiekis_d;
			max_d_index = o;
		}
	}
	ofstream fr("Rezultatai.txt", ios::app);

	fr << "------------------ 10 Dalis -------------------" << endl;
	fr << "Ilgiausiai gaminama detale: " << U[max_index].duotiKoda() << " Viso jos pagaminta: " << max_kiekis << endl
		<< " Daugiausiai pagamines darbininkas:" << A[max_d_index].duotiVarda();
}