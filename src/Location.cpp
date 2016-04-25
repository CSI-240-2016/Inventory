
#include "Location.h"

// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Location::Location() {
	mBuilding = "";
	mRoom = "";
	mCode = "";
}

Location::Location(string building, string room, string code) {
	mBuilding = building;
	mRoom = room;
	mCode = code;
}

// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

string	Location::getBuilding() {
	return mBuilding;
}

string	Location::getRoom() {
	return mRoom;
}

string	Location::getCode() {
	return mCode;
}

// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void	Location::setBuilding(string str) {
	mBuilding = str;
}

void	Location::setRoom(string str) {
	mRoom = str;
}

void	Location::setCode(string str) {
	mCode = str;
}
