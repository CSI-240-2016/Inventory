/*
    Created by Dustin Yost on 4/30/2016.
*/

#include "menu.h"
#include "../lib/display.h"
#include "actionsPublic.h"

/** PURPOSE: Run the main program loop
 * PRE:  load lists from data files
 * POST: None
 */
void run(LinkedList<User> *users, LinkedList<Item> *items, LinkedList<Log> *logs) {
	bool shouldExit;
	do {
		shouldExit = runMenuMain(users, items, logs);
	} while (!shouldExit);
}

/** PURPOSE: Display the main menu & take user input
 * PRE:  the data lists
 * POST: true if the program should shutdown
 */
bool runMenuMain(LinkedList<User> *users, LinkedList<Item> *items, LinkedList<Log> *logs) {

	int choice;

	displayMenuWithPrompt(MENU_GENERAL_PUBLIC, MENU_GENERAL_PUBLIC_SIZE, choice, "Main Menu", "Enter a choice: ");

	switch (choice) {
		case -1:
			return true;
		case 1: // Items
			runMenuItem(items, choice);
			break;
		case 2: // Log In

			break;
		default: break;
	}

	return false;
}

/** PURPOSE: Display the main menu & take user input
 * PRE:  The item data
 * POST: None
 */
void runMenuItem(LinkedList<Item> *items, int &choice) {

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
