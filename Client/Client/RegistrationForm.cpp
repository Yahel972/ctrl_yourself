#include "RegistrationForm.h"

Client::RegistrationForm::RegistrationForm(Peer& p): _p(p) { InitializeComponent(); }

Peer& Client::RegistrationForm::getPeer()
{
	return this->_p;
}

Client::RegistrationForm::~RegistrationForm()
{
	if (components)
		delete components;
}

bool Client::RegistrationForm::isEmail(const std::string& s)
{
	std::regex pattern("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}");
	return std::regex_match(s, pattern);
}

System::Void Client::RegistrationForm::registration_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->username_textbox->text == "" || this->password_textbox->text == "" || this->email_textbox->text == "")
	{
		MessageBox::Show("Please fill all fields", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	if (!(isEmail(msclr::interop::marshal_as<std::string>(this->email_textbox->text))))
	{
		MessageBox::Show("Please enter a valid email address", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// creating login request
	std::string msg = "4&" + msclr::interop::marshal_as<std::string>(this->username_textbox->text) + "&" + msclr::interop::marshal_as<std::string>(this->password_textbox->text) + "&" + msclr::interop::marshal_as<std::string>(this->email_textbox->text);
	send(this->getPeer().getSock(), msg.c_str(), msg.size(), 0);

	MessageBox::Show("User registered successfully!", "Registration Complete", MessageBoxButtons::OK, MessageBoxIcon::Information);
	login_link_clicked(nullptr, nullptr);
}

System::Void Client::RegistrationForm::OnFormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	exit(0);
}

System::Void Client::RegistrationForm::login_link_clicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
{
	LoginForm^ lf = gcnew LoginForm();
	lf->Show();
	this->Hide();
}
