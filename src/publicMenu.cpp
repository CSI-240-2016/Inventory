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
		showInItems();
		break;
	case 2:
		showOutItems();
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

void logIn()
{

}

template <typename T>
void searchClub(LinkedList<Item> *listOfItems)
{
	/*

	string desiredClub;
	Node<T> *tmp;

	cout << "Please enter the name of the club:\n\n"
		<< "Club: ";
	cin >> desiredClub; //Error check will be added later
	cout << endl;

	tmp = listOfItems->mHead;

	while (tmp != NULL)
	{
		if (tmp club name is equal to desiredClub)
		{
			cout << mName of item; 			
			tmp = tmp->mNext;
		}
		else
		{
			tmp = tmp->mNext;
		}
	}

	*/
}

template <typename T>
void searchItem(LinkedList<Item> *listOfItems)
{
	string desiredItem;
	Node<T> *tmp;

	cout << "Please enter the name of the item:\n\n"
		 << "Item: ";
	cin >> desiredItem; //Error check will be added later
	cout << endl;

	tmp = listOfItems->mHead;

	while (tmp != NULL)
	{
		if (tmp->mName == desiredItem)
		{
			break;
		}
		else
		{
			tmp = tmp->mNext;
		}
	}

	if (tmp == NULL)
	{
		cout << "The item does not exist\n\n";
	}
	else
	{
		cout << "Name: " << tmp->mName
			 << "Serial Number: " << tmp->mSerialNumber;
			 << "Status: " << tmp->IsIn << "\n\n";
	}
}

void showInItems()
{

}

void showOutItems()
{

}