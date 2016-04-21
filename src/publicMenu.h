#ifndef PUBLICMENU_H
#define PUBLICMENU_H

#include "common.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void displayItemMenu();
void displaySearchMenu();
void logIn(string username, string password);
void searchClub();
void searchItem();
void showInItems();
void showOutItems();
bool checkWords(string username, string password);

#endif 