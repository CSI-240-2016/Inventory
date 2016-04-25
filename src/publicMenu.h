#ifndef PUBLICMENU_H
#define PUBLICMENU_H

#include "common.h"
#include <iostream>
#include <iomanip>
#include <string>
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

template <typename T>
void showInItems(LinkedList<Item> *listOfItems);
template <typename T>
void showOutItems(LinkedList<Item> *listOfItems);
bool checkWords(string username, string password);

#endif 