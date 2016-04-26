#include "adminMenu.h"

void addClub()
{
	string nameOfClub;
	cout << "What is the name of the club you wish to add?"; // ask for the name of the club
	getline(cin, nameOfClub); // take the whole line as the name

	clubsOutput(nameOfClub); // send the name to the output club function
}

void addItem()
{
}

void addUser()
{
}

void checkInOut(LinkedList<Item> *listOfItems)
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
		if (tmp->mData.isCheckedIn() == true)
		{
			cout << "The item is currently checked in\n\n";
		}
		else
		{
			cout << "The item is currently checked out\n\n";
		}
	}
}

void displayAdminClub()
{
	int choice = 0;

	clearScreen();
	displayLogo();

	cout << setw(36) << right << "Administrator Club Menu:\n\n\n";
	cout << setw(12) << right << "1.) " << left << "Add Club\n";
	cout << setw(12) << right << "2.) " << left << "Remove Club\n";
	cout << setw(12) << right << "3.) " << left << "Modify Club\n";
	cout << setw(12) << right << "4.) " << left << "Return to Administrator Menu\n";

	cout << setw(28) << right << "Please enter a choice: ";
	cin >> choice;

	while ((choice < 1) || (choice > 4))
	{
		cout << setw(28) << right << "Invalid... Enter choice: ";
		cin >> choice;
	}

	switch (choice)
	{
	case 1:
		addClub();
		break;
	case 2:
		removeClub();
		break;
	case 3:
		modifyClub();
		break;
	case 4:
		displayAdminMenu();
	}
}

void displayAdminItem(LinkedList<Item> *listOfItems)
{
	int choice = 0;

	clearScreen();
	displayLogo();

	cout << setw(36) << right << "Administrator Item Menu:\n\n\n";
	cout << setw(12) << right << "1.) " << left << "Show In Items\n";
	cout << setw(12) << right << "2.) " << left << "Show Out Items\n";
	cout << setw(12) << right << "3.) " << left << "Show All Items\n";
	cout << setw(12) << right << "4.) " << left << "Add Item\n";
	cout << setw(12) << right << "5.) " << left << "Remove Item\n";
	cout << setw(12) << right << "6.) " << left << "Modify Item\n";
	cout << setw(12) << right << "7.) " << left << "Return to Administrator Menu\n";

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
		//showInItems();
		break;
	case 2:
		//showOutItems();
		break;
	case 3:
		showAllItems(listOfItems);
		break;
	case 4:
		addItem();
		break;
	case 5:
		removeItem();
		break;
	case 6: 
		modifyItem();
		break;
	case 7:
		displayAdminMenu();
	}
}

void displayAdminSearch()
{
	int choice = 0;

	clearScreen();
	displayLogo();

	cout << setw(22) << right << "Search Menu:\n\n\n";
	cout << setw(12) << right << "1.) " << left << "Search for a Club\n";
	cout << setw(12) << right << "2.) " << left << "Search for an Item\n";
	cout << setw(12) << right << "3.) " << left << "Return to Administrator Menu\n";

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
		//searchClub();
		break;
	case 2:
		//searchItem();
		break;
	case 3:
		displayAdminMenu();
	}
}

void displayAdminUser()
{
	int choice = 0;

	clearScreen();
	displayLogo();

	cout << setw(36) << right << "Administrator User Menu:\n\n\n";
	cout << setw(12) << right << "1.) " << left << "Add User\n";
	cout << setw(12) << right << "2.) " << left << "Remove User\n";
	cout << setw(12) << right << "3.) " << left << "Modify User\n";
	cout << setw(12) << right << "4.) " << left << "Return to Administrator Menu\n";

	cout << setw(28) << right << "Please enter a choice: ";
	cin >> choice;

	while ((choice < 1) || (choice > 4))
	{
		cout << setw(28) << right << "Invalid... Enter choice: ";
		cin >> choice;
	}

	switch (choice)
	{
	case 1:
		addUser();
		break;
	case 2:
		removeUser();
		break;
	case 3:
		modifyUser();
		break;
	case 4:
		displayAdminMenu();
	}
}

void exportExcel()
{
}

void removeClub()
{
}

void removeItem()
{
}

void removeUser()
{
}

void modifyClub()
{
}

void modifyItem()
{
}

void modifyUser()
{
}

void showAllItems(LinkedList<Item> *listOfItems)
{
	Node<Item> *tmp;

	tmp = listOfItems->mHead;

	cout << "All items:\n\n";

	while (tmp != NULL)
	{
		cout << "Name: " << tmp->mData.getName()
			 << "\nSerial Number: " << tmp->mData.getSerial()
			 << "\nStatus: " << tmp->mData.isCheckedIn() << "\n\n";

		tmp = tmp->mNext;
	}
}
