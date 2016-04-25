#ifndef PUBLICMENU_H
#define PUBLICMENU_H

#include "common.h"
#include <iomanip>
<<<<<<< HEAD
=======
#include <string>
>>>>>>> 6df10f71b288fedc8743669994b9c65ce6cda287
#include <conio.h>
#include "LinkedList.h"

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