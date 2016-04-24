#include "Source.h"

/* Pre: None
* Post: Source object created.
* Purpose: To create Source object
*********************************************************/
Source::Source()
{
	mUnitPrice = 0;
}


/* Pre: None
* Post: Source object created with given values
* Purpose: To create Source object with particular values
*********************************************************/
Source::Source(double unitPrice, Seller seller)
{
	mUnitPrice = unitPrice;
	mSeller = seller;
}


/* Pre: None
* Post: Source object deconstructed.
* Purpose: To deconstruct source object
*********************************************************/
Source::~Source()
{

}


/* Pre: None
* Post: Returns mUnitPrice for a source object
* Purpose: To gain access to a source objects unit price value
*********************************************************/
double Source::getUnitPrice()
{
	return mUnitPrice;
}


/* Pre: None
* Post: Returns seller for a source object
* Purpose: To gain access to a souce objects seller value
*********************************************************/
Seller& Source::getSeller()
{
	return mSeller;
}


/* Pre: None
* Post: mUnitPrice set to given value
* Purpose: To set a Source objects price
*********************************************************/
void Source::setUnitPrice(double unitPrice)
{
	mUnitPrice = unitPrice;
}



/* Pre: None
* Post: mSeller set to given value
* Purpose: To set a source objects seller
*********************************************************/
void Source::setSeller(Seller seller)
{
	mSeller = seller;
}
