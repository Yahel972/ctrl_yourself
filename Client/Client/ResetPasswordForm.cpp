#include "ResetPasswordForm.h"

Client::ResetPasswordForm::~ResetPasswordForm()
{
	if (components)
		delete components;
}

System::Void Client::ResetPasswordForm::login_link_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
{
	LoginForm^ lf = gcnew LoginForm();
	lf->Show();
	this->Hide();;
}
