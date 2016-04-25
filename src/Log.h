#ifndef LOG_H_
#define LOG_H_
#include <string>
#include <fstream>
#include <iostream>
#include "Date.h"
using namespace std;
class Log
{
public:
	Log();
	~Log();
	int getItemSerial();
	string getItemName();
	Date getOutDate();
	Date getInDate();
	Date getExpectedDate();
	string getOutByName();
	string getOutByUsername();
	string getOutTo();
	string getClubName();
	string getInByName();
	string getInByUsername();
	string getInFromName();
	friend istream& operator>>(istream& in, Log& targ);
	friend ostream& operator<<(ostream& out, Log& targ);
private:
	int mItemSerial;
	string mItemName;
	Date mOutDate;
	Date mInDate;
	Date mExpectedInDate;
	string mOutByName;
	string mOutByUsername;
	string mOutTo;
	string mClubName;
	string mInByName;
	string mInByUsername;
	string mInFromName;
};
#endif