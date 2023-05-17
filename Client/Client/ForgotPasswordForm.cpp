#include "ForgotPasswordForm.h"

Client::ForgotPasswordForm::ForgotPasswordForm(Peer& p): _p(p), _code(new int(0)) { InitializeComponent(); }

Peer& Client::ForgotPasswordForm::getPeer()
{
	return this->_p;
}

Client::ForgotPasswordForm::~ForgotPasswordForm()
{
	if (components)
		delete components;
	delete this->_code;
}

bool Client::ForgotPasswordForm::isNumber(String^ s)
{
	std::regex digits_regex("\\d+"); // regex to match one or more digits
	std::string str_std = msclr::interop::marshal_as<std::string>(s); // convert String^ to std::string
	return std::regex_match(str_std, digits_regex);
}

System::Void Client::ForgotPasswordForm::button_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->button->ButtonText == "Send Code")
	{
		if (this->username_textbox->text == "")
		{
			MessageBox::Show("Please fill all fields", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// checking if username exists and receiving email
		std::string msg = "5&" + msclr::interop::marshal_as<std::string>(this->username_textbox->text);
		send(this->getPeer().getSock(), msg.c_str(), msg.size(), 0);

		String^ email = "yahelbareket@gmail.com"; // TODO: extract the email
		if (false)
		{
			MessageBox::Show("Username doesn't exist", "Invalid Username", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		
		*this->_code = CodeSender::sendCode(msclr::interop::marshal_as<std::string>(email), msclr::interop::marshal_as<std::string>(username_textbox->text));

		this->code_label->Visible = true;
		this->code_textbox->Visible = true;
		this->status_label->Visible = true;
		this->username_textbox->Enabled = false;
		this->status_label->Text = "sent to: " + email;
		this->status_label->Location = Point((int)((300 - this->status_label->Size.Width) / 2), this->status_label->Location.Y);
		this->button->ButtonText = "Validate Code";
	}
	else  // == "Validate Code"
	{
		if (!isNumber(this->code_textbox->text))
		{
			MessageBox::Show("Invalid code given", "Invalid Code", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (!(*this->_code == std::stoi(msclr::interop::marshal_as<std::string>(this->code_textbox->text))))
		{
			MessageBox::Show("Incorrect code given", "Incorrect Code", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// code is valid - openning ResetPasswordForm:
		ResetPasswordForm^ rpf = gcnew ResetPasswordForm(_p, msclr::interop::marshal_as<std::string>(this->username_textbox->text));
		rpf->Show();
		this->Hide();
	}
}

System::Void Client::ForgotPasswordForm::login_link_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
{
	LoginForm^ lf = gcnew LoginForm();
	lf->Show();
	this->Hide();
}

System::Void Client::ForgotPasswordForm::OnFormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	exit(0);
}
