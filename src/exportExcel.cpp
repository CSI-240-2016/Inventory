
#include "exportExcel.h"
#include ""

void exportAll()
{
	string fileName = getFileName();


}

void exportClubs()
{

}

void exportItems()
{

}

void exportLogs()
{

}

void exportSellers()
{

}

string getFileName()
{
	string fileName;

	cout << "Enter a name for the file to be exported (without extension): ";
	cin >> fileName;

	fileName += ".csv";

	return fileName;
}