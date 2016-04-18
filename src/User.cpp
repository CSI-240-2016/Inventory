
#include "Location.h"

// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

User::User(string name, string username, string password) {
	mName = name;
	mUsername = username;
	mPassword = password;
}

// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

string	User::getName() {
	return mName;
}

string	User::getUserName() {
	return mUsername;
}

string	User::getPassword() {
	return mPassword;
}

// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void	User::setName(string name) {
	mName = name;
}

void	User::setUserName(string username) {
	mUsername = username;
}

void	User::setPassword(string password) {
	mPassword = password;
}
