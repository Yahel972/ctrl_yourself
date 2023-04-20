#pragma once

#include "User.h"

namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class ResetPasswordForm : public System::Windows::Forms::Form
	{
	public:
		ResetPasswordForm(User u) { InitializeComponent(); }
		// Form must get a User to work on (sets a new password to it)
		// MUST CHECK THAT THE USER IS VALID BEFORE CHANGING IT"S PASSWORD!

	protected:
		~ResetPasswordForm();
			
	private: 
		System::Windows::Forms::Panel^ panel;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Label^ label1;
		Bunifu::Framework::UI::BunifuTextbox^ password_textbox;
		System::Windows::Forms::LinkLabel^ forgotPassword_link;
		Bunifu::Framework::UI::BunifuThinButton2^ login_button;
		Bunifu::Framework::UI::BunifuTextbox^ username_textbox;
		System::Windows::Forms::Label^ topic;
		System::Windows::Forms::Label^ register_label;
		System::Windows::Forms::LinkLabel^ login_link;
		System::ComponentModel::Container^ components;

		System::Void login_link_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
	
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ResetPasswordForm::typeid));
			this->panel = (gcnew System::Windows::Forms::Panel());
			this->register_label = (gcnew System::Windows::Forms::Label());
			this->login_link = (gcnew System::Windows::Forms::LinkLabel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->password_textbox = (gcnew Bunifu::Framework::UI::BunifuTextbox());
			this->forgotPassword_link = (gcnew System::Windows::Forms::LinkLabel());
			this->login_button = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->username_textbox = (gcnew Bunifu::Framework::UI::BunifuTextbox());
			this->topic = (gcnew System::Windows::Forms::Label());
			this->panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel
			// 
			this->panel->BackColor = System::Drawing::Color::Transparent;
			this->panel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel.BackgroundImage")));
			this->panel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel->Controls->Add(this->register_label);
			this->panel->Controls->Add(this->login_link);
			this->panel->Controls->Add(this->label2);
			this->panel->Controls->Add(this->label1);
			this->panel->Controls->Add(this->password_textbox);
			this->panel->Controls->Add(this->forgotPassword_link);
			this->panel->Controls->Add(this->login_button);
			this->panel->Controls->Add(this->username_textbox);
			this->panel->Controls->Add(this->topic);
			this->panel->Location = System::Drawing::Point(296, 35);
			this->panel->Name = L"panel";
			this->panel->Size = System::Drawing::Size(300, 450);
			this->panel->TabIndex = 2;
			// 
			// register_label
			// 
			this->register_label->AutoSize = true;
			this->register_label->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12));
			this->register_label->ForeColor = System::Drawing::Color::White;
			this->register_label->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->register_label->Location = System::Drawing::Point(31, 381);
			this->register_label->Margin = System::Windows::Forms::Padding(0);
			this->register_label->Name = L"register_label";
			this->register_label->Size = System::Drawing::Size(196, 23);
			this->register_label->TabIndex = 12;
			this->register_label->Text = L"Already have an account\?";
			// 
			// login_link
			// 
			this->login_link->AutoSize = true;
			this->login_link->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12));
			this->login_link->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->login_link->LinkColor = System::Drawing::Color::Blue;
			this->login_link->Location = System::Drawing::Point(222, 381);
			this->login_link->Name = L"login_link";
			this->login_link->Size = System::Drawing::Size(48, 23);
			this->login_link->TabIndex = 11;
			this->login_link->TabStop = true;
			this->login_link->Text = L"Login";
			this->login_link->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &ResetPasswordForm::login_link_LinkClicked);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label2->Location = System::Drawing::Point(100, 202);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(170, 23);
			this->label2->TabIndex = 10;
			this->label2->Text = L"confirm new password";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label1->Location = System::Drawing::Point(161, 112);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(109, 23);
			this->label1->TabIndex = 9;
			this->label1->Text = L"new password";
			// 
			// password_textbox
			// 
			this->password_textbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->password_textbox->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"password_textbox.BackgroundImage")));
			this->password_textbox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->password_textbox->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F));
			this->password_textbox->ForeColor = System::Drawing::Color::MintCream;
			this->password_textbox->Icon = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"password_textbox.Icon")));
			this->password_textbox->Location = System::Drawing::Point(25, 225);
			this->password_textbox->Margin = System::Windows::Forms::Padding(0);
			this->password_textbox->Name = L"password_textbox";
			this->password_textbox->Size = System::Drawing::Size(250, 50);
			this->password_textbox->TabIndex = 7;
			this->password_textbox->text = L"";
			// 
			// forgotPassword_link
			// 
			this->forgotPassword_link->AutoSize = true;
			this->forgotPassword_link->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12));
			this->forgotPassword_link->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->forgotPassword_link->LinkColor = System::Drawing::Color::Blue;
			this->forgotPassword_link->Location = System::Drawing::Point(140, 280);
			this->forgotPassword_link->Name = L"forgotPassword_link";
			this->forgotPassword_link->Size = System::Drawing::Size(0, 23);
			this->forgotPassword_link->TabIndex = 4;
			// 
			// login_button
			// 
			this->login_button->ActiveBorderThickness = 1;
			this->login_button->ActiveCornerRadius = 20;
			this->login_button->ActiveFillColor = System::Drawing::Color::White;
			this->login_button->ActiveForecolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->login_button->ActiveLineColor = System::Drawing::Color::White;
			this->login_button->BackColor = System::Drawing::Color::Transparent;
			this->login_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"login_button.BackgroundImage")));
			this->login_button->ButtonText = L"Set Password";
			this->login_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->login_button->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12));
			this->login_button->ForeColor = System::Drawing::Color::MintCream;
			this->login_button->IdleBorderThickness = 1;
			this->login_button->IdleCornerRadius = 20;
			this->login_button->IdleFillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->login_button->IdleForecolor = System::Drawing::Color::White;
			this->login_button->IdleLineColor = System::Drawing::Color::White;
			this->login_button->Location = System::Drawing::Point(60, 330);
			this->login_button->Margin = System::Windows::Forms::Padding(0);
			this->login_button->Name = L"login_button";
			this->login_button->Size = System::Drawing::Size(180, 49);
			this->login_button->TabIndex = 3;
			this->login_button->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// username_textbox
			// 
			this->username_textbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->username_textbox->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"username_textbox.BackgroundImage")));
			this->username_textbox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->username_textbox->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F));
			this->username_textbox->ForeColor = System::Drawing::Color::MintCream;
			this->username_textbox->Icon = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"username_textbox.Icon")));
			this->username_textbox->Location = System::Drawing::Point(25, 135);
			this->username_textbox->Margin = System::Windows::Forms::Padding(0);
			this->username_textbox->Name = L"username_textbox";
			this->username_textbox->Size = System::Drawing::Size(250, 50);
			this->username_textbox->TabIndex = 1;
			this->username_textbox->text = L"";
			// 
			// topic
			// 
			this->topic->AutoSize = true;
			this->topic->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 27.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->topic->ForeColor = System::Drawing::Color::White;
			this->topic->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->topic->Location = System::Drawing::Point(6, 23);
			this->topic->Name = L"topic";
			this->topic->Size = System::Drawing::Size(289, 52);
			this->topic->TabIndex = 0;
			this->topic->Text = L"Reset Password";
			// 
			// ResetPasswordForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(892, 521);
			this->Controls->Add(this->panel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ResetPasswordForm";
			this->Text = L"Reset Password";
			this->panel->ResumeLayout(false);
			this->panel->PerformLayout();
			this->ResumeLayout(false);
		}
#pragma endregion
};
}
