#include "publicMenu.h"
#include "common.h"

void displayItemMenu(LinkedList<Item> *listOfItems)
{
	int choice = 0;

	clearScreen();
	displayLogo();

	cout << setw(22) << right << "Item Menu:\n\n\n";
	cout << setw(12) << right << "1.) " << left << "Show In Items\n";
	cout << setw(12) << right << "2.) " << left << "Show Out Items\n";
	cout << setw(12) << right << "3.) " << left << "Return to Menu\n";

	cout << setw(28) << right << "Please enter a choice: ";
	cin >> choice;

	while ((choice < 1) || (choice > 3))
	{
		cout << setw(28) << right << "Invalid... Enter choice: ";
		cin >> choice;
	}

	switch (choice)
	{
	case 1:
		//showInItems();
		break;
	case 2:
		//showOutItems();
		break;
	case 3:
		displayGeneralMenu(listOfItems);
	}
}


template <typename T>
void displaySearchMenu(LinkedList<Item> *listOfItems)
{
	int choice = 0;

	clearScreen();
	displayLogo();

	cout << setw(22) << right << "Search Menu:\n\n\n";
	cout << setw(12) << right << "1.) " << left << "Search for a Club\n";
	cout << setw(12) << right << "2.) " << left << "Search for an Item\n";
	cout << setw(12) << right << "3.) " << left << "Return to Menu\n";

	cout << setw(28) << right << "Please enter a choice: ";
	cin >> choice;

	while ((choice < 1) || (choice > 3))
	{
		cout << setw(28) << right << "Invalid... Enter choice: ";
		cin >> choice;
	}

	switch (choice)
	{
	case 1:
		searchClub(listOfItems);
		break;
	case 2:
		searchItem(listOfItems);
		break;
	case 3:
		displayGeneralMenu();
	}
}


void login(LinkedList<Item> *listOfItems)
{
	string password, username;
	char temp;
	ifstream datafile;
	datafile.open("users.txt");

	if (!datafile.is_open())
	{
		cout << "One of the files does not exist." << endl;
		system("pause");

	}

	else
	{
		cout << "Input username" << endl;
		getline(cin, username);
		//getline(cin, password);

		//Password Masking
		#ifdef _WIN32  //For Windows (conio.h is only included if on a window OS)
			temp = _getch();
			while(temp != '\r')
				{
					cout << "Input password" << endl;

					temp = _getch();
					if (temp == '\r')
						break;
					std::cout << "*";
					password += temp;
				}
		#elif __APPLE__
			password = getpass("Input password");
		#elif __linux__
			password = getpass("Input password");
		#elif __unix__
			password = getpass("Input password");
		#endif

		if (checkWords(username, password, listOfItems) == true)
		{
			clearScreen();
			cout << "You logged in!" << endl;
			displayAdminMenu(listOfItems);
			system("pause");
		}

		else
		{
			cout << "This is not a valid login." << endl;
			login(listOfItems);
			return;
		}
	}
}


void searchClub(LinkedList<Item> *listOfItems)
{
	string nameOfClub;
	Node<Item> *tmp;

	cout << "Please enter the name of the club:\n\n"
		 << "Club: ";
	cin >> nameOfClub; //Error check will be added later
	cout << endl;

	tmp = listOfItems->mHead; //Set tmp to the first element of the list

	cout << "Items for " << nameOfClub << "\n\n";

	while (tmp != NULL) //Check the entire list for the club's items
	{
		if (tmp->mData.getNameOwner() == nameOfClub)
		{
			//When an item of the club is found, it is displayed to the console
			cout << tmp->mData.getName() << endl;
			tmp = tmp->mNext;
		}
		else
		{
			//If an item does not belong to a club, the loop just moves to the next item listed
			tmp = tmp->mNext;
		}
	}

	cout << endl;
}


void searchItem(LinkedList<Item> *listOfItems)
{
	string nameOfItem;
	Node<Item> *tmp;

	cout << "Please enter the name of the item:\n\n"
		 << "Item: ";
	cin >> nameOfItem; //Error check will be added later
	cout << endl;

	tmp = listOfItems->mHead; //Set tmp to the first element of the list

	while (tmp != NULL) //Check the entire list until the item is found
	{
		//If found, exit from the loop and print the information
		//As long as it isn't found, check the next item
		if (tmp->mData.getName() == nameOfItem)
		{
			break;
		}
		else
		{
			tmp = tmp->mNext;
		}
	}

	if (tmp == NULL) //This is true if the item does not exist
	{
		cout << "The item does not exist\n\n";
	}
	else
	{
		cout << "Name: " << tmp->mData.getName()
			 << "\nSerial Number: " << tmp->mData.getSerial()
			 << "\nStatus: " << tmp->mData.isCheckedIn() << "\n\n";
	}
}

void showInItems(LinkedList<Item> *listOfItems)
{
	Node<Item> *tmp;

	tmp = listOfItems->mHead;

	while (tmp != NULL)
	{
		if (tmp->mData.isCheckedIn() == true)
		{
			cout << "Name: " << tmp->mData.getName()
				<< "\nSerial Number: " << tmp->mData.getSerial()
				<< "\nStatus: " << tmp->mData.isCheckedIn() << "\n\n";
		}
		tmp = tmp->mNext;
	}
}

void showOutItems(LinkedList<Item> *listOfItems)
{
	Node<Item> *tmp;
	
	tmp = listOfItems->mHead;

	while (tmp != NULL)
	{
		if (tmp->mData.isCheckedIn() == false)
		{
			cout << "Name: " << tmp->mData.getName()
				<< "\nSerial Number: " << tmp->mData.getSerial()
				<< "\nStatus: " << tmp->mData.isCheckedIn() << "\n\n";
		}
		tmp = tmp->mNext;
	}
}

bool checkWords(string username, string password, LinkedList<Item> *listOfItems)
{
	ifstream datafile;
	datafile.open("datafile.txt");
	string tempName;
	string tempPass;



	if (!datafile.is_open())
	{
		cout << "One of the files does not exist." << endl;
		system("pause");
		login(listOfItems);
	}
	else
	{
		datafile >> tempName;
		while (!datafile.eof())
		{
			datafile >> tempPass;
			if (username == tempName && password == tempPass)
			{
				datafile.close();
				return true;
			}
			else
			{
				datafile >> tempName;
			}
		}
		datafile.close();
		return false;
	}
}