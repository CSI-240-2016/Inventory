#ifndef PUBLICMENU_H
#define PUBLICMENU_H

#include "common.h"
#include <iomanip>
#include <string>
// doesnt compile on unix #include <conio.h>
#include "LinkedList.h"
#include "Item.h"

using namespace std;

void displayItemMenu();

template <typename T>
void displaySearchMenu(LinkedList<Item> *listOfItems);

void login();

template <typename T>
void searchClub(LinkedList<Item> *listOfItems);

template <typename T>
void searchItem(LinkedList<Item> *listOfItems);

void showInItems();
void showOutItems();
bool checkWords(string username, string password);

#endif 