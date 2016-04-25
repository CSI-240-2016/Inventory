
#include "LinkedList.h"
#include "Item.h"
#include "Log.h"

using namespace std;

int main() {
	
	// ~~~~~ Start: Declare lists
	LinkedList<Item> *listItems;
	LinkedList<Log> *listLogs;
	
	// ~~~~~~~ End: Declare lists
	
	// ~~~~~ Start: Init lists
	listItems = new LinkedList<Item>;
	listLogs = new LinkedList<Log>;
	
	// ~~~~~~~ End: Init lists
	
	// TODO load and run
	
	// ~~~~~ Start: Delete lists
	delete listItems;
	delete listLogs;
	
	// ~~~~~~~ End: Delete lists
	
	return 0;
}
