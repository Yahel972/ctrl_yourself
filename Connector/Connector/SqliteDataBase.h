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

	bool open(); // for creating the database
	bool doesUserExist(std::string user);
	bool doesPasswordMatch(std::string username, std::string passwordToMatch);
	void addNewUser(std::string name, std::string password, std::string email);
	std::vector<std::string> getUsers();

private:
	sqlite3* _db;

	static int callback_single_string(void* data, int argc, char** argv, char** azColName);
};