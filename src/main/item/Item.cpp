/*
    Created by Dustin Yost on 4/30/2016.
*/

#include "Item.h"
#include <iomanip>

using namespace std;

// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* PURPOSE: Create an item object with default values
 * PRE:  None
 * POST: An item object with default values
*/
Item::Item() {
	mSerial = -1;
	mName = "";
	mDescription = "";
	mClubName = "";
	mLocation = Location();
	mSource = Source();
}

/* PURPOSE: Create an item object with specific values
 * PRE:  The serial number (Integer)
 * POST: An item object with specified values
*/
Item::Item(int serial) {
	mSerial = serial;
}

// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* PURPOSE: Retrieve the serial number
 * PRE:  None
 * POST: The serial number (Integer)
*/
int		Item::getSerial() {
	return mSerial;
}

/* PURPOSE: Retrieve the name
 * PRE:  None
 * POST: The name (String)
*/
string	Item::getName() {
	return mName;
}

/* PURPOSE: Retrieve the type
 * PRE:  None
 * POST: The type (String)
*/
string	Item::getDescription() {
	return mDescription;
}

/* PURPOSE: Retrieve the club name
 * PRE:  None
 * POST: The club name (String)
*/
string	Item::getClubName() {
	return mClubName;
}

/* PURPOSE: Retrieve the location
 * PRE:  None
 * POST: The location (Location)
*/
Location	Item::getLocation() {
	return mLocation;
}

// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* PURPOSE: Update the serial number
 * PRE:  The serial number (Integer)
 * POST: The value is changed to the parameter
*/
void	Item::setSerial(int i) {
	mSerial = i;
}

/* PURPOSE: Update the name
 * PRE:  The name (String)
 * POST: The value is changed to the parameter
*/
void	Item::setName(string s) {
	mName = s;
}

/* PURPOSE: Update the type
 * PRE:  The type (String)
 * POST: The value is changed to the parameter
*/
void	Item::setDescription(string s) {
	mDescription = s;
}

/* PURPOSE: Update the club name
 * PRE:  The club name (String)
 * POST: The value is changed to the parameter
*/
void	Item::setClubName(string s) {
	mClubName = s;
}

/* PURPOSE: Update the location
 * PRE:  The location (Location)
 * POST: The value is changed to the parameter
*/
void	Item::setLocation(Location location) {
	mLocation = location;
}

// ~~~~~~~~~~ Operators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* PURPOSE: OVERLOAD Determine if this item is equal to another item
 * PRE:  The other item (Item)
 * POST: true, if the two serials' are the same
*/
bool	Item::operator==(Item other) {
	return mSerial == other.mSerial;
}

/* PURPOSE: Tries to read the serial from the file stream
 * PRE:  The file stream
 * POST: if the serial could be read
 */
bool	Item::readSerial(ifstream& stream) {
	return !(stream >> mSerial).eof();
}

/** PURPOSE: OVERLOAD Inputs variables from the file stream to object
 * PRE:  The file stream (fstream), The item (Item)
 * 		 Item.readSerial MUST be called prior
 * POST: Reads data from the file stream
 */
ifstream& operator>>(ifstream& stream, Item& obj) {

	// "Item:mSerial Item:mName"
	stream.get(); // get rid of the space character
	getline(stream, obj.mName);

	// "Item:mDescription"
	getline(stream, obj.mDescription);

	// "Item:mClubName"
	getline(stream, obj.mClubName);

	// "Item:mLocation:mBuilding"
	// "Item:mLocation:mCode Item:mLocation:mRoom"
	stream >> obj.mLocation;

	/*
	Item:mSource:mPriceUnit Item:mSource:mName
	Item:mSource:mURL
	Item:mSource:mAddress:mNumberStreet Item:mSource:mAddress:mNumberApartment Item:mSource:mAddress:mStreet
	Item:mSource:mAddress:mCity
	Item:mSource:mAddress:mState
	Item:mSource:mAddress:mZipCode
	Item:mSource:mAddress:mCountry
	 */
	stream >> obj.mSource;

	return stream;
}

/** PURPOSE: OVERLOAD Inputs variables from the stream to object
 * PRE:  The stream (istream), The item (Item)
 * POST: Reads data from the stream
 */
istream& operator>>(istream& stream, Item& obj) {

	// "Item:mSerial Item:mName"
	cout << "Enter the name: ";
	getline(stream, obj.mName);

	// "Item:mDescription"
	cout << "Enter the description: ";
	getline(stream, obj.mDescription);

	// "Item:mClubName"
	cout << "Enter the name of the club: ";
	getline(stream, obj.mClubName);

	// "Item:mLocation:mBuilding"
	// "Item:mLocation:mCode Item:mLocation:mRoom"
	stream >> obj.mLocation; // stream should be completely clean afterwards

	/*
	Item:mSource:mPriceUnit Item:mSource:mName
	Item:mSource:mURL
	Item:mSource:mAddress:mNumberStreet Item:mSource:mAddress:mNumberApartment Item:mSource:mAddress:mStreet
	Item:mSource:mAddress:mCity
	Item:mSource:mAddress:mState
	Item:mSource:mAddress:mZipCode
	Item:mSource:mAddress:mCountry
	*/
	stream >> obj.mSource; // stream should be completely clean afterwards

	return stream;
}

/** PURPOSE: OVERLOAD Outputs variables from object to the file stream
		 * PRE:  The file stream (fstream), The obj (Item)
		 * POST: Reads data from the file stream
		 */
ofstream& operator<<(ofstream& stream, Item& obj) {

	stream
		// "Item:mSerial Item:mName"
		<< obj.mSerial << ' ' << obj.mName << '\n'
		// "Item:mDescription"
		<< obj.mDescription << "\n"
		// "Item:mClubName"
		<< obj.mClubName << "\n";
	;

	// "Item:mLocation:mBuilding"
	// "Item:mLocation:mCode Item:mLocation:mRoom"
	stream << obj.mLocation << "\n";

	/*
	Item:mSource:mPriceUnit Item:mSource:mName
	Item:mSource:mURL
	Item:mSource:mAddress:mNumberStreet Item:mSource:mAddress:mNumberApartment Item:mSource:mAddress:mStreet
	Item:mSource:mAddress:mCity
	Item:mSource:mAddress:mState
	Item:mSource:mAddress:mZipCode
	Item:mSource:mAddress:mCountry
	 */
	stream << obj.mSource;

	return stream;
}

/** PURPOSE: OVERLOAD Outputs variables from object to the console
 * PRE:  The stream (ostream), The obj (Item)
 * POST: Reads data from the stream
 */
ostream& operator<<( ostream& stream, Item& obj) {
	stream
		<< setw(10) << right
			<< obj.mSerial << ' '
		<< setw(20) << left
			<< obj.mName
		<< setw(20) << left
			<< obj.mClubName
	;
	return stream;
}
