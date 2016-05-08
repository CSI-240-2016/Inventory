/*
    Created by Dustin Yost on 4/30/2016.
*/

#ifndef INVENTORY_SOURCE_H
#define INVENTORY_SOURCE_H

#include <string>
#include "Address.h"
#include <fstream>
#include <iostream>

class Source {

	private:
		double mPriceUnit;
		string mName, mURL;
		Address mAddress;

	public:
		// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/* PURPOSE: Create an Source object with default values
		 * PRE:  None
		 * POST: An Source object with default values
		*/
		Source();

		// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/* PURPOSE: Retrieve the unit price
		 * PRE:  None
		 * POST: The unit price (Double)
		*/
		double	getUnitPrice();

		/* PURPOSE: Retrieve the name
		 * PRE:  None
		 * POST: The name (String)
		*/
		string	getName();

		/* PURPOSE: Retrieve the URL
		 * PRE:  None
		 * POST: The URL (String)
		*/
		string	getURL();

		/* PURPOSE: Retrieve the address
		 * PRE:  None
		 * POST: The address (Address)
		*/
		Address	getAddress();

		// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/* PURPOSE: Update the unit price
		 * PRE:  The unit price (Double)
		 * POST: The value is changed to the parameter
		*/
		void	setUnitPrice(double);

		/* PURPOSE: Update the name
		 * PRE:  The name (String)
		 * POST: The value is changed to the parameter
		*/
		void	setName(string);

		/* PURPOSE: Update the url
		 * PRE:  The url (String)
		 * POST: The value is changed to the parameter
		*/
		void	setURL(string);

		/* PURPOSE: Update the address
		 * PRE:  The address (Address)
		 * POST: The value is changed to the parameter
		*/
		void	setAddress(Address);

		// ~~~~~~~~~~ Operators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/** PURPOSE: OVERLOAD Inputs variables from the file stream to object
		 * PRE:  The file stream (fstream), The source (Source)
		 * POST: Reads data from the file stream
		 */
		friend ifstream& operator>>(ifstream& stream, Source& obj);

		/** PURPOSE: OVERLOAD Inputs variables from the file stream to object
		 * PRE:  The stream (istream), The obj (Source)
		 * POST: Reads data from the stream
		 */
		friend  istream& operator>>(istream& stream, Source& obj);

		/** PURPOSE: OVERLOAD Outputs variables from object to the file stream
		 * PRE:  The file stream (fstream), The obj (Source)
		 * POST: Reads data from the file stream
		 */
		friend ofstream& operator<<(ofstream& stream, const Source obj);

};

#endif //INVENTORY_SOURCE_H
