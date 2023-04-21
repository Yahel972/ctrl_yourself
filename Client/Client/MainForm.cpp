#include "MainForm.h"

Client::MainForm::MainForm(User u): _user(new User(u)) { InitializeComponent(); }

Client::MainForm::~MainForm()
{
	if (components)
		delete components;
	delete this->_user;
}
