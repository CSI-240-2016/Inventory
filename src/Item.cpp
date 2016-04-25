
#include "Item.h"

// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Item::Item(int serial, string name) {
	mSerialNumber = serial;
	mName = name;
	
	mType = "";
	mOwner = "";
	mIsIn = false;
}

// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int 		Item::getSerial() {
	return mSerialNumber;
}

string 		Item::getName() {
	return mName;
}

string 		Item::getNameType() {
	return mType;
}

string 		Item::getNameOwner() {
	return mOwner;
}

Source 		Item::getSource() {
	return mSource;
}

Location 	Item::getLocation() {
	return mLocation;
}

bool 		Item::isCheckedIn() {
	return mIsIn;
}

// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void 	Item::setSerial(int serial) {
	mSerialNumber = serial;
}

void 	Item::setName(string name) {
	mName = name;
}

void 	Item::setNameType(string name) {
	mType = name;
}

void 	Item::setNameOwner(string name) {
	mOwner = name;
}

void 	Item::setSource(Source source) {
	mSource = source;
}

void 	Item::setLocation(Location location) {
	mLocation = location;
}

bool 	Item::checkOut() {
	if (canBeCheckedOut())
		mIsIn = false;
	return !mIsIn;
}

bool 	Item::checkIn() {
	if (!isCheckedIn())
		mIsIn = true;
	return mIsIn;
}

