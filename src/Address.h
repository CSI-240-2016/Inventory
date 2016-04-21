#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

using namespace std;

class Address {

private:
	string mNumberStreet, mStreet, mNumberApartment, mCity, mState, mCountry, mZipCode;

public:
	// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Address();

	// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	string 	getNumberStreet();
	string 	getStreet();
	string 	getNumberApartment();
	string 	getCity();
	string 	getState();
	string 	getCountry();
	string 	getZipCode();

	// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void 	setNumberStreet(string);
	void 	setStreet(string);
	void 	setNumberApartment(string);
	void 	setCity(string);
	void 	setState(string);
	void 	setCountry(string);
	void 	setZipCode(string);

	// ~~~~~ Overloaded Operators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Address operator=(const Address &address);

};

#endif
