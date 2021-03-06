#include "Log.h"


/* Pre: none
 * Post: object is created with empty members
 * Purpose: default constructor
 */
Log::Log()
{

}

Log::Log(int serialItem, string nameItem,
		Date out, Date inExpt, Date in,
		string nameClub,
		string nameOutBy_username, string nameOutBy, string nameOutTo,
		string nameInBy_username, string nameInBy, string nameInFrom) {
	mItemSerial = serialItem;
	mItemName = nameItem;
	mOutDate = out;
	mExpectedInDate = inExpt;
	mInDate = in;
	mClubName = nameClub;
	mOutByUsername = nameOutBy_username;
	mOutByName = nameOutBy;
	mOutTo = nameOutTo;
	mInByUsername = nameInBy_username;
	mInByName = nameInBy;
	mInFromName = nameInFrom;
}

/* Pre: none
 * Post: object is destroyed
 * Purpose: default destructor
 */
Log::~Log()
{
}

/* Pre: none
 * Post: returns item serial
 * Purpose: accessor for mItemSerial
 */
int Log::getItemSerial()
{
	return mItemSerial;
}

/* Pre: none
 * Post: returns item name
 * Purpose: accessor for mItemName
 */
string Log::getItemName()
{
	return mItemName;
}

/* Pre: none
 * Post: returns out date - pass by value!
 * Purpose: accessor for mOutDate
 */
Date Log::getOutDate()
{
	return mOutDate;
}

/* Pre: none
 * Post: returns mInDate - pass by value!
 * Purpose: accessor for mInDate
 */
Date Log::getInDate()
{
	return mInDate;
}

/* Pre: none
 * Post: returns the expected in date - pass by value!
 * Purpose: accessor for mExpectedInDate
 */
Date Log::getExpectedDate()
{
	return mExpectedInDate;
}

/* Pre: none
 * Post: returns name of the person checking out the item(?)
 * Purpose: accessor for mOutByName
 */
string Log::getOutByName()
{
	return mOutByName;
}

/* Pre: none
 * Post: returns the username of the person checking out the item (?)
 * Purpose: accessor for mOutByUsername
 */
string Log::getOutByUsername()
{
	return mOutByUsername;
}

/* Pre: none
 * Post: returns out to
 * Purpose: accessor for mOutTo
 */
string Log::getOutTo()
{
	return mOutTo;
}

/* Pre: none
 * Post: returns the name of the club checking out the item (?)
 * Purpose: accessor for mClubName
 */
string Log::getClubName()
{
	return mClubName;
}

/* Pre: none
 * Post: returns the name of the person returning the item (?)
 * Purpose: accessor for mInByName
 */
string Log::getInByName()
{
	return mInByName;
}

/* Pre: none
 * Post: returns the username of the person returning the item (?)
 * Purpose: accessor for mInByUsername
 */
string Log::getInByUsername()
{
	return mInByUsername;
}

/* Pre: none
 * Post: returns the... ?
 * Purpose: accessor for mInFromName
 */
string Log::getInFromName()
{
	return mInFromName;
}

/* Pre: in is an open istream from a data file, targ is a referance to the Log to write the info from in to
 * Post: writes the info found in in to targ and returns in
 * Purpose: overloaded form of >> for Log
 */
istream& operator>>(istream& in, Log& targ)
{
	in >> targ.mItemSerial >> targ.mItemName;
	// TODO in >> targ.mOutDate >> targ.mExpectedInDate >> targ.mInDate; // Assume here that there's an overloaded form of >> for Date
	in >> targ.mClubName;
	in >> targ.mOutByUsername >> targ.mOutByName;
	in >> targ.mOutTo;
	in >> targ.mInByUsername >> targ.mInByName;
	in >> targ.mInFromName;
	return in;
}

/* Pre: out is an ostream to a data file (I would assume), targ is a referance to a Log to write to out
 * Post: writes the info found in targ to out, and reeturns out
 * Purpose: overloaded form of << for Log
 */
ostream& operator<<(ostream& out, Log& targ)
{
	out << targ.mItemSerial << " " << targ.mItemName << endl;
	// TODO out << targ.mOutDate << " " << targ.mExpectedInDate << " " << targ.mInDate << endl; // Assume here that there's an overloaded form of >> for Date
	out << targ.mClubName << endl;
	out << targ.mOutByUsername << " " << targ.mOutByName << endl;
	out << targ.mOutTo << endl;
	out << targ.mInByUsername << " " << targ.mInByName << endl;
	out << targ.mInFromName << endl;
	return out;
}

ifstream& operator>>(ifstream& stream, Log& obj) {
	stream >> obj.mItemSerial;
	getline(stream, obj.mItemName);
	
	obj.mOutDate = Date();
	obj.mExpectedInDate = Date();
	obj.mInDate = Date();
	stream
		>> obj.mOutDate
		>> obj.mExpectedInDate
		>> obj.mInDate
	;
	getline(stream, obj.mClubName); // clear the line
	
	getline(stream, obj.mClubName);
	
	stream >> obj.mOutByUsername;
	getline(stream, obj.mOutByName);
	getline(stream, obj.mOutTo);
	
	stream >> obj.mInByUsername;
	getline(stream, obj.mInByName);
	getline(stream, obj.mInFromName);
	
	return stream;
}

ofstream& operator<<(ofstream& stream, Log& obj) {
	
	stream
		<< obj.mItemSerial << " "
			<< obj.mItemName << "\n";
	stream << obj.mOutDate << " ";
	stream << obj.mExpectedInDate << " ";
	stream << obj.mInDate << "\n";
	stream
		<< obj.mClubName << "\n"
		<< obj.mOutByUsername << " "
			<< obj.mOutByName << "\n"
		<< obj.mOutTo << "\n"
		<< obj.mInByUsername << " "
			<< obj.mInByName << "\n"
		<< obj.mInFromName
	;
	
	return stream;
}
