#pragma once

namespace Client
{
	class Global
	{
	public:
		static int dir;
	};
}

//#pragma once
//
//#include "User.h"
//#include "LoginForm.h"
//#include "RegistrationForm.h"
//#include "ForgotPasswordForm.h"
//#include "ResetPasswordForm.h"
//
//#define LOGIN_FORM "login_form"
//#define REGISTRATION_FORM "registration_form"
//#define FORGOT_PASSWORD_FORM "forgot_password_form"
//#define RESET_PASSWORD_FORM "reset_password_form"
//
//namespace Client
//{
//	class Global
//	{
//	public:
//		static void initMembers();
//		static std::string getCurrentForm();
//		static User getCurrentUser();
//		static void setCurrentForm(std::string form_name);
//
//		static void formChanged();
//		static void formStable();
//		static bool getFormState();
//
//	private:
//		static std::string current_form;
//		static User current_user;
//		static bool is_form_changed;
//	};
//
//	ref class GlobalForms
//	{
//	public:
//		static void initForms();
//
//		static void hideForm(Form^ f);
//		static void showForm(Form^ f);
//		static void toogleFormVisibility(Form^ f);
//
//	public:
//		static LoginForm^ login_form;
//		static RegistrationForm^ registration_form;
//		static ForgotPasswordForm^ forgot_password_form;
//		static ResetPasswordForm^ reset_password_form;
//	};
//}