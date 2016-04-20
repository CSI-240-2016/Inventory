//Not Stable
#include <string>

class Seller
{
	private: 
		std::string mName, mURL;
		Address mAddress;

	public:
		//Accessors
		Address getAddress();
		std::string getName();
		std::string getURL();

		//Constructors
		Seller();
		Seller(std::string name, std::string URL, Address address);
		~Seller();

		//Mutators
		void setAddress(Address address);
		void setName(string name);
		void setURL(string URL);

};