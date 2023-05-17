#include "ResetPasswordForm.h"

Client::ResetPasswordForm::ResetPasswordForm(std::string username): _username(new std::string(username)) { InitializeComponent(); }

Client::ResetPasswordForm::~ResetPasswordForm()
{
	if (components)
		delete components;
	delete this->_username;
}

System::Void Client::ResetPasswordForm::login_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->password_textbox->text == "" || this->confirmPassword_textbox->text == "")
	{
		MessageBox::Show("Please fill all fields", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	if (this->password_textbox->text != this->confirmPassword_textbox->text)
	{
		MessageBox::Show("Passwords unidentical", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// TODO: set the new password for the user
	// DEAN

	MessageBox::Show("Password Changed Successfully!", "Password Changed", MessageBoxButtons::OK, MessageBoxIcon::Information);
	login_link_LinkClicked(nullptr, nullptr);
}

System::Void Client::ResetPasswordForm::login_link_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
{
	LoginForm^ lf = gcnew LoginForm();
	lf->Show();
	this->Hide();;
}
