
#ifndef NODE_H
#define NODE_H

using namespace std;

/** PURPOSE: Add a way to track data in the lists */
struct Node {
	
	// ~~~~~ Variables ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	
	/** The next node in the list. Can be NULL. */
	Node *mNext;
	/** The data this node contains */
	int mData;
	
	// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	
	Node();
	Node(int data);

};

#endif