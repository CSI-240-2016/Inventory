#ifndef SEARCH_LOGS_H_
#define SEARCH_LOGS_H_
#include <vector>
#include <string>
#include "club.h"
#include "Log.h"
using namespace std;

Log* searchBySerial(Log* logs, int numLogs, int serial, int& retLength);
Log* searchByClub(Log* logs, int numLogs, string clubName, int& retLength);
Log* searchByClub(Log* logs, int numLogs, Club club, int& retLength);
Log* searchByOutDate(Log* logs, int numLogs, Date outDate, int& retLength);
Log* searchByInDate(Log* logs, int numLogs, Date inDate, int& retLength);
Log* searchByExpectedInDate(Log* logs, int numLogs, Date expectedInDate, int& retLength);
Log* toArray(vector<Log> vec);

#endif