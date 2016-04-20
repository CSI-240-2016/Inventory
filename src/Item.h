
#ifndef ITEM_H
#define ITEM_H

#include "Source.h"

using namespace std;

class Item {

	private:
		int mSerialNumber;
		string mName, mType, mOwner;
		Source mSource;
		Location mLocation;
		bool mIsIn;
	
	public:
		// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		Item(int, string);
		
		// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		int 		getSerial();
		string 		getName();
		string 		getNameType();
		string 		getNameOwner();
		Source 		getSource();
		Location 	getLocation();
		bool 		canBeCheckedOut();
		bool 		isCheckedIn();
		
		// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		void 	setSerial(int);
		void 	setName(string);
		void 	setNameType(string);
		void 	setNameOwner(string);
		void 	setSource(Source);
		void 	setLocation(Location);
		bool 	checkOut();
		bool 	checkIn();
	
};

#endif