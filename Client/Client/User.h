#pragma once

#include <string>

class User
{
public:
	User(int id, std::string username, std::string password, std::string email="");
	User(const User& other);

	int getID() const;
	std::string getUsername() const;
	std::string getPassword() const;
	std::string getEmail() const;

	// TODO: add helper functions for the class

private:
	int _id;
	std::string _username;
	std::string _password;
	std::string _email;
};

