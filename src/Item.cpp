
#include "Item.h"
#include "Address.h"

// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Item::Item() {
	mSerialNumber = 0;
	mName = "";
	
	mType = "";
	mOwner = "";
	mIsIn = false;
}

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
	if (isCheckedIn())
		mIsIn = false;
	return !mIsIn;
}

bool 	Item::checkIn() {
	if (!isCheckedIn())
		mIsIn = true;
	return mIsIn;
}

// ~~~~~~~~~~ Operators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/** PURPOSE: OVERLOAD Outputs variables to console stream
 */
ostream& operator<<( ostream& stream, Item& obj) {
	string del = "\n";
	Address address = obj.mSource.getSeller().getAddress();
	stream
		<< obj.mSerialNumber << del
		<< obj.mName << del
		<< obj.mType << del
		<< obj.mOwner << del
		
		<< obj.mLocation.getBuilding() << " "
		<< obj.mLocation.getRoom() << " "
		<< obj.getLocation().getCode() << del
		
		<< obj.mSource.getSeller().getName() << del
		
		<< "#" << address.getNumberStreet() << del
			<< address.getNumberApartment()
			<< address.getStreet()
		<< del
		<< address.getCity()
			<< ", " << address.getState()
			<< " " << address.getZipCode()
		<< del
		
		<< obj.mSource.getUnitPrice() << del
		<< obj.mIsIn
	;
	return stream;
}

