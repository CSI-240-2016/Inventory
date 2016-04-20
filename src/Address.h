
#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

using namespace std;

class Address {
	
	private:
		String mNumberStreet, mStreet, mNumberApartment, mCity, mState, mCountry, mZipCode;
	
	public:
		// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		Address();
		
		// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		String 	getNumberStreet();
		String 	getStreet();
		String 	getNumberApartment();
		String 	getCity();
		String 	getState();
		String 	getCountry();
		String 	getZipCode();
		
		// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		void 	setNumberStreet(String);
		void 	setStreet(String);
		void 	setNumberApartment(String);
		void 	setCity(String);
		void 	setState(String);
		void 	setCountry(String);
		void 	setZipCode(String);
	
}

#endif