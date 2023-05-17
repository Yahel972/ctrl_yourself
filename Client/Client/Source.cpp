#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "LoginForm.h"
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;
using namespace Client;

void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	LoginForm form;
	Application::Run(% form);
}