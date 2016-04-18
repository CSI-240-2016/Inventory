
#include "LinkedList.h"

// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

LinkedList::LinkedList() {
	mHead = NULL;
	mTail = NULL;
	mCount = 0;
}

LinkedList::~LinkedList() {
	Node *tmp, *toBeDeleted;
	
	// Get the first node in the sequence
	tmp = mHead;
	
	// while each node exists
	while (tmp != NULL) {
		// set the node to be deleted
		toBeDeleted = tmp;
		// get the next node
		tmp = tmp->mNext;
		// remove link from this node to the next node
		toBeDeleted->mNext = NULL;
		// delete this node
		delete toBeDeleted;
	}
	
	// Set all variables to NULL values
	mHead = NULL;
	mTail = NULL;
	mCount = 0;
}

// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/** Purpose: Get the quantity of items in the list
 * Pre:		_
 * Post:	_
 */
int LinkedList::getCount() {
	return mCount;
}

/** Purpose: Check if there are elements in the list
 * Pre:		_
 * Post:	_
 */
bool LinkedList::isEmpty() {
	return mHead == NULL;
}

/** Purpose: Checks if the data passed exists in the list
 * Pre:		the data to check for
 * Post:	returns true if the data exists
 */
bool LinkedList::doesExist(int data) {
	// create a pointer to each node to be checked
	Node *tmp;
	
	// start with first node
	tmp = mHead;
	
	// while the current node exists
	while (tmp != NULL) {
		if (tmp->mData == searchKey) // is the current data the same as the passed data
			return true;
		else // get the next element
			tmp = tmp->mNext;
	}
	
	return false;
}

// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/** Purpose: Inserts data at the beginning of the list
 * Pre:		the data
 * Post:	returns true if the data was put in the list
 */
void LinkedList::insert(int data) {
	// Create a new node for the data
	Node *newNode = new Node(data);
	
	// If the node is NULL (not enough memory to create node)
	if (newNode == NULL)
		return false;
	
	if (isEmpty()) { // If the list is empty, then the tail must be set
		mTail = newNode;
	}
	else { // if not empty, then the current head is the next node
		newNode->mNext = mHead;
	}
	
	// set the current head to the new node
	mHead = newNode;
	// increase the count
	mCount++;
	
	// node was successfully created
	return true;
}

/** Purpose: Appends data at the end of the list
 * Pre:		the data
 * Post:	returns true if the data was put in the list
 */
bool LinkedList::append(int data) {
	// Create a new node for the data
	Node *newNode = new Node(data);
	
	// If the node is NULL (not enough memory to create node)
	if (newNode == NULL)
		return false;
	
	if (isEmpty()) { // If the list is empty, then the head must be set
		mHead = newNode;
	}
	else { // if not empty, then the new node is the current tail's next node
		mTail->mNext = newNode;
	}
	
	// set the current tail to the new node
	mTail = newNode;
	// increase the count
	mCount++;
	
	// node was successfully created
	return true;
}

// ~~~~~ Utility ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/** Purpose: Displays the list
 * Pre:		_
 * Post:	_
 */
void LinkedList::display() {
	Node *tmp = mHead;
	while (tmp != NULL) {
		cout << tmp->mData << "\n";
		tmp = tmp->mNext;
	}
}
