/*
    Created by Dustin Yost on 4/30/2016.
*/

#include "actions.h"
#include "../lib/display.h"
#include "../lib/io.h"
#include "../item/FileItem.h"

/** Purpose: To display specific information for a valid item being search for
 * PRE:  The list of item must be created
 * POST: Information for a searched item is displayed to the console screen
*/
void showItemsViaStatus(LinkedList<Item> *listOfItems, bool isIn) {
	Node<Item> *tmp;

	tmp = listOfItems->getHead();

	cout << "\n";

	if (tmp == NULL) {
		cout << "There are no items\n";
		pause();
		return;
	}

	int quantityItemsIn = 0;
	while (tmp != NULL) {
		/*
		if (tmp->mData.isCheckedIn()) {
			quantityItemsIn++;
			cout
				<< "Name:\t"	<< tmp->mData.getName()		<< "\n"
				<< "Serial:\t"	<< tmp->mData.getSerial()	<< "\n"
			;
		}
		*/
		tmp = tmp->mNext;
	}

	if (quantityItemsIn <= 0) {
		cout << "There are no item ";
		if (isIn) cout << "in.\n";
		else cout << "out.\n";
	}

}

/** Purpose: To display specific information for a valid item being search for
* PRE:  The list of items, The serial number
* POST: Displays a list of items matching the serial number
*/
void showItemsBySerial(LinkedList<Item> *listOfItems, int serial) {
	Node<Item> *tmp = listOfItems->getHead();
	if (tmp == NULL) {
		cout << "There are no items\n";
		pause();
	}
	else while (tmp != NULL) {
		if (tmp->mData.getSerial() == serial)
			cout << tmp->mData << "\n";
		tmp = tmp->mNext;
	}
}

/** Purpose: To display specific information for a valid item being search for
* PRE:  The list of items, The type
* POST: Displays a list of items matching the type
*/
void showItemsByType(LinkedList<Item> *listOfItems, string type) {
	Node<Item> *tmp = listOfItems->getHead();
	if (tmp == NULL) {
		cout << "There are no items\n";
		pause();
	}
	else while (tmp != NULL) {
		if (tmp->mData.getDescription() == type)
			cout << tmp->mData << "\n";
		tmp = tmp->mNext;
	}
}

/** Purpose: To display specific information for a valid item being search for
* PRE:  The list of items, The club
* POST: Displays a list of items matching the club
*/
void showItemsByClub(LinkedList<Item> *listOfItems, string club) {
	Node<Item> *tmp = listOfItems->getHead();
	if (tmp == NULL) {
		cout << "There are no items\n";
		pause();
	}
	else while (tmp != NULL) {
		if (tmp->mData.getClubName() == club)
			cout << tmp->mData << "\n";
		tmp = tmp->mNext;
	}
}

void addItem(LinkedList<Item> *items, int serial) {
	Item item = Item(serial);
	cin >> item; // stream should be completely clean afterwards
	items->append(item);
	saveItems(items);
}

bool removeItem(LinkedList<Item> *items, int serial) {
	Node<Item> *tmp = items->getHead(), *before = NULL;
	while (tmp != NULL) {
		if (tmp->mData.getSerial() == serial) {
			
			if (before == NULL) { // is the head node
				items->mHead = tmp->mNext;
			}
			else { // not the head node
				before->mNext = tmp->mNext;
			}

			if (items->mTail == tmp) { // to be deleted is the tail
				items->mTail = before;
			}

			items->mCount--;

			delete tmp;

			return true;
		}
		before = tmp;
		tmp = tmp->mNext;
	}
	cout << "No such item with serial " << serial << ".\n";
	return false;
}

void changeItem(LinkedList<Item> *items, int serial) {
	Node<Item> *tmp = items->getHead(), *before = NULL;
	bool complete = false;
	int choice, inputSerial;
	string name, description, club;
	Location location;
	Source source;

	while (tmp != NULL) {
		if (tmp->mData.getSerial() == serial) {
			do {
				displayMenuWithPrompt(MENU_CHANGE_ITEM, MENU_CHANGE_ITEM_SIZE, choice, "Change Item Menu", "Enter a choice: ");

				clear();

				switch (choice) {
					case -1:
						complete = true;
						return;
					case 1: //Serial
						cout << "Current Serial: " << tmp->mData.getSerial() << endl;
						cout << "New Serial: ";
						cin >> inputSerial;
						tmp->mData.setSerial(inputSerial);
						break;
					case 2: //Name
						cout << "Current Name: " << tmp->mData.getName() << endl;
						cout << "New Name: ";
						getline(cin, name);
						tmp->mData.setName(name);
						break;
					case 3: //Description
						cout << "Current Description: \n" << tmp->mData.getDescription() << endl;
						cout << "New Description: \n";
						getline(cin, description);
						tmp->mData.setDescription(description);
						break;
					case 4: //Club
						cout << "Current Club Name: " << tmp->mData.getClubName() << endl;
						cout << "New Club Name: ";
						getline(cin, club);
						tmp->mData.setClubName(club);
						break;
					case 5: //Location
						cout << "Current Location Information: \n" << location << endl;
						cout << "New Location Information: \n";
						cin >> location;
						tmp->mData.setLocation(location);
						break;
					case 6: //Source
						Source source = tmp->mData.getSource();
						cout << "Current Source Information: \n" << source << endl;
						cout << "New Source Information: \n";
						cin >> source;
						tmp->mData.setSource(source);
						break;
				}
			} while (!complete);

			return;
		}
	}
	cout << "No such item with serial " << serial << ".\n";
}