#include "ForgotPasswordForm.h"

Client::ForgotPasswordForm::~ForgotPasswordForm()
{
	if (components)
		delete components;
}

System::Void Client::ForgotPasswordForm::button_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->button->ButtonText == "Send Code")
	{
		// TODO: Send an email to the user - generate a code and send it to him

		// after all good (email sent):
		String^ email = "a@gmail.com"; // TODO: extract the email

		this->code_label->Visible = true;
		this->code_textbox->Visible = true;
		this->status_label->Visible = true;
		this->status_label->Text = "sent to: " + email;

		this->button->ButtonText = "Validate Code";
	}
	else
	{
		// TODO: validate the code given
		// NEEDED ANOTHER DATABASE

		// if code matches open a reset password form and PARSE THE USER!
		if (true)  // change the statement
		{
			/*User u("", "");
			ResetPasswordForm rpf(u);
			this->Close();
			rpf.Show();*/
		}
		else
		{
			// messageBox
		}
	}
}

System::Void Client::ForgotPasswordForm::login_link_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
{
	LoginForm^ f = gcnew LoginForm();
	f->Show();
	this->Hide();
}
