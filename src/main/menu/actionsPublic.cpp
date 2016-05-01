/*
    Created by Dustin Yost on 4/30/2016.
*/

#include "actionsPublic.h"
#include "../lib/io.h"

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
