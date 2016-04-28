
#include "LinkedList.h"
#include "Item.h"
#include "Log.h"
#include "User.h"
#include "IO_Users.h"
#include "itemsDat.h"

using namespace std;

int main() {
	
	// ~~~~~ Start: Declare lists
	LinkedList<User> *listUsers;
	LinkedList<Item> *listItems;
	LinkedList<Log> *listLogs;
	
	// ~~~~~~~ End: Declare lists
	
	// ~~~~~ Start: Init lists
	listUsers = new LinkedList<User>;
	listItems = new LinkedList<Item>;
	listLogs = new LinkedList<Log>;
	
	// ~~~~~~~ End: Init lists
	
	// ~~~~~ Start: Load Data
	
	loadUsers(listUsers);
	itemsInput(listItems);
	
	// ~~~~~~~ End: Load Data
	
	// ~~~~~ Start: Run
	
	printUsers(listUsers);
	printItems(listItems);
	
	// ~~~~~~~ End: Run
	
	// ~~~~~ Start: Save Data
	
	saveUsers(listUsers);
	saveItems(listItems);
	
	// ~~~~~~~ End: Save Data
	
	// ~~~~~ Start: Delete lists
	delete listItems;
	delete listLogs;
	
	// ~~~~~~~ End: Delete lists
	
	return 0;
}
