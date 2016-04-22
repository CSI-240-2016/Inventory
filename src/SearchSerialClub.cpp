#include "master.h"


void LinkedList::searchSerial(string searchKey)
{
	Node *tmp;
	Node *before;

	tmp = mHead;
	before = mHead;

	while (tmp != NULL && tmp->data.mSerialNumber != searchKey) // while tmp is not NULL and serial is not equal to search key, go to the next
	{
		before = tmp;
		tmp = tmp->mNext;
	}

	if (tmp == NULL) //If tmp is null, searchKey not in the list
	{
		cout << searchKey << " is not in the list." << endl;
	}

	else //if serial is equal to the searchkey, return data
	{
		cout << data << endl;
	}
}

void LinkedList::searchByClub(string searchKey)
{
	Node *tmp;
	Node *before;

	tmp = mHead;
	before = mHead;

	while (tmp != NULL)
	{
		if (tmp->data.mOwner == searchKey)
		{
			cout << data << endl;
		}
		before = tmp;
		tmp = tmp->mNext;
	}

	if (tmp == NULL) //If tmp is null, searchKey not in the list
	{
		cout << searchKey << " is not in the list." << endl;
	}

	else //if serial is equal to the searchkey, return true
	{
		cout << data << endl;
	}
}