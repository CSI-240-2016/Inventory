/*
    Created by Dustin Yost on 4/30/2016.
*/

#include "FileLog.h"

void loadLogs(LinkedList<Log> *list) {
	ifstream file;
	file.open(FILE_DATA_LOGS, ios::in);

	if (file.is_open()) {
		// Create a pointer to easily get rid of the object after each loop
		Log *ptr_element = new Log();

		// try to read the serial number from file
		while (ptr_element->readPrimary(file)) {

			// load the item data from file
			file >> (*ptr_element);

			// append the object to the list
			list->append(*ptr_element);

			// Create a fresh item object
			ptr_element = new Log();
		}

		delete ptr_element;
	}

	file.close();
}

void saveLogs(LinkedList<Log> *list) {
	ofstream file;
	file.open(FILE_DATA_LOGS, ios::trunc);

	if (file.is_open()) {
		Node<Log> *tmp = list->getHead();
		while (tmp != NULL) {
			file << tmp->mData;
			tmp = tmp->mNext;
			if (tmp != NULL) file << '\n';
		}
	}

	file.close();
}
