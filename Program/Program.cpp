#include "MainMenuGrocery.h"

using namespace System;
using namespace System::Windows::Forms;

void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Program::MainMenuGrocery mainMenuGrocery;

	Application::Run(% mainMenuGrocery);

}
