/*
    Created by Dustin Yost on 4/30/2016.
*/

#ifndef INVENTORY_LOCATION_H
#define INVENTORY_LOCATION_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Location {

	private:
		string mBuilding, mRoom, mCode;

	public:
		// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/* PURPOSE: Create a Location object with default values
		 * PRE:  None
		 * POST: A Location object with default values
		*/
		Location();

		/* PURPOSE: Create an item object with specific values
		 * PRE:  The building (String), The room (String), The code (String)
		 * POST: An item object with specified values
		*/
		Location(string building, string room, string code);

		// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/* PURPOSE: Retrieve the building
		 * PRE:  None
		 * POST: The building (String)
		*/
		string	getBuilding();

		/* PURPOSE: Retrieve the room
		 * PRE:  None
		 * POST: The room (String)
		*/
		string	getRoom();

		/* PURPOSE: Retrieve the code
		 * PRE:  None
		 * POST: The code (String)
		*/
		string	getCode();

		// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/* PURPOSE: Update the building
		 * PRE:  The building (String)
		 * POST: The value is changed to the parameter
		*/
		void	setBuilding(string);

		/* PURPOSE: Update the room
		 * PRE:  The room (String)
		 * POST: The value is changed to the parameter
		*/
		void	setRoom(string);

		/* PURPOSE: Update the code
		 * PRE:  The code (String)
		 * POST: The value is changed to the parameter
		*/
		void	setCode(string);

		// ~~~~~~~~~~ Operators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/* PURPOSE: Determine if this Location is equal to another Location
		 * PRE:  The other Location (Location)
		 * POST: true, if the all the buildings, rooms, and codes match
		*/
		bool	operator==(Location);

		/** PURPOSE: OVERLOAD Inputs variables from the file stream to object
		 * PRE:  The file stream (fstream), The location (Location)
		 * POST: Reads data from the file stream
		 */
		friend ifstream& operator>>(ifstream& stream, Location& obj);

		/** PURPOSE: OVERLOAD Inputs variables from the file stream to object
		 * PRE:  The stream (istream), The obj (Location)
		 * POST: Reads data from the stream
		 */
		friend  istream& operator>>(istream& stream, Location& obj);

		/** PURPOSE: OVERLOAD Outputs variables from object to the file stream
		 * PRE:  The file stream (fstream), The obj (Location)
		 * POST: Reads data from the file stream
		 */
		friend ofstream& operator<<(ofstream& stream, const Location obj);

};

#endif //INVENTORY_LOCATION_H
