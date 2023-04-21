#include "ResetPasswordForm.h"

Client::ResetPasswordForm::ResetPasswordForm(std::string username): _username(new std::string(username)) { InitializeComponent(); }

Client::ResetPasswordForm::~ResetPasswordForm()
{
	if (components)
		delete components;
	delete this->_username;
}

System::Void Client::ResetPasswordForm::login_link_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
{
	LoginForm^ lf = gcnew LoginForm();
	lf->Show();
	this->Hide();;
}
