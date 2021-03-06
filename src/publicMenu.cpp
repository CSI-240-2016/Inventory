
#include "publicMenu.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>
#include "IO_Users.h"

void displayItemMenu(LinkedList<Item> *listOfItems, LinkedList<Club> *listOfClubs, LinkedList<User> *listOfUsers)
{
	int choice = 0;

	clearScreen();
	displayLogo();

	cout << setw(22) << right << "Item Menu:\n\n\n";
	cout << setw(12) << right << "1.) " << left << "Show In Items\n";
	cout << setw(12) << right << "2.) " << left << "Show Out Items\n";
	cout << setw(12) << right << "3.) " << left << "Return to Menu\n";

	string junk;
	
	do {
		cout << setw(28) << right << "Please enter a choice: ";
		cin >> choice;
		getline(cin, junk);
		if (choice < 1 || choice > 3)
			cout << setw(28) << right << "Invalid...\n";
	} while(choice < 1 || choice > 3);

	switch (choice)
	{
	case 1:
		showInItems(listOfItems);
		break;
	case 2:
		showOutItems(listOfItems);
		break;
	case 3:
		displayGeneralMenu(listOfItems, listOfClubs, listOfUsers);
		return;
	}
	pause();
}

void displaySearchMenu(LinkedList<Item> *listOfItems, LinkedList<Club> *listOfClubs, LinkedList<User> *listOfUsers)
{
	int choice = 0;

	clearScreen();
	displayLogo();

	cout << setw(22) << right << "Search Menu:\n\n\n";
	cout << setw(12) << right << "1.) " << left << "Search for a Club\n";
	cout << setw(12) << right << "2.) " << left << "Search for an Item\n";
	cout << setw(12) << right << "3.) " << left << "Return to Menu\n";
	
	string junk;
	do {
		cout << setw(28) << right << "Please enter a choice: ";
		cin >> choice;
		getline(cin, junk); // get rid of anything else in the line
		if (choice < 1 || choice > 3)
			cout << setw(28) << right << "Invalid...\n";
	} while (choice < 1 || choice > 3);

	switch (choice)
	{
	case 1:
		searchClub(listOfItems);
		break;
	case 2:
		searchItem(listOfItems);
		break;
	case 3:
		displayGeneralMenu(listOfItems, listOfClubs, listOfUsers);
	}
}


void login(LinkedList<Item> *listOfItems, LinkedList<Club> *listOfClubs, LinkedList<User> *listOfUsers)
{
	string password, username;
	Node<User> *tmp;
	
	cout << "Input username: ";
	getline(cin, username);
	cout << "Input password: ";
	getline(cin, password);

	/*Password Masking
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
		//password = getpass("Input password");
	#elif __linux__
		//password = getpass("Input password");
	#elif __unix__
		//password = getpass("Input password");
	#endif
	*/

	tmp = listOfUsers->mHead;

	while (tmp != NULL)
	{
		if ((tmp->mData.getUserName() == username) && (tmp->mData.getPassword() == password))
		{
			clearScreen();
			cout << "You logged in!" << endl;
			pause();
			bool logout = false;
			do {
				logout = displayAdminMenu(listOfItems, listOfClubs, listOfUsers);
			} while (!logout);
			return;
		}

		tmp = tmp->mNext;
	}

	cout << "This is not a valid login." << endl;
	login(listOfItems, listOfClubs, listOfUsers);

	//if (checkWords(username, password, listOfItems, listOfClubs, listOfUsers) == true)
	//{
	//	clearScreen();
	//	cout << "You logged in!" << endl;
	//	displayAdminMenu(listOfItems, listOfClubs, listOfUsers);
	//	system("pause");
	//}

	//else
	//{
	//	cout << "This is not a valid login." << endl;
	//	login(listOfItems, listOfClubs, listOfUsers);
	//	return;
	//}
}


void searchClub(LinkedList<Item> *listOfItems)
{
	Node<Item> *tmp = listOfItems->mHead;
	
	if (tmp == NULL) {
		cout << "No clubs in data.\n";
		return;
	}
	
	bool valid = false;
	string nameOfClub;
	
	do {
		cout	<< "Please enter the name of the club:\n\n"
				<< "Club: ";
		getline(cin, nameOfClub);
		valid = validateStr(nameOfClub);
		if (!valid) cout << "Invalid input...\n";
	} while (!valid);
	
	cout << "\nItems for '" << nameOfClub << "':\n\n";
	
	int quantity = 0;
	
	while (tmp != NULL) //Check the entire list for the club's items
	{
		if (tmp->mData.getNameOwner() == nameOfClub)
		{
			//When an item of the club is found, it is displayed to the console
			cout << tmp->mData.getName() << endl;
			quantity++;
			tmp = tmp->mNext;
		}
		else
		{
			//If an item does not belong to a club, the loop just moves to the next item listed
			tmp = tmp->mNext;
		}
	}
	
	if (quantity <= 0) {
		cout << "No items found.";
	}

	cout << endl;
	
	pause();
}


void searchItem(LinkedList<Item> *listOfItems)
{
	Node<Item> *tmp = listOfItems->mHead;
	
	if (tmp == NULL) {
		cout << "No clubs in data.\n";
		return;
	}
	
	bool valid = false;
	string name;
	
	do {
		cout	<< "Please enter the name of the item:\n\n"
				<< "Item: ";
		getline(cin, name);
		valid = validateStr(name);
		if (!valid) cout << "Invalid input...\n";
	} while (!valid);
	
	cout << "\nItems for '" << name << "':\n\n";
	
	int quantity = 0;
	
	while (tmp != NULL) //Check the entire list for the club's items
	{
		if (tmp->mData.getName() == name)
		{
			//When an item of the club is found, it is displayed to the console
			cout << tmp->mData.getName() << endl;
			quantity++;
			tmp = tmp->mNext;
		}
		else
		{
			//If an item does not belong to a club, the loop just moves to the next item listed
			tmp = tmp->mNext;
		}
	}
	
	if (quantity <= 0) {
		cout << "No items found.";
	}

	cout << endl;
	
	pause();
}

void showInItems(LinkedList<Item> *listOfItems)
{
	Node<Item> *tmp;

	tmp = listOfItems->mHead;
	
	cout << "\n";
	
	if (tmp == NULL) {
		cout << "There are no items\n";
		pause();
		return;
	}
	
	int quantityItemsIn = 0;
	while (tmp != NULL) // check to see if there is a next item
	{
		if (tmp->mData.isCheckedIn() == true) // if the item is checked in
		{
			quantityItemsIn++;
			cout
				<< "Name:\t"	<< tmp->mData.getName()		<< "\n"
				<< "Serial:\t"	<< tmp->mData.getSerial()	<< "\n"
			;
		}
		tmp = tmp->mNext;
	}
	
	if (quantityItemsIn <= 0) {
		cout << "There are no items in\n";
	}
	
}

void showOutItems(LinkedList<Item> *listOfItems)
{
	Node<Item> *tmp;

	tmp = listOfItems->mHead;
	
	cout << "\n";
	
	if (tmp == NULL) {
		cout << "There are no items\n";
		pause();
		return;
	}
	
	int quantityItemsIn = 0;
	while (tmp != NULL) // check to see if there is a next item
	{
		if (tmp->mData.isCheckedIn() == false) // if the item is checked out
		{
			quantityItemsIn++;
			cout
				<< "Name:\t"	<< tmp->mData.getName()		<< "\n"
				<< "Serial:\t"	<< tmp->mData.getSerial()	<< "\n"
			;
		}
		tmp = tmp->mNext;
	}
	
	if (quantityItemsIn <= 0) {
		cout << "There are no items out\n";
	}
	
}

bool checkWords(string username, string password, LinkedList<Item> *listOfItems, LinkedList<Club> *listOfClubs, LinkedList<User> *listOfUsers)
{
	ifstream datafile;
	datafile.open("datafile.txt");
	string tempName;
	string tempPass;



	if (!datafile.is_open()) // check if the file is actually in the folder
	{
		cout << "One of the files does not exist." << endl;
		system("pause");
		login(listOfItems, listOfClubs, listOfUsers); // if not go back to log in
	}
	else
	{
		datafile >> tempName;
		while (!datafile.eof())
		{
			datafile >> tempPass;
			if (username == tempName && password == tempPass) // check if the username and password are the same as in the file
			{
				datafile.close();
				return true; // return true if they are
			}
			else
			{
				datafile >> tempName;
			}
		}
		datafile.close();
		return false; // return false if they are not
	}
}

bool validateStr(string str)
{
	bool valid = true;	
	int strLength = str.length();

	for (int i = 0; i < strLength; i++)
	{
		if (!(isalpha(str[i])) && str[i] != ' ') //If any non-alpha characters are found, the input is invalid
		{
			valid = false;
		}
	}

	return valid;
}