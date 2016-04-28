#ifndef IO_USERS_H
#define IO_USERS_H

#include "LinkedList.h"
#include "User.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

void loadUsers(LinkedList<User> *);
void saveUsers(LinkedList<User> *);

#endif