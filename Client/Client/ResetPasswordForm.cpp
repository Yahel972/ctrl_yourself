#include "ResetPasswordForm.h"

Client::ResetPasswordForm::~ResetPasswordForm()
{
	if (components)
		delete components;
}

System::Void Client::ResetPasswordForm::login_link_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
{
	return System::Void();
}
