#include "User.h"

User::User(std::string username, std::string password, std::string email) : _username(username), _password(password), _email(email) {}

std::string User::getUsername() const { return this->_username; }

std::string User::getPassword() const { return this->_password; }

std::string User::getEmail() const { return this->_email; }
