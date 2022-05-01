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
int recX;
int recY;
int row = 14;
int maxShip1 = 9;
int liveShip1 = 9;
int maxShip2 = 9;
int liveShip2 = 9;
bool turn1 = true;
bool turn2 = false;
bool rturn1 = false;
bool rturn2 = false;
bool placeMod = false;
bool battleMod = false;
bool rotated = true;
bool isMain = true;
bool isSelectPlace = false;
bool game = true;
bool autoMode = false;
bool selectTurn;
int isMode1 = 0;
int isMode2 = 0;
bool correctAttack = false;
bool sideR=true;
bool sideL = false;
bool sideU = false;
bool sideD = false;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);


#include "Header.h"
#include "Tables.h"

int main()
{

	srand(time(0));
	cout << right;
	fillCordinateArray(cordinate1, row);
	fillCordinateArray(cordinate2, row);
	while (game)
	{

		{
			int c = 0;
			while (isMain)
			{
				cout << "\x1B[2J\x1B[H";
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

		{
			int c = 0;
			while (isSelectPlace)
			{
				system("cls||clear");
				SetConsoleTextAttribute(h, 9);
				cout << setw(30) << "New Game: " << endl;
				SetConsoleTextAttribute(h, 12);
				cout << setw(25) << "Select player:";
				SetConsoleTextAttribute(h, 15);
				c == 0 ? cout << char(60) : cout << ' ';
				cout << endl;
				SetConsoleTextAttribute(h, 10);
				cout << setw(26) << " Settings";
				SetConsoleTextAttribute(h, 15);
				c == 1 ? cout << char(60) : cout << ' ';
				cout << endl;
				placeController(c);
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
				cout << "1) * - " << count1p1 << endl;
				cout << "2) ** - " << count1p2 << endl;
				cout << "3) *** - " << count1p3 << endl;
			}
			else
			{
				cout << endl;
				cout << setw(24) << "1) * - " << count2p1 << endl;
				cout << setw(24) << "2) ** - " << count2p2 << endl;
				cout << setw(24) << "3) *** - " << count2p3 << endl;
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
				if (isMode2 == 2)
				{
					turn2 = true;
					randomMode(cordinate2);
					turn2 = false;
				}
				else if (isMode2 == 0)
				{
					turn2 = true;
					randomMode(cordinate2);
					rturn2 = true;
					turn2 = false;
				}
				else
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
			if (turn1 && !rturn1)
				crossShowerForBattle(playerTableOne, row, tagX, tagY);
			if (turn2 && !rturn2)
				crossShowerForBattle(playerTableTwo, row, tagX, tagY);
			fullTable(fulltable, playerTableOne, playerTableTwo, row);
			system("cls");
			if (turn1)
				cout << "Player 1:";
			else cout << setw(24) << "Player 2: ";
			cout << endl;
			showFullTableForBattle(fulltable, cordinate1, cordinate2);
			if (turn1 && rturn1)
				BotMode(cordinate2);
			else if(turn1)
				crossControllerForBattle(cordinate2, tagX, tagY, row);
			if (turn2 && rturn2)
				BotMode(cordinate1);
			else if(turn2)
				crossControllerForBattle(cordinate1, tagX, tagY, row);
			deleteTable(playerTableOne, row);
			deleteTable(playerTableTwo, row);
			if (!liveShip1)
			{
				system("cls||clear");
				cout << "Player 2 is Winner!\nCongratsssss...";
				battleMod = false;
				game = false;
			}
			else if (!liveShip2)
			{
				system("cls||clear");
				cout << "Player 1 is winner!\nCongratsssss...";
				battleMod = false;
				game = false;
			}
		}
	}
	cout << "\n\n\nThe game is finished." << endl;
	system("pause");
	exit(0);

}