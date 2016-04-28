#include <string>
#include <iostream>
#include <fstream>
#include "sellersDat.h"
using namespace std;

void sellerInput(LinkedList<Seller> list) 
{
	string name, url, street, city, state, country, stNumber, aptNumber, zipcode;
	const string fileName = "sellers.dat";
	fstream fin;
	Seller seller;
	fin.open(fileName);
	if (fin.is_open()) {
		do {
			//while open will loop and pull in the information in the fileformat
			getline(fin, name);
			list.append(Seller(name));
			fin >> url;
			list.append(Seller(url));
			fin >> stNumber;
			//Same with location in the items not sure how to accesss adress
			seller.getAddress().setNumberStreet(stNumber);
			fin >> aptNumber;
			seller.getAddress().setNumberApartment(aptNumber);
			fin >> zipcode;
			seller.getAddress().setZipCode(zipcode);
			getline(fin, street);
			seller.getAddress().setStreet(street);
			getline(fin, city);
			seller.getAddress().setCity(city);
			getline(fin, state);
			seller.getAddress().setState(state);
			getline(fin, country);
			seller.getAddress().setCountry(country);
		} while (fin.eof());
	}
	fin.close();
}

void sellerOutput(string name, string url, string street, string city, string state, string country, string stNumber, string aptNumber, string zipcode) {
	const string fileName = "sellers.dat";
	ofstream fout;
	fout.open(fileName, std::ios_base::app);
	fout << name << "\n";
	fout << url << "\n";
	fout << stNumber << " " << aptNumber << " " << zipcode << "\n";
	fout << street << "\n";
	fout << city << "\n";
	fout << state << "\n";
	fout << country << "\n";
	fout.close();
}