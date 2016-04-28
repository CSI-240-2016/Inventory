#include "IO_Users.h"

void loadUsers(LinkedList<User> *mData)
{
	string junk;
	string tmpName;
	string tmpUsername;
	string tmpPassword;
	User user;

	ifstream file;

	file.open("users.dat");

	if (file.is_open())
	{
		do
		{

			//First line is Name
			getline(file,tmpName);

			//Set name of user
			user.setName(tmpName);
			
			//Get username and password
			file >> tmpUsername >> tmpPassword;
			
			//Set username and password of user
			user.setUserName(tmpUsername);
			user.setPassword(tmpPassword);

			//Add user to linkedlist
			mData->append(user);

			getline(file, junk);

		} while (!file.eof());

	} 

	else
	{
		cout << "Error opening the file" << endl;
	}

	file.close();
}

void saveUsers(LinkedList<User> *mData)
{
	ofstream file;

	file.open("user.dat", ios::out);
	Node<User> *tmp;
	Node<User> *before;

	tmp = mData->mHead;
	before = mData->mHead;

	if (file.is_open())
	{
		while (tmp != NULL) //While list not empty or not at the end
		{
			file << tmp->mData << endl;
			before = tmp;
			tmp = tmp->mNext;
		}
	}

	else
	{
		cout << "Error opening the file." << endl;
	}
	file.close();
}
