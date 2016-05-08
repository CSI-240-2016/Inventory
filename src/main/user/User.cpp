/*
    Created by Dustin Yost on 4/30/2016.
*/

#include "User.h"
#include <iostream>

// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* PURPOSE: Create a User object with default values
 * PRE:  None
 * POST: A User object with default values
*/
User::User() {
	mName = mUsername = mPassword = "";
}

/* PURPOSE: Create an User object with specific values
 * PRE:  The name (String), The username (String), The password (String)
 * POST: An User object with specified values
*/
User::User(string name, string username, string password) {
	mName = name;
	mUsername = username;
	mPassword = password;
}

// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* PURPOSE: Retrieve the name
 * PRE:  None
 * POST: The name (String)
*/
string	User::getName() {
	return mName;
}

/* PURPOSE: Retrieve the username
 * PRE:  None
 * POST: The username (String)
*/
string	User::getUsername() {
	return mUsername;
}

/* PURPOSE: Retrieve the password
 * PRE:  None
 * POST: The password (String)
*/
string	User::getPassword() {
	return mPassword;
}

// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* PURPOSE: Update the name
 * PRE:  The name (String)
 * POST: The value is changed to the parameter
*/
void	User::setName(string s) {
	mName = s;
}

/* PURPOSE: Update the username
 * PRE:  The username (String)
 * POST: The value is changed to the parameter
*/
void	User::setUsername(string s) {
	mUsername = s;
}

/* PURPOSE: Update the password
 * PRE:  The password (String)
 * POST: The value is changed to the parameter
*/
void	User::setPassword(string s) {
	mPassword = s;
}

// ~~~~~~~~~~ Operators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* PURPOSE: Tries to read the serial from the file stream
		 * PRE:  The file stream
		 * POST: if the serial could be read
		 */
bool	User::readUsername(ifstream& stream) {
	// "User:mName"
	return !getline(stream, mName).eof();
}

/** PURPOSE: OVERLOAD Inputs variables from the file stream to object
 * PRE:  The file stream (fstream), The obj (User)
 * POST: Reads data from the file stream
 */
ifstream& operator>>(ifstream& stream, User& obj) {

	// "User:mName" -> readUsername

	// "User:mUsername User:mPassword"
	stream >> obj.mUsername >> obj.mPassword;

	string junk;
	getline(stream, junk);

	return stream;
}

/** PURPOSE: OVERLOAD Inputs variables from the stream to object
 * PRE:  The stream (istream), The obj (User)
 * POST: Reads data from the stream
 */
istream& operator>>(istream& stream, User& obj) {

	string junk;

	// "User:mName"
	cout << "Enter User Name: ";
	getline(stream, obj.mName);

	// "User:mUsername User:mPassword"
	cout << "Enter User Password: ";
	stream >> obj.mPassword;
	getline(stream, junk);

	return stream;
}

/** PURPOSE: OVERLOAD Outputs variables from object to the file stream
 * PRE:  The file stream (fstream), The obj (User)
 * POST: Reads data from the file stream
 */
ofstream& operator<<(ofstream& stream, const User obj) {
	stream
		// "User:mName"
		<< obj.mName << '\n'
		// "User:mUsername User:mPassword"
		<< obj.mUsername << ' ' << obj.mPassword
	;
	return stream;
}

/** PURPOSE: OVERLOAD Outputs variables from object to the console
 * PRE:  The file stream (fstream), The obj (User)
 * POST: Reads data from the file stream
 */
ostream& operator<<( ostream& stream, const User obj) {
	stream << obj.mName + " (" + obj.mUsername << ")";
	return stream;
}
