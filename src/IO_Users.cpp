#include "LinkedList.h"
#include "User.h"
#include <string>
#include <fstream>
#include <iostream>

void loadUsers(LinkedList<User> &mData)
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

			//Change LinkedList by name of the list
			user.setName(tmpName);
			mData.append(tmpName);

			//Second line is username and password

			file >> user.setUserName >> user.setPassword;
			//Change LinkedList by name of the list
			mData.append(tmpUsername);

			//Change LinkedList by name of the list
			mData.append(tmpPassword);
			getline(file, junk);
		} while (!file.eof());

	} 

	else
	{
		cout << "Error opening the file" << endl;
	}

	file.close();
}

void saveUsers(LinkedList<User> mData)
{
	ofstream file;

	file.open("user.dat", ios::out);
	Node<User> *tmp;
	Node<User> *before;

	tmp = mData.mHead;
	before = mData.mHead;

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
