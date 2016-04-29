
#ifndef ITEM_H
#define ITEM_H

#include "Source.h"
#include "Location.h"
#include <iostream>

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
		Item();
		/*
		Pre: None
		Post: An item object with default values is created
		Purpose: To create an item object with default values
		*/

		Item(int, string);
		/*
		Pre: An int variable and a string variable
		Post: An item object with specified values is created
		Purpose: To create an item object with specific values
		*/
		
		// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		int 		getSerial();
		/*
		Pre: None
		Post: An int value is returned
		Purpose: To retrieve the value of a specific variable
		*/

		string 		getName();
		/*
		Pre: None
		Post: A string value is returned
		Purpose: To retrieve the value of a specific variable
		*/

		string 		getNameType();
		/*
		Pre: None
		Post: A string value is returned
		Purpose: To retrieve the value of a specific variable
		*/

		string 		getNameOwner();
		/*
		Pre: None
		Post: A string value is returned
		Purpose: To retrieve the value of a specific variable
		*/

		Source 		getSource();
		/*
		Pre: None
		Post: A source value is returned
		Purpose: To retrieve the value of a specific variable
		*/

		Location 	getLocation();
		/*
		Pre: None
		Post: A location value is returned
		Purpose: To retrieve the value of a specific variable
		*/

		bool 		isCheckedIn();
		/*
		Pre: None
		Post: A bool value is returned
		Purpose: To retrieve the value of a specific variable
		*/
		
		// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		void 	setSerial(int);
		/*
		Pre: An int variable
		Post: The value of a specific variable is changed to the value of the parameter
		Purpose: To update the information of a specific variable
		*/

		void 	setName(string);
		/*
		Pre: A string variable
		Post: The value of a specific variable is changed to the value of the parameter
		Purpose: To update the information of a specific variable
		*/

		void 	setNameType(string);
		/*
		Pre: A string variable
		Post: The value of a specific variable is changed to the value of the parameter
		Purpose: To update the information of a specific variable
		*/

		void 	setNameOwner(string);
		/*
		Pre: A string variable
		Post: The value of a specific variable is changed to the value of the parameter
		Purpose: To update the information of a specific variable
		*/

		void 	setSource(Source);
		/*
		Pre: A source variable
		Post: The value of a specific variable is changed to the value of the parameter
		Purpose: To update the information of a specific variable
		*/

		void 	setLocation(Location);
		/*
		Pre: A location variable
		Post: The value of a specific variable is changed to the value of the parameter
		Purpose: To update the information of a specific variable
		*/

		void	setStatus(bool);
		/*
		Pre: A bool variable
		Post: The value of a specific variable is changed to the value of the parameter
		Purpose: To update the information of a specific variable
		*/

		bool 	checkOut();
		/*
		Pre: None
		Post: A bool value is returned
		Purpose: To update the information of a specific variable
		*/

		bool 	checkIn();
		/*
		Pre: None
		Post: A bool value is returned
		Purpose: To update the information of a specific variable
		*/
		
		// ~~~~~~~~~~ Operators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		
		/** PURPOSE: OVERLOAD Outputs variables to file stream
		 */
		friend ofstream& operator<<(ofstream& stream, Item& obj);
		/** PURPOSE: OVERLOAD Outputs variables to console stream
		 */
		friend  ostream& operator<<( ostream& stream, Item& obj);
};

#endif