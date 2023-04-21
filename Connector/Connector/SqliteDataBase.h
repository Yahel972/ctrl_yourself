#pragma once

#include "sqlite3.h"
#include <iostream>
#include <string>
#include <vector>
#include <io.h>

class SqliteDataBase
{
public:
	SqliteDataBase();

	bool open();
	bool doesUserExist(std::string user);
	bool doesPasswordMatch(std::string username, std::string passwordToMatch);
	void addNewUser(std::string name, std::string password, std::string email);
	std::vector<std::string> getUsers();

	// TODO: implement these functions:
	int getID(std::string username);  // get the username's id (use db)

private:
	sqlite3* _db;

	static int callback_single_string(void* data, int argc, char** argv, char** azColName);
};