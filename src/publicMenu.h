#ifndef PUBLICMENU_H
#define PUBLICMENU_H

#include "common.h"
#include <iomanip>
#include <string>
<<<<<<< HEAD
#include <conio.h>
=======
// doesnt compile on unix #include <conio.h>
>>>>>>> 2718255af37e8e8624dae9e445cbf2fd1dfe0da5
#include "LinkedList.h"
#include "Item.h"

using namespace std;

void displayItemMenu();

void displaySearchMenu(LinkedList<Item> *listOfItems);

void login();

void searchClub(LinkedList<Item> *listOfItems);

void searchItem(LinkedList<Item> *listOfItems);

void showInItems();
void showOutItems();
bool checkWords(string username, string password);

#endif 