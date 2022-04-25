#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <iomanip>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

int count1p1 = 4;
int count2p1 = 4;
int count1p2 = 3;
int count2p2 = 3;
int count2p3 = 2;
int count1p3 = 2;
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
bool placeMod = false;
bool battleMod = false;
bool rotated = true;
bool isMain = true;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);


#include "Header.h"

int main()
{
	cout << right;

	char** playerTableOne;
	char** playerTableTwo;
	char** freeTable = createFulltable(row);
	int** freeCor = createCoArray(row);
	char** fulltable = createFulltable(row);
	int** cordinate1 = createCoArray(row);
	int** cordinate2 = createCoArray(row);
	fillCordinateArray(cordinate1, row);
	fillCordinateArray(cordinate2, row);
	{
		int c = 0;
		while (isMain)
		{
			system("cls||clear");
			SetConsoleTextAttribute(h, 9);
			cout << setw(30) << "Welcome to BattleShip" << endl;
			SetConsoleTextAttribute(h, 12);
			cout << setw(25) << "Start game";
			SetConsoleTextAttribute(h, 15);
			c == 0 ? cout << char(60) : cout << ' ';
			cout << endl;
			SetConsoleTextAttribute(h, 10);
			cout << setw(22) << "Exit";
			SetConsoleTextAttribute(h, 15);
			c == 1 ? cout << char(60) : cout << ' ';
			cout << endl;
			mainController(c);
		}
	}

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
		showFullTableForPlace(fulltable);
		cout << "Press 'f' to select ship";
		if (turn1)
		{
			cout << endl;
			cout << "1) * - " << count1p1<<endl;
			cout << "2) ** - " << count1p2 << endl;
			cout << "3) *** - " << count1p3 << endl;
		}
		else
		{
			cout << endl;
			cout <<setw(24)<< "1) * - " << count2p1 << endl;
			cout <<setw(24)<< "2) ** - " << count2p2 << endl;
			cout <<setw(24)<< "3) *** - " << count2p3 << endl;
		}
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
		showFullTableForBattle(fulltable,cordinate1,cordinate2);
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
			battleMod = false;
		}
		else if (!liveShip2)
		{
			system("cls||clear");
			cout << "Player 1 is winner!\nCongratsssss...";
			battleMod = false;
		}
	}

	cout << "\n\n\nThe game is over. Press any key to exit." << endl;
	system("pause");
	exit(0);
}