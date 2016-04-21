
#include "Address.h"

// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Address::Address() {
	mNumberStreet = "";
	mStreet = "";
	mNumberApartment = "";
	mCity = "";
	mState = "";
	mCountry = "";
	mZipCode = "";
}

// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

string 	Address::getNumberStreet() {
	return mNumberStreet;
}

string 	Address::getStreet() {
	return mStreet;
}

string 	Address::getNumberApartment() {
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

void 	Address::setNumberStreet(string str) {
	mNumberStreet = str;
}

void 	Address::setStreet(string str) {
	mStreet = str;
}

void 	Address::setNumberApartment(string str) {
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

Address Address::operator=(const Address&)
{
	Address address;

	address.setCity(this->getCity());
	address.setCountry(this->getCountry());
	address.setNumberApartment(this->getNumberApartment());
	address.setNumberStreet(this->getNumberStreet());
	address.setState(this->getState());
	address.setStreet(this->getState());
	address.setZipCode(this->getZipCode());
	
	return address;	
}
