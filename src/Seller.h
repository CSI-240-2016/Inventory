#ifndef SELLER_H
#define SELLER_H

#include <string>
#include "Address.h"

class Seller
{
	private:
		std::string mName, mURL;
		Address mAddress;
	
	
	public:	
		//Constuctors
		Seller();
		Seller(std::string name, std::string URL, Address address);
		~Seller();
	
		//Accessors
		Address& getAddress();
		std::string getName();
		std::string getURL();
	
		//Mutators
		void setSeller(std::string name, std::string URL, Address address);
		void setAddress(Address address);
		void setName(std::string name);
		void setURL(std::string URL);
	
		//Overloaded Operators
		Seller& operator=(const Seller&);
		bool operator==(string);
		/** PURPOSE: OVERLOAD Loads variables from a file stream
		 */
		friend ifstream& operator>>(ifstream& stream, Seller& obj);
		
		
};

#endif
