
#include "User.h"
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

// ~~~~~~~~~~ Operators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/** Purpose: OVERLOAD Loads variables from a file stream
 * PRE:  the file stream, the class instance
 * POST: loads variables from stream, returns the stream
 */
ifstream& operator>>(ifstream& stream, User& obj) {
	getline(stream, obj.mName);
	stream >> obj.mUsername >> obj.mPassword;
	string tmp;
	getline(stream, tmp);
	return stream;
}

/** PURPOSE: OVERLOAD Outputs variables to file stream
 */
ofstream& operator<<(ofstream& stream, User& obj) {
	stream << obj.mName << "\n" << obj.mUsername << " " << obj.mPassword;
	return stream;
}

/** PURPOSE: OVERLOAD Outputs variables to console stream
 */
ostream& operator<<( ostream& stream, User& obj) {
	stream << obj.mName + " (" + obj.mUsername << ")";
	return stream;
}
