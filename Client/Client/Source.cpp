#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "LoginForm.h"
#include "Global.h"
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

	/*while (true)
	{
		if (Global::getFormState())
		{
			std::string current_from = Global::getCurrentForm();

			if (current_from == LOGIN_FORM)
			{
				std::cout << "LOGIN";
				continue;
			}
			else if (current_from == REGISTRATION_FORM)
			{
				std::cout << "REGISTER";
				continue;
			}
			else if (current_from == FORGOT_PASSWORD_FORM)
			{
				std::cout << "FORGOT_PASSWORD";
				continue;
			}
			else if (current_from == RESET_PASSWORD_FORM)
			{
				std::cout << "RESET_PASSWORD";
				continue;
			}

			Global::formStable();
		}
	}*/
}