
#ifndef ITEM_H
#define ITEM_H

#include "Source.h"

using namespace std;

class Item {

	private:
		int mSerialNumber;
		String mName, mType, mOwner;
		Source mSource;
		Location mLocation;
		bool mIsIn;
	
	public:
		// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		Item(int, String);
		
		// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		int 		getSerial();
		String 		getName();
		String 		getNameType();
		String 		getNameOwner();
		Source 		getSource();
		Location 	getLocation();
		bool 		canBeCheckedOut();
		bool 		isCheckedIn();
		
		// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		void 	setSerial(int);
		void 	setName(String);
		void 	setNameType(String);
		void 	setNameOwner(String);
		void 	setSource(Source);
		void 	setLocation(Location);
		bool 	checkOut();
		bool 	checkIn();
	
};

#endif