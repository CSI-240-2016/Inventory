
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
	
	return stream;
}

/** Purpose: OVERLOAD Loads variables from a console stream
 * PRE:  the stream, the class instance
 * POST: outputs prompts, loads variables from stream, returns the stream
 */
istream& operator>>(istream& stream, User& obj) {
	
	return stream;
}

/** PURPOSE: OVERLOAD Outputs variables to file stream
 */
ofstream& operator<<(ofstream& stream, User& obj) {
	
	return stream;
}

/** PURPOSE: OVERLOAD Outputs variables to console stream
 */
ostream& operator<<( ostream& stream, User& obj) {
	
	return stream;
}
