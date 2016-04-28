
#ifndef EXPORTEXCEL_H
#define EXPORTEXCEL_H

#include "club.h"
#include "Item.h"
#include "Log.h"

using namespace std;

//const string ALL_DATA = "SGA_Data.csv";
//const string CLUB_DATA = "SGA_Clubs.csv";
//const string ITEMS_DATA = "SGA_Items.csv";
//const string LOGS_DATA = "SGA_Logs.csv";

void exportAll();
void exportClubs();
void exportItems();
void exportLogs();
void exportSellers();
string getFileName();

#endif