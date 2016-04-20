
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

String 	Address::getNumberStreet() {
	return mNumberStreet;
}

String 	Address::getStreet() {
	return mStreet;
}

String 	Address::getNumberApartment() {
	return mNumberApartment;
}

String 	Address::getCity() {
	return mCity;
}

String 	Address::getState() {
	return mState;
}

String 	Address::getCountry() {
	return mCountry;
}

String 	Address::getZipCode() {
	return mZipCode;
}

// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void 	Address::setNumberStreet(String str) {
	mNumberStreet = str;
}

void 	Address::setStreet(String str) {
	mStreet = str;
}

void 	Address::setNumberApartment(String str) {
	mNumberApartment = str;
}

void 	Address::setCity(String str) {
	mCity = str;
}

void 	Address::setState(String str) {
	mState = str;
}

void 	Address::setCountry(String str) {
	mCountry = str;
}

void 	Address::setZipCode(String str) {
	mZipCode = str;
}
