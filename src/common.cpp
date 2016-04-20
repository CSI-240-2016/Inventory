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
	cout << setw(29) << right << "Administrator Menu:\n\n\n";
	cout << setw(12) << right << "1.) " << left << "Check In and Check Out\n";
	cout << setw(12) << right << "2.) " << left << "Items\n";
	cout << setw(12) << right << "3.) " << left << "Clubs\n";
	cout << setw(12) << right << "4.) " << left << "Users\n";
	cout << setw(12) << right << "5.) " << left << "Search\n";
	cout << setw(12) << right << "6.) " << left << "Export\n";
	cout << setw(12) << right << "7.) " << left << "Log Out\n";
}

void displayGeneralMenu()
{
	cout << setw(22) << right << "Public Menu:\n\n\n";
	cout << setw(12) << right << "1.) " << left << "Items\n";
	cout << setw(12) << right << "2.) " << left << "Search\n";
	cout << setw(12) << right << "3.) " << left << "Log In as Admin\n";
	cout << setw(12) << right << "4.) " << left << "Shutdown\n";
}

void displayLogo()
{
	clearScreen();
	cout << endl << endl <<
		"    _____  _____       " << endl <<
		"   / ____|/ ____|   /\\" << endl <<
		"  | (___ | |  __   /  \\" << endl <<
		"   \\___ \\| | |_ | / /\\ \\" << endl <<
		"   ____) | |__| |/ ____ \\" << endl <<
		"  |_____/ \\_____/_/    \\_\\" << endl << endl << endl;
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
