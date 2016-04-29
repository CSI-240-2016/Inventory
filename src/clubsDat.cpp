
#include "clubsDat.h"

using namespace std;

void clubsInput(LinkedList<Club> *list) {
	string name;
	const string fileName = "clubs.dat";
	fstream fin;
	fin.open(fileName, ios::in);
	if (fin.is_open()) {
		while (getline(fin, name)) {
			list->append(Club(name));
		}
		while (!fin.eof());
	}
	fin.close();
}

void saveClubs(LinkedList<Club> *list) {
	string fileName = "clubs.dat";
	
	ofstream file;
	file.open(fileName, ios::out);
	
	if (file.is_open()) {
		Node<Club> *tmpNode = list->mHead;
		while (tmpNode != NULL) {
			file << tmpNode->mData;
			tmpNode = tmpNode->mNext;
			if (tmpNode != NULL) file << "\n";
		}
	}
	
	file.close();
}

void printClubs(LinkedList<Club> *list) {
	
}

void clubsOutput(string name) {
	const string fileName = "clubs.dat";
	ofstream fout;
	fout.open(fileName, std::ios_base::app);
	fout << name << "\n";
	fout.close();
}