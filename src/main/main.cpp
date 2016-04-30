/*
    Created by Dustin Yost on 4/30/2016.
*/

#include <iostream>
#include "class/item/Item.h"
#include "class/LinkedList.h"
#include "class/item/FileItem.h"
#include "class/user/User.h"
#include "class/user/FileUser.h"
#include <iomanip>

using namespace std;

int main() {

	cout << "Starting...\n\n";

	// ~~~~~ START: Init lists
	LinkedList<User> *users = new LinkedList<User>;
	LinkedList<Item> *items = new LinkedList<Item>;
	// ~~~~~~~ END: Init lists

	// ~~~~~ START: Load data
	loadUsers(users);
	loadItems(items);
	// ~~~~~~~ END: Load data

	cout << "Users:\n";
	users->display();
	cout << '\n';

	cout << "Items:\n";
	cout
		<< setw(10) << right
			<< "Serial"
		<< ' '
		<< setw(20) << left
			<< "Name"
		<< setw(20) << left
			<< "Club"
		<< '\n'
	;
	items->display();
	cout << '\n';

	// ~~~~~ START: Save data
	saveUsers(users);
	saveItems(items);
	// ~~~~~~~ END: Save data

	delete items;

	cout << "Ending...\n";

	return 0;
}
