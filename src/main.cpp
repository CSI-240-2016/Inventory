
#include "LinkedList.h"
#include "Item.h"
#include "Log.h"
#include "User.h"
#include "IO_Users.h"
#include "itemsDat.h"
#include "clubsDat.h"

#include "common.h"

using namespace std;

int main() {
	
	// ~~~~~ Start: Declare lists
	LinkedList<User> *listUsers;
	LinkedList<Item> *listItems;
	LinkedList<Club> *listClubs;
	LinkedList<Log> *listLogs;
	// ~~~~~~~ End: Declare lists
	
	// ~~~~~ Start: Init lists
	listUsers = new LinkedList<User>;
	listItems = new LinkedList<Item>;
	listClubs = new LinkedList<Club>;
	listLogs = new LinkedList<Log>;
	// ~~~~~~~ End: Init lists
	
	// ~~~~~ Start: Load Data
	loadUsers(listUsers);
	itemsInput(listItems);
	clubsInput(listClubs);
	// ~~~~~~~ End: Load Data
	
	// ~~~~~ Start: Run
	
	printUsers(listUsers);
	printItems(listItems);
	
	//displayGeneralMenu(listItems, listClubs, listUsers);
	
	// ~~~~~~~ End: Run
	
	// ~~~~~ Start: Save Data
	saveUsers(listUsers);
	saveItems(listItems);
	saveClubs(listClubs);
	// ~~~~~~~ End: Save Data
	
	// ~~~~~ Start: Delete lists
	delete listUsers;
	delete listItems;
	delete listClubs;
	delete listLogs;
	// ~~~~~~~ End: Delete lists
	
	return 0;
}
