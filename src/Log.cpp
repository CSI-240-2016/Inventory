#include "Log.h"


/* Pre: none
 * Post: object is created with empty members
 * Purpose: default constructor
 */
Log::Log()
{
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

istream& operator>>(istream& in, Log& targ)
{
	in >> targ.mItemSerial >> targ.mItemName;
	in >> targ.mOutDate >> targ.mExpectedInDate >> targ.mInDate;
	in >> targ.mClubName;
	in >> targ.mOutByUsername >> targ.mOutByName;
	in >> targ.mOutTo;
	in >> targ.mInByUsername >> targ.mInByName;
	in >> targ.mInFromName;
	return in;
}

ostream& operator<<(ostream& out, Log& targ)
{
	out << targ.mItemSerial << " " << targ.mItemName << endl;
	out << targ.mOutDate << " " << targ.mExpectedInDate << " " << targ.mInDate << endl;
	out << targ.mClubName << endl;
	out << targ.mOutByUsername << " " << targ.mOutByName << endl;
	out << targ.mOutTo << endl;
	out << targ.mInByUsername << " " << targ.mInByName << endl;
	out << targ.mInFromName << endl;
	return out;
}