/*
    Created by Dustin Yost on 4/30/2016.
*/

#ifndef INVENTORY_ITEM_H
#define INVENTORY_ITEM_H

#include <string>
#include <fstream>
#include <iostream>
#include "Location.h"
#include "Source.h"

const int		MENU_CHANGE_ITEM_SIZE = 6;
const string	MENU_CHANGE_ITEM[] = {
	"Serial", "Name", "Description", "Club", "Location", "Source"
};

class Item {

	private:
		int mSerial;
		string mName, mDescription, mClubName;
		Location mLocation;
		Source mSource;

	public:
		// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/* PURPOSE: Create an Item object with default values
		 * PRE:  None
		 * POST: An Item object with default values
		*/
		Item();

		/* PURPOSE: Create an item object with specific values
		 * PRE:  The serial number (Integer)
		 * POST: An item object with specified values
		*/
		Item(int);

		// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/* PURPOSE: Retrieve the serial number
		 * PRE:  None
		 * POST: The serial number (Integer)
		*/
		int		getSerial();

		/* PURPOSE: Retrieve the name
		 * PRE:  None
		 * POST: The name (String)
		*/
		string	getName();

		/* PURPOSE: Retrieve the type
		 * PRE:  None
		 * POST: The type (String)
		*/
		string	getDescription();

		/* PURPOSE: Retrieve the club name
		 * PRE:  None
		 * POST: The club name (String)
		*/
		string	getClubName();

		/* PURPOSE: Retrieve the location
		 * PRE:  None
		 * POST: The location (Location)
		*/
		Location	getLocation();

		/* PURPOSE: Retrive the source
		 *PRE: None
		 *POST: The source (Source)
		*/
		Source		getSource();

		// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/* PURPOSE: Update the serial number
		 * PRE:  The serial number (Integer)
		 * POST: The value is changed to the parameter
		*/
		void	setSerial(int);

		/* PURPOSE: Update the name
		 * PRE:  The name (String)
		 * POST: The value is changed to the parameter
		*/
		void	setName(string);

		/* PURPOSE: Update the type
		 * PRE:  The type (String)
		 * POST: The value is changed to the parameter
		*/
		void	setDescription(string);

		/* PURPOSE: Update the club name
		 * PRE:  The club name (String)
		 * POST: The value is changed to the parameter
		*/
		void	setClubName(string);

		/* PURPOSE: Update the location
		 * PRE:  The location (Location)
		 * POST: The value is changed to the parameter
		*/
		void	setLocation(Location);
		
		/* PURPOSE: Update the source info
		 * PRE:	 The source (Source)
		 * POST: The value is changed to the parameter
		*/
		void	setSource(Source);

		// ~~~~~~~~~~ Operators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/* PURPOSE: OVERLOAD Determine if this item is equal to another item
		 * PRE:  The other item (Item)
		 * POST: true, if the two serials' are the same
		*/
		bool	operator==(Item);

		/* PURPOSE: Tries to read the serial from the file stream
		 * PRE:  The file stream
		 * POST: if the serial could be read
		 */
		bool	readSerial(ifstream&);

		/** PURPOSE: OVERLOAD Inputs variables from the file stream to object
		 * PRE:  The file stream (fstream), The item (Item)
		 * 		 Item.readSerial MUST be called prior
		 * POST: Reads data from the file stream
		 */
		friend ifstream& operator>>(ifstream& stream, Item& obj);

		/** PURPOSE: OVERLOAD Inputs variables from the stream to object
		 * PRE:  The stream (istream), The obj (Item)
		 * POST: Reads data from the stream
		 */
		friend  istream& operator>>( istream& stream, Item& obj);

		/** PURPOSE: OVERLOAD Outputs variables from object to the file stream
		 * PRE:  The file stream (fstream), The obj (Item)
		 * POST: Reads data from the file stream
		 */
		friend ofstream& operator<<(ofstream& stream, Item& obj);

		/** PURPOSE: OVERLOAD Outputs variables from object to the console
		 * PRE:  The stream (ostream), The obj (Item)
		 * POST: Reads data from the stream
		 */
		friend  ostream& operator<<( ostream& stream, Item& obj);

};

#endif //INVENTORY_ITEM_H
