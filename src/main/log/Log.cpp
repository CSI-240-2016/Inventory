/*
    Created by Dustin Yost on 4/30/2016.
*/

#include "Log.h"
#include <iomanip>

// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* PURPOSE: Create a Log object with default values
 * PRE:  None
 * POST: A Log object with default values
*/
Log::Log() {
	mItemSerial = 0;
	mItemName = mClubName = "";
	mDateOut = mDateInExpected = mDateIn = Date();
	mOutBy_Name = mOutBy_Username = mOutTo_Name =
		mInBy_Name = mInBy_Username = mInFrom_Name = "";
}

// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* PURPOSE: Retrieve the item serial
 * PRE:  None
 * POST: The item serial (Integer)
*/
int		Log::getSerial() {
	return mItemSerial;
}

/* PURPOSE: Retrieve the name
 * PRE:  None
 * POST: The name (String)
*/
string	Log::getName() {
	return mItemName;
}

/* PURPOSE: Retrieve the club name
 * PRE:  None
 * POST: The club name (String)
*/
string	Log::getClubName() {
	return mClubName;
}

/* PURPOSE: Retrieve the date out
 * PRE:  None
 * POST: The date out (Date)
*/
Date	Log::getDateOut() {
	return mDateOut;
}

/* PURPOSE: Retrieve the expected date in
 * PRE:  None
 * POST: The expected date in (Date)
*/
Date	Log::getDateInExpected() {
	return mDateInExpected;
}

/* PURPOSE: Retrieve the date in
 * PRE:  None
 * POST: The date in (Date)
*/
Date	Log::getDateIn() {
	return mDateIn;
}

/* PURPOSE: Retrieve the name of who the item was checked out by
 * PRE:  None
 * POST: The name of who the item was checked out by (String)
*/
string	Log::getOutByName() {
	return mOutBy_Name;
}

/* PURPOSE: Retrieve the username of who the item was checked out by
 * PRE:  None
 * POST: The username of who the item was checked out by (String)
*/
string	Log::getOutByUsername() {
	return mOutBy_Username;
}

/* PURPOSE: Retrieve the name of who the item was checked out to
 * PRE:  None
 * POST: The name of who the item was checked out to (String)
*/
string	Log::getOutToName() {
	return mOutTo_Name;
}

/* PURPOSE: Retrieve the name of who the item was checked in by
 * PRE:  None
 * POST: The name of who the item was checked in by (String)
*/
string	Log::getInByName() {
	return mInBy_Name;
}

/* PURPOSE: Retrieve the username of who the item was checked in by
 * PRE:  None
 * POST: The username of who the item was checked in by (String)
*/
string	Log::getInByUsername() {
	return mInBy_Username;
}

/* PURPOSE: Retrieve the name of who the item was checked in from
 * PRE:  None
 * POST: The name of who the item was checked in from (String)
*/
string	Log::getInFromName() {
	return mInFrom_Name;
}

// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* PURPOSE: Update the item serial
 * PRE:  The item serial (Integer)
 * POST: The value is changed to the parameter
*/
void	Log::setSerial(int i) {
	mItemSerial = i;
}

/* PURPOSE: Update the name
 * PRE:  The name (String)
 * POST: The value is changed to the parameter
*/
void	Log::setName(string s) {
	mItemName = s;
}

/* PURPOSE: Update the club name
 * PRE:  The club name (String)
 * POST: The value is changed to the parameter
*/
void	Log::setClubName(string s) {
	mClubName = s;
}

/* PURPOSE: Update the date out
 * PRE:  The date out (Date)
 * POST: The value is changed to the parameter
*/
void	Log::setDateOut(Date d) {
	mDateOut = d;
}

/* PURPOSE: Update the expected date in
 * PRE:  The expected date in (Date)
 * POST: The value is changed to the parameter
*/
void	Log::setDateInExpected(Date d) {
	mDateInExpected = d;
}

/* PURPOSE: Update the date in
 * PRE:  The date in (Date)
 * POST: The value is changed to the parameter
*/
void	Log::setDateIn(Date d) {
	mDateIn = d;
}

/* PURPOSE: Update the name of who the item was checked out by
 * PRE:  The name of who the item was checked out by (String)
 * POST: The value is changed to the parameter
*/
void	Log::setOutBy_Name(string s) {
	mOutBy_Name = s;
}

/* PURPOSE: Update the username of who the item was checked out by
 * PRE:  The username of who the item was checked out by (String)
 * POST: The value is changed to the parameter
*/
void	Log::setOutBy_Username(string s) {
	mOutBy_Username = s;
}

/* PURPOSE: Update the name of who the item was checked out to
 * PRE:  The name of who the item was checked out to (String)
 * POST: The value is changed to the parameter
*/
void	Log::setOutTo_Name(string s) {
	mOutTo_Name = s;
}

/* PURPOSE: Update the name of who the item was checked in by
 * PRE:  The name of who the item was checked in by (String)
 * POST: The value is changed to the parameter
*/
void	Log::setInByName(string s) {
	mInBy_Name = s;
}

/* PURPOSE: Update the username of who the item was checked in by
 * PRE:  The username of who the item was checked in by (String)
 * POST: The value is changed to the parameter
*/
void	Log::setInByUsername(string s) {
	mInBy_Username = s;
}

/* PURPOSE: Update the name of who the item was checked in from
 * PRE:  The name of who the item was checked in from (String)
 * POST: The value is changed to the parameter
*/
void	Log::setInFromName(string s) {
	mInFrom_Name = s;
}

// ~~~~~~~~~~ Operators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* PURPOSE: Tries to read from the file stream
 * PRE:  The file stream
 * POST: if the log is able to be read (the first element could be read)
 */
bool	Log::readPrimary(ifstream& stream) {
	return !(stream >> mItemSerial).eof();
}

/** PURPOSE: OVERLOAD Inputs variables from the file stream to object
 * PRE:  The file stream (fstream), The obj (Log)
 * 		 Log.readPrimary MUST be called prior
 * POST: Reads data from the file stream
 */
ifstream& operator>>(ifstream& stream, Log& obj) {

	// "Log:mItemSerial Log:mItemName"
	stream.get();
	getline(stream, obj.mItemName);

	// "Log:mDateOut:mMonth Log:mDateOut:mDay Log:mDateOut:mYear Log:mDateInExpected:mMonth Log:mDateInExpected:mDay Log:mDateInExpected:mYear Log:mDateIn:mMonth Log:mDateIn:mDay Log:mDateIn:mYear"
	stream >> obj.mDateOut >> obj.mDateInExpected >> obj.mDateIn;
	getline(stream, obj.mClubName); // clear line

	// "Log:mClubName"
	getline(stream, obj.mClubName);

	// "Log:mOutBy_Username Log:mOutBy_Name"
	stream >> obj.mOutBy_Username;
	stream.get();
	getline(stream, obj.mOutBy_Name);

	// "Log:mOutTo_Name"
	getline(stream, obj.mOutTo_Name);

	// "Log:mInBy_Username Log:mInBy_Name"
	stream >> obj.mInBy_Username;
	stream.get();
	getline(stream, obj.mInBy_Name);

	// "Log:mInFrom_Name"
	getline(stream, obj.mInFrom_Name);

	return stream;
}

/** PURPOSE: OVERLOAD Outputs variables from object to the file stream
 * PRE:  The file stream (fstream), The obj (Log)
 * POST: Reads data from the file stream
 */
ofstream& operator<<(ofstream& stream, const Log obj) {

	stream
		// "Log:mItemSerial Log:mItemName"
		<< obj.mItemSerial << ' ' << obj.mItemName << '\n'
	;

	// "Log:mDateOut:mMonth Log:mDateOut:mDay Log:mDateOut:mYear Log:mDateInExpected:mMonth Log:mDateInExpected:mDay Log:mDateInExpected:mYear Log:mDateIn:mMonth Log:mDateIn:mDay Log:mDateIn:mYear"
	stream << obj.mDateOut << ' ';
	stream << obj.mDateInExpected << ' ';
	stream << obj.mDateIn << '\n';

	stream
		// "Log:mClubName"
		<< obj.mClubName << '\n'
		// "Log:mOutBy_Username Log:mOutBy_Name"
		<< obj.mOutBy_Username << ' ' << obj.mOutBy_Name << '\n'
		// "Log:mOutTo_Name"
		<< obj.mOutTo_Name << '\n'
		// "Log:mInBy_Username Log:mInBy_Name"
		<< obj.mInBy_Username << ' ' << obj.mInBy_Name << '\n'
		// "Log:mInFrom_Name"
		<< obj.mInFrom_Name
	;

	return stream;
}

/** PURPOSE: OVERLOAD Outputs variables from object to the console
 * PRE:  The file stream (fstream), The obj (Log)
 * POST: Reads data from the file stream
 */
ostream& operator<<( ostream& stream, Log obj) {
	stream
		<< setw(10) << right
			<< obj.mItemSerial << ' '
		<< setw(20) << left
			<< obj.mItemName
		<< setw(20) << left
			<< obj.mClubName
		<< setw(15) << left
			<< obj.mDateOut.toString("mm/dd/yyyy")
		<< setw(15) << left
			<< obj.mDateInExpected.toString("mm/dd/yyyy")
		<< setw(15) << left
			<< obj.mDateIn.toString("mm/dd/yyyy")
	;
	return stream;
}
