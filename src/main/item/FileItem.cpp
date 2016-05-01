/*
    Created by Dustin Yost on 4/30/2016.
*/

#include <fstream>
#include "FileItem.h"

void loadItems(LinkedList<Item> *list) {
	ifstream file;
	file.open(FILE_DATA_ITEMS, ios::in);

	if (file.is_open()) {
		// Create a pointer to easily get rid of the object after each loop
		Item *ptr_element = new Item();

		// try to read the serial number from file
		while (ptr_element->readSerial(file)) {

			// load the item data from file
			file >> (*ptr_element);

			// append the object to the list
			list->append(*ptr_element);

			// Create a fresh item object
			ptr_element = new Item();
		}

		delete ptr_element;
	}

	file.close();
}

void saveItems(LinkedList<Item> *list) {
	ofstream file;
	file.open(FILE_DATA_ITEMS, ios::out);

	if (file.is_open()) {
		Node<Item> *tmp = list->getHead();
		while (tmp != NULL) {
			file << tmp->mData;
			tmp = tmp->mNext;
			if (tmp != NULL) file << '\n';
		}
	}

	file.close();
}
