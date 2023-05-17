#include "MainForm.h"

Client::MainForm::MainForm(User u): _user(new User(u)) { InitializeComponent(); }

Client::MainForm::~MainForm()
{
	if (components)
		delete components;
	delete this->_user;
}

System::Void Client::MainForm::logout_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	LoginForm^ lf = gcnew LoginForm();
	lf->Show();
	this->Hide();
}

System::Void Client::MainForm::OnFormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	exit(0);
}
