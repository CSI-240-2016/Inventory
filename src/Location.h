
#ifndef LOCATION_H
#define LOCATION_H

#include <string>

using namespace std;

class Location {

	private:
		string mBuilding;
		string mRoom, mCode;
	
	public:
		// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		Location(string building, string room, string code);
		
		// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		string getBuilding();
		string getRoom();
		string setCode();

};

#endif