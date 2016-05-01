/*
    Created by Dustin Yost on 4/30/2016.
*/

#ifndef INVENTORY_ACTIONSPUBLIC_H
#define INVENTORY_ACTIONSPUBLIC_H

#include "../LinkedList.h"
#include "../item/Item.h"

using namespace std;

/** Purpose: To display specific information for a valid item being search for
 * PRE:  The list of item must be created, whether to look for items in or out
 * POST: Information for a searched item is displayed to the console screen
*/
void showItemsViaStatus(LinkedList<Item> *listOfItems, bool isIn);

#endif //INVENTORY_ACTIONSPUBLIC_H
