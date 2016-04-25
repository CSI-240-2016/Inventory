#ifndef SOURCE_H
#define SOURCE_H

#include <string>
#include "Seller.h"

class Source
{
private:
	double mUnitPrice;
	Seller mSeller;
public:
	//Constuctors
	Source();
	Source(double unitPrice, Seller seller);
	~Source();

	//Accessors
	double getUnitPrice();
	Seller& getSeller();

	//Mutators
	void setUnitPrice(double unitPrice);
	void setSeller(Seller seller);

};

#endif