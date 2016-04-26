#include <string>
#include <iostream>
#include <fstream>
#include "sellersDat.h"
#include "Item.h"
using namespace std;

void itemsInput() {
	int serialNumber;
	string name, type, club, sellerName, price, building, room, shelfSlot;
	Item items;
	bool status;
	const string fileName = "items.dat";
	fstream fin;
	fin.open(fileName);
	if (fin.is_open()) {
		while (fin.eof()) {
			fin >> serialNumber;
			items.setSerial(serialNumber);
			getline(fin, name);
			items.setName(name);
			getline(fin, type);
			items.setNameType(type);
			getline(fin, club);
			items.setNameOwner(club);
			fin >> status;
			if (status == true)
				items.checkIn();
			else
				items.checkOut();
			getline(fin, building);
			items.getLocation.setBuilding(building);
			getline(fin, room);
			items.getLocation.setRoom(room);
			getline(fin, shelfSlot);
			items.getLocation.setCode(shelfSlot);
			getline(fin, sellerName);
			items.getSource.getSeller.setName(sellerName);
			getline(fin, price);
			items.getSource.setUnitPrice(price);
		}
	}
	fin.close();
}

void itemsOutput(int serialNumber,string name, string type, string club, string sellerName, string price, string building, string room, string shelfSlot, bool status) {
	const string fileName = "items.dat";
	ofstream fout;
	fout.open(fileName, std::ios_base::app);
	fout << serialNumber << "\n";
	fout << name << "\n";
	fout << type << "\n";
	fout << club << "\n";
	fout << status << "\n";
	fout << building << "\n";
	fout << room << "\n";
	fout << shelfSlot << "\n";
	fout << sellerName << "\n";
	fout << price << "\n";
	fout.close();
}