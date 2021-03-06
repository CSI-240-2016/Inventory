
#include "Item.h"
#include "LinkedList.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Seller.h"

using namespace std;

void itemsInput(LinkedList<Item> *list);
void saveItems(LinkedList<Item> *);
void printItems(LinkedList<Item> *);

void  itemsOutput(int serialNumber, string name, string type, string club, string sellerName, double price, string building, string room, string shelfSlot, bool status);
