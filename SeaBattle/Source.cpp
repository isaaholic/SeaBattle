#include <iostream>
#include <conio.h>
#include <Windows.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

bool isActive1 = false;
bool isActive2 = false;
bool isActive3 = false;
int tagX = 1;
int tagY = 1;
int row = 14;

#include "Header.h"

int main()
{
	char** table;
	int** cordinate = createCoArray(row);
	fillCordinateArray(cordinate, row);
	while (1)
	{
		table = createArray(row);
		createTable(table, cordinate, row, tagX, tagY);
		crossShower(table, row, tagX, tagY);
		showTable(table, cordinate, row, tagX, tagY);
		deleteTable(table, row);
	}

}