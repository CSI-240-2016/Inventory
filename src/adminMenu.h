#ifndef ADMINMENU_H
#define ADMINMENU_H

#include "Item.h"
#include "club.h"
#include "User.h"
#include "LinkedList.h"

using namespace std;

void addClub(LinkedList<Club> *listOfClubs);
/*
Pre: The list of clubs must be created
Post: A new club is added to the system
Purpose: To add a new club
*/

void addUser(LinkedList<User> *listOfUsers);
/*
Pre: The list of users must be created
Post: A new user is added to the system
Purpose: To add a new user
*/

void addItem(LinkedList<Item> *listOfItems);
/*
Pre: The list of items must be created
Post: A new item is added to the system
Purpose: To add a new item
*/

void checkInOut(LinkedList<Item> *listOfItems);
/*
Pre: The list of items must be created
Post: An item's status is changed to either checked in or checked out
Purpose: To check items in and out
*/

void displayAdminClub(LinkedList<Item> *listOfItems, LinkedList<Club> *listOfClubs, LinkedList<User> *listOfUsers);
/*
Pre: The lists of items, clubs, and users must be created
Post: The menu featuring admin options for club information is displayed to the console screen
Purpose: To display the admin options for clubs
*/

void displayAdminItem(LinkedList<Item> *listOfItems, LinkedList<Club> *listOfClubs, LinkedList<User> *listOfUsers);
/*
Pre: The lists of items, clubs, and users must be created
Post: The menu featuring admin options for item information is displayed to the console screen
Purpose: To display the admin options for items
*/

void displayAdminSearch(LinkedList<Item> *listOfItems, LinkedList<Club> *listOfClubs, LinkedList<User> *listOfUsers);
/*
Pre: The lists of items, clubs, and users must be created
Post: The menu featuring admin search options is displayed to the console screen
Purpose: To display the admin search options
*/

void displayAdminUser(LinkedList<Item> *listOfItems, LinkedList<Club> *listOfClubs, LinkedList<User> *listOfUsers);
/*
Pre: The lists of item, clubs, and users must be created
Post: The menu featuring admin options for user information is displayed to the console screen
Purpose: To display the admin options for users
*/

void exportExcel(LinkedList<Item> *listOfItems);
/*
Pre: The list of items must be created
Post: Information of each listed item is exported to a spreadsheet
Purpose: To export inventory information
*/

string getFileName();
/*
Pre: None
Post: An export file is given a specified name
Purpose: To label export files
*/

void removeClub(LinkedList<Club> *listOfClubs);
/*
Pre: The list of clubs must be created
Post: A club is removed from the list
Purpose: To remove a specific club
*/

void removeItem(LinkedList<Item> *);
/*
Pre: The list of items must be created
Post: An item is removed from the list
Purpose: To remove a specific item
*/

void removeUser(LinkedList<User> *listOfUsers);
/*
Pre: The list of users must be created
Post: A user is removed from the list
Purpose: To remove a specific club
*/

void modifyClub(LinkedList<Club> *listOfClubs);
/*
Pre: The list of clubs must be created
Post: A specific club's information is updated
Purpose: To update a club's information
*/

void modifyItem(LinkedList<Item> *);
/*
Pre: The list of items must be created
Post: A specific item's information is updated
Purpose: To update an item's information
*/

void modifyUser(LinkedList<User> *listOfUsers);
/*
Pre: The list of users must be created
Post: A specific user's information is updated
Purpose: To update a user's information
*/

void showAllItems(LinkedList<Item> *listOfItems);
/*
Pre: The list of items must be created
Post: Specific information for all listed items is displayed to the console screen
Purpose: To display information for all listed items
*/

//bool validateStr(string str);

#endif
