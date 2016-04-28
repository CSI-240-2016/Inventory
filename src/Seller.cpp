#include "Seller.h"

using namespace std;

/* Pre: None
* Post: Seller object created. Default values are set to "";
* Purpose: To create Seller object
*********************************************************/
Seller::Seller()
{
	mName = "";
	mURL = "";
}


/* Pre: None
* Post: Seller object created. Default values are set to given values;
* Purpose: To create Seller object
*********************************************************/
Seller::Seller(string name, string URL, Address address)
{
	mName = name;
	mURL = URL;
	mAddress = address;
}


/* Pre: None
* Post: Seller Object deconstructed
* Purpose: To deconstruct seller object
*********************************************************/
Seller::~Seller()
{

}


/* Pre: None
* Post: Date object created. Default date is January 1st 2000
* Purpose: To create Date object
*********************************************************/
Address& Seller::getAddress()
{
	return mAddress;
}


/* Pre: None
* Post: Returns name
* Purpose: To gain access to a Seller's mName value
*********************************************************/
string Seller::getName()
{
	return mName;
}


/* Pre: None
* Post: Returns URL
* Purpose: To gain access to a Seller's mURL value
*********************************************************/
string Seller::getURL()
{
	return mURL;
}


/* Pre: None
* Post: mAddress set to given value
* Purpose: To set mAddress to a value
*********************************************************/
void  Seller::setAddress(Address address)
{
	mAddress = address;
}


/* Pre: None
* Post: mName set to given value
* Purpose: To set mName to a value
*********************************************************/
void  Seller::setName(string name)
{
	mName = name;
}

void Seller::setSeller(string name, string URL, Address address)
{
	mName = name;
	mAddress = address;
	mURL = URL;
}

/* Pre: None
* Post: mURL set to given value
* Purpose: To set mURL to a value
*********************************************************/
void  Seller::setURL(string URL)
{
	mURL = URL;
}

/* Pre: None
* Post: Sets seller equal to another
* Purpose: To easily set seller values equal to one another
*********************************************************/
Seller& Seller::operator=(const Seller& sellerTwo)
{
	this->mAddress = sellerTwo.mAddress;
	this->mName = sellerTwo.mName;
	this->mURL = sellerTwo.mURL;
	return *this;
}

/* Pre: Name of seller two
* Post: Check if seller name is equal to seller name two
* Purpose: Compare seller name to another
*********************************************************/

bool Seller::operator==(string sellerTwo)
{
	return mName == sellerTwo;

}

/** Purpose: OVERLOAD Loads variables from a file stream
 * PRE:  the file stream, the class instance
 * POST: loads variables from stream, returns the stream
 */
ifstream& operator>>(ifstream& stream, Seller& obj) {
	getline(stream, obj.mName);
	getline(stream, obj.mURL);
	stream >> obj.mAddress;
	return stream;
}
