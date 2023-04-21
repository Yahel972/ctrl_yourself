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

	// TODO: send a message to the connector, including the name & password
	// check if details are correct and receive a response
	// DEAN
	
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
