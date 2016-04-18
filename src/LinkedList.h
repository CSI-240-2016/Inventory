
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

using namespace std;

class LinkedList {

	private:
		/** Pointer to the first node in the sequence. Can be NULL. */
		Node *mHead;
		/** Pointer to the last node in the sequence. Can be NULL. */
		Node *mTail;
		/** The quantity of nodes in the sequence. */
		int mCount;
	public:
	
		// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	
		LinkedList();
		~LinkedList();
		
		// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		
		/** Purpose: Get the quantity of items in the list
		 * Pre:		_
		 * Post:	_
		 */
		int		getCount();
		/** Purpose: Check if there are elements in the list
		 * Pre:		_
		 * Post:	_
		 */
		bool 	isEmpty();
		
		/** Purpose: Checks if the data passed exists in the list
		 * Pre:		the data to check for
		 * Post:	returns true if the data exists
		 */
		bool	doesExist(int data);
		
		// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		
		/** Purpose: Inserts data at the beginning of the list
		 * Pre:		the data
		 * Post:	returns true if the data was put in the list
		 */
		bool	insert(int data);
		/** Purpose: Appends data at the end of the list
		 * Pre:		the data
		 * Post:	returns true if the data was put in the list
		 */
		bool	append(int data);
		/** Purpose: Remove the data at the index
		 * Pre:		the index
		 * Post:	the data at the index (after it has been removed)
		 */
		int		remove(int index);
		
		// ~~~~~ Utility ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		
		/** Purpose: Displays the list
		 * Pre:		_
		 * Post:	_
		 */
		void	display();

};

#endif