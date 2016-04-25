#ifndef PUBLICMENU_H
#define PUBLICMENU_H

#include "common.h"
#include <iomanip>

#include <string>
#include <conio.h>
#include "LinkedList.h"

using namespace std;

void displayItemMenu();


void displaySearchMenu(LinkedList<Item> *listOfItems);

void login();


void searchClub(LinkedList<Item> *listOfItems);

void searchItem(LinkedList<Item> *listOfItems);


void showInItems(LinkedList<Item> *listOfItems);

void showOutItems(LinkedList<Item> *listOfItems);
bool checkWords(string username, string password);

#endif 