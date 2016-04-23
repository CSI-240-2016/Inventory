
#include "LinkedList.h"
#include "User.h"
#include <string>
#include <fstream>
#include <iostream>

void loadUsers(LinkedList<string> &mData)
{
	string junk;
	string tmpName;
	string tmpUsername;
	string tmpPassword;

	ifstream file;

	file.open("users.dat");

	if (file.is_open())
	{
		while (!file.eof())
		{
			
			//First line is Name
			getline(cin, tmpName);
			
			//Change LinkedList by name of the list
			mData.append(tmpName);

			//Second line is username and password
			
			cin >> tmpUsername >> tmpPassword;
			//Change LinkedList by name of the list
			mData.append(tmpUsername);

			//Change LinkedList by name of the list
			mData.append(tmpPassword);
			getline(cin, junk);
		}

	}

	else
	{
		cout << "Error opening the file" << endl;
	}

	file.close();
}

void saveUsers(LinkedList<User> mData)
{
	ifstream file;

	file.open("user.dat",ios::in);
	Node *tmp;
	Node *before;

	tmp = mHead;
	before = mHead;

	if (file.is_open())
	{
		while (tmp != NULL) //While list not empty or not at the end
		{
			file << mData.getName() << endl; //output name in file
			file << mData.getUsername() << mData.getPassword() << endl; //output username and password in file
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
