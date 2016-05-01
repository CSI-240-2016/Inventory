/*
    Created by Dustin Yost on 4/30/2016.
*/

#include <fstream>
#include "FileUser.h"

void loadUsers(LinkedList<User> *list) {
	ifstream file;
	file.open(FILE_DATA_USERS, ios::in);

	if (file.is_open()) {
		// Create a pointer to easily get rid of the object after each loop
		User *ptr_element = new User();

		// try to read the serial number from file
		while (ptr_element->readUsername(file)) {

			// load the item data from file
			file >> (*ptr_element);

			// append the object to the list
			list->append(*ptr_element);

			// Create a fresh item object
			ptr_element = new User();
		}

		delete ptr_element;
	}

	file.close();
}

void saveUsers(LinkedList<User> *list) {
	ofstream file;
	file.open(FILE_DATA_USERS, ios::out);

	if (file.is_open()) {
		Node<User> *tmp = list->getHead();
		while (tmp != NULL) {
			file << tmp->mData;
			tmp = tmp->mNext;
			if (tmp != NULL) file << '\n';
		}
	}

	file.close();
}
