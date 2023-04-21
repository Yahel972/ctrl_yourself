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
		System::Windows::Forms::Panel^ panel;
		System::Windows::Forms::ListView^ friends_list;
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::Button^ button2;
		System::ComponentModel::Container ^components;
		User* _user;  // logged in user

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->panel = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->friends_list = (gcnew System::Windows::Forms::ListView());
			this->panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel
			// 
			this->panel->BackColor = System::Drawing::Color::Transparent;
			this->panel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel.BackgroundImage")));
			this->panel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel->Controls->Add(this->button2);
			this->panel->Controls->Add(this->button1);
			this->panel->Controls->Add(this->friends_list);
			this->panel->Location = System::Drawing::Point(42, 30);
			this->panel->Margin = System::Windows::Forms::Padding(0);
			this->panel->Name = L"panel";
			this->panel->Padding = System::Windows::Forms::Padding(3);
			this->panel->Size = System::Drawing::Size(808, 460);
			this->panel->TabIndex = 3;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::White;
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button2->Location = System::Drawing::Point(646, 0);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(74, 67);
			this->button2->TabIndex = 2;
			this->button2->UseVisualStyleBackColor = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Black;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Location = System::Drawing::Point(726, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(74, 67);
			this->button1->TabIndex = 1;
			this->button1->UseVisualStyleBackColor = false;
			// 
			// friends_list
			// 
			this->friends_list->BackColor = System::Drawing::SystemColors::Info;
			this->friends_list->HideSelection = false;
			this->friends_list->Location = System::Drawing::Point(50, 50);
			this->friends_list->Name = L"friends_list";
			this->friends_list->Size = System::Drawing::Size(200, 360);
			this->friends_list->TabIndex = 0;
			this->friends_list->UseCompatibleStateImageBehavior = false;
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
			this->Text = L"Lobby";
			this->panel->ResumeLayout(false);
			this->ResumeLayout(false);
		}
#pragma endregion
};
}
