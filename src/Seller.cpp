//Not Stable
#include "Seller.h"

using namespace std;

Address Seller::getAddress()
{
	return mAddress;
}

string Seller::getName()
{
	return mName;
}

string Seller::getURL()
{
	return mURL;
}

Seller::Seller()
{
	mName = "";
	mURL = "";
	mAddress();
}

Seller::Seller(string name, string URL, Address address)
{
	mName = name;
	mURL = URL;
	mAddress = address;
}

Seller::~Seller()
{

}

void Seller::setAddress(Address address)
{
	mAddress = address;
}

void Seller::setName(string name)
{
	mName = name;
}

void Seller::setURL(string URL)
{
	mURL = URL;
}