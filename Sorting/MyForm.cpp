#include "MyForm.h"
#include "Leidinys.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Laboras3::MyForm form; // Eilutė, kuri gali būti koreguojama
	Application::Run(%form);
}