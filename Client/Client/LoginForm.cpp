#include "LoginForm.h"

Client::LoginForm::LoginForm() { InitializeComponent(); }

Client::LoginForm::~LoginForm()
{
	if (components)
		delete components;
}

System::Void Client::LoginForm::register_linkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
{
	RegistrationForm^ rf = gcnew RegistrationForm();
	rf->Show();
	this->Close();
}

System::Void Client::LoginForm::forgotPassword_link_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
{
	ForgotPasswordForm^ fpf = gcnew ForgotPasswordForm();
	fpf->Show();
	this->Close();
}
