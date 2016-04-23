
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
	getline(stream, obj.mID);
	obj.setIDValue();
	getline(stream, obj.mName);
	getline(stream, obj.mAddress);
	getline(stream, obj.mPhoneNumber);
	return stream;
}

/** Purpose: OVERLOAD Loads variables from a console stream
 * PRE:  the stream, the class instance
 * POST: outputs prompts, loads variables from stream, returns the stream
 */
istream& operator>>(istream& stream, User& obj) {
	
	cout << "Enter name: ";
	getline(stream, obj.mName);
	
	cout << "Enter ID: ";
	getline(stream, obj.mID);
	obj.setIDValue();
	
	cout << "Enter address: ";
	getline(stream, obj.mAddress);
	
	cout << "Enter phone number: ";
	getline(stream, obj.mPhoneNumber);
	
	return stream;
}
