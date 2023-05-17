#pragma once

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
	private: System::Windows::Forms::Panel^ panel;

	private: System::Windows::Forms::ListView^ friends_list;


	private: Bunifu::Framework::UI::BunifuThinButton2^ login_button;
	private: System::Windows::Forms::Label^ register_label;



	private: System::Windows::Forms::Label^ topic;


	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button2;
	private: Bunifu::Framework::UI::BunifuThinButton2^ new_message_alert;


		   User* _user;  // logged in user

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->panel = (gcnew System::Windows::Forms::Panel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->topic = (gcnew System::Windows::Forms::Label());
			this->register_label = (gcnew System::Windows::Forms::Label());
			this->login_button = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->friends_list = (gcnew System::Windows::Forms::ListView());
			this->new_message_alert = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel
			// 
			this->panel->BackColor = System::Drawing::Color::Transparent;
			this->panel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel.BackgroundImage")));
			this->panel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel->Controls->Add(this->new_message_alert);
			this->panel->Controls->Add(this->button5);
			this->panel->Controls->Add(this->button2);
			this->panel->Controls->Add(this->button4);
			this->panel->Controls->Add(this->topic);
			this->panel->Controls->Add(this->register_label);
			this->panel->Controls->Add(this->login_button);
			this->panel->Controls->Add(this->friends_list);
			this->panel->Location = System::Drawing::Point(42, 30);
			this->panel->Margin = System::Windows::Forms::Padding(0);
			this->panel->Name = L"panel";
			this->panel->Padding = System::Windows::Forms::Padding(3);
			this->panel->Size = System::Drawing::Size(808, 460);
			this->panel->TabIndex = 3;
			// 
			// button5
			// 
			this->button5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.BackgroundImage")));
			this->button5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Location = System::Drawing::Point(733, 0);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 75);
			this->button5->TabIndex = 20;
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->ForeColor = System::Drawing::Color::Transparent;
			this->button2->Location = System::Drawing::Point(658, 0);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 75);
			this->button2->TabIndex = 19;
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Location = System::Drawing::Point(0, 0);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 75);
			this->button4->TabIndex = 18;
			this->button4->UseVisualStyleBackColor = true;
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
			this->login_button->ButtonText = L"Invite";
			this->login_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->login_button->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12));
			this->login_button->ForeColor = System::Drawing::Color::MintCream;
			this->login_button->IdleBorderThickness = 1;
			this->login_button->IdleCornerRadius = 20;
			this->login_button->IdleFillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->login_button->IdleForecolor = System::Drawing::Color::White;
			this->login_button->IdleLineColor = System::Drawing::Color::White;
			this->login_button->Location = System::Drawing::Point(314, 391);
			this->login_button->Margin = System::Windows::Forms::Padding(0);
			this->login_button->Name = L"login_button";
			this->login_button->Size = System::Drawing::Size(180, 49);
			this->login_button->TabIndex = 4;
			this->login_button->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
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
			// MainForm
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
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Menu";
			this->panel->ResumeLayout(false);
			this->panel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
};
}
