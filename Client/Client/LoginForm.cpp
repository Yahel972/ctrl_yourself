#include "LoginForm.h"

using namespace System;
using namespace System::Windows::Forms;

int main()
//int main (array＜String^＞^args )
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Client::LoginForm form;
	Application::Run(% form);
	return 0;
}