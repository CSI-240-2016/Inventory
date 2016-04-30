/*
    Created by Dustin Yost on 4/30/2016.
*/

#ifndef INVENTORY_ITEMS_H
#define INVENTORY_ITEMS_H

#include "../class/item/Item.h"
#include "../class/item/LinkedList.h"

const string FILE_DATA_ITEMS = "items.dat";

void loadItems(LinkedList<Item> *list);
void saveItems(LinkedList<Item> *list);

#endif //INVENTORY_ITEMS_H
