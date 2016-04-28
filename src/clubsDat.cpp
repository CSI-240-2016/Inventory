
#include "clubsDat.h"

using namespace std;

void clubsInput(LinkedList<Club> list) {
	string name;
	const string fileName = "clubs.dat";
	fstream fin;
	fin.open(fileName, ios::in);
	if (fin.is_open()) {
		while (getline(fin, name)) {
			list.append(Club(name));
		}
		while (!fin.eof());
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