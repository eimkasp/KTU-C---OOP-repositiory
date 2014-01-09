#pragma once
#include <fstream>
#include "Darbininkas.h"
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>
#include <iomanip>

int pagamino_detaliu(Darbininkas A);
void min_max_ikainis(Darbininkas A[], int i);
void Spausdinti(Darbininkas a, int i);
void vidurkis(Darbininkas A[], int i);
void maziau_nei_vidurkis(Darbininkas A[], int i);
void menesis_min_max(Darbininkas A[], int i, int menesioNum);
void nedirbo(Darbininkas A[], int i);
void Min_Max(Darbininkas D[], int i);
void min_max_detales(Darbininkas A[], int i);
void vienos_rusies(Darbininkas A[], int i);
void nurodyraDetale(Darbininkas A[], int i);
void nurodyraDetale(Darbininkas A[], int i, string det);
void ilgiausiaiGaminama(Darbininkas A[], int i);

namespace KTU_Laboratorinis2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	

	/// <summary>
	/// Summary for MyForm
	/// </summary>

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;






	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;


	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(15, 91);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Vykdyti";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"Sausis", L"Vasaris", L"Kovas", L"Balandis", L"Geguze",
					L"Birzelis", L"Liepa", L"Rugpjutis", L"Rugsejis", L"Spalis", L"Laprkitis", L"Gruodis"
			});
			this->comboBox1->Location = System::Drawing::Point(166, 6);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 4;
			this->comboBox1->Text = L"Menesis";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(91, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Pasirinkite menesi";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(166, 33);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(121, 20);
			this->textBox1->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 36);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(138, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Iveskite detales pavadinima";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 66);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(93, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Darbininko vardas";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(166, 63);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(121, 20);
			this->textBox2->TabIndex = 9;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(305, 6);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(227, 297);
			this->richTextBox1->TabIndex = 10;
			this->richTextBox1->Text = L"";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(731, 304);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void skaitymas( int &i)
		{
			Darbininkas D[100];
			//Sukuriami darbiniai pagalbiniai kintamieji
			Detale Laik;
			int data[3];
			string vardas;
			string kodas;
			string pavadinimas;
			double kaina;
			int kiekis;
			bool darbininkas_yra = false;
			//Aprasomas duomenu failas
			ifstream fd("Darbai.txt");

			// Skaitome duomenu faila
			while (!fd.eof())
			{
				// Gaunamo reikmes
				fd >> data[0] >> data[1] >> data[2] >> vardas >> kodas >> pavadinimas >> kaina >> kiekis;
				Laik.deti(kodas, pavadinimas, kaina, kiekis);
				// Tikriname ar darbinkas jau egzistuoja
				for (int j = 0; j < i && !darbininkas_yra; j++)
				{
					if (D[j].duotiVarda() == vardas)
					{
						// Jei toks darbininkas egzsituoja, papildome darbininko informacija
						darbininkas_yra = true;
						D[j].PapildytiDetales(i, Laik, data);
					}
					else
					{

					}
				}
				if (!darbininkas_yra)
				{
					// Jei tokio darbininko nera, pridedame nauja darbininka
					D[i].deti(vardas, Laik, data);
					i++;
				}
				else {

				}

//				output = marshal_as<String^>(D[i].duotiVarda());
				// label1->Text = output;

				// Atgal nustato numatyta reiksme
				darbininkas_yra = false;
			}
		}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 // Paruosiami duomenys vartotojo ivestiems duomenims
				 String^ menesis;
				 String^ vardasIN;
				 String^ detaleIN;
				 string vardasOUT;
				 string detaleOUT;
				 detaleIN = textBox1->Text;
				 vardasIN = textBox2->Text;
				 menesis = comboBox1->Text;
				 int i = 0;
				 // Duomenu konvertavimas
				 vardasOUT = marshal_as<string>(vardasIN);
				 detaleOUT = marshal_as<string>(detaleIN);

				 //Sukuriamas darbininku masyvas
				 Darbininkas D[100];			
				 int menesioNum = menesio_pavertimas(menesis);
				
				 String^ output = "Test" ;

				 skaitymas(i);

				 // Kvieciame parasytas funkcijas paeiliui pagal uzduoties salyga
				 Min_Max(D, i);
				 min_max_detales(D, i);
				 vienos_rusies(D, i);
				 min_max_ikainis(D, i);
				 vidurkis(D, i);
				 maziau_nei_vidurkis(D, i);
				 menesis_min_max(D, i, menesioNum);
				 nedirbo(D, i);
				 nurodyraDetale(D, i, detaleOUT);
				 ilgiausiaiGaminama(D,i);
				 richTextBox1->LoadFile(L"C:\\Rezultatai.txt", RichTextBoxStreamType::PlainText);
			 }

			 // Paverciame pasirinkima is combo box i sveikaji skaiciu kuri naudosime kitose funkcijose
			 int menesio_pavertimas(String^ menesis)
			 {
				 if (menesis == "Sausis")
				 {
					 return 1;
				 }
				 else if (menesis == "Vasaris")
				 {
					 return 2;
				 }
				 else if (menesis == "Kovas"){
					 return 3;
				 }
				 else if (menesis == "Balandis")
				 {
					 return 4;
				 }
				 else if (menesis == "Geguze")
				 {
					 return 5;
				 }
				 else if (menesis == "Birzelis")
				 {
					 return 6;
				 }
				 else if (menesis == "Liepa")
				 {
					 return 7;
				 }
				 else if (menesis == "Rugpjutis")
				 {
					 return 8;
				 }
				 else if (menesis == "Rugsejis")
				 {
					 return 9;
				 }
				 else if (menesis == "Spalis")
				 {
					 return 10;
				 }
				 else if (menesis == "Lapkritis")
				 {
					 return 11;
				 }
				 else if (menesis == "Gruodis")
				 {
					 return 12;
				 }
			 }
};
}
