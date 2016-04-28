#include "Item.h"
#include "LinkedList.h"
#include <string>
using namespace std;

void itemsInput(LinkedList<Item> list);

void  itemsOutput(int serialNumber, string name, string type, string club, string sellerName, double price, bool status);
