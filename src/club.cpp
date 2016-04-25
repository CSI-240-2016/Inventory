#include "club.h"

/* Pre: None
* Post: Initiate mClubName and give them empty value
* Purpose: Initiate mClubName
*********************************************************/
Club::Club()
{
	mClubName = "";
}

/* Pre: Passing a name
* Post: mClubName = name given
* Purpose: Initiation mClubName with a given value
*********************************************************/
Club::Club(string name)
{
	mClubName = name;
}

/* Pre: None
* Post: Name is set to SGA
* Purpose: Set club name to SGA once deleted
*********************************************************/
Club::~Club()
{
	setName("sga");
}

/* Pre: None
* Post: Return name of club
* Purpose: Get the name of the club
*********************************************************/
string Club::getName()
{
	return mClubName;
}

/* Pre: String name of club
* Post: Set the name of the club with the given value
* Purpose: Set the name of the club according to the value given
*********************************************************/
void Club::setName(string name)
{
	mClubName = name;
}
