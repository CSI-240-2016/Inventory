/*
    Created by Dustin Yost on 4/30/2016.
*/

#include "Address.h"
#include "../lib/io.h"

// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* PURPOSE: Create an Address object with default values
 * PRE:  None
 * POST: An Address object with default values
*/
Address::Address() {
	mNumberStreet = 0;
	mNumberApartment = 0;
	mZipCode = "";
	mStreet = "";
	mCity = "";
	mState = "";
	mCountry = "";
}

// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* PURPOSE: Retrieve the street number
 * PRE:  None
 * POST: The street number (Integer)
*/
int		Address::getStreetNumber(){
	return mNumberStreet;
}

/* PURPOSE: Retrieve the apartment number
 * PRE:  None
 * POST: The apartment number (Integer)
*/
int		Address::getApartmentNumber() {
	return mNumberApartment;
}

/* PURPOSE: Retrieve the zip code
 * PRE:  None
 * POST: The zip code (String)
*/
string	Address::getZipCode() {
	return mZipCode;
}

/* PURPOSE: Retrieve the street
 * PRE:  None
 * POST: The street (String)
*/
string	Address::getStreet() {
	return mStreet;
}

/* PURPOSE: Retrieve the city
 * PRE:  None
 * POST: The city (String)
*/
string	Address::getCity() {
	return mCity;
}

/* PURPOSE: Retrieve the state
 * PRE:  None
 * POST: The state (String)
*/
string	Address::getState() {
	return mState;
}

/* PURPOSE: Retrieve the country
 * PRE:  None
 * POST: The country (String)
*/
string	Address::getCountry() {
	return mCountry;
}

// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* PURPOSE: Update the street number
 * PRE:  The street number (Integer)
 * POST: The value is changed to the parameter
*/
void	Address::setStreetNumber(int i) {
	mNumberStreet = i;
}

/* PURPOSE: Update the apartment number
 * PRE:  The apartment number (Integer)
 * POST: The value is changed to the parameter
*/
void	Address::setApartmentNumber(int i) {
	mNumberApartment = i;
}

/* PURPOSE: Update the zip code
 * PRE:  The zip code (String)
 * POST: The value is changed to the parameter
*/
void	Address::setZipCode(string s) {
	mZipCode = s;
}

/* PURPOSE: Update the street
 * PRE:  The street (String)
 * POST: The value is changed to the parameter
*/
void	Address::setStreet(string s) {
	mStreet = s;
}

/* PURPOSE: Update city
 * PRE:  The city (String)
 * POST: The value is changed to the parameter
*/
void	Address::setCity(string s) {
	mCity = s;
}

/* PURPOSE: Update the state
 * PRE:  The state (String)
 * POST: The value is changed to the parameter
*/
void	Address::setState(string s) {
	mState = s;
}

/* PURPOSE: Update the country
 * PRE:  The country (String)
 * POST: The value is changed to the parameter
*/
void	Address::setCountry(string s) {
	mCountry = s;
}

// ~~~~~~~~~~ Operators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/** PURPOSE: OVERLOAD Inputs variables from the file stream to object
 * PRE:  The file stream (fstream), The address (Address)
 * POST: Reads data from the file stream
 */
ifstream& operator>>(ifstream& stream, Address& obj) {

	// "Address:mNumberStreet Address:mNumberApartment Address:mStreet"
	stream >> obj.mNumberStreet >> obj.mNumberApartment;
	stream.get();
	getline(stream, obj.mStreet);

	// "Address:mCity"
	getline(stream, obj.mCity);

	// "Address:mState"
	getline(stream, obj.mState);

	// "Address:mZipCode"
	getline(stream, obj.mZipCode);

	// "Address:mCountry"
	getline(stream, obj.mCountry);

	return stream;
}

/** PURPOSE: OVERLOAD Inputs variables from the file stream to object
 * PRE:  The stream (istream), The obj (Address)
 * POST: Reads data from the stream
 */
istream& operator>>(istream& stream, Address& obj) {
	
	// "Address:mNumberStreet Address:mNumberApartment Address:mStreet"
	obj.mNumberStreet = cinInteger("Enter street number: ");
	obj.mNumberApartment = cinInteger("Enter apartment number (0 if none): ");
	cout << "Enter street: ";
	getline(stream, obj.mStreet);

	// "Address:mCity"
	cout << "Enter city: ";
	getline(stream, obj.mCity);

	// "Address:mState"
	cout << "Enter state: ";
	getline(stream, obj.mState);

	// "Address:mZipCode"
	cout << "Enter zip code: ";
	getline(stream, obj.mZipCode);

	// "Address:mCountry"
	cout << "Enter country: ";
	getline(stream, obj.mCountry);

	return stream;
}

/** PURPOSE: OVERLOAD Outputs variables from object to the file stream
 * PRE:  The file stream (fstream), The obj (Address)
 * POST: Reads data from the file stream
 */
ofstream& operator<<(ofstream& stream, const Address obj) {

	stream
		// "Address:mNumberStreet Address:mNumberApartment Address:mStreet"
		<< obj.mNumberStreet << ' ' << obj.mNumberApartment << ' ' << obj.mStreet << '\n'
		// "Address:mCity"
		<< obj.mCity << '\n'
		// "Address:mState"
		<< obj.mState << '\n'
		// "Address:mZipCode"
		<< obj.mZipCode << '\n'
		// "Address:mCountry"
		<< obj.mCountry
	;

	return stream;
}
