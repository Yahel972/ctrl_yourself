#pragma once

#include "LoginForm.h"
#include "ResetPasswordForm.h"
#include <string>
#include "CodeSender.h"

namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class ForgotPasswordForm : public System::Windows::Forms::Form
	{
	public:
		ForgotPasswordForm();

	protected:
		~ForgotPasswordForm();

	private: 
		System::Windows::Forms::Panel^ panel;
		System::Windows::Forms::Label^ code_label;
		System::Windows::Forms::Label^ label1;
		Bunifu::Framework::UI::BunifuTextbox^ code_textbox;
		System::Windows::Forms::LinkLabel^ forgotPassword_link;
		Bunifu::Framework::UI::BunifuThinButton2^ button;
		Bunifu::Framework::UI::BunifuTextbox^ username_textbox;
		System::Windows::Forms::Label^ topic;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::LinkLabel^ login_link;
		System::Windows::Forms::Label^ status_label;
		System::ComponentModel::Container^ components;
		int* _code;

		System::Void button_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void login_link_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
		System::Void OnFormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
		static bool isNumber(String^ s);

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ForgotPasswordForm::typeid));
			this->panel = (gcnew System::Windows::Forms::Panel());
			this->status_label = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->login_link = (gcnew System::Windows::Forms::LinkLabel());
			this->code_label = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->code_textbox = (gcnew Bunifu::Framework::UI::BunifuTextbox());
			this->forgotPassword_link = (gcnew System::Windows::Forms::LinkLabel());
			this->button = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
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
			this->panel->Controls->Add(this->status_label);
			this->panel->Controls->Add(this->label3);
			this->panel->Controls->Add(this->login_link);
			this->panel->Controls->Add(this->code_label);
			this->panel->Controls->Add(this->label1);
			this->panel->Controls->Add(this->code_textbox);
			this->panel->Controls->Add(this->forgotPassword_link);
			this->panel->Controls->Add(this->button);
			this->panel->Controls->Add(this->username_textbox);
			this->panel->Controls->Add(this->topic);
			this->panel->Location = System::Drawing::Point(296, 35);
			this->panel->Name = L"panel";
			this->panel->Size = System::Drawing::Size(300, 450);
			this->panel->TabIndex = 2;
			// 
			// status_label
			// 
			this->status_label->AutoSize = true;
			this->status_label->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->status_label->ForeColor = System::Drawing::Color::Lime;
			this->status_label->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->status_label->Location = System::Drawing::Point(25, 278);
			this->status_label->Name = L"status_label";
			this->status_label->Size = System::Drawing::Size(249, 23);
			this->status_label->TabIndex = 13;
			this->status_label->Text = L"sent to: yahelbareket@gmail.com";
			this->status_label->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label3->Location = System::Drawing::Point(31, 383);
			this->label3->Margin = System::Windows::Forms::Padding(0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(196, 23);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Already have an account\?";
			// 
			// login_link
			// 
			this->login_link->AutoSize = true;
			this->login_link->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12));
			this->login_link->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->login_link->LinkColor = System::Drawing::Color::Blue;
			this->login_link->Location = System::Drawing::Point(222, 383);
			this->login_link->Name = L"login_link";
			this->login_link->Size = System::Drawing::Size(48, 23);
			this->login_link->TabIndex = 11;
			this->login_link->TabStop = true;
			this->login_link->Text = L"Login";
			this->login_link->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &ForgotPasswordForm::login_link_LinkClicked);
			// 
			// code_label
			// 
			this->code_label->AutoSize = true;
			this->code_label->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12));
			this->code_label->ForeColor = System::Drawing::Color::White;
			this->code_label->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->code_label->Location = System::Drawing::Point(227, 190);
			this->code_label->Name = L"code_label";
			this->code_label->Size = System::Drawing::Size(43, 23);
			this->code_label->TabIndex = 10;
			this->code_label->Text = L"code";
			this->code_label->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label1->Location = System::Drawing::Point(194, 97);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(76, 23);
			this->label1->TabIndex = 9;
			this->label1->Text = L"username";
			// 
			// code_textbox
			// 
			this->code_textbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->code_textbox->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"code_textbox.BackgroundImage")));
			this->code_textbox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->code_textbox->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F));
			this->code_textbox->ForeColor = System::Drawing::Color::MintCream;
			this->code_textbox->Icon = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"code_textbox.Icon")));
			this->code_textbox->Location = System::Drawing::Point(25, 213);
			this->code_textbox->Margin = System::Windows::Forms::Padding(0);
			this->code_textbox->Name = L"code_textbox";
			this->code_textbox->Size = System::Drawing::Size(250, 50);
			this->code_textbox->TabIndex = 7;
			this->code_textbox->text = L"";
			this->code_textbox->Visible = false;
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
			// button
			// 
			this->button->ActiveBorderThickness = 1;
			this->button->ActiveCornerRadius = 20;
			this->button->ActiveFillColor = System::Drawing::Color::White;
			this->button->ActiveForecolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button->ActiveLineColor = System::Drawing::Color::White;
			this->button->BackColor = System::Drawing::Color::Transparent;
			this->button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button.BackgroundImage")));
			this->button->ButtonText = L"Send Code";
			this->button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12));
			this->button->ForeColor = System::Drawing::Color::MintCream;
			this->button->IdleBorderThickness = 1;
			this->button->IdleCornerRadius = 20;
			this->button->IdleFillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button->IdleForecolor = System::Drawing::Color::White;
			this->button->IdleLineColor = System::Drawing::Color::White;
			this->button->Location = System::Drawing::Point(60, 326);
			this->button->Margin = System::Windows::Forms::Padding(5);
			this->button->Name = L"button";
			this->button->Size = System::Drawing::Size(180, 49);
			this->button->TabIndex = 3;
			this->button->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->button->Click += gcnew System::EventHandler(this, &ForgotPasswordForm::button_Click);
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
			this->username_textbox->Location = System::Drawing::Point(25, 120);
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
			this->topic->Location = System::Drawing::Point(-2, 20);
			this->topic->Name = L"topic";
			this->topic->Size = System::Drawing::Size(306, 52);
			this->topic->TabIndex = 0;
			this->topic->Text = L"Forgot Password";
			// 
			// ForgotPasswordForm
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
			this->Name = L"ForgotPasswordForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Forgot Password";
			this->panel->ResumeLayout(false);
			this->panel->PerformLayout();
			this->ResumeLayout(false);

			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &ForgotPasswordForm::OnFormClosing);
		}
#pragma endregion
};
}
