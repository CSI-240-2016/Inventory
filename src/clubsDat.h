
#include <string>
#include "LinkedList.h"
#include "club.h"
#include <fstream>

using namespace std;

void clubsInput(LinkedList<Club> *list);
void saveClubs(LinkedList<Club> *);
void printClubs(LinkedList<Club> *);

void clubsOutput(string name);