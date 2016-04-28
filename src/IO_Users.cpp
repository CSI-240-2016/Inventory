
#include "IO_Users.h"

void loadUsers(LinkedList<User> *mData)
{
	string junk;
	string tmpName;
	string tmpUsername;
	string tmpPassword;

	ifstream file;

	file.open("users.dat", ios::in);

	if (file.is_open())
	{
		
		while (getline(file,tmpName))//!file.eof())
		{
			
			//Get username and password
			file >> tmpUsername >> tmpPassword;

			getline(file, junk);
			
			//Add user to linkedlist
			mData->append(User(tmpName, tmpUsername, tmpPassword));

		}

	} 

	else
	{
		cout << "Error opening the file" << endl;
	}

	file.close();
}

void saveUsers(LinkedList<User> *list)
{
	ofstream file;
	file.open("users.dat", ios::out);
	
	Node<User> *tmpNode = list->mHead;

	if (file.is_open())
	{
		while (tmpNode != NULL) //While list not empty or not at the end
		{
			file << "\n" << tmpNode->mData;
			tmpNode = tmpNode->mNext;
		}
	}

	else
	{
		cout << "Error opening the file." << endl;
	}
	file.close();
}

void printUsers(LinkedList<User> *list) {
	Node<User> *tmpNode = list->mHead;
	while (tmpNode != NULL) {
		cout << tmpNode->mData << "\n";
		tmpNode = tmpNode->mNext;
	}
}
