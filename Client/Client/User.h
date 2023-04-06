#pragma once

#include <string>

class User
{
public:
	User(std::string username, std::string password, std::string email="");

	std::string getUsername() const;
	std::string getPassword() const;
	std::string getEmail() const;

	// TODO: add helper functions for the class

private:
	std::string _username;
	std::string _password;
	std::string _email;
};

