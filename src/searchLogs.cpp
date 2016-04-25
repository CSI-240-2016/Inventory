#include <vector>
#include "searchLogs.h"

using namespace std;
/* Pre: logs is an array of ALL logs, numLogs is the length of logs, itemSerial is the 
 *		serial # of the item to search for, retLength is a referance that will be set 
 *		to the length of the array returned
 * Post: reteurns an array of all the Logs that have the item serial number itemSerial, 
 *		and sets retLength to the length of that array
 * Purpose: searches a list of logs based on serial number
 */
Log* getLogs(Log* logs, int numLogs, int itemSerial, int& retLength)
{
	retLength = 0;
	vector<Log> logsWithSerial;
	for (int i = 0; i < numLogs; i++)
	{
		if (logs[i].getItemSerial() == itemSerial)
		{
			logsWithSerial[retLength] = logs[i];
			retLength++;
		}
	}
	return toArray(logsWithSerial);
}

/* Pre: logs is an array of ALL logs, numLogs is the length of logs, club is the 
 *		club to search for, retLength is a referance that will be set to the length
 *		of the array returned
 * Post: reteurns an array of all the Logs that have the Club club, and sets retLength 
 *		to the length of that array
 * Purpose: searches a list of logs based on Club
 */
Log* getLogs(Log* logs, int numLogs, Club club, int& retLength)
{
	return getLogs(logs, numLogs, club.getName(), retLength);
}

/* Pre: logs is an array of ALL logs, numLogs is the length of logs, club is the 
 *		name of theclub to search for, retLength is a referance that will be set 
 *		to the length of the array returned
 * Post: reteurns an array of all the Logs that have the Club club, and sets retLength 
 *		to the length of that array
 * Purpose: identical to the previous function, but takes a club name rather than a club object
 */
Log* getLogs(Log* logs, int numLogs, string clubName, int& retLength)
{
	retLength = 0;
	vector<Log> logsWithClub;
	for (int i = 0; i < numLogs; i++)
	{
		if (logs[i].getClubName() == clubName)
		{
			logsWithClub[retLength] = logs[i];
			retLength++;
		}
	}
	return toArray(logsWithClub);
}

/* Pre: logs is an array of ALL logs, numLogs is the length of logs, date is the 
 *		in date to search for, retLength is a referance that will be set to the 
 *		length of the array returned
 * Post: reteurns an array of all the Logs that have the in date Date, and sets 
 *		retLength to the length of that array
 * Purpose: searches a list of logs based on Date
 */
Log* getLogsByInDate(Log* logs, int numLogs, Date date, int& retLength)
{
	retLength = 0;
	vector<Log> logsWithDate;
	for (int i = 0; i < numLogs; i++)
	{
		if (logs[i].getInDate() == date)
		{
			logsWithDate[retLength] = logs[i];
			retLength++;
		}
	}
	return toArray(logsWithDate);
}

/* Pre: logs is an array of ALL logs, numLogs is the length of logs, date is the 
 *		out date to search for, retLength is a referance that will be set to the 
 *		length of the array returned
 * Post: reteurns an array of all the Logs that have the out date Date, and sets 
 *		retLength to the length of that array
 * Purpose: searches a list of logs based on Date
 */
Log* getLogsByOutDate(Log* logs, int numLogs, Date date, int& retLength)
{
	retLength = 0;
	vector<Log> logsWithDate;
	for (int i = 0; i < numLogs; i++)
	{
		if (logs[i].getOutDate() == date)
		{
			logsWithDate[retLength] = logs[i];
			retLength++;
		}
	}
	return toArray(logsWithDate);
}

/* Pre: logs is an array of ALL logs, numLogs is the length of logs, date is the 
 *		expected date to search for, retLength is a referance that will be set to the 
 *		length of the array returned
 * Post: reteurns an array of all the Logs that have the expected date Date, and sets 
 *		retLength to the length of that array
 * Purpose: searches a list of logs based on Date
 */
Log* getLogsByExpectedDate(Log* logs, int numLogs, Date date, int& retLength)
{
	retLength = 0;
	vector<Log> logsWithDate;
	for (int i = 0; i < numLogs; i++)
	{
		if (logs[i].getExpectedDate() == date)
		{
			logsWithDate[retLength] = logs[i];
			retLength++;
		}
	}
	return toArray(logsWithDate);
}

/* Pre: vec is a vector of logs to convert into an array
 * Post: returns an array of the logs contained in vec
 * Purpose: helper function to convert vectors into dynamically allocated arrays
 */
Log* toArray(vector<Log> vec)
{
	Log* ret = new Log[vec.size()];
	for (int i = 0; i < vec.size(); i++)
	{
		ret[i] = vec[i];
	}
	return ret;
}