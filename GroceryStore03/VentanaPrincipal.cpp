#include "VentanaPrincipal.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GroceryStore03::VentanaPrincipal form;
	Application::Run(% form);
}
