#ifndef ADMINMENU_H
#define ADMINMENU_H

#include "publicMenu.h"
#include "common.h"
#include "Item.h"

using namespace std;

void addClub();
void addItem();
void addUser();
void checkInOut(LinkedList<Item> *listOfItems);
void displayAdminClub(LinkedList<Item> *listOfItems);
void displayAdminItem(LinkedList<Item> *listOfItems);
void displayAdminSearch(LinkedList<Item> *listOfItems);
void displayAdminUser(LinkedList<Item> *listOfItems);
void exportExcel();
void removeClub();
void removeItem();
void removeUser();
void modifyClub();
void modifyItem();
void modifyUser();
void showAllItems(LinkedList<Item> *listOfItems);

#endif
