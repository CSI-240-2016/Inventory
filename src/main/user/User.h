/*
    Created by Dustin Yost on 4/30/2016.
*/

#ifndef INVENTORY_USER_H
#define INVENTORY_USER_H

#include <string>
#include <fstream>

using namespace std;

class User {

	private:
		string mName, mUsername, mPassword;

	public:
		// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/* PURPOSE: Create a User object with default values
		 * PRE:  None
		 * POST: A User object with default values
		*/
		User();

		/* PURPOSE: Create an User object with specific values
		 * PRE:  The name (String), The username (String), The password (String)
		 * POST: An User object with specified values
		*/
		User(string name, string username, string password);

		// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/* PURPOSE: Retrieve the name
		 * PRE:  None
		 * POST: The name (String)
		*/
		string	getName();

		/* PURPOSE: Retrieve the username
		 * PRE:  None
		 * POST: The username (String)
		*/
		string	getUsername();

		/* PURPOSE: Retrieve the password
		 * PRE:  None
		 * POST: The password (String)
		*/
		string	getPassword();

		// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/* PURPOSE: Update the name
		 * PRE:  The name (String)
		 * POST: The value is changed to the parameter
		*/
		void	setName(string);

		/* PURPOSE: Update the username
		 * PRE:  The username (String)
		 * POST: The value is changed to the parameter
		*/
		void	setUsername(string);

		/* PURPOSE: Update the password
		 * PRE:  The password (String)
		 * POST: The value is changed to the parameter
		*/
		void	setPassword(string);

		// ~~~~~~~~~~ Operators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/* PURPOSE: Tries to read the serial from the file stream
		 * PRE:  The file stream
		 * POST: if the serial could be read
		 */
		bool	readUsername(ifstream&);

		/** PURPOSE: OVERLOAD Inputs variables from the file stream to object
		 * PRE:  The file stream (fstream), The obj (User)
		 * 		 User.readUsername MUST be called prior
		 * POST: Reads data from the file stream
		 */
		friend ifstream& operator>>(ifstream& stream, User& obj);

		/** PURPOSE: OVERLOAD Inputs variables from the stream to object
		 * PRE:  The stream (istream), The obj (User)
		 * POST: Reads data from the stream
		 */
		friend  istream& operator>>(istream& stream, User& obj);

		/** PURPOSE: OVERLOAD Outputs variables from object to the file stream
		 * PRE:  The file stream (fstream), The obj (User)
		 * POST: Reads data from the file stream
		 */
		friend ofstream& operator<<(ofstream& stream, const User obj);

		/** PURPOSE: OVERLOAD Outputs variables from object to the console
		 * PRE:  The file stream (fstream), The obj (User)
		 * POST: Reads data from the file stream
		 */
		friend  ostream& operator<<( ostream& stream, const User obj);

};

#endif //INVENTORY_USER_H
