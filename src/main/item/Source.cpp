/*
    Created by Dustin Yost on 4/30/2016.
*/

#include "Source.h"

// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* PURPOSE: Create an Source object with default values
 * PRE:  None
 * POST: An Source object with default values
*/
Source::Source() {
	mPriceUnit = 0;
	mName = "";
	mURL = "";
	mAddress = Address();
}

// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* PURPOSE: Retrieve the unit price
 * PRE:  None
 * POST: The unit price (Double)
*/
double	Source::getUnitPrice() {
	return mPriceUnit;
}

/* PURPOSE: Retrieve the name
 * PRE:  None
 * POST: The name (String)
*/
string	Source::getName() {
	return mName;
}

/* PURPOSE: Retrieve the URL
 * PRE:  None
 * POST: The URL (String)
*/
string	Source::getURL() {
	return mURL;
}

/* PURPOSE: Retrieve the address
 * PRE:  None
 * POST: The address (Address)
*/
Address	Source::getAddress() {
	return mAddress;
}

// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* PURPOSE: Update the unit price
 * PRE:  The unit price (Double)
 * POST: The value is changed to the parameter
*/
void	Source::setUnitPrice(double d) {
	mPriceUnit = d;
}

/* PURPOSE: Update the name
 * PRE:  The name (String)
 * POST: The value is changed to the parameter
*/
void	Source::setName(string s) {
	mName = s;
}

/* PURPOSE: Update the url
 * PRE:  The url (String)
 * POST: The value is changed to the parameter
*/
void	Source::setURL(string s) {
	mURL = s;
}

/* PURPOSE: Update the address
 * PRE:  The address (Address)
 * POST: The value is changed to the parameter
*/
void	Source::setAddress(Address address) {
	mAddress = address;
}

// ~~~~~~~~~~ Operators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/** PURPOSE: OVERLOAD Inputs variables from the file stream to object
 * PRE:  The file stream (fstream), The source (Source)
 * POST: Reads data from the file stream
 */
ifstream& operator>>(ifstream& stream, Source& obj) {

	// "Source:mPriceUnit "Source:mName"
	stream >> obj.mPriceUnit;
	stream.get();
	getline(stream, obj.mName);

	// "Source:mURL"
	getline(stream, obj.mURL);

	/*
	Source:mAddress:mNumberStreet Source:mAddress:mNumberApartment Source:mAddress:mStreet
	Source:mAddress:mCity
	Source:mAddress:mState
	Source:mAddress:mZipCode
	Source:mAddress:mCountry
	*/
	stream >> obj.mAddress;

	return stream;
}

/** PURPOSE: OVERLOAD Outputs variables from object to the file stream
 * PRE:  The file stream (fstream), The obj (Source)
 * POST: Reads data from the file stream
 */
ofstream& operator<<(ofstream& stream, const Source obj) {

	stream
		// "Source:mPriceUnit "Source:mName"
		<< obj.mPriceUnit << " " << obj.mName << "\n"
		// "Source:mURL"
		<< obj.mURL << "\n"
	;

	/*
	Source:mAddress:mNumberStreet Source:mAddress:mNumberApartment Source:mAddress:mStreet
	Source:mAddress:mCity
	Source:mAddress:mState
	Source:mAddress:mZipCode
	Source:mAddress:mCountry
	*/
	stream << obj.mAddress;

	return stream;
}
