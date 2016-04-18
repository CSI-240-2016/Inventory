
#ifndef USER_H
#define USER_H

using namespace std;

class User {

	private:
		String mName, mUsername, mPassword;
	
	public:
		// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		User(string name, string username, string password);
		
		// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		string getName();
		string getUserName();
		string getPassword();

};

#endif