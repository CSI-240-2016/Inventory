#include "LinkedList.h"
#include <iostream>

void searchSerial(string searchKey, LinkedList mData)
{
	Node *tmp;
	Node *before;

	tmp = mData.getHead();
	before = mData.getHead();

	while (tmp != NULL && tmp->data.getSerial() != searchKey) // while tmp is not NULL and serial is not equal to search key, go to the next
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

void searchByClub(string searchKey, LinkedList mData)
{
	Node *tmp;
	Node *before;

	tmp = mData.getHead();
	before = mData.getHead();

	while (tmp != NULL)
	{
		if (tmp->data.getNameOwner() == searchKey)
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
