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
