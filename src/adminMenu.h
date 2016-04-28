#ifndef ADMINMENU_H
#define ADMINMENU_H

#include "publicMenu.h"
#include "common.h"
#include "Item.h"
#include "club.h"
#include "clubsDat.h"
#include "itemsDat.h"
#include "IO_Users.h"

using namespace std;

void addClub(LinkedList<Item> *listOfClubs);
void addUser(LinkedList<User> *listOfUsers);
void addItem(LinkedList<Item> *listOfItems);
void checkInOut(LinkedList<Item> *listOfItems);
void displayAdminClub(LinkedList<Item> *listOfItems);
void displayAdminItem(LinkedList<Item> *listOfItems);
void displayAdminSearch(LinkedList<Item> *listOfItems);
void displayAdminUser(LinkedList<Item> *listOfItems, LinkedList<User> *listOfUsers);
void exportExcel();
void removeClub(LinkedList<Item> *listOfClubs);
void removeItem(LinkedList<Item> *);
void removeUser(LinkedList<User> *listOfUsers);
void modifyClub(LinkedList<Item> *listOfClubs);
void modifyItem(LinkedList<Item> *);
void modifyUser(LinkedList<User> *listOfUsers);
void showAllItems(LinkedList<Item> *listOfItems);
//bool validateStr(string str);

#endif
