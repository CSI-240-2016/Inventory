#include "LinkedList.h"
#include "Item.h"
#include <iostream>

void searchSerial(int searchKey, LinkedList<Item> data)
{
	Node<Item> *tmp;
	Node<Item> *before;

	tmp = data.mHead;
	before = data.mHead;

	while (tmp != NULL && tmp->mData.getSerial() != searchKey) // while tmp is not NULL and serial is not equal to search key, go to the next
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
		//cout << tmp->mData << endl;
	}
}

void searchByClub(string searchKey, LinkedList<Item> data)
{
	Node<Item> *tmp;
	Node<Item> *before;

	tmp = data.mHead;
	before = data.mHead;

	while (tmp != NULL)
	{
		if (tmp->mData.getNameOwner() == searchKey)
		{
			//cout << data << endl;
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
		//cout << data << endl;
	}
}
