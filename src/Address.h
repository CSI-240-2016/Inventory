#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Address {

	private:
		int mNumberStreet, mNumberApartment;
		string mStreet, mCity, mState, mCountry, mZipCode;
	
	public:
		// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		Address();
	
		// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		int 	getNumberStreet();
		string 	getStreet();
		int 	getNumberApartment();
		string 	getCity();
		string 	getState();
		string 	getCountry();
		string 	getZipCode();
	
		// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		void 	setNumberStreet(int);
		void 	setStreet(string);
		void 	setNumberApartment(int);
		void 	setCity(string);
		void 	setState(string);
		void 	setCountry(string);
		void 	setZipCode(string);
	
		// ~~~~~ Overloaded Operators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		Address& operator=(const Address& addressTwo);
		/** PURPOSE: OVERLOAD Loads variables from a file stream
		 */
		friend ifstream& operator>>(ifstream& stream, Address& obj);
		friend ofstream& operator<<(ofstream& stream, Address& obj);

};

#endif
