/*
    Created by Dustin Yost on 4/30/2016.
*/

#ifndef INVENTORY_MENU_H
#define INVENTORY_MENU_H

#include "../LinkedList.h"
#include "../user/User.h"
#include "../item/Item.h"
#include "../log/Log.h"
#include <string>

using namespace std;

const int		MENU_GENERAL_PUBLIC_SIZE = 2;
const string	MENU_GENERAL_PUBLIC[] = { "Items", "Log In as Admin" };
const int		MENU_ITEM_PUBLIC_SIZE = 2;
const string	MENU_ITEM_PUBLIC[] = { "View Items In", "View Items Out" };

const int		MENU_GENERAL_ADMIN_SIZE = 5;
const string	MENU_GENERAL_ADMIN[] = { "Items", "Clubs", "Users", "Export", "Logout" };

const int		MENU_ITEM_ADMIN_SIZE = 8;
const string	MENU_ITEM_ADMIN[] = {
		"Add", "Modify", "Remove",
		"View Items In", "View Items Out",
		"Search For Item by Serial", "Search For Item by Type", "Search For Item by Club"
};

const int		MENU_CLUB_ADMIN_SIZE = 3;
const string	MENU_CLUB_ADMIN[] = {
	"Add", "Modify", "Remove"
};

const int		MENU_USER_ADMIN_SIZE = 3;
const string	MENU_USER_ADMIN[] = {
	"Add", "Modify", "Remove"
};

/** PURPOSE: Run the main program loop
 * PRE:  load lists from data files
 * POST: None
 */
void run(LinkedList<User> *users, LinkedList<Item> *items, LinkedList<Log> *logs);

/** PURPOSE: Display the main menu & take user input
 * PRE:  the data lists
 * POST: true if the program should shutdown
 */
bool runMenuMain(LinkedList<User> *users, LinkedList<Item> *items, LinkedList<Log> *logs, bool &loggedIn);

/** PURPOSE: Display the item menu & take user input
 * PRE:  The item data, the choice variable
 * POST: None
 */
void runMenuItem(LinkedList<Item> *items, int &choice, bool loggedIn);

/** PURPOSE: Take user input in order to log in a user
 * PRE:  the user list
 * POST: if the user logged in
 */
bool logInUser(LinkedList<User> *users);

#endif //INVENTORY_MENU_H
