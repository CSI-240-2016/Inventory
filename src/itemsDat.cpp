
#include "itemsDat.h"

void itemsInput(LinkedList<Item> list) {
	int serialNumber;
	string name, type, club, sellerName, building, room, shelfSlot;
	double price;
	Item item;
	Seller seller;
	bool status;
	const string fileName = "items.dat";
	ifstream fin;
	fin.open(fileName, ios::in);
	if (fin.is_open()) {
		getline(fin, name); // read first line, must be empty
		while (!fin.eof()) {
			
			// Item init variables
			
			fin >> serialNumber;
			getline(fin, name);
			
			item = Item(serialNumber, name);
			
			// owning data
			
			getline(fin, type);
			getline(fin, club);
			
			item.setNameType(type);
			item.setNameOwner(club);
			
			// status
			
			fin >> status;
			getline(fin, building); // get rid of excess on this line
			
			item.setStatus(status);
			
			// location
			
			getline(fin, building);
			getline(fin, room);
			getline(fin, shelfSlot);
			
			item.setLocation(Location(building, room, shelfSlot));
			
			// source
			
			fin >> price;
			getline(fin, sellerName); // clear the rest of the line
			seller = Seller();
			fin >> seller;
			item.setSource(Source(price, seller));
			
			// append
			
			list.append(item);
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