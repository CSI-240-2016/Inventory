#ifndef ADMINMENU_H
#define ADMINMENU_H

#include "publicMenu.h"
#include "common.h"
#include "Item.h"
#include "club.h"
#include "clubsDat.h"
#include "itemsDat.h"
#include "IO_Users.h"
#include "LinkedList.h"

using namespace std;

void addClub(LinkedList<Club> *listOfClubs);
void addUser(LinkedList<User> *listOfUsers);
void addItem(LinkedList<Item> *listOfItems);
void checkInOut(LinkedList<Item> *listOfItems);
void displayAdminClub(LinkedList<Item> *listOfItems, LinkedList<Club> *listOfClubs, LinkedList<User> *listOfUsers);
void displayAdminItem(LinkedList<Item> *listOfItems, LinkedList<Club> *listOfClubs, LinkedList<User> *listOfUsers);
void displayAdminSearch(LinkedList<Item> *listOfItems, LinkedList<Club> *listOfClubs, LinkedList<User> *listOfUsers);
void displayAdminUser(LinkedList<Item> *listOfItems, LinkedList<Club> *listOfClubs, LinkedList<User> *listOfUsers);
void exportExcel();
void removeClub(LinkedList<Club> *listOfClubs);
void removeItem(LinkedList<Item> *);
void removeUser(LinkedList<User> *listOfUsers);
void modifyClub(LinkedList<Club> *listOfClubs);
void modifyItem(LinkedList<Item> *);
void modifyUser(LinkedList<User> *listOfUsers);
void showAllItems(LinkedList<Item> *listOfItems);
//bool validateStr(string str);

#endif
