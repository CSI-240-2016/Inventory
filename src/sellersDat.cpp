#include <string>
#include <iostream>
#include <fstream>
#include "sellersDat.h"
#include "Seller.h"
using namespace std;

void sellerInput() {
	string name, url, street, city, state, country, stNumber, aptNumber, zipcode;
	Seller seller;
	const string fileName = "sellers.dat";
	fstream fin;
	fin.open(fileName);
	if (fin.is_open()) {
		while (fin.eof()) {
			//while open will loop and pull in the information in the fileformat
			getline(fin, name);
			seller.setName(name);
			fin >> url;
			seller.setURL(url);
			fin >> stNumber;
			seller.getAddress.setNumberStreet(stNumber);
			fin >> aptNumber;
			seller.getAddress.setNumberApartment(aptNumber);
			fin >> zipcode;
			seller.getAddress.setZipCode(zipcode);
			getline(fin, street);
			seller.getAddress.setStreet(street);
			getline(fin, city);
			seller.getAddress.setCity(city);
			getline(fin, state);
			seller.getAddress.setState(state);
			getline(fin, country);
			seller.getAddress.setCountry(country);
		}
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