#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>
#include "Leidinys.h"

const int Max = 100;
const string Cl = "U3a.txt";
const string Cp = "U3b.txt";
const string Cr = "Rezultatai.txt";
void nuskaitytiLeidini(Leidinys Leid[], int & i);
void nuskaitytiPrenumeratoriu(Prenumeratorius Pre[], int & n);
void nustatytiBendrasiasLeidiniuPajamas(Leidinys Leid[], Prenumeratorius Pre[], int i, int n);
void sarasasLeidiniuMazesniuUzVidPajamas(Leidinys Leid[], Prenumeratorius Pre[], int i, int n);

void prenumeratoriuSarasas(Leidinys Leid[], Prenumeratorius Pre[], int i, int n, int menesis, string pavadinimasOUT);
void kiekvienoMenesioDidziausiosPajamos(Leidinys Leid[], Prenumeratorius Pre[], int i, int n);

namespace Laboras3 {
		

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
	private: System::Windows::Forms::ComboBox^  comboBox1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;

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
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"Sausis", L"Vasaris", L"Kovas", L"Balandis", L"Geguze",
					L"Birzelis", L"Liepa", L"Rugpjutis", L"Rugsejis", L"Spalis", L"Laprkitis", L"Gruodis"
			});
			this->comboBox1->Location = System::Drawing::Point(281, 219);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(184, 219);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(91, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Pasirinkite menesi";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(327, 258);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Vykdyti";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(281, 175);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(191, 178);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(84, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Pasirinkite leidini";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(0, 12);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(185, 281);
			this->richTextBox1->TabIndex = 5;
			this->richTextBox1->Text = L"";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(414, 293);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 int i;		// Leidiniu skaicius
				 int n;		// Prenumeratoriu skaicius
				 Leidinys Leid[Max];
				 Prenumeratorius Pre[Max];
				 nuskaitytiLeidini(Leid, i);
				 nuskaitytiPrenumeratoriu(Pre, n);
				 String^ pavadinimasGUI = "Testas";
				 for (int j = 0; j < i; j++)
				 {
					 // Duomenu konvertavimas
					 pavadinimasGUI = marshal_as<String^>(Leid[j].ImtiPavadinimas());
					 comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(1) {
						 pavadinimasGUI
					 });
				 }
				
	}
			 // Menesis paverciamas i skaiciu is combo box
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

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 String^ menesis;
				 String^ vardas;
				 string vardasOUT;
				 string menesisOUT;
				 int menesio_nr;
				 menesis = comboBox1->Text;
				 vardas = comboBox2->Text;
				 menesio_nr = menesio_pavertimas(menesis);
				 vardasOUT = marshal_as<string>(vardas);
				 int i;		// Leidiniu skaicius
				 int n;		// Prenumeratoriu skaicius
				 Leidinys Leid[Max];
				 Prenumeratorius Pre[Max];
				
				
				 nuskaitytiLeidini(Leid, i);
				 nuskaitytiPrenumeratoriu(Pre, n);
				 nustatytiBendrasiasLeidiniuPajamas(Leid, Pre, i, n);
				 prenumeratoriuSarasas(Leid, Pre, i, n, menesio_nr, vardasOUT);
				 sarasasLeidiniuMazesniuUzVidPajamas(Leid, Pre, i, n);
				 kiekvienoMenesioDidziausiosPajamos(Leid, Pre, i, n);
				 richTextBox1->LoadFile("Rezultatai.txt", RichTextBoxStreamType::PlainText);
	}
};
}
