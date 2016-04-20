#include "common.h"

void clearScreen()
{
	#ifdef _WIN32
		system("CLS");
	#elif __APPLE__
		system("clear");
	#elif __linux__
		system("clear");
	#elif __unix__
		system("clear");
	#endif
}

void displayAdminMenu()
{

}

void displayGeneralMenu()
{

}

void displayLogo()
{

}

void pause()
{
	#ifdef _WIN32
		system("pause");
	#elif __APPLE__
		system("read");
	#elif __linux__
		system("read");
	#elif __unix__
		system("read");
	#endif
}
