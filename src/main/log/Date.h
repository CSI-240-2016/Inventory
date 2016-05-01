/*
    Created by Dustin Yost on 4/30/2016.
*/

#ifndef INVENTORY_DATE_H
#define INVENTORY_DATE_H

#include <string>
#include <fstream>

using namespace std;

class Date {

	private:
		int mMonth, mDay, mYear;

	public:
		// ~~~~~ ...Structors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/* PURPOSE: Create a Date object with default values
		 * PRE:  None
		 * POST: A Date object with default values
		*/
		Date();

		/* PURPOSE: Create an Date object with specific values
		 * PRE:  The month (Integer), The day (Integer), The year (Integer)
		 * POST: An Date object with specified values
		*/
		Date(int month, int day, int year);

		// ~~~~~ Accessors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/* PURPOSE: Retrieve the month
		 * PRE:  None
		 * POST: The month (Integer)
		*/
		int		getMonth();

		/* PURPOSE: Retrieve the month as a string
		 * PRE:  None
		 * POST: The month as an Integer in a String
		*/
		string	getMonthString();

		/* PURPOSE: Retrieve the day
		 * PRE:  None
		 * POST: The day (Integer)
		*/
		int		getDay();

		/* PURPOSE: Retrieve the day as a string
		 * PRE:  None
		 * POST: The day as an Integer in a String
		*/
		string	getDayString();

		/* PURPOSE: Retrieve the year
		 * PRE:  None
		 * POST: The year (Integer)
		*/
		int		getYear();

		/* PURPOSE: Retrieve the year as a string
		 * PRE:  None
		 * POST: The year as an Integer in a String
		*/
		string	getYearString();

		// ~~~~~ Mutators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/* PURPOSE: Update the month
		 * PRE:  The month (Integer)
		 * POST: The value is changed to the parameter
		*/
		void	setMonth(int);

		/* PURPOSE: Update the day
		 * PRE:  The day (Integer)
		 * POST: The value is changed to the parameter
		*/
		void	setDay(int);

		/* PURPOSE: Update the year
		 * PRE:  The year (Integer)
		 * POST: The value is changed to the parameter
		*/
		void	setYear(int);

		// ~~~~~ Utility ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		string	toString(string format);

		// ~~~~~~~~~~ Operators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/** PURPOSE: OVERLOAD Inputs variables from the file stream to object
		 * PRE:  The file stream (fstream), The obj (Date)
		 * POST: Reads data from the file stream
		 */
		friend ifstream& operator>>(ifstream& stream, Date& obj);

		/** PURPOSE: OVERLOAD Outputs variables from object to the file stream
		 * PRE:  The file stream (fstream), The obj (Date)
		 * POST: Reads data from the file stream
		 */
		friend ofstream& operator<<(ofstream& stream, const Date obj);

};

#endif //INVENTORY_DATE_H
