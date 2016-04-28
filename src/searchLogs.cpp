#include "searchLogs.h"

/* Pre: logs is an array of logs to search, numLogs is the length of logs,
 *		serial is the serial number to search for, retLength is a referance
 *		to be set to the length of the returned array
 * Post: returns an array of all the Log in logs with serial # serial, 
 *		 and sets retLength to the length of the returned array
 * Purpose: searches logs by serial number
 */
Log* searchBySerial(Log* logs, int numLogs, int serial, int& retLength)
{
	retLength = 0;
	vector<Log> withSerial;
	for (int i = 0; i < numLogs; i++)
	{
		if (logs[i].getItemSerial() == serial)
		{
			withSerial[retLength] = logs[i];
			retLength++;
		}
	}
	return toArray(withSerial);
}

/* Pre: logs is an array of logs to search, numLogs is the length of logs,
 *		clubName is the club name to search for, retLength is a referance
 *		to be set to the length of the returned array
 * Post: returns an array of all the Log in logs with club name clubName
 *		 and sets retLength to the length of the returned array
 * Purpose: searches logs by club name
 */
Log* searchByClub(Log* logs, int numLogs, string clubName, int& retLength)
{
	retLength = 0;
	vector<Log> withClub;
	for (int i = 0; i < numLogs; i++)
	{
		if (logs[i].getClubName() == clubName)
		{
			withClub[retLength] = logs[i];
			retLength++;
		}
	}
	return toArray(withClub);
}

/* Pre: logs is an array of logs to search, numLogs is the length of logs,
 *		club is the club to search for, retLength is a referance
 *		to be set to the length of the returned array
 * Post: returns an array of all the Log in logs with club club
 *		 and sets retLength to the length of the returned array
 * Purpose: searches logs by club
 */
Log* searchByClub(Log* logs, int numLogs, Club club, int& retLength)
{
	return searchByClub(logs, numLogs, club.getName(), retLength);
}

/* Pre: logs is an array of logs to search, numLogs is the length of logs,
 *		outDate is the out date to search for, retLength is a referance
 *		to be set to the length of the returned array
 * Post: returns an array of all the Log in logs with out date outDate 
 *		 and sets retLength to the length of the returned array
 * Purpose: searches logs by out date
 */
Log* searchByOutDate(Log* logs, int numLogs, Date outDate, int& retLength)
{
	retLength = 0;
	vector<Log> withDate;
	for (int i = 0; i < numLogs; i++)
	{
		/* No operator overloaded for Data class
		if (logs[i].getOutDate() == outDate)
		{
			withDate[retLength] = logs[i];
			retLength++;
		}
		*/
	}
	return toArray(withDate);
}

/* Pre: logs is an array of logs to search, numLogs is the length of logs,
 *		serial is the serial number to search for, retLength is a referance
 *		to be set to the length of the returned array
 * Post: returns an array of all the Log in logs with serial # serial, 
 *		 and sets retLength to the length of the returned array
 * Purpose: searches logs by serial number
 */
Log* searchByInDate(Log* logs, int numLogs, Date inDate, int& retLength)
{
	retLength = 0;
	vector<Log> withInDate;
	for (int i = 0; i < numLogs; i++)
	{
		/* No operator overloaded for Data class
		if (logs[i].getInDate() == inDate)
		{
			withInDate[retLength] = logs[i];
			retLength++;
		}
		*/
	}
	return toArray(withInDate);
}

/* Pre: logs is an array of logs to search, numLogs is the length of logs,
 *		serial is the serial number to search for, retLength is a referance
 *		to be set to the length of the returned array
 * Post: returns an array of all the Log in logs with serial # serial, 
 *		 and sets retLength to the length of the returned array
 * Purpose: searches logs by serial number
 */
Log* searchByExpectedInDate(Log* logs, int numLogs, Date expectedInDate, int& retLength)
{
	retLength = 0;
	vector<Log> withExpectedDate;
	for (int i = 0; i < numLogs; i++)
	{
		/* No operator overloaded for Data class
		if (logs[i].getExpectedDate() == expectedInDate)
		{
			withExpectedDate[retLength] = logs[i];
			retLength++;
		}
		*/
	}
	return toArray(withExpectedDate);
}

/* Pre: vec is a vector of Log
 * Post: returns an array with the contents of vec
 * Pre: helper function to turn a vector into an array
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
