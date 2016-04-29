#ifndef PUBLICMENU_H
#define PUBLICMENU_H

#include "common.h"
#ifdef _WIN32
	#include <conio.h>
#endif

using namespace std;

void displayItemMenu(LinkedList<Item> *listOfItems, LinkedList<Club> *listOfClubs, LinkedList<User> *listOfUsers);
/*
Pre: The lists of items, clubs, and users must be created
Post: The menu featuring the options for listed items is displayed to the console
Purpose: To display the menu specific to listed items
*/

void displaySearchMenu(LinkedList<Item> *listOfItems, LinkedList<Club> *listOfClubs, LinkedList<User> *listOfUsers);
/*
Pre: The lists of items, clubs, and users must be created
Post: The menu featuring the search options for listed items and clubs is displayed to the console
Purpose: To display the menu specific to searching items and clubs
*/

void login(LinkedList<Item> *listOfItems, LinkedList<Club> *listOfClubs, LinkedList<User> *listOfUsers);
/*
Pre: The lists of items, clubs, and users must be created
Post: The admin user is logged into the system 
Purpose: To allow admin users to access the admin menu
*/

void searchClub(LinkedList<Item> *listOfItems);
/*
Pre: The list of items must be created
Post: Information for a searched club is displayed to the console screen
Purpose: To display specific information for a valid club being search for
*/

void searchItem(LinkedList<Item> *listOfItems);
/*
Pre: The list of items must be created
Post: Information for a searched item is displayed to the console screen
Purpose: To display specific information for a valid item being search for
*/

void showInItems(LinkedList<Item> *listOfItems);
/*
Pre: The list of items must be created
Post: Specific information of each item that is checked in is displayed to the console screen
Purpose: To display which items are checked in
*/

void showOutItems(LinkedList<Item> *listOfItems);
/*
Pre: The list of items must be created
Post: Specific information of each item that is checked out is displayed to the console screen
Purpose: To display which items are checked out
*/

bool checkWords(string username, string password, LinkedList<Item> *listOfItems, LinkedList<Club> *listOfClubs, LinkedList<User> *listOfUsers);
/*
Pre: Two string variables must be passed by value and the lists of items, clubs, and users must be created
Post:
Purpose:
*/

bool validateStr(string str);
/*
Pre: A string variable must be passed by value
Post: A bool value is returned
Purpose: To determine if a string contains unwanted characters
*/

#endif 