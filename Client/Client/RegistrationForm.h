#pragma once

#include "LoginForm.h"
#include <regex>

namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class RegistrationForm : public System::Windows::Forms::Form
	{
	public:
		RegistrationForm();

	protected:
		~RegistrationForm();

	private:
		System::Windows::Forms::Panel^ panel;
		Bunifu::Framework::UI::BunifuTextbox^ email_textbox;
		System::Windows::Forms::Label^ login_label;
		Bunifu::Framework::UI::BunifuTextbox^ password_textbox;
		System::Windows::Forms::LinkLabel^ login_link;
		Bunifu::Framework::UI::BunifuThinButton2^ registration_button;
		Bunifu::Framework::UI::BunifuTextbox^ username_textbox;
		System::Windows::Forms::Label^ topic;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Label^ label3;
		System::ComponentModel::Container^ components;

		System::Void login_link_clicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
		System::Void registration_button_Click(System::Object^ sender, System::EventArgs^ e);
		static bool isEmail(const std::string& s);

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RegistrationForm::typeid));
			this->panel = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->email_textbox = (gcnew Bunifu::Framework::UI::BunifuTextbox());
			this->login_label = (gcnew System::Windows::Forms::Label());
			this->password_textbox = (gcnew Bunifu::Framework::UI::BunifuTextbox());
			this->login_link = (gcnew System::Windows::Forms::LinkLabel());
			this->registration_button = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->username_textbox = (gcnew Bunifu::Framework::UI::BunifuTextbox());
			this->topic = (gcnew System::Windows::Forms::Label());
			this->panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel
			// 
			this->panel->BackColor = System::Drawing::Color::Transparent;
			resources->ApplyResources(this->panel, L"panel");
			this->panel->Controls->Add(this->label3);
			this->panel->Controls->Add(this->label2);
			this->panel->Controls->Add(this->label1);
			this->panel->Controls->Add(this->email_textbox);
			this->panel->Controls->Add(this->login_label);
			this->panel->Controls->Add(this->password_textbox);
			this->panel->Controls->Add(this->login_link);
			this->panel->Controls->Add(this->registration_button);
			this->panel->Controls->Add(this->username_textbox);
			this->panel->Controls->Add(this->topic);
			this->panel->Name = L"panel";
			// 
			// label3
			// 
			resources->ApplyResources(this->label3, L"label3");
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Name = L"label3";
			// 
			// label2
			// 
			resources->ApplyResources(this->label2, L"label2");
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Name = L"label2";
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Name = L"label1";
			// 
			// email_textbox
			// 
			this->email_textbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			resources->ApplyResources(this->email_textbox, L"email_textbox");
			this->email_textbox->ForeColor = System::Drawing::Color::MintCream;
			this->email_textbox->Icon = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"email_textbox.Icon")));
			this->email_textbox->Name = L"email_textbox";
			this->email_textbox->text = L"";
			// 
			// login_label
			// 
			resources->ApplyResources(this->login_label, L"login_label");
			this->login_label->ForeColor = System::Drawing::Color::White;
			this->login_label->Name = L"login_label";
			// 
			// password_textbox
			// 
			this->password_textbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			resources->ApplyResources(this->password_textbox, L"password_textbox");
			this->password_textbox->ForeColor = System::Drawing::Color::MintCream;
			this->password_textbox->Icon = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"password_textbox.Icon")));
			this->password_textbox->Name = L"password_textbox";
			this->password_textbox->text = L"";
			// 
			// login_link
			// 
			resources->ApplyResources(this->login_link, L"login_link");
			this->login_link->LinkColor = System::Drawing::Color::Blue;
			this->login_link->Name = L"login_link";
			this->login_link->TabStop = true;
			this->login_link->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &RegistrationForm::login_link_clicked);
			// 
			// registration_button
			// 
			this->registration_button->ActiveBorderThickness = 1;
			this->registration_button->ActiveCornerRadius = 20;
			this->registration_button->ActiveFillColor = System::Drawing::Color::White;
			this->registration_button->ActiveForecolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->registration_button->ActiveLineColor = System::Drawing::Color::White;
			this->registration_button->BackColor = System::Drawing::Color::Transparent;
			resources->ApplyResources(this->registration_button, L"registration_button");
			this->registration_button->ButtonText = L"Register";
			this->registration_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->registration_button->ForeColor = System::Drawing::Color::MintCream;
			this->registration_button->IdleBorderThickness = 1;
			this->registration_button->IdleCornerRadius = 20;
			this->registration_button->IdleFillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->registration_button->IdleForecolor = System::Drawing::Color::White;
			this->registration_button->IdleLineColor = System::Drawing::Color::White;
			this->registration_button->Name = L"registration_button";
			this->registration_button->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->registration_button->Click += gcnew System::EventHandler(this, &RegistrationForm::registration_button_Click);
			// 
			// username_textbox
			// 
			this->username_textbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			resources->ApplyResources(this->username_textbox, L"username_textbox");
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
			// RegistrationForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->panel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"RegistrationForm";
			this->panel->ResumeLayout(false);
			this->panel->PerformLayout();
			this->ResumeLayout(false);
		}
#pragma endregion
};
}
