/*
    Created by Dustin Yost on 4/30/2016.
*/

#include "actions.h"
#include "../lib/display.h"
#include "../lib/io.h"
#include "../item/FileItem.h"
#include "../user/FileUser.h"

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
				displayMenuWithPrompt(MENU_CHANGE_ITEM, MENU_CHANGE_ITEM_SIZE, choice, "Modify Item Menu", "Enter a choice: ");

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
						source = tmp->mData.getSource();
						cout << "Current Source Information: \n" << source << endl;
						cout << "New Source Information: \n";
						cin >> source;
						tmp->mData.setSource(source);
						break;
					default: break;
				}
				saveItems(items);
			} while (!complete);

			return;
		}
	}
	cout << "No such item with serial " << serial << ".\n";
}

void addUser(LinkedList<User> *users, string username) {
	User obj = User();
	obj.setUsername(username);
	cin >> obj; // stream should be completely clean afterwards
	users->append(obj);
	saveUsers(users);
}

bool removeUser(LinkedList<User> *users, string username) {
	Node<User> *tmp = users->getHead(), *before = NULL;
	while (tmp != NULL) {
		if (tmp->mData.getUsername() == username) {

			if (before == NULL) { // is the head node
				users->mHead = tmp->mNext;
			}
			else { // not the head node
				before->mNext = tmp->mNext;
			}

			if (users->mTail == tmp) { // to be deleted is the tail
				users->mTail = before;
			}

			users->mCount--;

			delete tmp;

			return true;
		}
		before = tmp;
		tmp = tmp->mNext;
	}
	cout << "No such user with username " << username << ".\n";
	return false;
}

void changeUser(LinkedList<User> *users, string username) {
	Node<User> *tmp = users->getHead(), *before = NULL;
	bool complete = false;
	string input;
	int choice;

	while (tmp != NULL && !complete) {
		if (tmp->mData.getUsername() != username) continue;
		do {
			clear();

			displayMenuWithPrompt(MENU_CHANGE_USER, MENU_CHANGE_USER_SIZE, choice, "Modify User Menu", "Enter a choice: ");

			switch (choice) {
				case -1:
					complete = true;
					return;
				case 1: // Name
					cout << "Current Name: " << tmp->mData.getName() << endl;
					cout << "New Name: ";
					getline(cin, input);
					tmp->mData.setName(input);
					break;
				case 2: // Username
					cout << "Current Username: " << tmp->mData.getUsername() << endl;
					cout << "New Username: ";
					getline(cin, input);
					tmp->mData.setUsername(input);
					break;
				case 3: // Password
					cout << "Current Password: " << tmp->mData.getPassword() << endl;
					cout << "New Password: ";
					getline(cin, input);
					tmp->mData.setPassword(input);
					break;
				default: break;
			}
			saveUsers(users);
		} while (!complete);
	}

	cout << "No such user with username " << username << ".\n";
}

void exportExcel(LinkedList<Item> *items, LinkedList<User> *users, LinkedList<Log> *logs) {
	string extension, fileName;

	extension = "xml";
	/*
	do {
		extension = cinString("Enter extension (xml): ");
		if (extension != "xml")
			cout << "Invalid extension.\n";
	} while (extension != "xml");
	*/

	fileName = cinString("Enter file name (w/o ext): ");

	ofstream file;
	file.open(fileName + "." + extension, ios::out);
	if (file.is_open()) {
		
		if (extension == "xml") {
			file
				<< "<?xml version=\"1.0\"?>" << '\n'
				<< "<Workbook"
					<< " xmlns=\"urn:schemas-microsoft-com:office:spreadsheet\""
					<< " xmlns:o=\"urn:schemas-microsoft-com:office:office\""
					<< " xmlns:x=\"urn:schemas-microsoft-com:office:excel\""
					<< " xmlns:ss=\"urn:schemas-microsoft-com:office:spreadsheet\""
					<< " xmlns:html=\"http://www.w3.org/TR/REC-html40\""
				<< ">" << '\n'
			;

			// ~~~~~~~~~ Start: Items ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

			file
				<< "\t<Worksheet ss:Name=\"Items\">" << '\n'
				<< "\t\t<Table "
					<< "ss:ExpandedRowCount=\"" << (1 + items->getCount()) << "\" "
					<< "ss:ExpandedColumnCount=\"" << 4 << "\" "
					<< "ss:DefaultRowHeight=\"" << 15 << "\" "
					<< ">" << '\n'
				<< "\t\t"
					<< "<Column ss:Width=\"" << 32 << "\"/>\n"
				<< "\t\t"
					<< "<Column ss:Width=\"" << 42 << "\"/>\n"
				<< "\t\t"
					<< "<Column ss:Width=\"" << 102 << "\"/>\n"
				<< "\t\t"
					<< "<Column ss:Width=\"" << 27 << "\"/>\n"
			;

			file
				<< "\t\t\t<Row>\n"
					<< "\t\t\t\t<Cell><Data ss:Type=\"String\">Serial</Data></Cell>\n"
					<< "\t\t\t\t<Cell><Data ss:Type=\"String\">Name</Data></Cell>\n"
					<< "\t\t\t\t<Cell><Data ss:Type=\"String\">Description</Data></Cell>\n"
					<< "\t\t\t\t<Cell><Data ss:Type=\"String\">Club</Data></Cell>\n"
				<< "\t\t\t</Row>\n"
			;

			Node<Item> *tmpItem = items->getHead();
			while (tmpItem != NULL) {
				file
					<< "\t\t\t<Row>\n"
						// Serial
						<< "\t\t\t\t"
							<< "<Cell><Data ss:Type=\"Number\">"
								<< tmpItem->mData.getSerial()
							<< "</Data></Cell>\n"
						// Name
						<< "\t\t\t\t"
							<< "<Cell><Data ss:Type=\"String\">"
								<< tmpItem->mData.getName()
							<< "</Data></Cell>\n"
						// Description
						<< "\t\t\t\t"
							<< "<Cell><Data ss:Type=\"String\">"
								<< tmpItem->mData.getDescription()
							<< "</Data></Cell>\n"
						// Club
						<< "\t\t\t\t"
							<< "<Cell><Data ss:Type=\"String\">"
								<< tmpItem->mData.getClubName()
							<< "</Data></Cell>\n"
					<< "\t\t\t</Row>\n"
				;
				tmpItem = tmpItem->mNext;
			}

			file
				<< "\t\t</Table>" << '\n'
				<< "\t</Worksheet>" << '\n'
			;
			
			// ~~~~~~~~~~~ End: Items ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

			// ~~~~~~~~~ Start: Users ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

			file
				<< "\t<Worksheet ss:Name=\"Users\">" << '\n'
				<< "\t\t<Table "
					<< "ss:ExpandedRowCount=\"" << (1 + users->getCount()) << "\" "
					<< "ss:ExpandedColumnCount=\"" << 3 << "\" "
					<< "ss:DefaultRowHeight=\"" << 15 << "\" "
					<< ">" << '\n'
			;

			file
				<< "\t\t\t<Row>\n"
					<< "\t\t\t\t<Cell><Data ss:Type=\"String\">Username</Data></Cell>\n"
					<< "\t\t\t\t<Cell><Data ss:Type=\"String\">Name</Data></Cell>\n"
					<< "\t\t\t\t<Cell><Data ss:Type=\"String\">Password</Data></Cell>\n"
				<< "\t\t\t</Row>\n"
			;

			Node<User> *tmpUser = users->getHead();
			while (tmpUser != NULL) {
				file
					<< "\t\t\t<Row>\n"
						// Username
						<< "\t\t\t\t"
							<< "<Cell><Data ss:Type=\"String\">"
								<< tmpUser->mData.getUsername()
							<< "</Data></Cell>\n"
						// Name
						<< "\t\t\t\t"
							<< "<Cell><Data ss:Type=\"String\">"
								<< tmpUser->mData.getName()
							<< "</Data></Cell>\n"
						// Password
						<< "\t\t\t\t"
							<< "<Cell><Data ss:Type=\"String\">"
								<< tmpUser->mData.getPassword()
							<< "</Data></Cell>\n"
					<< "\t\t\t</Row>\n"
				;
				tmpUser = tmpUser->mNext;
			}

			file
				<< "\t\t</Table>" << '\n'
				<< "\t</Worksheet>" << '\n'
			;

			// ~~~~~~~~~~~ End: Items ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

			// ~~~~~~~~~ Start: Logs ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

			file
				<< "\t<Worksheet ss:Name=\"Logs\">" << '\n'
				<< "\t\t<Table "
					<< "ss:ExpandedRowCount=\"" << (1 + logs->getCount()) << "\" "
					<< "ss:ExpandedColumnCount=\"" << 12 << "\" "
					<< "ss:DefaultRowHeight=\"" << 15 << "\" "
					<< ">" << '\n'
			;

			file
				<< "\t\t\t<Row>\n"
					<< "\t\t\t\t<Cell><Data ss:Type=\"String\">"
						<< "Item Serial"
					<< "</Data></Cell>\n"
					<< "\t\t\t\t<Cell><Data ss:Type=\"String\">"
						<< "Item Name"
					<< "</Data></Cell>\n"
					<< "\t\t\t\t<Cell><Data ss:Type=\"String\">"
						<< "Club"
					<< "</Data></Cell>\n"
					<< "\t\t\t\t<Cell><Data ss:Type=\"String\">"
						<< "Date Out"
					<< "</Data></Cell>\n"
					<< "\t\t\t\t<Cell><Data ss:Type=\"String\">"
						<< "Date Expected Back"
					<< "</Data></Cell>\n"
					<< "\t\t\t\t<Cell><Data ss:Type=\"String\">"
						<< "Date In"
					<< "</Data></Cell>\n"
					<< "\t\t\t\t<Cell><Data ss:Type=\"String\">"
						<< "Checked Out By (Name)"
					<< "</Data></Cell>\n"
					<< "\t\t\t\t<Cell><Data ss:Type=\"String\">"
						<< "Checked Out By (Username)"
					<< "</Data></Cell>\n"
					<< "\t\t\t\t<Cell><Data ss:Type=\"String\">"
						<< "Checked Out To"
					<< "</Data></Cell>\n"
					<< "\t\t\t\t<Cell><Data ss:Type=\"String\">"
						<< "Checked In By (Name)"
					<< "</Data></Cell>\n"
					<< "\t\t\t\t<Cell><Data ss:Type=\"String\">"
						<< "Checked In By (Username)"
					<< "</Data></Cell>\n"
					<< "\t\t\t\t<Cell><Data ss:Type=\"String\">"
						<< "Checked In From"
					<< "</Data></Cell>\n"
				<< "\t\t\t</Row>\n"
			;

			Node<Log> *tmpLog = logs->getHead();
			while (tmpLog != NULL) {
				file
					<< "\t\t\t<Row>\n"
						// Username
						<< "\t\t\t\t"
							<< "<Cell><Data ss:Type=\"Number\">"
								<< tmpLog->mData.getSerial()
							<< "</Data></Cell>\n"
						// Name
						<< "\t\t\t\t"
							<< "<Cell><Data ss:Type=\"String\">"
								<< tmpLog->mData.getName()
							<< "</Data></Cell>\n"
						// Club
						<< "\t\t\t\t"
							<< "<Cell><Data ss:Type=\"String\">"
								<< tmpLog->mData.getClubName()
							<< "</Data></Cell>\n"
						// Date Out
						<< "\t\t\t\t"
							<< "<Cell><Data ss:Type=\"Date\">"
								<< tmpLog->mData.getDateOut().toString("mm/dd/yyyy")
							<< "</Data></Cell>\n"
						// Date In Expected
						<< "\t\t\t\t"
							<< "<Cell><Data ss:Type=\"Date\">"
								<< tmpLog->mData.getDateInExpected().toString("mm/dd/yyyy")
							<< "</Data></Cell>\n"
						// Date In
						<< "\t\t\t\t"
							<< "<Cell><Data ss:Type=\"Date\">"
								<< tmpLog->mData.getDateIn().toString("mm/dd/yyyy")
							<< "</Data></Cell>\n"
						// Out By Name
						<< "\t\t\t\t"
							<< "<Cell><Data ss:Type=\"String\">"
								<< tmpLog->mData.getOutByName()
							<< "</Data></Cell>\n"
						// Out By Username
						<< "\t\t\t\t"
							<< "<Cell><Data ss:Type=\"String\">"
								<< tmpLog->mData.getOutByUsername()
							<< "</Data></Cell>\n"
						// Out To
						<< "\t\t\t\t"
							<< "<Cell><Data ss:Type=\"String\">"
								<< tmpLog->mData.getOutToName()
							<< "</Data></Cell>\n"
						// In By Name
						<< "\t\t\t\t"
							<< "<Cell><Data ss:Type=\"String\">"
								<< tmpLog->mData.getInByName()
							<< "</Data></Cell>\n"
						// In By Username
						<< "\t\t\t\t"
							<< "<Cell><Data ss:Type=\"String\">"
								<< tmpLog->mData.getInByUsername()
							<< "</Data></Cell>\n"
						// In From
						<< "\t\t\t\t"
							<< "<Cell><Data ss:Type=\"String\">"
								<< tmpLog->mData.getInFromName()
							<< "</Data></Cell>\n"
					<< "\t\t\t</Row>\n"
				;
				tmpLog = tmpLog->mNext;
			}

			file
				<< "\t\t</Table>" << '\n'
				<< "\t</Worksheet>" << '\n'
			;

			// ~~~~~~~~~~~ End: Logs ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

			file << "</Workbook>";

		}

	}
	file.close();

}

void checkInOut(LinkedList<Item> *items, int serial) {

}
