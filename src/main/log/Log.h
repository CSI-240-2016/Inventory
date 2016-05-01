/*
    Created by Dustin Yost on 4/30/2016.
*/

#ifndef INVENTORY_LOG_H
#define INVENTORY_LOG_H

#include <string>
#include "Date.h"
#include <fstream>
#include <iostream>

using namespace std;

class Log {

	private:
		int mItemSerial;
		string mItemName, mClubName;
		Date mDateOut, mDateInExpected, mDateIn;
		string	mOutBy_Name, mOutBy_Username, mOutTo_Name,
				mInBy_Name, mInBy_Username, mInFrom_Name;

	public:
		// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/* PURPOSE: Create a Log object with default values
		 * PRE:  None
		 * POST: A Log object with default values
		*/
		Log();

		// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/* PURPOSE: Retrieve the item serial
		 * PRE:  None
		 * POST: The item serial (Integer)
		*/
		int		getSerial();

		/* PURPOSE: Retrieve the name
		 * PRE:  None
		 * POST: The name (String)
		*/
		string	getName();

		/* PURPOSE: Retrieve the club name
		 * PRE:  None
		 * POST: The club name (String)
		*/
		string	getClubName();

		/* PURPOSE: Retrieve the date out
		 * PRE:  None
		 * POST: The date out (Date)
		*/
		Date	getDateOut();

		/* PURPOSE: Retrieve the expected date in
		 * PRE:  None
		 * POST: The expected date in (Date)
		*/
		Date	getDateInExpected();

		/* PURPOSE: Retrieve the date in
		 * PRE:  None
		 * POST: The date in (Date)
		*/
		Date	getDateIn();

		/* PURPOSE: Retrieve the name of who the item was checked out by
		 * PRE:  None
		 * POST: The name of who the item was checked out by (String)
		*/
		string	getOutByName();

		/* PURPOSE: Retrieve the username of who the item was checked out by
		 * PRE:  None
		 * POST: The username of who the item was checked out by (String)
		*/
		string	getOutByUsername();

		/* PURPOSE: Retrieve the name of who the item was checked out to
		 * PRE:  None
		 * POST: The name of who the item was checked out to (String)
		*/
		string	getOutToName();

		/* PURPOSE: Retrieve the name of who the item was checked in by
		 * PRE:  None
		 * POST: The name of who the item was checked in by (String)
		*/
		string	getInByName();

		/* PURPOSE: Retrieve the username of who the item was checked in by
		 * PRE:  None
		 * POST: The username of who the item was checked in by (String)
		*/
		string	getInByUsername();

		/* PURPOSE: Retrieve the name of who the item was checked in from
		 * PRE:  None
		 * POST: The name of who the item was checked in from (String)
		*/
		string	getInFromName();

		// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/* PURPOSE: Update the item serial
		 * PRE:  The item serial (Integer)
		 * POST: The value is changed to the parameter
		*/
		void	setSerial(int);

		/* PURPOSE: Update the name
		 * PRE:  The name (String)
		 * POST: The value is changed to the parameter
		*/
		void	setName(string);

		/* PURPOSE: Update the club name
		 * PRE:  The club name (String)
		 * POST: The value is changed to the parameter
		*/
		void	setClubName(string);

		/* PURPOSE: Update the date out
		 * PRE:  The date out (Date)
		 * POST: The value is changed to the parameter
		*/
		void	setDateOut(Date);

		/* PURPOSE: Update the expected date in
		 * PRE:  The expected date in (Date)
		 * POST: The value is changed to the parameter
		*/
		void	setDateInExpected(Date);

		/* PURPOSE: Update the date in
		 * PRE:  The date in (Date)
		 * POST: The value is changed to the parameter
		*/
		void	setDateIn(Date);

		/* PURPOSE: Update the name of who the item was checked out by
		 * PRE:  The name of who the item was checked out by (String)
		 * POST: The value is changed to the parameter
		*/
		void	setOutBy_Name(string);

		/* PURPOSE: Update the username of who the item was checked out by
		 * PRE:  The username of who the item was checked out by (String)
		 * POST: The value is changed to the parameter
		*/
		void	setOutBy_Username(string);

		/* PURPOSE: Update the name of who the item was checked out to
		 * PRE:  The name of who the item was checked out to (String)
		 * POST: The value is changed to the parameter
		*/
		void	setOutTo_Name(string);

		/* PURPOSE: Update the name of who the item was checked in by
		 * PRE:  The name of who the item was checked in by (String)
		 * POST: The value is changed to the parameter
		*/
		void	setInByName(string);

		/* PURPOSE: Update the username of who the item was checked in by
		 * PRE:  The username of who the item was checked in by (String)
		 * POST: The value is changed to the parameter
		*/
		void	setInByUsername(string);

		/* PURPOSE: Update the name of who the item was checked in from
		 * PRE:  The name of who the item was checked in from (String)
		 * POST: The value is changed to the parameter
		*/
		void	setInFromName(string);

		// ~~~~~~~~~~ Operators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/* PURPOSE: Tries to read from the file stream
		 * PRE:  The file stream
		 * POST: if the log is able to be read (the first element could be read)
		 */
		void*	readPrimary(ifstream&);

		/** PURPOSE: OVERLOAD Inputs variables from the file stream to object
		 * PRE:  The file stream (fstream), The obj (Log)
		 * 		 Log.readPrimary MUST be called prior
		 * POST: Reads data from the file stream
		 */
		friend ifstream& operator>>(ifstream& stream, Log& obj);

		/** PURPOSE: OVERLOAD Outputs variables from object to the file stream
		 * PRE:  The file stream (fstream), The obj (Log)
		 * POST: Reads data from the file stream
		 */
		friend ofstream& operator<<(ofstream& stream, const Log obj);

		/** PURPOSE: OVERLOAD Outputs variables from object to the console
		 * PRE:  The file stream (fstream), The obj (Log)
		 * POST: Reads data from the file stream
		 */
		friend  ostream& operator<<( ostream& stream, Log obj);

};

#endif //INVENTORY_LOG_H
