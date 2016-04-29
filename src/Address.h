#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Address {

	private:
		int mNumberStreet, mNumberApartment;
		string mStreet, mCity, mState, mCountry, mZipCode;
	
	public:
		// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		Address();
		/*
		Pre: None
		Post: An address object is created
		Purpose: To create address objects
		*/
	
		// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		int 	getNumberStreet();
		/*
		Pre: None
		Post: An int value is returned
		Purpose: To retrieve the value of a specific variable
		*/

		string 	getStreet();
		/*
		Pre: None
		Post: A string value is returned
		Purpose: To retrieve the value of a specific variable
		*/

		int 	getNumberApartment();
		/*
		Pre: None
		Post: An int value is returned
		Purpose: To retrieve the value of a specific variable
		*/

		string 	getCity();
		/*
		Pre: None
		Post: A string value is returned
		Purpose: To retrieve the value of a specific variable
		*/

		string 	getState();
		/*
		Pre: None
		Post: A string value is returned
		Purpose: To retrieve the value of a specific variable
		*/

		string 	getCountry();
		/*
		Pre: None
		Post: A string value is returned
		Purpose: To retrieve the value of a specific variable
		*/

		string 	getZipCode();
		/*
		Pre: None
		Post: A string value is returned
		Purpose: To retrieve the value of a specific variable
		*/
	
		// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		void 	setNumberStreet(int);
		/*
		Pre: An int variable
		Post: The value of a specific variable is changed to the value of the parameter
		Purpose: To update the information of a specific variable
		*/

		void 	setStreet(string);
		/*
		Pre: A string variable
		Post: The value of a specific variable is changed to the value of the parameter
		Purpose: To update the information of a specific variable
		*/

		void 	setNumberApartment(int);
		/*
		Pre: An int variable
		Post: The value of a specific variable is changed to the value of the parameter
		Purpose: To update the information of a specific variable
		*/

		void 	setCity(string);
		/*
		Pre: A string variable
		Post: The value of a specific variable is changed to the value of the parameter
		Purpose: To update the information of a specific variable
		*/

		void 	setState(string);
		/*
		Pre: A string variable
		Post: The value of a specific variable is changed to the value of the parameter
		Purpose: To update the information of a specific variable
		*/

		void 	setCountry(string);
		/*
		Pre: A string variable
		Post: The value of a specific variable is changed to the value of the parameter
		Purpose: To update the information of a specific variable
		*/

		void 	setZipCode(string);
		/*
		Pre: A string variable
		Post: The value of a specific variable is changed to the value of the parameter
		Purpose: To update the information of a specific variable
		*/

		// ~~~~~ Overloaded Operators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		Address& operator=(const Address& addressTwo);
		/** PURPOSE: OVERLOAD Loads variables from a file stream
		 */

		friend ifstream& operator>>(ifstream& stream, Address& obj);
		/*
		Pre: The file stream and class instances
		Post: Information is loaded from the stream to variables
		Purpose: To read information to the variables
		*/

		friend ofstream& operator<<(ofstream& stream, Address& obj);
		/*
		Pre: The file stream and class instances
		Post: Information of variables is written to the stream
		Purpose: To read information to the stream
		*/
};

#endif
