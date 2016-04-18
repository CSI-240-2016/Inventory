#include "Log.h"



Log::Log()
{
}


Log::~Log()
{
}

int Log::getItemSerial()
{
	return mItemSerial;
}

string Log::getItemName()
{
	return mItemName;
}

Date Log::getOutDate()
{
	return mOutDate;
}

Date Log::getInDate()
{
	return mInDate;
}

Date Log::getExpectedDate()
{
	return mExpectedDate;
}

string Log::getOutByName()
{
	return mOutByName;
}

string Log::getOutByUsername()
{
	return mOutByUsername;
}

string Log::getOutTo()
{
	return mOutTo;
}

string Log::getClubName()
{
	return mClubName;
}

string Log::getInByName()
{
	return mInByName;
}

string Log::getInByUsername()
{
	return mInByUsername;
}

string Log::getInFromName()
{
	return mInFromName;
}

std::istream& operator>>(std::istream& in, Log& targ)
{
	in >> targ.mItemSerial >> targ.mItemName;
	string dateStr; //dateStr is a temporary var that will be used to store multiple dates at different points in the program
	in >> dateStr;
	targ.mOutDate = parseDate(dateStr);
	in >> dateStr;
	targ.mExpectedInDate = parseDate(dateStr);
	in >> dateStr;
	targ.mInDate = parseDate(dateStr);
	in >> targ.mClubName;
	in >> targ.mOutByUsername >> targ.mOutByName;
	in >> targ.mOutTo;
	in >> targ.mInByUsername >> targ.mInByName;
	in >> targ.mInFromName;
	return in;
}

Date parseDate(string dateString)
{
	char* components = strtok(dateString.c_str(), "/");
}