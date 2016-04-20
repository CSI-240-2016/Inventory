
#include "Item.h"

// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Item::Item(int serial, String name) {
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

String 		Item::getName() {
	return mName;
}

String 		Item::getNameType() {
	return mType;
}

String 		Item::getNameOwner() {
	return mOwner;
}

Source 		Item::getSource() {
	return mSource;
}

Location 	Item::getLocation() {
	return mLocation;
}

bool 		Item::canBeCheckedOut() {
	return !mIsIn;
}

bool 		Item::isCheckedIn() {
	return mIsIn;
}

// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void 	Item::setSerial(int serial) {
	mSerialNumber = serial;
}

void 	Item::setName(String name) {
	mName = name;
}

void 	Item::setNameType(String name) {
	mType = name;
}

void 	Item::setNameOwner(String name) {
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

