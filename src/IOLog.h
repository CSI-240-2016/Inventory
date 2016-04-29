#ifndef IO_LOG_H
#define IO_LOG_H

#include "LinkedList.h"
#include "Log.h"

using namespace std;

void loadLogs(LinkedList<Log> *);
void saveLogs(LinkedList<Log> *);
void printLogs(LinkedList<Log> *);

#endif