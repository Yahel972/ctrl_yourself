#include "LoginForm.h"

Client::LoginForm::LoginForm(Peer& p): _p(p) { InitializeComponent(); }

Peer& Client::LoginForm::getPeer()
{
	return this->_p;
}

Client::LoginForm::~LoginForm()
{
	if (components)
		delete components;
}

System::Void Client::LoginForm::register_linkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
{
	RegistrationForm^ rf = gcnew RegistrationForm();
	rf->Show();
	this->Hide();
}

System::Void Client::LoginForm::forgotPassword_link_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
{
	ForgotPasswordForm^ fpf = gcnew ForgotPasswordForm();
	fpf->Show();
	this->Hide();
}

System::Void Client::LoginForm::login_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->username_textbox->text == "" || this->password_textbox->text == "")
	{
		MessageBox::Show("Please fill all fields", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// creating login request
	std::string msg = "3&" + msclr::interop::marshal_as<std::string>(this->username_textbox->text) + "&" + msclr::interop::marshal_as<std::string>(this->password_textbox->text);
	send(this->getPeer().getSock(), msg.c_str(), msg.size(), 0);

	// TODO: recieve login response
	// fill here the result of the checking in the db (instead of the false)
	if (false)
	{
		MessageBox::Show("Invalid Details given", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// login successfull, openning the main form:
	int id = 0; // TODO: receive the user's id (username & password are given already) DEAN
	User u(id, msclr::interop::marshal_as<std::string>(this->username_textbox->text), msclr::interop::marshal_as<std::string>(this->password_textbox->text));
	MainForm^ mf = gcnew MainForm(u);
	mf->Show();
	this->Hide();
}

System::Void Client::LoginForm::OnFormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	exit(0);
}
