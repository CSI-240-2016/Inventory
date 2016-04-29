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
		Club(string name); // Constructor
		~Club(); // Destructor, change name to SGA
		string getName(); //Accessor
		void setName(string name); //Mutator
		
		/** PURPOSE: OVERLOAD Outputs variables to file stream
		 */
		friend ofstream& operator<<(ofstream& stream, Club& obj);

};


#endif

