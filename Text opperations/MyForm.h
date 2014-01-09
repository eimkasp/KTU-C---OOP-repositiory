#pragma once
#include "Funkcijos.h"
#include "Tekstas.h"
#include "ZodziuDaznis.h"
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <sstream>


namespace LD4_2_Lygiavimas {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	protected:
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(11, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(1087, 27);
			this->button1->TabIndex = 0;
			this->button1->Text = L"LYGIUOTI";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->richTextBox1->Location = System::Drawing::Point(12, 45);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(1086, 687);
			this->richTextBox1->TabIndex = 2;
			this->richTextBox1->Text = L"";
			this->richTextBox1->WordWrap = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1110, 744);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"LD4_2_Lygiavimas";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 richTextBox1->Clear();
				 Funkcijos f;
				 // Register data file
				 ifstream IF("Knyga.txt");
				 stringstream stream;
				 stream << IF.rdbuf();
				 // If empty
				 if (stream.str().size() == 0) {
					 string pranesimas = "Duomenu failas tuscias.";
					 String^ pranessyst = gcnew String(pranesimas.c_str());
					 // Show initial data in screen
					 richTextBox1->AppendText(pranessyst);
				 }
				 else {
					 IF.close();
					 // Separators of sentences
					 Tekstas sakiniai = Tekstas(stream.str(), ".", "!", "?");
					 // Separator of lines
					 Tekstas eilutes = Tekstas(stream.str(), "\n");
					 int zod, simb;
					 zod = 0;
					 simb = 0;
					 // Initial map structure to store data
					 map<string, int> zodziaisk;
					 // Find most common words
					 f.RastiZodziuDaznius(zodziaisk, sakiniai);
					 // Vector of common words tocount 
					 vector<ZodziuDaznis> sarasas;
					 f.ZodziuDazniuSarasas(zodziaisk, sarasas);
					 // Sort alphabeticaly
					 stringstream lygiuota = f.Lygiuoti(eilutes);
					 // Results files registering
					 ofstream OF("ManoKnyga.txt");
					 ofstream AF("Analize.txt");
					 // Populate results file
					 OF << lygiuota.str() << endl;

					 // Find 10 longest words
					 if (sarasas.size() >= 10) {
						 AF << "10 ilgiausiu zodziu: " << endl;
						 for (int i = 0; i < 10; i++)
							 AF << sarasas[i].ImtiZodi() << " " << sarasas[i].ImtiKiek() << endl;
					 }
					 // If there is less words than 10
					 else {
						 AF << sarasas.size() << " ilgiausi zodziai: " << endl;
						 for (int i = 0; i < sarasas.size(); i++)
							 AF << sarasas[i].ImtiZodi() << " " << sarasas[i].ImtiKiek() << endl;
					 }
					 AF << endl;
					 vector<ZodziuDaznis> sarasas1;
					 f.ZodziuDazniuSarasas(zodziaisk, sarasas1, 0);
					 if (sarasas1.size() >= 10) {
						 AF << "10 daugiausiai pasikartojant zodziai: " << endl;
						 for (int i = 0; i < 10; i++)
							 AF << sarasas1[i].ImtiZodi() << " " << sarasas1[i].ImtiKiek() << endl;
					 }
					 else {
						 AF << sarasas1.size() << " daugiausiai pasikartojantys zodziai: " << endl;
						 for (int i = 0; i < sarasas1.size(); i++)
							 AF << sarasas1[i].ImtiZodi() << " " << sarasas1[i].ImtiKiek() << endl;
					 }

					 // Close result files to prevent unexpected output
					 OF.close();
					 AF.close();
					 ifstream AIF("Analize.txt");
					 stringstream analize;
					 analize << AIF.rdbuf();

					 // Populate screen with final results
					 richTextBox1->LoadFile("ManoKnyga.txt", RichTextBoxStreamType::PlainText);
					 String^ analizestr = gcnew String(analize.str().c_str());
					 richTextBox1->AppendText(analizestr);
				 }
	}
	};
}
