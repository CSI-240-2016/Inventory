/*
    Created by Dustin Yost on 4/30/2016.
*/

#include <sstream>
#include "Date.h"

// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* PURPOSE: Create a Date object with default values
 * PRE:  None
 * POST: A Date object with default values
*/
Date::Date() {
	mMonth = mDay = mYear = 0;
}

/* PURPOSE: Create an Date object with specific values
 * PRE:  The month (Integer), The day (Integer), The year (Integer)
 * POST: An Date object with specified values
*/
Date::Date(int month, int day, int year) {
	mMonth = month;
	mDay = day;
	mYear = year;
}

// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* PURPOSE: Retrieve the month
 * PRE:  None
 * POST: The month (Integer)
*/
int		Date::getMonth() {
	return mMonth;
}

/* PURPOSE: Retrieve the month as a string
 * PRE:  None
 * POST: The month as an Integer in a String
*/
string	Date::getMonthString() {
	stringstream ss;
	ss << mMonth;
	return ss.str();
}

/* PURPOSE: Retrieve the day
 * PRE:  None
 * POST: The day (Integer)
*/
int		Date::getDay() {
	return mDay;
}

/* PURPOSE: Retrieve the day as a string
 * PRE:  None
 * POST: The day as an Integer in a String
*/
string	Date::getDayString() {
	stringstream ss;
	ss << mDay;
	return ss.str();
}

/* PURPOSE: Retrieve the year
 * PRE:  None
 * POST: The year (Integer)
*/
int		Date::getYear() {
	return mYear;
}

/* PURPOSE: Retrieve the year as a string
 * PRE:  None
 * POST: The year as an Integer in a String
*/
string	Date::getYearString() {
	stringstream ss;
	ss << mYear;
	return ss.str();
}

// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* PURPOSE: Update the month
 * PRE:  The month (Integer)
 * POST: The value is changed to the parameter
*/
void	Date::setMonth(int i) {
	mMonth = i;
}

/* PURPOSE: Update the day
 * PRE:  The day (Integer)
 * POST: The value is changed to the parameter
*/
void	Date::setDay(int i) {
	mDay = i;
}

/* PURPOSE: Update the year
 * PRE:  The year (Integer)
 * POST: The value is changed to the parameter
*/
void	Date::setYear(int i) {
	mYear = i;
}

// ~~~~~ Utility ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

string	Date::toString(string format) {
	string ret = format, key, value;
	unsigned int lengthDif;
	size_t index;

	key = "mm";
	value = getMonthString();
	lengthDif = key.length() - value.length();
	value = string(lengthDif, '0').append(value);
	for (index = 0 ; ; index += value.length()) {
		index = ret.find(key, index);
		if (index == string::npos) break;
		ret.erase(index, key.length());
		ret.insert(index, value);
	}

	key = "dd";
	value = getDayString();
	lengthDif = key.length() - value.length();
	value = string(lengthDif, '0').append(value);
	for (index = 0 ; ; index += value.length()) {
		index = ret.find(key, index);
		if (index == string::npos) break;
		ret.erase(index, key.length());
		ret.insert(index, value);
	}

	key = "yyyy";
	value = getYearString();
	lengthDif = key.length() - value.length();
	value = string(lengthDif, '0').append(value);
	for (index = 0 ; ; index += value.length()) {
		index = ret.find(key, index);
		if (index == string::npos) break;
		ret.erase(index, key.length());
		ret.insert(index, value);
	}

	return ret;
}

// ~~~~~~~~~~ Operators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/** PURPOSE: OVERLOAD Inputs variables from the file stream to object
 * PRE:  The file stream (fstream), The obj (Date)
 * POST: Reads data from the file stream
 */
ifstream& operator>>(ifstream& stream, Date& obj) {
	stream >> obj.mMonth >> obj.mDay >> obj.mYear;
	return stream;
}

/** PURPOSE: OVERLOAD Outputs variables from object to the file stream
		 * PRE:  The file stream (fstream), The obj (Date)
		 * POST: Reads data from the file stream
		 */
ofstream& operator<<(ofstream& stream, const Date obj) {
	stream << obj.mMonth << ' ' << obj.mDay << ' ' << obj.mYear;
	return stream;
}
