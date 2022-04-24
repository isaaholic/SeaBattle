#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <iomanip>

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
int maxShip1 = 9;
int liveShip1 = 9;
int maxShip2 = 9;
int liveShip2 = 9;
bool turn1 = true;
bool turn2 = false;
bool placeMod = true;
bool battleMod = false;

#include "Header.h"

int main()
{
	char** playerTableOne;
	char** playerTableTwo;
	char** freeTable = createFulltable(row);
	int** freeCor = createCoArray(row);
	char** fulltable = createFulltable(row);
	int** cordinate1 = createCoArray(row);
	//createTableForP(freeTable, freeCor, row, 0, 0);
	int** cordinate2 = createCoArray(row);
	//createTable(freeTable, freeCor, 2 * row, 0, 0);
	fillCordinateArray(cordinate1, row);
	fillCordinateArray(cordinate2, row);
	while (placeMod)
	{
		playerTableOne = createArray(row);
		playerTableTwo = createArray(row);
		createTableForPlace(playerTableOne, cordinate1, row, tagX, tagY);
		createTableForPlace(playerTableTwo, cordinate2, row, tagX, tagY);
		if (turn1)
			crossShower(playerTableOne, row, tagX, tagY);
		if (turn2)
			crossShower(playerTableTwo, row, tagX, tagY);
		fullTable(fulltable, playerTableOne, playerTableTwo, row);
		//showTable(table, cordinate, row, tagX, tagY);
		system("cls");
		if (turn1)
			cout << "Player 1:";
		else cout << setw(24) << "Player 2: ";
		cout << endl;
		for (size_t i = 0; i < row; i++)
		{
			int ss;
			if (turn1)
				ss = 0;
			else ss = 10;

			for (size_t j = 0; j < row * 2; j++)
			{
				if (turn1 && j < row)
				{
					cout << fulltable[i][j];
				}
				else if (turn2 && j >= row)
				{
					cout << fulltable[i][j];
				}
				else
				{
					cout << ' ';
				}
			}
			cout << endl;
		}
		cout << maxShip1 << endl;
		cout << maxShip2 << endl;
		if (turn1)
			crossControllerForPlace(cordinate1, tagX, tagY, row);
		if (turn2)
			crossControllerForPlace(cordinate2, tagX, tagY, row);

		deleteTable(playerTableOne, row);
		deleteTable(playerTableTwo, row);
		if (maxShip1 == 0)
		{
			turn1 = false;
			turn2 = true;
		}
		if (maxShip2 == 0)
		{
			turn1 = true;
			turn2 = false;
			placeMod = false;
			battleMod = true;
		}
	}

	while (battleMod)
	{
		playerTableOne = createArray(row);
		playerTableTwo = createArray(row);
		createTableForBattle(playerTableOne, cordinate2, row, tagX, tagY);
		createTableForBattle(playerTableTwo, cordinate1, row, tagX, tagY);
		if (turn1)
			crossShower(playerTableOne, row, tagX, tagY);
		if (turn2)
			crossShower(playerTableTwo, row, tagX, tagY);
		fullTable(fulltable, playerTableOne, playerTableTwo, row);
		system("cls");
		if (turn1)
			cout << "Player 1:";
		else cout << setw(24) << "Player 2: ";
		cout << endl;
		for (size_t i = 0; i < row; i++)
		{
			int ss;
			if (turn1)
				ss = 0;
			else ss = 10;

			for (size_t j = 0; j < row * 2; j++)
			{
				if (turn1 && j < row)
				{
					cout << fulltable[i][j];
				}
				else if (turn2 && j >= row)
				{
					cout << fulltable[i][j];
				}
				else
				{
					cout << ' ';
				}
			}
			cout << endl;
		}
		if (turn1)
			crossControllerForBattle(cordinate2, tagX, tagY, row);
		if (turn2)
			crossControllerForBattle(cordinate1, tagX, tagY, row);

		deleteTable(playerTableOne, row);
		deleteTable(playerTableTwo, row);
		if (!liveShip1)
		{
			system("cls||clear");
			cout << "Player 2 is Winner!\nCongratsssss...";
		}
		else if (!liveShip2)
		{
			system("cls||clear");
			cout << "Player 1 is winner!\nCongratsssss...";
		}
	}

	cout << "\n\n\nThe game is over. Press any key to exit." << endl;
	system("pause");
	exit(0);
}