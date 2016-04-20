#include "Date.h"

using namespace std;

/* Pre: None
* Post: Date object created. Default date is January 1st 2000
* Purpose: To create Date object
*********************************************************/
Date::Date()
{
	mDay = 1;
	mMonth = 1;
	mYear = 2000;
}


/* Pre: Day, month and year passed into function
* Post: Date object created with specified day month and year.
* Purpose: To create Date object
*********************************************************/
Date::Date(int day, int month, int year)
{
	mDay = day;
	mMonth = month;
	mYear = year;
}


/* Pre: None
* Post: Deconstructs Date object
* Purpose: to deconstruct a Date object
*********************************************************/
Date::~Date()
{

}


/* Pre: None
* Post: Returns string form of date object
* Purpose: To allow user to easily get date object
*********************************************************/
string Date::getDate()
{
	return to_string(mMonth) + '/' + to_string(mDay) + '/' + to_string(mYear);
}


/* Pre: None
* Post: returns mDay
* Purpose: To gain access to a Date's day value
*********************************************************/
int Date::getDay()
{
	return mDay;
}


/* Pre: None
* Post: returns mMonth
* Purpose: To gain access to a Date's month value
*********************************************************/
int Date::getMonth()
{
	return mMonth;
}


/* Pre: None
* Post: returns mYear
* Purpose: To gain access to a Date's year value
*********************************************************/
int Date::getYear()
{
	return mYear;
}

/* Pre: Two date objects compared with == operator
* Post: Returns boolean value
* Purpose: To allow for easy comparison of date objects
*********************************************************/
bool operator == (Date& dateOne, Date& dateTwo)
{
	if (dateOne.getYear() == dateTwo.getYear() && dateOne.getMonth() == dateTwo.getMonth() && dateOne.getDay()
		== dateTwo.getDay())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* Pre: Two date objects compared with >= operator
* Post: Returns boolean value
* Purpose: To allow for easy comparison of date objects
*********************************************************/
bool operator > (Date& dateOne, Date& dateTwo)
{
	if (dateOne.getYear() > dateTwo.getYear())
	{
		return true;
	}
	else if (dateOne.getYear() == dateTwo.getYear())
	{
		if (dateOne.getMonth() > dateTwo.getMonth())
		{
			return true;
		}
		else if (dateOne.getMonth() == dateTwo.getMonth())
		{
			if (dateOne.getDay() > dateTwo.getDay())
			{
				return true;
			}
		}
	}
	return false;
}


/* Pre: Two date objects compared with <= operator
* Post: Returns boolean value
* Purpose: To allow for easy comparison of date objects
*********************************************************/
bool operator < (Date& dateOne, Date& dateTwo)
{
	if (dateOne.getYear() < dateTwo.getYear())
	{
		return true;
	}
	else if (dateOne.getYear() == dateTwo.getYear())
	{
		if (dateOne.getMonth() < dateTwo.getMonth())
		{
			return true;
		}
		else if (dateOne.getMonth() == dateTwo.getMonth())
		{
			if (dateOne.getDay() < dateTwo.getDay())
			{
				return true;
			}
		}
	}
	return false;

}


/* Pre: Two date objects compared with != operator
* Post: Returns boolean value
* Purpose: To allow for easy comparison of date objects
*********************************************************/
bool operator != (Date& dateOne, Date& dateTwo)
{
	if (dateOne.getYear() != dateTwo.getYear() || dateOne.getMonth() != dateTwo.getMonth() || dateOne.getDay()
		!= dateTwo.getDay())
	{
		return true;
	}
	else
	{
		return false;
	}
}


/* Pre: Two Date objects compared with = operator
* Post: Sets object one to object two
* Purpose: To allow for easy changing of all date values
*********************************************************/
void operator = (Date& dateOne, Date& dateTwo)
{
	dateOne.setDate(dateTwo.getDay(),dateTwo.getMonth(),dateTwo.getYear());
}


/* Pre: Given three ints
* Post: Sets mDay, mMonth, and Myear values for date object
* Purpose: To allow for easy changing of all date values
*********************************************************/
void Date::setDate(int day, int month, int year)
{
	mDay = day;
	mMonth = month;
	mYear = year;
}

/* Pre: Given day value
* Post: Sets mDay to given value
* Purpose: To set a Date's mDay value
*********************************************************/
void Date::setDay(int day)
{
	mDay = day;
}


/* Pre: Given month value
* Post: Sets mMonth to given value
* Purpose: To set a Date's mMonth value
*********************************************************/
void Date::setMonth(int month)
{
	mMonth = month;
}


/* Pre: Given Year value
* Post: Sets mYear to given value
* Purpose: To set a Date's mYear value
*********************************************************/
void Date::setYear(int year)
{
	mYear = year;
}
