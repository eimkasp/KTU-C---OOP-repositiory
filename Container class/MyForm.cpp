#include "MyForm.h"
#include "Darbininkas.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]
int main(array<System::String ^> ^args) 
{
Application::EnableVisualStyles();
Application::SetCompatibleTextRenderingDefault(false);
KTU_Laboratorinis2::MyForm form; // Eilutė, kuri gali būti koreguojama
Application::Run(%form);
}


