#ifndef SEARCHBYITEM_H
#define SEARCHBYITEM_H

#include "LinkedList.h"
#include "Item.h"
#include <iostream>
#include <string>

using namespace std;


void searchByClub(LinkedList<Item>, string);
void searchByLocation(LinkedList<Item>, string);
void searchBySeller(LinkedList<Item>,string);
void searchBySerial(LinkedList<Item>, int);
void searchByType(LinkedList<Item>, string);

#endif
