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

/** Purpose: To display specific information for a valid item being search for
 * PRE:  The list of items, The serial number
 * POST: Displays a list of items matching the serial number
 */
void showItemsBySerial(	LinkedList<Item> *listOfItems, int serial);

/** Purpose: To display specific information for a valid item being search for
* PRE:  The list of items, The type
* POST: Displays a list of items matching the type
*/
void showItemsByType(	LinkedList<Item> *listOfItems, string type);

/** Purpose: To display specific information for a valid item being search for
* PRE:  The list of items, The club
* POST: Displays a list of items matching the club
*/
void showItemsByClub(	LinkedList<Item> *listOfItems, string club);

void addItem(		LinkedList<Item> *items, int serial);

bool removeItem(	LinkedList<Item> *items, int serial);

void changeItem(	LinkedList<Item> *items, int serial);

#endif //INVENTORY_ACTIONSPUBLIC_H