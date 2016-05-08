/*
    Created by Dustin Yost on 4/30/2016.
*/

#include "menu.h"
#include "../lib/display.h"
#include "../lib/io.h"
#include "actions.h"

/** PURPOSE: Run the main program loop
 * PRE:  load lists from data files
 * POST: None
 */
void run(LinkedList<User> *users, LinkedList<Item> *items, LinkedList<Log> *logs) {
	bool shouldExit, loggedIn = false;
	do {
		shouldExit = runMenuMain(users, items, logs, loggedIn);
	} while (!shouldExit);
}

/** PURPOSE: Display the main menu & take user input
 * PRE:  the data lists
 * POST: true if the program should shutdown
 */
bool runMenuMain(LinkedList<User> *users, LinkedList<Item> *items, LinkedList<Log> *logs, bool &loggedIn) {

	int choice;

	if (!loggedIn) {

		displayMenuWithPrompt(MENU_GENERAL_PUBLIC, MENU_GENERAL_PUBLIC_SIZE, choice, "Main Menu", "Enter a choice: ");
		
		clear();

		switch (choice) {
			case -1:
				return true;
			case 1: // Items
				runMenuItem(items, choice, loggedIn);
				break;
			case 2: // Login
				loggedIn = logInUser(users);
				break;
			default: break;
		}

	}
	else {

		displayMenuWithPrompt(MENU_GENERAL_ADMIN, MENU_GENERAL_ADMIN_SIZE, choice, "Admin Menu", "Enter a choice: ");

		switch (choice) {
			case -1:
				return true;
			case 1: // Items
				runMenuItem(items, choice, loggedIn);
				break;
			case 2: // Clubs

				break;
			case 3: // Users

				break;
			case 4: // Export

				break;
			case 5: // Logout
				loggedIn = false;
				cout << "\nYou have been logged out.\n\n";
				pause();
				break;
			default: break;
		}

	}

	return false;
}

/** PURPOSE: Display the main menu & take user input
 * PRE:  The item data
 * POST: None
 */
void runMenuItem(LinkedList<Item> *items, int &choice, bool loggedIn) {

	if (!loggedIn) {

		displayMenuWithPrompt(MENU_ITEM_PUBLIC, MENU_ITEM_PUBLIC_SIZE, choice, "Item Menu", "Enter a choice: ");

		switch (choice) {
			case 1: // View Items In
				showItemsViaStatus(items, true);
				break;
			case 2: // View Items Out
				showItemsViaStatus(items, false);
				break;
			default: break;
		}

	}
	else {

		displayMenuWithPrompt(MENU_ITEM_ADMIN, MENU_ITEM_ADMIN_SIZE, choice, "Item Menu", "Enter a choice: ");

		switch (choice) {
			case 1: // Add
				clear();
				addItem(items, cinInteger("Enter the serial number: "));
				break;
			case 2: // Modify
				clear();
				changeItem(items, cinInteger("Enter the serial number: "));
				break;
			case 3: // Remove
				clear();
				if (!removeItem(items, cinInteger("Enter the serial number: ")))
					cout << "Unable to remove.\n";
				pause();
				break;
			case 4: // View Items In
				showItemsViaStatus(items, true);
				break;
			case 5: // View Items Out
				showItemsViaStatus(items, false);
				break;
			case 6: // Search For Item by Serial
				clear();
				showItemsBySerial(items, cinInteger("Enter the serial number: "));
				pause();
				break;
			case 7: // Search For Item by Type
				clear();
				showItemsByType(items, cinString("Enter an item description: "));
				pause();
				break;
			case 8: // Search For Item by Club
				clear();
				showItemsByClub(items, cinString("Enter a club name: "));
				pause();
				break;
			default: break;
		}

	}

}

/** PURPOSE: Take user input in order to log in a user
* PRE:  the user list
* POST: log in the user with details entered by user
*/
bool logInUser(LinkedList<User> *users) {

	if (users->getHead() == NULL) {
		cout << "There are no users. Please contact the systems administrator.\n";
		return false;
	}
	
	string username, password, junk;
	Node<User> *tmp;

	do {
		
		cout << "Enter username: ";
		cin >> username;
		getline(cin, junk);
		
		cout << "Enter password: ";
		cin >> password;
		getline(cin, junk);

		tmp = users->getHead();
		while (tmp != NULL) {
			if (tmp->mData.getUsername() == username &&
					tmp->mData.getPassword() == password) {
				cout << "\nYou have been logged in as " << username << ".\n\n";
				pause();
				return true;
			}
			tmp = tmp->mNext;
		}

	} while (true);

	return false;
}
