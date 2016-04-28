#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

template <typename R>
struct Node {
	
	// ~~~~~ Variables ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	
	/** The next node in the list. Can be NULL. */
	Node<R> *mNext;
	/** The data this node contains */
	R mData;
	
	// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	Node() {
		mNext = NULL;
		mData = R();
	}
	
	Node(R data) {
		mNext = NULL;
		mData = data;
	}
	
};

template <typename T>
class LinkedList {
	
	private:
		/** Pointer to the last node in the sequence. Can be NULL. */
		Node<T> 	*mTail;
		/** The quantity of nodes in the sequence. */
		int 		mCount;
	
	public:
		/** Pointer to the first node in the sequence. Can be NULL. */
		Node<T> 	*mHead;
		
		// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		
		LinkedList();
		~LinkedList();
		
		// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		
		/** Purpose: Get the quantity of items in the list
		* Pre:		_
		* Post:	_
		*/
		int getCount();
		/** Purpose: Check if there are elements in the list
		* Pre:		_
		* Post:	_
		*/
		bool isEmpty();
		
		/** Purpose: Checks if the data passed exists in the list
		* Pre:		the data to check for
		* Post:	returns true if the data exists
		*/
		bool doesExist(T data);
		
		// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		
		/** Purpose: Inserts data at the beginning of the list
		* Pre:		the data
		* Post:	returns true if the data was put in the list
		*/
		bool insert(T data);
		/** Purpose: Appends data at the end of the list
		* Pre:		the data
		* Post:	returns true if the data was put in the list
		*/
		bool append(T data);
		/** Purpose: Remove the data at the index
		* Pre:		the index
		* Post:	the data at the index (after it has been removed)
		*/
		//int		remove(int index);
		
		// ~~~~~ Utility ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		
		/** Purpose: Displays the list
		* Pre:		_
		* Post:	_
		*/
		void display();
		//friend ofstream& operator<<(ofstream& stream, LinkedList<T>& obj);
};

// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template <typename T>
LinkedList<T>::LinkedList() {
	mHead = NULL;
	mTail = NULL;
	mCount = 0;
}


template <typename T>
LinkedList<T>::~LinkedList() {
	Node<T> *tmp, *toBeDeleted;
	
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
template <typename T>
int LinkedList<T>::getCount() {
	return mCount;
}

/** Purpose: Check if there are elements in the list
* Pre:		_
* Post:	_
*/
template <typename T>
bool LinkedList<T>::isEmpty() {
	return mHead == NULL;
}

/** Purpose: Checks if the data passed exists in the list
* Pre:		the data to check for
* Post:	returns true if the data exists
*/
template <typename T>
bool LinkedList<T>::doesExist(T data) {
	// create a pointer to each node to be checked
	Node<T> *tmp;
	
	// start with first node
	tmp = mHead;
	
	// while the current node exists
	while (tmp != NULL) {
		if (tmp->mData == data) // is the current data the same as the passed data
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
template <typename T>
bool LinkedList<T>::insert(T data) {
	// Create a new node for the data
	Node<T> *newNode = new Node<T>(data);
	
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
template <typename T>
bool LinkedList<T>::append(T data) {
	// Create a new node for the data
	Node<T> *newNode = new Node<T>(data);
	
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
template <typename T>
void LinkedList<T>::display() {
	Node<T> *tmp = mHead;
	while (tmp != NULL) {
		cout << tmp->mData << "\n";
		tmp = tmp->mNext;
	}
}

/*
template<class T>
ostream& operator<<(ostream& os, const LinkedList<T>& data ) {
	Node<T> *tmp = data.mHead;
	while (tmp != NULL)
		os << tmp->mData << endl;
	return os;
}
*/

bool removeByItem_Serial(LinkedList<Item> *list, int serial) {
	Node<Item> *before = NULL;
	Node<Item> *tmp = list->mHead;
	while (tmp != NULL) {
		if (tmp->mData.getSerial() == serial) {
			
			if (before == NULL)
				list->mHead = tmp->mNext;
			else
				before->mNext = tmp->mNext;
			
			delete tmp;
			
			return true;
		}
		before = tmp;
		tmp = tmp->mNext;
	}
	return false;
}

bool removeByUser_UserName(LinkedList<User> *list, string username) {
	Node<User> *before = NULL;
	Node<User> *tmp = list->mHead;
	while (tmp != NULL) {
		if (tmp->mData.getUserName() == username) {
			
			if (before == NULL)
				list->mHead = tmp->mNext;
			else
				before->mNext = tmp->mNext;
			
			delete tmp;
			
			return true;
		}
		before = tmp;
		tmp = tmp->mNext;
	}
	return false;
}

bool removeByClub_Name(LinkedList<Club> *list, string name) {
	Node<Club> *before = NULL;
	Node<Club> *tmp = list->mHead;
	while (tmp != NULL) {
		if (tmp->mData.getName() == name) {
			
			if (before == NULL)
				list->mHead = tmp->mNext;
			else
				before->mNext = tmp->mNext;
			
			delete tmp;
			
			return true;
		}
		before = tmp;
		tmp = tmp->mNext;
	}
	return false;
}

#endif