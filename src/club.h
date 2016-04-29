#ifndef CLUB_H
#define CLUB_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Club
{
	private:
		string mClubName; // Name of the club

	public:
	
		Club(); // Deefault constructor
		/*
		Pre: None
		Post: A club obejct with default values is created
		Purpose: To create a club object with default values
		*/

		Club(string name); // Constructor
		/*
		Pre: A string variable
		Post: A club object with specificied values is created
		Purpose: To create a club object with specific values
		*/

		~Club(); // Destructor, change name to SGA
		/*
		Pre: None
		Post: A club object is destroyed
		Purpose: To destroy a club object
		*/

		string getName(); //Accessor
		/*
		Pre: None
		Post: A string value is returned
		Purpose: To retrieve the value of a specific variable
		*/

		void setName(string name); //Mutator
		/*
		Pre: A string variable
		Post: The value of a specific variable is changed to the value of the parameter
		Purpose: To update the information of a specific variable
		*/
		
		friend ofstream& operator<<(ofstream& stream, Club& obj);
		/*
		Pre: The file stream and class instances
		Post: Information of variables is written to the stream
		Purpose: To read information to the stream
		*/

};


#endif

