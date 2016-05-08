/*
    Created by Dustin Yost on 4/30/2016.
*/

#include "Location.h"
#include "../lib/io.h"

// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* PURPOSE: Create a Location object with default values
 * PRE:  None
 * POST: A Location object with default values
*/
Location::Location(){
	mBuilding	= "";
	mRoom		= "";
	mCode		= "";
}

/* PURPOSE: Create an item object with specific values
 * PRE:  The building (String), The room (String), The code (String)
 * POST: An item object with specified values
*/
Location::Location(string building, string room, string code) {
	mBuilding	= building;
	mRoom		= room;
	mCode		= code;
}

// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* PURPOSE: Retrieve the building
 * PRE:  None
 * POST: The building (String)
*/
string	Location::getBuilding(){
	return mBuilding;
}

/* PURPOSE: Retrieve the room
 * PRE:  None
 * POST: The room (String)
*/
string	Location::getRoom() {
	return mRoom;
}

/* PURPOSE: Retrieve the code
 * PRE:  None
 * POST: The code (String)
*/
string	Location::getCode() {
	return mCode;
}

// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* PURPOSE: Update the building
 * PRE:  The building (String)
 * POST: The value is changed to the parameter
*/
void	Location::setBuilding(string s) {
	mBuilding = s;
}

/* PURPOSE: Update the room
 * PRE:  The room (String)
 * POST: The value is changed to the parameter
*/
void	Location::setRoom(string s) {
	mRoom = s;
}

/* PURPOSE: Update the code
 * PRE:  The code (String)
 * POST: The value is changed to the parameter
*/
void	Location::setCode(string s) {
	mCode = s;
}

// ~~~~~~~~~~ Operators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* PURPOSE: Determine if this Location is equal to another Location
 * PRE:  The other Location (Location)
 * POST: true, if the all the buildings, rooms, and codes match
*/
bool	Location::operator==(Location other) {
	return mBuilding == other.mBuilding &&
		mRoom == other.mRoom &&
		mCode == other.mCode;
}

/** PURPOSE: OVERLOAD Inputs variables from the file stream to object
 * PRE:  The file stream (fstream), The location (Location)
 * POST: Reads data from the file stream
 */
ifstream& operator>>(ifstream& stream, Location& obj) {

	// "Location:mBuilding"
	getline(stream, obj.mBuilding);

	// "Location:mCode Location:mRoom"
	stream >> obj.mCode;
	stream.get();
	getline(stream, obj.mRoom);

	return stream;
}

/** PURPOSE: OVERLOAD Inputs variables from the file stream to object
 * PRE:  The stream (istream), The obj (Location)
 * POST: Reads data from the stream
 */
istream& operator>>(istream& stream, Location& obj) {
	
	// "Location:mBuilding"
	cout << "Enter the building name: ";
	getline(stream, obj.mBuilding);

	// "Location:mCode Location:mRoom"
	cout << "Enter the room: ";
	getline(stream, obj.mRoom);
	
	cout << "Enter the shelf/code: ";
	getline(stream, obj.mCode);

	return stream;
}

/** PURPOSE: OVERLOAD Outputs variables from object to the file stream
 * PRE:  The file stream (fstream), The obj (Location)
 * POST: Reads data from the file stream
 */
ofstream& operator<<(ofstream& stream, const Location obj) {
	stream
		// "Location:mBuilding"
		<< obj.mBuilding << "\n"
		// "Location:mCode Location:mRoom"
		<< obj.mCode << " " << obj.mRoom
	;
	return stream;
}
