/*
    Created by Dustin Yost on 4/30/2016.
*/

#ifndef INVENTORY_DISPLAY_H
#define INVENTORY_DISPLAY_H

#include <string>

using namespace std;

/** PURPOSE: Displays a menu to the user
* PRE: String array of options, the size of the array, a choice integer, the menu title, the prompt
* POST: The index of the selected option
*/
void displayMenuWithPrompt(const string options[], int size, int &choice, string title, string prompt);

#endif //INVENTORY_DISPLAY_H
