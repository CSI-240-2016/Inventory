/*
    Created by Dustin Yost on 4/30/2016.
*/

#include "display.h"
#include "io.h"
#include <iomanip>

/** PURPOSE: Displays a menu to the user
* PRE: Takes an array of string options and the array size
* POST: The index of the selected option
*/
void displayMenuWithPrompt(const string options[], int size, int &choice, string title, string prompt) {
	// handles the junk after a user's choice AND the error message if the user enters something wrong
	string junkAndError = "", titleSuffix = " (-1 to exit):";
	int titleLength = title.length() + titleSuffix.length() + 1;

	int promptLength = prompt.length() + 1;
	int spacing = titleLength;
	if (promptLength > spacing) spacing = promptLength;

	do {
		clear();

		if (!junkAndError.empty()) {
			cout << junkAndError << '\n';
		}

		cout << title << titleSuffix << '\n';
		for (choice = 0; choice < size; choice++)
			cout << setw(spacing) << right << (choice + 1) << ") " << left << options[choice] << '\n';
		cout << '\n';

		cout << setw(spacing) << right << prompt;
		cin >> choice;
		getline(cin, junkAndError);

		if (choice != -1 && (choice < 1 || choice > size))
			junkAndError = "That is not a valid selection.";
		else
			junkAndError = "";

	} while (choice != -1 && (choice < 1 || choice > size));

}
