#ifndef LOG_H_
#define LOG_H_
#include <string>
#include <istream>
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
	friend std::istream& operator>>(std::istream& in, Log& targ);
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
Date parseDate(string datestring);
#endif