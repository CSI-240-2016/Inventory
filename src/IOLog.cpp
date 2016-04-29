
#include "IOLog.h"
#include <string>
#include <fstream>
#include <iostream>

void loadLogs(LinkedList<Log> *list) {
	ifstream stream;
	stream.open("logs.dat", ios::in);
	
	int nameSerial;
	string nameItem;
	Date dateOut, dateInExpected, dateIn;
	string	nameClub,
			nameOutBy_username, nameOutBy, nameOutTo,
			nameInBy_username, nameInBy, nameInFrom;
	
	if (stream.is_open()) {
		Log element;
		while (stream >> nameSerial) {
			
			getline(stream, nameItem);
			
			dateOut = Date();
			dateInExpected = Date();
			dateIn = Date();
			stream
				>> dateOut
				>> dateInExpected
				>> dateIn
			;
			getline(stream, nameClub); // clear the line
			
			getline(stream, nameClub);
			
			stream >> nameOutBy_username;
			getline(stream, nameOutBy);
			getline(stream, nameOutTo);
			
			stream >> nameInBy_username;
			getline(stream, nameInBy);
			getline(stream, nameInFrom);
			
			element = Log(	nameSerial, nameItem,
							dateOut, dateInExpected, dateIn,
							nameClub,
							nameOutBy_username, nameOutBy, nameOutTo,
							nameInBy_username, nameInBy, nameInFrom);
			list->append(element);
		}
	}
	
	stream.close();
}

void saveLogs(LinkedList<Log> *list) {
	ofstream file;
	file.open("logs.dat", ios::out);
	
	Node<Log> *tmpNode = list->mHead;

	if (file.is_open()) {
		while (tmpNode != NULL) {
			file << tmpNode->mData;
			tmpNode = tmpNode->mNext;
			if (tmpNode != NULL) file << "\n";
		}
	}
	file.close();
}

void printLogs(LinkedList<Log> *list) {
	Node<Log> *tmpNode = list->mHead;
	while (tmpNode != NULL) {
		cout << tmpNode->mData << "\n";
		tmpNode = tmpNode->mNext;
	}
}
