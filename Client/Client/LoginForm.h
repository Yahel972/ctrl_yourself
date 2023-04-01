#pragma once

namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm() { InitializeComponent(); }

	protected:
		~LoginForm() {
			if (components)
				delete components;
		}

	private:
		System::Windows::Forms::Panel^ panel;
		System::Windows::Forms::Label^ topic;
		Bunifu::Framework::UI::BunifuTextbox^ username_textbox;
		Bunifu::Framework::UI::BunifuTextbox^ password_textbox;
		System::Windows::Forms::LinkLabel^ forgotPassword_link;
		Bunifu::Framework::UI::BunifuThinButton2^ login_button;
		System::Windows::Forms::Label^ register_label;
		System::Windows::Forms::LinkLabel^ register_link;

		System::ComponentModel::Container^ components;
		

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->panel = (gcnew System::Windows::Forms::Panel());
			this->register_label = (gcnew System::Windows::Forms::Label());
			this->password_textbox = (gcnew Bunifu::Framework::UI::BunifuTextbox());
			this->register_link = (gcnew System::Windows::Forms::LinkLabel());
			this->forgotPassword_link = (gcnew System::Windows::Forms::LinkLabel());
			this->login_button = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->username_textbox = (gcnew Bunifu::Framework::UI::BunifuTextbox());
			this->topic = (gcnew System::Windows::Forms::Label());
			this->panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel
			// 
			resources->ApplyResources(this->panel, L"panel");
			this->panel->BackColor = System::Drawing::Color::Transparent;
			this->panel->Controls->Add(this->register_label);
			this->panel->Controls->Add(this->password_textbox);
			this->panel->Controls->Add(this->register_link);
			this->panel->Controls->Add(this->forgotPassword_link);
			this->panel->Controls->Add(this->login_button);
			this->panel->Controls->Add(this->username_textbox);
			this->panel->Controls->Add(this->topic);
			this->panel->Name = L"panel";
			// 
			// register_label
			// 
			resources->ApplyResources(this->register_label, L"register_label");
			this->register_label->ForeColor = System::Drawing::Color::White;
			this->register_label->Name = L"register_label";
			// 
			// password_textbox
			// 
			resources->ApplyResources(this->password_textbox, L"password_textbox");
			this->password_textbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->password_textbox->ForeColor = System::Drawing::Color::MintCream;
			this->password_textbox->Icon = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"password_textbox.Icon")));
			this->password_textbox->Name = L"password_textbox";
			this->password_textbox->text = L"";
			// 
			// register_link
			// 
			resources->ApplyResources(this->register_link, L"register_link");
			this->register_link->LinkColor = System::Drawing::Color::Blue;
			this->register_link->Name = L"register_link";
			this->register_link->TabStop = true;
			// 
			// forgotPassword_link
			// 
			resources->ApplyResources(this->forgotPassword_link, L"forgotPassword_link");
			this->forgotPassword_link->LinkColor = System::Drawing::Color::Blue;
			this->forgotPassword_link->Name = L"forgotPassword_link";
			this->forgotPassword_link->TabStop = true;
			// 
			// login_button
			// 
			resources->ApplyResources(this->login_button, L"login_button");
			this->login_button->ActiveBorderThickness = 1;
			this->login_button->ActiveCornerRadius = 20;
			this->login_button->ActiveFillColor = System::Drawing::Color::White;
			this->login_button->ActiveForecolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->login_button->ActiveLineColor = System::Drawing::Color::White;
			this->login_button->BackColor = System::Drawing::Color::Transparent;
			this->login_button->ButtonText = L"Log in";
			this->login_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->login_button->ForeColor = System::Drawing::Color::MintCream;
			this->login_button->IdleBorderThickness = 1;
			this->login_button->IdleCornerRadius = 20;
			this->login_button->IdleFillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->login_button->IdleForecolor = System::Drawing::Color::White;
			this->login_button->IdleLineColor = System::Drawing::Color::White;
			this->login_button->Name = L"login_button";
			this->login_button->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->login_button->Click += gcnew System::EventHandler(this, &LoginForm::login_button_Click);
			// 
			// username_textbox
			// 
			resources->ApplyResources(this->username_textbox, L"username_textbox");
			this->username_textbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->username_textbox->ForeColor = System::Drawing::Color::MintCream;
			this->username_textbox->Icon = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"username_textbox.Icon")));
			this->username_textbox->Name = L"username_textbox";
			this->username_textbox->text = L"";
			// 
			// topic
			// 
			resources->ApplyResources(this->topic, L"topic");
			this->topic->ForeColor = System::Drawing::Color::White;
			this->topic->Name = L"topic";
			// 
			// LoginForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->panel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"LoginForm";
			this->panel->ResumeLayout(false);
			this->panel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: 
		System::Void login_button_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			String^ username = this->username_textbox->text;
			String^ password = this->password_textbox->text;

			if (username == "" || password == "")
			{
				// TODO: post error msg
				return;
			}

			// TODO: send login request to the connector
			// then receive answer and reply as matched
			if (true)
			{
				// logged in successfully
			}
			else
			{
				// TODO: post error msg (username & password doesnt match)
			}
		}
};
}
