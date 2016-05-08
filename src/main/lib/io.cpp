/*
    Created by Dustin Yost on 4/30/2016.
*/

#include "io.h"
#include <cstdlib>

/** PURPOSE: To clear the screen of the display
 * PRE:  None
 * POST: Clears the screen of all text
 */
void clear() {
	//return;
	#ifdef _WIN32
		system("CLS");
	#elif __APPLE__
		system("clear");
	#elif __linux__
		system("clear");
	#elif __unix__
		system("clear");
	#endif
}

/** PURPOSE: To pause the program until the user is ready to continue
 * PRE:  None
 * POST: Pause the program until a ENTER is pressed
 */
void pause() {
	#ifdef _WIN32
		system("pause");
	#elif __APPLE__
		cout << "Press ENTER to continue...";
		//system("read");
		cin.get();
	#elif __linux__
		cout << "Press ENTER to continue...";
		//system("read");
		cin.get();
	#elif __unix__
		cout << "Press ENTER to continue...";
		//system("read");
		cin.get();
	#endif
}

int cinInteger(string prompt) {
	
	int in;

	cout << prompt;
	cin >> in;
	getline(cin, prompt);

	return in;
}

string cinString(string prompt) {
	string in;

	cout << prompt;
	getline(cin, in);

	return in;
}
