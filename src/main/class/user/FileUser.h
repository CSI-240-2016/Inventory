/*
    Created by Dustin Yost on 4/30/2016.
*/

#ifndef INVENTORY_FILEUSER_H
#define INVENTORY_FILEUSER_H

#include "../LinkedList.h"
#include "User.h"

const string FILE_DATA_USERS = "users.dat";

void loadUsers(LinkedList<User> *list);
void saveUsers(LinkedList<User> *list);

#endif //INVENTORY_FILEUSER_H
