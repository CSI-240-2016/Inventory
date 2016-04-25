#ifndef SEARCH_LOGS_H_
#define SEARCH_LOGS_H_

#include <vector>
#include <string>
#include "Log.h"
#include "club.h"

using namespace std;

Log* getLogs(Log* logs, int numLogs, int itemSerial, int& retLength);
Log* getLogs(Log* logs, int numLogs, Club club, int& retLength);
Log* getLogs(Log* logs, int numLogs, string clubName, int& retLength);
Log* getLogsByInDate(Log* logs, int numLogs, Date date, int& retLength);
Log* getLogsByOutDate(Log* logs, int numLogs, Date date, int& retLength);
Log* getLogsByExpectedDate(Log* logs, int numLogs, Date date, int& retLength);

Log* toArray(vector<Log> vec);
#endif