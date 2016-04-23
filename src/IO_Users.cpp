//Get user from file
// Make sure User LinkedList is created prior of using function

void loadUsers()
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
			getline(tmpName);
			
			//Change LinkedList by name of the list
			//LinkedList.append(tmpName)

			//Second line is username and password
			
			cin >> tmpUserName >> tmpPassword;
			//Change LinkedList by name of the list
			//LinkedList.append(tmpUserName)

			//Change LinkedList by name of the list
			//LinkedList append(tmpPassword)
			getline(junk);
		}

	}

	else
	{
		cout << "Error opening the file" << endl;
	}

	file.close();
}

void saveUsers()
{
	ifstream file;

	file.open("user.dat",ios::in)
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
}