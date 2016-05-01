/*
    Created by Dustin Yost on 4/30/2016.
*/

#ifndef INVENTORY_ADDRESS_H
#define INVENTORY_ADDRESS_H

#include <string>
#include <fstream>

using namespace std;

class Address {

	private:
		int mNumberStreet, mNumberApartment;
		string mZipCode, mStreet, mCity, mState, mCountry;

	public:
		// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/* PURPOSE: Create an Address object with default values
		 * PRE:  None
		 * POST: An Address object with default values
		*/
		Address();

		// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/* PURPOSE: Retrieve the street number
		 * PRE:  None
		 * POST: The street number (Integer)
		*/
		int		getStreetNumber();

		/* PURPOSE: Retrieve the apartment number
		 * PRE:  None
		 * POST: The apartment number (Integer)
		*/
		int		getApartmentNumber();

		/* PURPOSE: Retrieve the zip code
		 * PRE:  None
		 * POST: The zip code (String)
		*/
		string	getZipCode();

		/* PURPOSE: Retrieve the street
		 * PRE:  None
		 * POST: The street (String)
		*/
		string	getStreet();

		/* PURPOSE: Retrieve the city
		 * PRE:  None
		 * POST: The city (String)
		*/
		string	getCity();

		/* PURPOSE: Retrieve the state
		 * PRE:  None
		 * POST: The state (String)
		*/
		string	getState();

		/* PURPOSE: Retrieve the country
		 * PRE:  None
		 * POST: The country (String)
		*/
		string	getCountry();

		// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/* PURPOSE: Update the street number
		 * PRE:  The street number (Integer)
		 * POST: The value is changed to the parameter
		*/
		void	setStreetNumber(int);

		/* PURPOSE: Update the apartment number
		 * PRE:  The apartment number (Integer)
		 * POST: The value is changed to the parameter
		*/
		void	setApartmentNumber(int);

		/* PURPOSE: Update the zip code
		 * PRE:  The zip code (String)
		 * POST: The value is changed to the parameter
		*/
		void	setZipCode(string);

		/* PURPOSE: Update the street
		 * PRE:  The street (String)
		 * POST: The value is changed to the parameter
		*/
		void	setStreet(string);

		/* PURPOSE: Update city
		 * PRE:  The city (String)
		 * POST: The value is changed to the parameter
		*/
		void	setCity(string);

		/* PURPOSE: Update the state
		 * PRE:  The state (String)
		 * POST: The value is changed to the parameter
		*/
		void	setState(string);

		/* PURPOSE: Update the country
		 * PRE:  The country (String)
		 * POST: The value is changed to the parameter
		*/
		void	setCountry(string);

		// ~~~~~~~~~~ Operators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/** PURPOSE: OVERLOAD Inputs variables from the file stream to object
		 * PRE:  The file stream (fstream), The address (Address)
		 * POST: Reads data from the file stream
		 */
		friend ifstream& operator>>(ifstream& stream, Address& obj);

		/** PURPOSE: OVERLOAD Outputs variables from object to the file stream
		 * PRE:  The file stream (fstream), The obj (Address)
		 * POST: Reads data from the file stream
		 */
		friend ofstream& operator<<(ofstream& stream, const Address obj);

};

#endif //INVENTORY_ADDRESS_H
