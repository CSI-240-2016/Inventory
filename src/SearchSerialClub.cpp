#include "LinkedList.h"
#include "Item.h"
#include <iostream>
#include <string>

void searchSerial(LinkedList<Item> mData, int searchKey)
{
	Node<Item> *tmp;
	Node<Item> *before;

	tmp = mData.mHead;
	before = mData.mHead;

	while (tmp != NULL) // While list not empty or not end of list
	{
		if (tmp->mData.getSerial() == searchKey) //if serial is same as searchkey, return item 
		{
			cout << endl << tmp->mData << endl;
		}
		before = tmp;
		tmp = tmp->mNext;
	}

	if (tmp == NULL) // Serial doesn't exist
	{
		cout << "Item with serial " << searchKey << " does not exist." << endl;
	}
}

void searchByClub(LinkedList<Item> mData, string searchKey)
{
	Node<Item> *tmp;
	Node<Item> *before;

	tmp = mData.mHead;
	before = mData.mHead;

	while (tmp != NULL) // While list not empty or not end of list
	{
		if (tmp->mData.getNameOwner() == searchKey) //if club is same as searchkey, return every items 
		{
			cout << endl << tmp->mData << endl;
		}
		before = tmp;
		tmp = tmp->mNext;
	}

	if (tmp == NULL) // Club doesn't have item
	{
		cout <<"Club " << searchKey << " does not have items or does not exist." << endl;
	}
}

void searchBySeller(LinkedList<Item> mData, string searchKey)
{
	Node<Item> *tmp;
	Node<Item> *before;

	tmp = mData.mHead;
	before = mData.mHead;

	while (tmp != NULL) // While list not empty or not end of list
	{
		if (tmp->mData.getSource().getSeller() == searchKey) //if seller is same as searchkey, return every items 
		{
			cout << endl << tmp->mData << endl;
		}
		before = tmp;
		tmp = tmp->mNext;
	}

	if (tmp == NULL) // Seller doesn't have item
	{
		cout << "Seller " << searchKey << " does not exist." << endl;
	}
}

void searchByLocation(LinkedList<Item> mData, string searchKey)
{
	Node<Item> *tmp;
	Node<Item> *before;

	tmp = mData.mHead;
	before = mData.mHead;

	while (tmp != NULL) // While list not empty or not end of list
	{
		if (tmp->mData.getLocation() == searchKey) //if location is same as searchkey, return every items 
		{
			cout << endl << tmp->mData << endl;
		}
		before = tmp;
		tmp = tmp->mNext;
	}

	if (tmp == NULL) // Club doesn't have item
	{
		cout << "No item in this location: " << searchKey << endl;
	}
}

void searchByType(LinkedList<Item> mData, string searchKey)
{
	Node<Item> *tmp;
	Node<Item> *before;

	tmp = mData.mHead;
	before = mData.mHead;

	while (tmp != NULL) // While list not empty or not end of list
	{
		if (tmp->mData.getNameType() == searchKey) //if type is same as searchkey, return every items 
		{
			cout << endl << tmp->mData << endl;
		}
		before = tmp;
		tmp = tmp->mNext;
	}

	if (tmp == NULL) // Type doesn't have item
	{
		cout << "Type " << searchKey << " does not exist." << endl;
	}
}