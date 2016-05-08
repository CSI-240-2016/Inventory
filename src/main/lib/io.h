/*
    Created by Dustin Yost on 4/30/2016.
*/

#ifndef INVENTORY_IO_H
#define INVENTORY_IO_H

#include <string>
#include <iostream>

using namespace std;

/** PURPOSE: To clear the screen of the display
 * PRE:  None
 * POST: Clears the screen of all text
 */
void clear();

/** PURPOSE: To pause the program until the user is ready to continue
 * PRE:  None
 * POST: Pause the program until a ENTER is pressed
 */
void pause();

int cinInteger(string prompt);

string cinString(string prompt);

#endif //INVENTORY_IO_H
