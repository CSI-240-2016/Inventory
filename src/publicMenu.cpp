#include "publicMenu.h"
#include "common.h"

void displayItemMenu()
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
		displayGeneralMenu();
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


void login()
{
	string password, username;
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
		cout << "Input password" << endl;
		getline(cin, password);

		if (checkWords(username, password) == true)
		{
			clearScreen();
			cout << "You logged in!" << endl;
			displayAdminMenu();
			system("pause");
		}

		else
		{
			cout << "This is not a valid login." << endl;
			login();
			return;
		}
	}
}


template <typename T>
void searchClub(LinkedList<Item> *listOfItems)
{
	string nameOfClub;
	Node<T> *tmp;

	cout << "Please enter the name of the club:\n\n"
		<< "Club: ";
	cin >> nameOfClub; //Error check will be added later
	cout << endl;

	tmp = listOfItems->mHead; //Set tmp to the first element of the list

	cout << "Items for " << nameOfClub << "\n\n";

	while (tmp != NULL) //Check the entire list for the club's items
	{
		/*
		if (tmp club name is equal to nameOfClub)
		{
			cout << name of item << endl; 			
			tmp = tmp->mNext;
		}
		else
		{
			tmp = tmp->mNext;
		}
		*/
	}

	cout << "\n\n";
}


template <typename T>
void searchItem(LinkedList<Item> *listOfItems)
{
	string nameOfItem;
	Node<T> *tmp;

	cout << "Please enter the name of the item:\n\n"
		 << "Item: ";
	cin >> nameOfItem; //Error check will be added later
	cout << endl;

	tmp = listOfItems->mHead; //Set tmp to the first element of the list

	while (tmp != NULL) //Check the entire list until the item is found
	{
		//If found, exit from the loop and print the information
		//As long as it isn't found, check the next item
		if (tmp->mName == nameOfItem)
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
		cout << "Name: " << tmp->mName
			 << "\nSerial Number: " << tmp->mSerialNumber
			 << "\nStatus: " << tmp->IsIn << "\n\n";
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

bool checkWords(string username, string password)
{
	ifstream datafile;
	datafile.open("datafile.txt");
	string tempName;
	string tempPass;



	if (!datafile.is_open())
	{
		cout << "One of the files does not exist." << endl;
		system("pause");
		login();
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