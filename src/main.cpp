
#include "LinkedList.h"
#include "Item.h"
#include "Log.h"
#include "User.h"
#include "IO_Users.h"

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
	
	// ~~~~~~~ End: Load Data
	
	// ~~~~~ Start: Run
	
	printUsers(listUsers);
	
	// ~~~~~~~ End: Run
	
	// ~~~~~ Start: Save Data
	
	saveUsers(listUsers);
	
	// ~~~~~~~ End: Save Data
	
	// ~~~~~ Start: Delete lists
	delete listItems;
	delete listLogs;
	
	// ~~~~~~~ End: Delete lists
	
	return 0;
}
