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

<<<<<<< HEAD
void addClub();
void addItem(LinkedList<Item> *listOfItems);
void addUser();
=======
void addClub(LinkedList<Item> *listOfClubs);
void addItem();
void addUser(LinkedList<User> *listOfUsers);
>>>>>>> 27210ec7db058103b0e722fff71261c6d4bb01fe
void checkInOut(LinkedList<Item> *listOfItems);
void displayAdminClub(LinkedList<Item> *listOfItems);
void displayAdminItem(LinkedList<Item> *listOfItems);
void displayAdminSearch(LinkedList<Item> *listOfItems);
void displayAdminUser(LinkedList<Item> *listOfItems, LinkedList<User> *listOfUsers);
void exportExcel();
<<<<<<< HEAD
void removeClub();
void removeItem(LinkedList<Item> *listOfItems);
void removeUser();
void modifyClub();
void modifyItem(LinkedList<Item> *listOfItems);
=======
void removeClub(LinkedList<Item> *listOfClubs);
void removeItem();
void removeUser();
void modifyClub(LinkedList<Item> *listOfClubs);
void modifyItem();
>>>>>>> 27210ec7db058103b0e722fff71261c6d4bb01fe
void modifyUser();
void showAllItems(LinkedList<Item> *listOfItems);
//bool validateStr(string str);

#endif
