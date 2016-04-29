/*
Author: Derik Gagnon
Class: CSI-240-03
Assignment: SGA Inventory (Final Project)
Date Assigned:
Due Date:

Certification of Authenticity:  I certify that this is entirely my own work, except where
I have given fully-documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor
of this assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff; and/or

- Communicate a copy of this assignment to a plagiarism checking service (which may then retain
a copy of this assignment on its database for the purpose of future plagiarism checking)
*/

#include "common.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>

#include "publicMenu.h"
#include "adminMenu.h"

void clearScreen()
{
	return;
	#ifdef _WIN32
		system("CLS");
	#elif __APPLE__
		system("clear");
	#elif __linux__
		system("clear");
	#elif __unix__
		system("clear");
	#endif
}


void displayAdminMenu(LinkedList<Item> *listOfItems, LinkedList<Club> *listOfClubs, LinkedList<User> *listOfUsers)
{
	int choice = 0;

	clearScreen();
	displayLogo();

	cout << setw(29) << right << "Administrator Menu:\n\n\n";
	cout << setw(12) << right << "1.) " << left << "Check In and Check Out\n";
	cout << setw(12) << right << "2.) " << left << "Items\n";
	cout << setw(12) << right << "3.) " << left << "Clubs\n";
	cout << setw(12) << right << "4.) " << left << "Users\n";
	cout << setw(12) << right << "5.) " << left << "Search\n";
	cout << setw(12) << right << "6.) " << left << "Export\n";
	cout << setw(12) << right << "7.) " << left << "Log Out\n";

	cout << setw(28) << right << "Please enter a choice: ";
	cin >> choice;

	while ((choice < 1) || (choice > 7))
	{
		cout << setw(28) << right << "Invalid... Enter choice: ";
		cin >> choice;
	}

	switch (choice)
	{
	case 1:
		checkInOut(listOfItems);
		break;
	case 2:
		displayAdminItem(listOfItems, listOfClubs, listOfUsers);
		break;
	case 3:
		displayAdminClub(listOfItems, listOfClubs, listOfUsers);
		break;
	case 4:
		displayAdminUser(listOfItems, listOfClubs, listOfUsers);
		break;
	case 5:
		displayAdminSearch(listOfItems, listOfClubs, listOfUsers);
		break;
	case 6:
		exportExcel(listOfItems);
		break;
	case 7:
		displayGeneralMenu(listOfItems, listOfClubs, listOfUsers);
	}
}

bool displayGeneralMenu(LinkedList<Item> *listOfItems, LinkedList<Club> *listOfClubs, LinkedList<User> *listOfUsers)
{
	int choice = 0;
	string junk;

	clearScreen();
	displayLogo();

	cout << setw(22) << right << "Public Menu:\n\n\n";
	cout << setw(12) << right << "1.) " << left << "Items\n";
	cout << setw(12) << right << "2.) " << left << "Search\n";
	cout << setw(12) << right << "3.) " << left << "Log In as Admin\n";
	cout << setw(12) << right << "4.) " << left << "Shutdown\n\n";

	cout << setw(28) << right << "Please enter a choice: ";
	cin >> choice;
	getline(cin, junk);

	while ((choice < 1) || (choice > 4))
	{
		cout << setw(28) << right << "Invalid... Enter choice: ";
		cin >> choice;
		getline(cin, junk);
	}

	switch (choice)
	{
	case 1:
		displayItemMenu(listOfItems, listOfClubs, listOfUsers);
		break;
	case 2:
		//displaySearchMenu(listOfItems, listOfClubs, listOfUsers);
		break;
	case 3:
		login(listOfItems, listOfClubs, listOfUsers);
		break;
	default:
		//Shutdown
		return false;
	}
	return true;
}

void displayLogo()
{
	clearScreen();
	cout << endl << endl <<
		"    _____  _____       " << endl <<
		"   / ____|/ ____|   /\\" << endl <<
		"  | (___ | |  __   /  \\" << endl <<
		"   \\___ \\| | |_ | / /\\ \\" << endl <<
		"   ____) | |__| |/ ____ \\" << endl <<
		"  |_____/ \\_____/_/    \\_\\" << endl << endl << endl;
}

void pause()
{
	cout << "Press ENTER to continue...";
	#ifdef _WIN32
		system("pause");
	#elif __APPLE__
		//system("read");
		cin.get();
	#elif __linux__
		//system("read");
		cin.get();
	#elif __unix__
		//system("read");
		cin.get();
	#endif
}
