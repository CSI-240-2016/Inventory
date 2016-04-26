#include <string>
#include <fstream>
#include "clubsDat.h"
#include "club.h"
using namespace std;

void clubsInput() {
	string name;
	Club club;
	const string fileName = "clubs.dat";
	fstream fin;
	fin.open(fileName);
	if (fin.is_open()) {
		while (fin.eof()) {
			getline(fin, name);
			club.setName(name);
		}
	}
	fin.close();
}

void clubsOutput(string name) {
	const string fileName = "clubs.dat";
	ofstream fout;
	fout.open(fileName, std::ios_base::app);
	fout << name << "\n";
	fout.close();
}