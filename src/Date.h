
#ifndef DATE_H
#define DATE_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Date
{
private:
	int mMonth, mDay, mYear;

public:
	//Constructors
	Date();
	Date(int day, int month, int year);
	~Date();

	//Accessors
	std::string getDate();
	int getDay();
	int getMonth();
	int getYear();

	//Overloaded Operators
	friend bool operator == (Date& dateOne, Date& dateTwo);
	friend bool operator > (Date& dateOne, Date& dateTwo);
	friend bool operator < (Date& dateOne, Date& dateTwo);
	friend bool operator != (Date& dateOne, Date& dateTwo);
	friend ifstream& operator>>(ifstream& stream, Date& obj);
	friend ofstream& operator<<(ofstream& stream, Date& obj);

	//Mutators
	void setDate(int day, int month, int year);
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);

};


#endif