
#include "Location.h"

// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Location(string building, string room, string code) {
	mBuilding = building;
	mRoom = room;
	mCode = code;
}

// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

string getBuilding() {
	return mBuilding;
}

string getRoom() {
	return mRoom;
}

string setCode() {
	return mCode;
}
