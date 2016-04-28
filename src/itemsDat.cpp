#include <string>
#include <iostream>
#include <fstream>
#include "itemsDat.h"
using namespace std;

void itemsInput(LinkedList<Item> list) {
	int serialNumber;
	string name, type, club, sellerName, building, room, shelfSlot;
	double price;
	Item items;
	bool status;
	const string fileName = "items.dat";
	fstream fin;
	fin.open(fileName);
	if (fin.is_open()) {
		while (!fin.eof()) {
			fin >> serialNumber;
			list.append(Item(serialNumber));
			getline(fin, name);
			list.append(Item(name));
			getline(fin, type);
			list.append(Item(type));
			getline(fin, club);
			list.append(Item(club));
			fin >> status;
			//The bool values
			if (status == true)
				items.checkIn();
			else
				items.checkOut();
			//not sure how to access location through the items class in the linked list
			getline(fin, building);
			items.getLocation().setBuilding(building);
			getline(fin, room);
			items.getLocation().setRoom(room);
			getline(fin, shelfSlot);
			items.getLocation().setCode(shelfSlot);
			getline(fin, sellerName);
			items.getSource().getSeller().setName(sellerName);
			fin >> price;
			// paramter must be double items.getSource().setUnitPrice(price);
		}
	}
	fin.close();
}

void itemsOutput(int serialNumber,string name, string type, string club, string sellerName, double price, string building, string room, string shelfSlot, bool status) {
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