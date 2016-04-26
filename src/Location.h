
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
		Location();
		Location(string building, string room, string code);
		
		// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		string getBuilding();
		string getRoom();
		string getCode();
		
		// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		void setBuilding(string);
		void setRoom(string);
		void setCode(string);

};

#endif