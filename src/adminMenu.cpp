
#include "adminMenu.h"

#include "common.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>

#include "publicMenu.h"
#include "clubsDat.h"
#include "itemsDat.h"
#include "IO_Users.h"

#include "LinkedListHelper.h"

void addClub(LinkedList<Club> *listOfClubs)
{
	string nameOfClub;
	Node<Club> *current = listOfClubs->mHead;
	Node<Club> *previous = NULL;

	cout << "What is the name of the club you wish to add?"; // ask for the name of the club
	getline(cin, nameOfClub); // take the whole line as the name

	Club newClub(nameOfClub);
	listOfClubs->append(newClub); // add the club to the linked list

	saveClubs(listOfClubs);
	
}

void addItem(LinkedList<Item> *listOfItems)
{
	clearScreen();
	displayLogo();

	Item item;
	Location location;
	Source source;
	Seller seller;
	Address sellerAddress;
	int serialNumber;
	double price;
	string name, type, club = "SGA", sellerName, building, room, shelfSlot, sellerURL, junk;
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
	location.setCode(shelfSlot);  // Sets the information for location

	seller.setName(sellerName);
	seller.setAddress(sellerAddress);
	seller.setURL(sellerURL);     // Sets the information for seller

	source.setSeller(seller);
	source.setUnitPrice(price);   // Sets the information for Source

	item.setSerial(serialNumber);
	item.setName(name);
	item.setNameType(type);
	item.setLocation(location);
	item.setSource(source);
	item.setStatus(status);    //Sets all the Data for tmp

	listOfItems->append(item);  //Adds new item to the end of the list

	saveItems(listOfItems);
	//itemsOutput(serialNumber, name, type, club, sellerName, price, building, room, shelfSlot, status);  // File Output
}

void addUser(LinkedList<User> *listOfUsers)
{
	string name, username, password;

	clearScreen();
	displayLogo();

	//The user is prompted for the appropriate information
	cout << "Please enter the name of the new user:\n\n";
	getline(cin, name);

	cout << "\nPlease enter the username of the new user:\n\n";
	getline(cin, username);

	cout << "\nPlease enter the password of the new user:\n\n";
	getline(cin, password);

	//A new user with the specified information is created
	User newUser(name, username, password);

	//The new user is added to the list of users
	listOfUsers->append(newUser);
	
	saveUsers(listOfUsers);
}

void checkInOut(LinkedList<Item> *listOfItems)
{
	bool valid = false;
	int input;
	string junk;
	Node<Item> *tmp;

	while (valid == false)
	{
		cout << "Please enter the serial number of the item to check in or check out (-1 to quit):\n\n"
			 << "Item: ";
		cin >> input;
		getline(cin, junk);
		
		if (input < 0) return;
		
		// find item in list
		tmp = listOfItems->mHead; //Set tmp to the first element of the list
		while (tmp != NULL) //Check the entire list until the item is found
		{
			//If found, exist from the loop and perform appropriate action
			//As long as it isn't found, check the next item
			if (tmp->mData.getSerial() == input)
			{
				valid = true;
				break;
			}
			else
			{
				tmp = tmp->mNext;
			}
		}
		
		if (!valid) cout << "The item with with serial '" << input << "' does not exist...\n";
		
	}

	// item is now at tmp->mData
	
	cout << "The item with serial '" << input << "' is checked ";
	
	if (tmp->mData.isCheckedIn())
	{
		cout << "in.\n";
	}
	else {
		cout << "out.\n";
	}
	
	do {
		if (tmp->mData.isCheckedIn())
			cout << "Do you want to check this item out (-1 to cancel, 1 to continue)? ";
		else
			cout << "Do you want to check this item in  (-1 to cancel, 1 to continue)? ";
		cin >> input;
		getline(cin, junk);
		if (input < -1 || input == 0 || input > 1)
			cout << "Invalid input...\n";
	} while (input < -1 || input == 0 || input > 1);
	
	if (input <= 0) return;
	else {
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
	
	saveItems(listOfItems);
	
	pause();
}

void displayAdminClub(LinkedList<Item> *listOfItems, LinkedList<Club> *listOfClubs, LinkedList<User> *listOfUsers)
{
	int choice = 0;
	string junk;

	clearScreen();
	displayLogo();

	cout << setw(36) << right << "Administrator Club Menu:\n\n\n";
	cout << setw(12) << right << "1.) " << left << "Add Club\n";
	cout << setw(12) << right << "2.) " << left << "Remove Club\n";
	cout << setw(12) << right << "3.) " << left << "Modify Club\n";
	cout << setw(12) << right << "4.) " << left << "Return to Administrator Menu\n";

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
		addClub(listOfClubs);
		break;
	case 2:
		removeClub(listOfClubs);
		break;
	case 3:
		modifyClub(listOfClubs);
		break;
	case 4:
		displayAdminMenu(listOfItems, listOfClubs, listOfUsers);
		return;
	}
	pause();
}

void displayAdminItem(LinkedList<Item> *listOfItems, LinkedList<Club> *listOfClubs, LinkedList<User> *listOfUsers)
{
	int choice = 0;
	string junk;

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
	getline(cin, junk);

	while ((choice < 1) || (choice > 7))
	{
		cout << setw(28) << right << "Invalid... Enter choice: ";
		cin >> choice;
		getline(cin, junk);
	}

	switch (choice)
	{
	case 1:
		showInItems(listOfItems);
		break;
	case 2:
		showOutItems(listOfItems);
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
		displayAdminMenu(listOfItems, listOfClubs, listOfUsers);
		return;
	}
	pause();
}

void displayAdminSearch(LinkedList<Item> *listOfItems, LinkedList<Club> *listOfClubs, LinkedList<User> *listOfUsers)
{
	int choice = 0;
	string junk;

	clearScreen();
	displayLogo();

	cout << setw(22) << right << "Search Menu:\n\n\n";
	cout << setw(12) << right << "1.) " << left << "Search for a Club\n";
	cout << setw(12) << right << "2.) " << left << "Search for an Item\n";
	cout << setw(12) << right << "3.) " << left << "Return to Administrator Menu\n";

	cout << setw(28) << right << "Please enter a choice: ";
	cin >> choice;
	getline(cin, junk);

	while ((choice < 1) || (choice > 3))
	{
		cout << setw(28) << right << "Invalid... Enter choice: ";
		cin >> choice;
		getline(cin, junk);
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
		displayAdminMenu(listOfItems, listOfClubs, listOfUsers);
	}
}

void displayAdminUser(LinkedList<Item> *listOfItems, LinkedList<Club> *listOfClubs, LinkedList<User> *listOfUsers)
{
	int choice = 0;
	string junk;
	
	clearScreen();
	displayLogo();

	cout << setw(36) << right << "Administrator User Menu:\n\n\n";
	cout << setw(12) << right << "1.) " << left << "Add User\n";
	cout << setw(12) << right << "2.) " << left << "Remove User\n";
	cout << setw(12) << right << "3.) " << left << "Modify User\n";
	cout << setw(12) << right << "4.) " << left << "Return to Administrator Menu\n";

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
		addUser(listOfUsers);
		break;
	case 2:
		removeUser(listOfUsers);
		break;
	case 3:
		modifyUser(listOfUsers);
		break;
	case 4:
		displayAdminMenu(listOfItems, listOfClubs, listOfUsers);
	}
}

void exportExcel(LinkedList<Item> *listOfItems)
{
	string nextCell = ",";
	//comma acts as a trigger to close current cell & open next cell
	string fileName = getFileName();
	string seller;
	ofstream exOut;
	Node<Item> *current = listOfItems->mHead;//first node of linked list of Items

	exOut.open(fileName, ios::out);

	if (exOut.is_open()) {
		//default info to outline what data goes in which columns
		exOut << "Item Name" << nextCell
			<< "Item Type" << nextCell
			<< "Club Name(s)/Owner(s)" << nextCell
			<< "Source Bought From" << nextCell
			<< "Available" << nextCell
			<< "Serial Number" << endl;
		while (current != NULL) {
			//read through until there aren't any more nodes
			exOut << current->mData.getName() << nextCell
				<< current->mData.getNameType() << nextCell
				<< current->mData.getNameOwner() << nextCell
				<< current->mData.getSource().getSeller().getName() << nextCell
				<< current->mData.isCheckedIn() << nextCell
				<< current->mData.getSerial() << endl;

			//point to next node in linked list
			current = current->mNext;
		}
	}
	exOut.close();
}

string getFileName()
{
	string fileName;

	cout << "Enter a name for the file to be exported (without file extension): ";
	cin >> fileName;

	//for now, always export to .csv for convenience
	fileName += ".csv";

	return fileName;
}

void removeClub(LinkedList<Club> *listOfClubs)
{
	Node<Club> *current = listOfClubs->mHead;
	Node<Club> *previous = NULL;
	string removeClub; // The user is prompted for the name of the club they would like to remove.
	cout << "What is the name of the club you would like to remove?" << endl;
	getline(cin, removeClub);


	removeByClub_Name(listOfClubs, removeClub); // This function passes the list of clubs and the name of the club to be removed.
	saveClubs(listOfClubs);
}

void removeItem(LinkedList<Item> *listOfItems)
{
	int serialNumber;

	//The user is prompted for the serial number of the item that they want removed
	cout << "Please enter the serial no. of the item to remove:\n\n";
	cin >> serialNumber;

	removeByItem_Serial(listOfItems, serialNumber); //This function passes the list of items and serial no. of the item to be removed
	saveItems(listOfItems);
}

void removeUser(LinkedList<User> *listOfUsers)
{
	string username; 

	//The user is prompted for the username of the user that they want removed
	cout << "Please enter the username of the user to remove:\n\n";
	getline(cin, username);

	removeByUser_UserName(listOfUsers, username); //This function passes the list of user and username of the user to be removed
	saveUsers(listOfUsers);
}

void modifyClub(LinkedList<Club> *listOfClubs)
{
	string currentName;   // current club name
	string changeName;    // new club name
	Node<Club> *current = listOfClubs->mHead;   // setting current to the first item in the list

	
	cout << "What is the name of the club you would like to change?" << endl; // input for current club name
	getline(cin, currentName);
	cout << "What would you like to change the name to?" << endl;   // input for new club name
	getline(cin, changeName);


	while (current != NULL) // run through the list until there are no more nodes
	{
		if (current->mData.getName() == currentName)  // if the current name is found
		{
			current->mData.setName(changeName);  // change to the new name
		}
		else
		{
			current = current->mNext;
		}

	}
	
	saveClubs(listOfClubs);

}

void modifyItem(LinkedList<Item> *listOfItems)
{
	// TODO this needs to be finished
}

void modifyUser(LinkedList<User> *listOfUsers)
{
	string username, reply, modification;
	Node<User> *tmp;

	//The user is initially prompted for a username in order to identify which person to mod
	cout << "What is the username of the user you wish to modify?\n\n";
	getline(cin, username);

	tmp = listOfUsers->mHead; //tmp is set to the first user in the list

	while (tmp != NULL)
	{
		//As long as the specified user isn't found and tmp isn't NULL, the loop will search for the user
		if (tmp->mData.getUserName() == username)
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
		cout << "That user does not exist.\n\n";
	}
	else //If they exist, the user is prompted to change either the name, username, or password 
	{
		cout << "Would you like to modify the name, username, or password?\n\n";
		getline(cin, reply);

		if (reply == "name")
		{
			cout << "What is the new name?\n\n";
			getline(cin, modification);

			//setName is called and the modification is passed in order to update the name
			tmp->mData.setName(modification); 
		}
		else if (reply == "username")
		{
			cout << "What is the new username?\n\n";
			getline(cin, modification);

			//setUserName is called and the modification is passed in order to update the username
			tmp->mData.setUserName(modification);
		}
		else if (reply == "password")
		{
			cout << "What is the new password?\n\n";
			getline(cin, modification);

			//setPassword is called and the modification is passed in order to update the password
			tmp->mData.setPassword(modification);
		}
		else
		{
			cout << "Invalid selection.\n\n";
		}
	}
	
	saveUsers(listOfUsers);
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
