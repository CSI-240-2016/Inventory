#ifndef ADMINMENU_H
#define ADMINMENU_H

#include "publicMenu.h"
#include "common.h"
#include "Item.h"
#include "club.h"
#include "clubsDat.h"
#include "itemsDat.h"

using namespace std;

void addClub();
void addItem(LinkedList<Item> *listOfItems);
void addUser();
void checkInOut(LinkedList<Item> *listOfItems);
void displayAdminClub(LinkedList<Item> *listOfItems);
void displayAdminItem(LinkedList<Item> *listOfItems);
void displayAdminSearch(LinkedList<Item> *listOfItems);
void displayAdminUser(LinkedList<Item> *listOfItems);
void exportExcel();
void removeClub();
void removeItem(LinkedList<Item> *listOfItems);
void removeUser();
void modifyClub();
void modifyItem(LinkedList<Item> *listOfItems);
void modifyUser();
void showAllItems(LinkedList<Item> *listOfItems);
bool validateStr(string str);

#endif
