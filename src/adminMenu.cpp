#include "adminMenu.h"

void addClub()
{
	string nameOfClub;
	cout << "What is the name of the club you wish to add?"; // ask for the name of the club
	getline(cin, nameOfClub); // take the whole line as the name

	clubsOutput(nameOfClub); // send the name to the output club function
}

void addItem(LinkedList<Item> *listOfItems)
{
	clearScreen();
	displayLogo();

	Location location;
	Source source;
	Seller seller;
	Address sellerAddress;
	Node<Item> *tmp, *oneBefore;
	int serialNumber;
	double price;
	string name, type, club = "SGA", sellerName, building, room, shelfSlot, sellerAddress, sellerURL, junk;
	bool status = true;

	cout << "Enter the serial number of the new item: ";
	cin >> serialNumber;
	getline(cin, junk);
	cout << "What is the name of the item you wish to add? ";
	getline(cin, name);
	cout << "What is the type of the item you wish to add? ";
	getline(cin, type);
	cout << "Where was the item bought? ";
	getline(cin, sellerName);
	cout << "What is the URL of the store? ";
	getline(cin, sellerURL);
	cout << "What is the price of the item you wish to add? ";
	cin >> price;
	getline(cin, junk);
	cout << "What building is the item being stored in? ";
	getline(cin, building);
	cout << "What room is the item being stored in? ";
	getline(cin, room);
	cout << "What shelf slot is the item being stored in? ";
	getline(cin, shelfSlot);

	location.setBuilding(building);
	location.setRoom(room);
	location.setCode(shelfSlot);

	seller.setName(sellerName);
	seller.setAddress(sellerAddress);
	seller.setURL(sellerURL);

	source.setSeller(seller);
	source.setUnitPrice(price);

	tmp = listOfItems->mHead->mNext; //Set tmp to the first item in the list

	while (tmp != NULL)
	{
		tmp = tmp->mNext;
		if (tmp->mNext == NULL)
		{
			oneBefore = tmp;
			tmp->mData.setSerial(serialNumber);
			tmp->mData.setName(name);
			tmp->mData.setNameType(type);
			tmp->mData.setLocation(location);
			tmp->mData.setSerial(serialNumber);
			tmp->mData.setSerial(serialNumber);
			tmp->mData.setSerial(serialNumber);
		}
	}

	itemsOutput(serialNumber, name, type, club, sellerName, price, building, room, shelfSlot, status);
}

void addUser()
{
}

void checkInOut(LinkedList<Item> *listOfItems)
{
	bool valid = false;
	string nameOfItem;
	Node<Item> *tmp;

	while (valid == false)
	{
		cout << "Please enter the name of the item to check in or check out:\n\n"
			 << "Item: ";
		getline(cin, nameOfItem);

		valid = validateStr(nameOfItem);
	}

	tmp = listOfItems->mHead; //Set tmp to the first element of the list

	while (tmp != NULL) //Check the entire list until the item is found
	{
		//If found, exist from the loop and perform appropriate action
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
		cout << "The item does not exist.\n\n";
	}
	else
	{
		if (tmp->mData.isCheckedIn() == true) //If the item is checked in, check it out
		{
			tmp->mData.checkOut();
			cout << "The item has been checked out.\n\n";
		}
		else //If the item is checked out, check it back in
		{
			tmp->mData.checkIn();
			cout << "The item has been checked in.\n\n";
		}
	}
}

void displayAdminClub(LinkedList<Item> *listOfItems)
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
		displayAdminMenu(listOfItems);
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
		addItem(listOfItems);
		break;
	case 5:
		removeItem(listOfItems);
		break;
	case 6: 
		modifyItem(listOfItems);
		break;
	case 7:
		displayAdminMenu(listOfItems);
	}
}

void displayAdminSearch(LinkedList<Item> *listOfItems)
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
		displayAdminMenu(listOfItems);
	}
}

void displayAdminUser(LinkedList<Item> *listOfItems)
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
		displayAdminMenu(listOfItems);
	}
}

void exportExcel()
{
}

void removeClub()
{
}

void removeItem(LinkedList<Item> *listOfItems)
{
}

void removeUser()
{
}

void modifyClub()
{
	string currentName;
	string changeName;
	
	cout << "What is the name of the club you would like to change?" << endl;
	getline(cin, currentName);
	cout << "What would you like to change the name to?" << endl;
	getline(cin, changeName);

}

void modifyItem(LinkedList<Item> *listOfItems)
{
}

void modifyUser()
{
}

void showAllItems(LinkedList<Item> *listOfItems)
{
	bool status;
	Node<Item> *tmp;

	tmp = listOfItems->mHead; //Set tmp to the first item in the list

	cout << "All items:\n\n"
		 << "Name:" << setw(20)
		 << "Serial Number:" << setw(20)
		 << "Status:\n\n";

	while (tmp != NULL)
	{
		//The information of each item is displayed with each iteration
		cout << tmp->mData.getName()
			 << setw(20) << right << tmp->mData.getSerial();

		status = tmp->mData.isCheckedIn();

		if (status == true)
		{
			cout << setw(20) << right << "In" << endl;
		}
		else
		{
			cout << setw(20) << right << "Out" << endl;
		}

		tmp = tmp->mNext; //Before each iteration ends, tmp is set to the next item listed
	}

	cout << endl;
}

/* Already defined in publicMenu.h
bool validateStr(string str)
{
	bool valid = true;
	int strLength = str.length();

	for (int i = 0; i < strLength; i++)
	{
		if (!(isalpha(str[i]))) //If any non-alpha characters are found, the input is invalid
		{
			valid = false;
		}
	}

	return valid;
}
*/
