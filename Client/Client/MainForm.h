#pragma once

#include "LoginForm.h"
#include "User.h"

namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(User u);

	protected:
		~MainForm();

	private:
		System::ComponentModel::Container ^components;
		System::Windows::Forms::Panel^ panel;
		System::Windows::Forms::ListView^ friends_list;
	private: Bunifu::Framework::UI::BunifuThinButton2^ invite_button;

		System::Windows::Forms::Label^ register_label;
		System::Windows::Forms::Label^ topic;
	private: System::Windows::Forms::Button^ logout_button;
	private: System::Windows::Forms::Button^ add_friend_button;


	private: System::Windows::Forms::Button^ notifications_button;

		Bunifu::Framework::UI::BunifuThinButton2^ new_message_alert;
	private: System::Windows::Forms::Panel^ panel1;
	private: Bunifu::Framework::UI::BunifuTextbox^ username_textbox;
		   User* _user;  // logged in user

		System::Void logout_button_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void OnFormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->panel = (gcnew System::Windows::Forms::Panel());
			this->new_message_alert = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->add_friend_button = (gcnew System::Windows::Forms::Button());
			this->notifications_button = (gcnew System::Windows::Forms::Button());
			this->logout_button = (gcnew System::Windows::Forms::Button());
			this->topic = (gcnew System::Windows::Forms::Label());
			this->register_label = (gcnew System::Windows::Forms::Label());
			this->invite_button = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->friends_list = (gcnew System::Windows::Forms::ListView());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->username_textbox = (gcnew Bunifu::Framework::UI::BunifuTextbox());
			this->panel->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel
			// 
			this->panel->BackColor = System::Drawing::Color::Transparent;
			this->panel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel.BackgroundImage")));
			this->panel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel->Controls->Add(this->new_message_alert);
			this->panel->Controls->Add(this->add_friend_button);
			this->panel->Controls->Add(this->notifications_button);
			this->panel->Controls->Add(this->logout_button);
			this->panel->Controls->Add(this->topic);
			this->panel->Controls->Add(this->register_label);
			this->panel->Controls->Add(this->invite_button);
			this->panel->Controls->Add(this->friends_list);
			this->panel->Location = System::Drawing::Point(42, 30);
			this->panel->Margin = System::Windows::Forms::Padding(0);
			this->panel->Name = L"panel";
			this->panel->Padding = System::Windows::Forms::Padding(3);
			this->panel->Size = System::Drawing::Size(808, 460);
			this->panel->TabIndex = 3;
			// 
			// new_message_alert
			// 
			this->new_message_alert->ActiveBorderThickness = 1;
			this->new_message_alert->ActiveCornerRadius = 20;
			this->new_message_alert->ActiveFillColor = System::Drawing::Color::White;
			this->new_message_alert->ActiveForecolor = System::Drawing::Color::Red;
			this->new_message_alert->ActiveLineColor = System::Drawing::Color::White;
			this->new_message_alert->BackColor = System::Drawing::Color::Transparent;
			this->new_message_alert->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"new_message_alert.BackgroundImage")));
			this->new_message_alert->ButtonText = L"!";
			this->new_message_alert->Cursor = System::Windows::Forms::Cursors::Hand;
			this->new_message_alert->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->new_message_alert->ForeColor = System::Drawing::Color::MintCream;
			this->new_message_alert->IdleBorderThickness = 1;
			this->new_message_alert->IdleCornerRadius = 20;
			this->new_message_alert->IdleFillColor = System::Drawing::Color::Red;
			this->new_message_alert->IdleForecolor = System::Drawing::Color::White;
			this->new_message_alert->IdleLineColor = System::Drawing::Color::White;
			this->new_message_alert->Location = System::Drawing::Point(709, 0);
			this->new_message_alert->Margin = System::Windows::Forms::Padding(0);
			this->new_message_alert->Name = L"new_message_alert";
			this->new_message_alert->Size = System::Drawing::Size(24, 30);
			this->new_message_alert->TabIndex = 17;
			this->new_message_alert->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// add_friend_button
			// 
			this->add_friend_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"add_friend_button.BackgroundImage")));
			this->add_friend_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->add_friend_button->FlatAppearance->BorderSize = 0;
			this->add_friend_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->add_friend_button->Location = System::Drawing::Point(733, 0);
			this->add_friend_button->Name = L"add_friend_button";
			this->add_friend_button->Size = System::Drawing::Size(75, 75);
			this->add_friend_button->TabIndex = 20;
			this->add_friend_button->UseVisualStyleBackColor = true;
			// 
			// notifications_button
			// 
			this->notifications_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"notifications_button.BackgroundImage")));
			this->notifications_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->notifications_button->FlatAppearance->BorderSize = 0;
			this->notifications_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->notifications_button->ForeColor = System::Drawing::Color::Transparent;
			this->notifications_button->Location = System::Drawing::Point(658, 0);
			this->notifications_button->Name = L"notifications_button";
			this->notifications_button->Size = System::Drawing::Size(75, 75);
			this->notifications_button->TabIndex = 19;
			this->notifications_button->UseVisualStyleBackColor = true;
			// 
			// logout_button
			// 
			this->logout_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logout_button.BackgroundImage")));
			this->logout_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->logout_button->FlatAppearance->BorderSize = 0;
			this->logout_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->logout_button->Location = System::Drawing::Point(0, 0);
			this->logout_button->Name = L"logout_button";
			this->logout_button->Size = System::Drawing::Size(75, 75);
			this->logout_button->TabIndex = 18;
			this->logout_button->UseVisualStyleBackColor = true;
			this->logout_button->Click += gcnew System::EventHandler(this, &MainForm::logout_button_Click);
			// 
			// topic
			// 
			this->topic->AutoSize = true;
			this->topic->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 48, System::Drawing::FontStyle::Italic));
			this->topic->ForeColor = System::Drawing::Color::White;
			this->topic->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->topic->Location = System::Drawing::Point(306, 0);
			this->topic->Name = L"topic";
			this->topic->Size = System::Drawing::Size(197, 89);
			this->topic->TabIndex = 14;
			this->topic->Text = L"Menu";
			// 
			// register_label
			// 
			this->register_label->AutoSize = true;
			this->register_label->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->register_label->ForeColor = System::Drawing::Color::White;
			this->register_label->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->register_label->Location = System::Drawing::Point(366, 100);
			this->register_label->Margin = System::Windows::Forms::Padding(0);
			this->register_label->Name = L"register_label";
			this->register_label->Size = System::Drawing::Size(83, 26);
			this->register_label->TabIndex = 9;
			this->register_label->Text = L"Friends:";
			// 
			// invite_button
			// 
			this->invite_button->ActiveBorderThickness = 1;
			this->invite_button->ActiveCornerRadius = 20;
			this->invite_button->ActiveFillColor = System::Drawing::Color::White;
			this->invite_button->ActiveForecolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->invite_button->ActiveLineColor = System::Drawing::Color::White;
			this->invite_button->BackColor = System::Drawing::Color::Transparent;
			this->invite_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"invite_button.BackgroundImage")));
			this->invite_button->ButtonText = L"Invite";
			this->invite_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->invite_button->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12));
			this->invite_button->ForeColor = System::Drawing::Color::MintCream;
			this->invite_button->IdleBorderThickness = 1;
			this->invite_button->IdleCornerRadius = 20;
			this->invite_button->IdleFillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->invite_button->IdleForecolor = System::Drawing::Color::White;
			this->invite_button->IdleLineColor = System::Drawing::Color::White;
			this->invite_button->Location = System::Drawing::Point(314, 391);
			this->invite_button->Margin = System::Windows::Forms::Padding(0);
			this->invite_button->Name = L"invite_button";
			this->invite_button->Size = System::Drawing::Size(180, 49);
			this->invite_button->TabIndex = 4;
			this->invite_button->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// friends_list
			// 
			this->friends_list->HideSelection = false;
			this->friends_list->Location = System::Drawing::Point(104, 126);
			this->friends_list->Name = L"friends_list";
			this->friends_list->Size = System::Drawing::Size(600, 250);
			this->friends_list->TabIndex = 2;
			this->friends_list->UseCompatibleStateImageBehavior = false;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->username_textbox);
			this->panel1->Location = System::Drawing::Point(658, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(250, 560);
			this->panel1->TabIndex = 4;
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
			this->username_textbox->Location = System::Drawing::Point(26, 69);
			this->username_textbox->Margin = System::Windows::Forms::Padding(0);
			this->username_textbox->Name = L"username_textbox";
			this->username_textbox->Size = System::Drawing::Size(166, 50);
			this->username_textbox->TabIndex = 2;
			this->username_textbox->text = L"";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(892, 521);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Menu";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::OnFormClosing);
			this->panel->ResumeLayout(false);
			this->panel->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: 
	
};
}
