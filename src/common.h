/*
Author: Derik Gagnon
Class: CSI-240-03
Assignment: SGA Inventory (Final Project)
Date Assigned: 
Due Date: 

Certification of Authenticity:  I certify that this is entirely my own work, except where
I have given fully-documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor
of this assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff; and/or

- Communicate a copy of this assignment to a plagiarism checking service (which may then retain
a copy of this assignment on its database for the purpose of future plagiarism checking)
*/

#ifndef COMMON_H
#define COMMON_H

#include "Item.h"
#include "club.h"
#include "User.h"
#include "LinkedList.h"

using namespace std;

void clearScreen();
void displayAdminMenu(LinkedList<Item> *listOfItems, LinkedList<Club> *listOfClubs, LinkedList<User> *listOfUsers);
void displayGeneralMenu(LinkedList<Item> *listOfItems, LinkedList<Club> *listOfClubs, LinkedList<User> *listOfUsers);
void displayLogo();
void pause();


#endif

/***********************************

clearScreen();
Purpose: To clear the screen of the display
Post: Clears the screen of all text
Pre: None

displayAdminMenu();
Purpose: To display the Administrator Menu
Post: The menu has been displayed to the screen and sends the user to specified function
Pre: User has successfully logged in from public menu

displayGeneralMenu();
Purpose: To display the Public Menu
Post: The menu has been displayed to the screen and sends user to specific function
Pre: The logo has been displayed to the screen

displayLogo();
Purpose: To display the SGA Logo at the top of the command window
Post: Displays ASCII art of the SGA logo
Pre: clearScreen has been run and the display is blank

pause();
Purpose: To pause the program until the user is ready to continue
Post: Pause the program until a button is pressed
Pre: None

***********************************/