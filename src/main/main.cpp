/*
    Created by Dustin Yost on 4/30/2016.
*/

#include <iostream>
#include <iomanip>
#include "LinkedList.h"
#include "item/Item.h"
#include "item/FileItem.h"
#include "user/User.h"
#include "user/FileUser.h"
#include "log/Log.h"
#include "log/FileLog.h"
#include "menu/menu.h"

using namespace std;

int main() {

	cout << "Starting...\n\n";

	// ~~~~~ START: Init lists
	LinkedList<User> *users = new LinkedList<User>;
	LinkedList<Item> *items = new LinkedList<Item>;
	LinkedList<Log> *logs = new LinkedList<Log>;
	// ~~~~~~~ END: Init lists

	// ~~~~~ START: Load data
	loadUsers(users);
	loadItems(items);
	loadLogs(logs);
	// ~~~~~~~ END: Load data

	cout << "Users:\n";
	users->display();
	cout << '\n';

	cout << "Items:\n";
	cout
		<< setw(10) << right
			<< "Serial" << ' '
		<< setw(20) << left
			<< "Name"
		<< setw(20) << left
			<< "Club"
		<< '\n'
	;
	items->display();
	cout << '\n';

	cout << "Logs:\n";
	cout
		<< setw(10) << right
			<< "Serial" << ' '
		<< setw(20) << left
			<< "Name"
		<< setw(20) << left
			<< "Club"
		<< setw(15) << left
			<< "Date Out"
		<< setw(15) << left
			<< "Date In Exp."
		<< setw(15) << left
			<< "Date In"
		<< '\n'
	;
	logs->display();
	cout << '\n';

	run(users, items, logs);

	// ~~~~~ START: Save data
	saveUsers(users);
	saveItems(items);
	saveLogs(logs);
	// ~~~~~~~ END: Save data

	delete users;
	delete items;
	delete logs;

	cout << "Ending...\n";

	return 0;
}
