#include "User.h"

User::User(int id, std::string username, std::string password, std::string email) : _id(id), _username(username), _password(password), _email(email) {}

User::User(const User& other)
{
	this->_id = other._id;
	this->_username = other._username;
	this->_password = other._password;
	this->_email = other._email;
}

int User::getID() const { return this->_id; }

std::string User::getUsername() const { return this->_username; }

std::string User::getPassword() const { return this->_password; }

std::string User::getEmail() const { return this->_email; }
