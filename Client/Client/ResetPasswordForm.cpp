#include "ResetPasswordForm.h"

Client::ResetPasswordForm::ResetPasswordForm(Peer& p, std::string username): _p(p), _username(new std::string(username)) { InitializeComponent(); }

Peer& Client::ResetPasswordForm::getPeer()
{
	return this->_p;
}

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

	// creating login request
	std::string msg = "6&" + std::string(this->_username->c_str()) + "&" + msclr::interop::marshal_as<std::string>(this->password_textbox->text);
	send(this->getPeer().getSock(), msg.c_str(), msg.size(), 0);
	
	// TODO: receive response (change with the 'true')
	if (true)
	{
		MessageBox::Show("Password Changed Successfully!", "Password Changed", MessageBoxButtons::OK, MessageBoxIcon::Information);
		login_link_LinkClicked(nullptr, nullptr);
	}
}

System::Void Client::ResetPasswordForm::login_link_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
{
	LoginForm^ lf = gcnew LoginForm(_p);
	lf->Show();
	this->Hide();;
}

System::Void Client::ResetPasswordForm::OnFormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	exit(0);
}
