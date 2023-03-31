#pragma once

namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ topic;

	private: Bunifu::Framework::UI::BunifuThinButton2^ login_button;




	private: System::Windows::Forms::LinkLabel^ forgotPassword_link;
	private: System::Windows::Forms::LinkLabel^ register_link;




	private: Bunifu::Framework::UI::BunifuTextbox^ bunifuTextbox3;
	private: System::Windows::Forms::Label^ label2;
	private: Bunifu::Framework::UI::BunifuTextbox^ password_textbox;
	private: Bunifu::Framework::UI::BunifuTextbox^ username_textbox;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->password_textbox = (gcnew Bunifu::Framework::UI::BunifuTextbox());
			this->bunifuTextbox3 = (gcnew Bunifu::Framework::UI::BunifuTextbox());
			this->register_link = (gcnew System::Windows::Forms::LinkLabel());
			this->forgotPassword_link = (gcnew System::Windows::Forms::LinkLabel());
			this->login_button = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->username_textbox = (gcnew Bunifu::Framework::UI::BunifuTextbox());
			this->topic = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			resources->ApplyResources(this->panel1, L"panel1");
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->password_textbox);
			this->panel1->Controls->Add(this->bunifuTextbox3);
			this->panel1->Controls->Add(this->register_link);
			this->panel1->Controls->Add(this->forgotPassword_link);
			this->panel1->Controls->Add(this->login_button);
			this->panel1->Controls->Add(this->username_textbox);
			this->panel1->Controls->Add(this->topic);
			this->panel1->Name = L"panel1";
			// 
			// label2
			// 
			resources->ApplyResources(this->label2, L"label2");
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Name = L"label2";
			this->label2->Click += gcnew System::EventHandler(this, &LoginForm::label2_Click);
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
			// bunifuTextbox3
			// 
			resources->ApplyResources(this->bunifuTextbox3, L"bunifuTextbox3");
			this->bunifuTextbox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->bunifuTextbox3->ForeColor = System::Drawing::Color::MintCream;
			this->bunifuTextbox3->Icon = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTextbox3.Icon")));
			this->bunifuTextbox3->Name = L"bunifuTextbox3";
			this->bunifuTextbox3->text = L"Username";
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
			this->ControlBox = false;
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"LoginForm";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
