#ifndef PUBLICMENU_H
#define PUBLICMENU_H

#include "common.h"
#include <iostream>
#include <iomanip>
#include <string>
<<<<<<< HEAD
#include <conio.h>
=======
#include "LinkedList.h"
>>>>>>> 1af67a2af313c05b2bf26e878ce61daa8dc3ab6e

using namespace std;

void displayItemMenu();

template <typename T>
void displaySearchMenu(LinkedList<Item> *listOfItems);

void logIn();

template <typename T>
void searchClub(LinkedList<Item> *listOfItems);

template <typename T>
void searchItem(LinkedList<Item> *listOfItems);

void showInItems();
void showOutItems();
bool checkWords(string username, string password);

#endif 