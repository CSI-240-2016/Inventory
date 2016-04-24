
#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User {

	private:
		string mName, mUsername, mPassword;
	
	public:
		// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		User(string name, string username, string password);
		
		// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		string getName();
		string getUserName();
		string getPassword();
		
		// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		void setName(string);
		void setUserName(string);
		void setPassword(string);
		
		// ~~~~~~~~~~ Operators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		
		/** PURPOSE: OVERLOAD Loads variables from a file stream
		 */
		friend ifstream& operator>>(ifstream& stream, User& obj);
		
		/** PURPOSE: OVERLOAD Loads variables from a console stream
		 */
		friend  istream& operator>>( istream& stream, User& obj);
		
		/** PURPOSE: OVERLOAD Outputs variables to file stream
		 */
		friend ofstream& operator<<(ofstream& stream, User& obj);
		
		/** PURPOSE: OVERLOAD Outputs variables to console stream
		 */
		friend  ostream& operator<<( ostream& stream, User& obj);

};

#endif