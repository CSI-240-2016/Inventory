#ifndef PUBLICMENU_H
#define PUBLICMENU_H

#include "common.h"
#include <iomanip>
#include <string>
//#include <curses.h>
#include "LinkedList.h"
#include "Item.h"
#ifdef _WIN32
	#include <conio.h>
#endif

using namespace std;

void displayItemMenu(LinkedList<Item> *listOfItems);

void displaySearchMenu(LinkedList<Item> *listOfItems);

void login(LinkedList<Item> *listOfItems);

void searchClub(LinkedList<Item> *listOfItems);

void searchItem(LinkedList<Item> *listOfItems);

void showInItems(LinkedList<Item> *listOfItems);

void showOutItems(LinkedList<Item> *listOfItems);

bool checkWords(string username, string password, LinkedList<Item> *listOfItems);

#endif 