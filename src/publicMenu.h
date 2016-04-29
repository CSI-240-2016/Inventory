#ifndef PUBLICMENU_H
#define PUBLICMENU_H

#include "common.h"
#include "IO_Users.h"
#ifdef _WIN32
	#include <conio.h>
#endif

using namespace std;

void displayItemMenu(LinkedList<Item> *listOfItems, LinkedList<Club> *listOfClubs, LinkedList<User> *listOfUsers);

void displaySearchMenu(LinkedList<Item> *listOfItems, LinkedList<Club> *listOfClubs, LinkedList<User> *listOfUsers);

void login(LinkedList<Item> *listOfItems, LinkedList<Club> *listOfClubs, LinkedList<User> *listOfUsers);

void searchClub(LinkedList<Item> *listOfItems);

void searchItem(LinkedList<Item> *listOfItems);

void showInItems(LinkedList<Item> *listOfItems);

void showOutItems(LinkedList<Item> *listOfItems);

bool checkWords(string username, string password, LinkedList<Item> *listOfItems, LinkedList<Club> *listOfClubs, LinkedList<User> *listOfUsers);

bool validateStr(string str);

#endif 