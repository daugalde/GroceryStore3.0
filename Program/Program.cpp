#include "MainMenuGrocery.h"

using namespace System;
using namespace System::Windows::Forms;

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Program::MainMenuGrocery mainMenuGrocery;

	//loginForm.ShowDialog();
	//User^ user = loginForm.user;
	Application::Run(% mainMenuGrocery);
	//if (1 != 1) {
	//	//MyRestaurantProject::MainForm mainForm(user);
	//	
	//}
	//else {
	//	MessageBox::Show("Authentication Canceled",
	//		"Program.cpp", MessageBoxButtons::OK);
	//}
}
