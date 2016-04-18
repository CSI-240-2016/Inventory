#ifndef CLUB_H
#define CLUB_H

#include <iostream>
#include <string>

using namespace std;

class Club
{
	string mClubName; // Name of the club

public:

	Club(); // Deefault constructor
	Club(string name); // Constructor
	~Club(); // Destructor, change name to SGA
	string getName(); //Accessor
	void setName(string name); //Mutator

};


#endif

