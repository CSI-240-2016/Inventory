/*
    Created by Dustin Yost on 4/30/2016.
*/

#include <iostream>
#include "class/item/Item.h"
#include "class/item/LinkedList.h"
#include "files/items.h"

using namespace std;

int main() {

	cout << "Starting...\n\n";

	// ~~~~~ START: Init lists
	LinkedList<Item> *items = new LinkedList<Item>;
	// ~~~~~~~ END: Init lists

	// ~~~~~ START: Load data
	loadItems(items);
	// ~~~~~~~ END: Load data

	cout << "Items:\n";
	items->display();
	cout << '\n';

	// ~~~~~ START: Save data
	saveItems(items);
	// ~~~~~~~ END: Save data

	delete items;

	cout << "Ending...\n";

	return 0;
}
