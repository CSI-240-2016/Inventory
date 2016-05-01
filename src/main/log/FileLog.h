/*
    Created by Dustin Yost on 4/30/2016.
*/

#ifndef INVENTORY_FILELOG_H
#define INVENTORY_FILELOG_H

#include "../LinkedList.h"
#include "Log.h"

const string FILE_DATA_LOGS = "logs.dat";

void loadLogs(LinkedList<Log> *list);
void saveLogs(LinkedList<Log> *list);

#endif //INVENTORY_FILELOG_H
