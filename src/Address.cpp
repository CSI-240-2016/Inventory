#include "Address.h"

// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Address::Address() {
	mNumberStreet = 0;
	mStreet = "";
	mNumberApartment = 0;
	mCity = "";
	mState = "";
	mCountry = "";
	mZipCode = "";
}

// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int 	Address::getNumberStreet() {
	return mNumberStreet;
}

string 	Address::getStreet() {
	return mStreet;
}

int 	Address::getNumberApartment() {
	return mNumberApartment;
}

string 	Address::getCity() {
	return mCity;
}

string 	Address::getState() {
	return mState;
}

string 	Address::getCountry() {
	return mCountry;
}

string 	Address::getZipCode() {
	return mZipCode;
}

// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void 	Address::setNumberStreet(int str) {
	mNumberStreet = str;
}

void 	Address::setStreet(string str) {
	mStreet = str;
}

void 	Address::setNumberApartment(int str) {
	mNumberApartment = str;
}

void 	Address::setCity(string str) {
	mCity = str;
}

void 	Address::setState(string str) {
	mState = str;
}

void 	Address::setCountry(string str) {
	mCountry = str;
}

void 	Address::setZipCode(string str) {
	mZipCode = str;
}

// ~~~~~ Overloaded Operators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Address& Address::operator=(const Address& addressTwo)
{
	this->mCity = addressTwo.mCity;
	this->mCountry = addressTwo.mCountry;
	this->mNumberApartment = addressTwo.mNumberApartment;
	this->mNumberStreet = addressTwo.mNumberStreet;
	this->mState = addressTwo.mState;
	this->mStreet = addressTwo.mStreet;
	this->mZipCode = addressTwo.mZipCode;
	return *this;
}

/** Purpose: OVERLOAD Loads variables from a file stream
 * PRE:  the file stream, the class instance
 * POST: loads variables from stream, returns the stream
 */
ifstream& operator>>(ifstream& stream, Address& obj) {
	
	stream
		>> obj.mNumberStreet
		>> obj.mNumberApartment
	;
	getline(stream, obj.mZipCode);
	
	getline(stream, obj.mStreet);
	getline(stream, obj.mCity);
	getline(stream, obj.mState);
	getline(stream, obj.mCountry);
	
	return stream;
}
