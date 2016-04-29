
#ifndef LL_HELPER_H
#define LL_HELPER_H

#include "LinkedList.h"
#include "Item.h"
#include "User.h"
#include "club.h"

using namespace std;

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
