/*
    Created by Dustin Yost on 4/30/2016.
*/

#ifndef INVENTORY_FILEITEM_H
#define INVENTORY_FILEITEM_H

#include "Item.h"
#include "../LinkedList.h"

const string FILE_DATA_ITEMS = "items.dat";

void loadItems(LinkedList<Item> *list);
void saveItems(LinkedList<Item> *list);

#endif //INVENTORY_FILEITEM_H
