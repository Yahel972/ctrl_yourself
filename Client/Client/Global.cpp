//#include "Global.h"
//
//// Global:
//std::string Client::Global::current_form;
//User Client::Global::current_user = User("", "");
//bool Client::Global::is_form_changed = false;
//
//void Client::Global::initMembers()
//{
//	Global::current_form = "login_form";
//	Global::current_user = User("", "");
//	Global::is_form_changed = false;
//}
//std::string Client::Global::getCurrentForm() { return Global::current_form; }
//User Client::Global::getCurrentUser() { return Global::current_user; }
//
//void Client::Global::setCurrentForm(std::string form_name) { Global::current_form = form_name; }
//
//void Client::Global::formChanged() { Global::is_form_changed = true; }
//void Client::Global::formStable() { Global::is_form_changed = false; }
//bool Client::Global::getFormState() { return Global::is_form_changed; }
//
//// GlobalForms:
//void Client::GlobalForms::initForms()
//{
//	GlobalForms::login_form = gcnew LoginForm();
//	GlobalForms::registration_form = gcnew RegistrationForm();
//	GlobalForms::forgot_password_form = gcnew ForgotPasswordForm();
//	GlobalForms::reset_password_form = gcnew ResetPasswordForm(Global::getCurrentUser());
//
//	GlobalForms::login_form->Show();
//}
//
//void Client::GlobalForms::hideForm(Form^ f) { f->Hide(); }
//void Client::GlobalForms::showForm(Form^ f) { f->Show(); }
//void Client::GlobalForms::toogleFormVisibility(Form^ f)
//{
//	if (f->Visible)
//		f->Hide();
//	else
//		f->Show();
//}
