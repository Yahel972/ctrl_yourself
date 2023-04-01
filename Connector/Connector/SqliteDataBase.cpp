#include "SqliteDataBase.h"

SqliteDataBase::SqliteDataBase() { open(); }

// Function opens (or creates) a database
bool SqliteDataBase::open()
{
	std::string dbFileName = "UsersDB.sqlite";
	char** errorMessage = 0;
	int file_exist = _access(dbFileName.c_str(), 0);
	int res = sqlite3_open(dbFileName.c_str(), &(this->_db));
	if (res != SQLITE_OK) {
		this->_db = nullptr;
		std::cerr << "Failed to open DB" << std::endl;
		return false;
	}

	// creating the users table if not exists
	if (file_exist != 0) {
		const char* sqlStatement = "CREATE TABLE USERS ( \
			USERNAME TEXT NOT NULL, \
			PASSWORD TEXT NOT NULL, \
			EMAIL TEXT NOT NULL, \
			PRIMARY KEY(USERNAME));";
		res = sqlite3_exec(this->_db, sqlStatement, nullptr, nullptr, errorMessage);
		if (res != SQLITE_OK)
		{
			std::cerr << "ERROR: USERS wasn't created" << std::endl;
			return false;
		}
	}
	return true;
}

// Function checks if user exists
bool SqliteDataBase::doesUserExist(std::string user)
{
	char** errMessage = nullptr;
	std::string sqlStatement = "SELECT USERNAME FROM USERS where USERNAME='" + user + "';";
	std::string existingUser = "";
	sqlite3_exec(this->_db, sqlStatement.c_str(), callback_single_string, &existingUser, errMessage);
	return (user == existingUser);
}

// Function checks if a given password match to a user's password
bool SqliteDataBase::doesPasswordMatch(std::string username, std::string passwordToMatch)
{
	char** errMessage = nullptr;
	std::string sqlStatement = "SELECT PASSWORD FROM USERS where USERNAME='" + username + "';";
	std::string existingPassword = "";
	sqlite3_exec(this->_db, sqlStatement.c_str(), callback_single_string, &existingPassword, errMessage);
	return (existingPassword == passwordToMatch);
}


// Function adds a new user
void SqliteDataBase::addNewUser(std::string name, std::string password, std::string email)
{
	char** errMessage = nullptr;
	std::string sqlStatement = "INSERT INTO USERS(USERNAME,PASSWORD,EMAIL) VALUES('" + name + "','" + password + "','" + email + "');";
	sqlite3_exec(this->_db, sqlStatement.c_str(), nullptr, nullptr, errMessage);
}

std::vector<std::string> SqliteDataBase::getUsers()
{
	// TODO: get all of the users
	return std::vector<std::string>();
}

int SqliteDataBase::callback_single_string(void* data, int argc, char** argv, char** azColName)
{
	std::string* user = static_cast<std::string*>(data);
	*user = (std::string)((argv[0]));
	return 0;
}
