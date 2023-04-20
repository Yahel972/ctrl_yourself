#include "RegistrationForm.h"

Client::RegistrationForm::~RegistrationForm()
{
	if (components)
		delete components;
}

System::Void Client::RegistrationForm::registration_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	// TODO: check if username exist & insert to DB
	// if succeeded - force return to login form
}

System::Void Client::RegistrationForm::login_link_clicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
{
	LoginForm^ jgjg = gcnew LoginForm();
	jgjg->Show();
	this->Hide();
    return System::Void();
}
