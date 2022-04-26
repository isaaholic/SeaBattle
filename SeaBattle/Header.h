#pragma once

// create Array for both of Tables

char** createFulltable(int size)
{
	char** fullTable = new char* [size];
	for (size_t i = 0; i < size; i++)
	{
		fullTable[i] = new char[size * 2];
	}
	return fullTable;
}

//init FullTable

void fullTable(char** arr, char** arr1, char** arr2, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			arr[i][j] = arr1[i][j];
		}
	}
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = size; j < size * 2; j++)
		{
			arr[i][j] = arr2[i][j - size];
		}
	}
}

// Create Array for Table

char** createArray(int row)
{
	char** table = new char* [row];
	for (int i = 0; i < row; i++)
		table[i] = new char[row];
	return table;
}

// Create Array for Cordinate

int** createCoArray(int row)
{
	int** arr = new int* [row];
	for (int i = 0; i < row; i++)
		arr[i] = new int[row];
	return arr;
}

// init Cordinate

void fillCordinateArray(int** arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			arr[i][j] = 0;
		}
	}
}

// Cross Showing on the board for Battle Mod

void crossShowerForBattle(char** arr, int size, int tagX, int tagY)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (i == tagX && j == tagY)
			{
				arr[i][j] = 43;
			}
		}
	}
}

// Cross Showing on the board for Place Mod

void crossShower(char** arr, int size, int tagX, int tagY)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (i == tagX && j == tagY)
			{
				if (isActive1)
				{
					arr[i][j] = 232;
				}
				else if (isActive2)
				{
					arr[i][j] = 232;
					if (rotated)
					{
						arr[i][j + 1] = 232;
					}
					else
					{
						arr[i + 1][j] = 232;
					}
				}
				else if (isActive3)
				{
					arr[i][j] = 232;
					if (rotated)
					{
						arr[i][j + 1] = 232;
						arr[i][j + 2] = 232;
					}
					else
					{
						arr[i + 1][j] = 232;
						arr[i + 2][j] = 232;
					}
				}
				else arr[i][j] = 43;
			}
		}
	}
}

// Adding a Power Ship on the Board

void addShip1(int** cor, int tagX, int tagY)
{
	if (turn1)
	{
		if (count1p1 && cor[tagX][tagY] == 0)
		{
			cor[tagX][tagY] = 1;
			cor[tagX - 1][tagY - 1] = 2;
			cor[tagX - 1][tagY] = 2;
			cor[tagX - 1][tagY + 1] = 2;
			cor[tagX][tagY - 1] = 2;
			cor[tagX][tagY + 1] = 2;
			cor[tagX + 1][tagY - 1] = 2;
			cor[tagX + 1][tagY] = 2;
			cor[tagX + 1][tagY + 1] = 2;
			count1p1--;
			maxShip1--;
		}
		else if (count1p1 == 0)
		{
			cout << "\nYou don't have a ship with a power";
			Sleep(1500);
		}
		else {
			cout << "\nYour choice is very close to the protected land";
			Sleep(1500);
		}
	}
	else
	{
		if (count2p1 && cor[tagX][tagY] == 0)
		{
			cor[tagX][tagY] = 1;
			cor[tagX - 1][tagY - 1] = 2;
			cor[tagX - 1][tagY] = 2;
			cor[tagX - 1][tagY + 1] = 2;
			cor[tagX][tagY - 1] = 2;
			cor[tagX][tagY + 1] = 2;
			cor[tagX + 1][tagY - 1] = 2;
			cor[tagX + 1][tagY] = 2;
			cor[tagX + 1][tagY + 1] = 2;
			count2p1--;
			maxShip2--;

		}
		else if (count2p1 == 0)
		{
			cout << "\nYou don't have a ship with a power";
			Sleep(1500);
		}
		else {
			cout << "\nYour choice is very close to the protected land";
			Sleep(1500);
		}
	}
}

// Adding 2 Power Ship on the Board

void addShip2(int** cor, int tagX, int tagY)
{
	int tag2Y = tagY + 1;
	int tag2X = tagX + 1;
	if (!rotated)
	{
		if (turn1 && tag2Y != 13)
		{
			if (count1p2 && cor[tagX][tagY] == 0 && cor[tag2X][tagY] == 0)
			{
				cor[tagX][tagY] = 1;
				cor[tag2X][tagY] = 1;

				cor[tagX - 1][tagY - 1] = 2;//
				cor[tagX - 1][tagY] = 2;//
				cor[tagX - 1][tag2Y] = 2;//

				cor[tagX][tagY - 1] = 2;
				cor[tagX][tag2Y] = 2;
				cor[tag2X][tagY - 1] = 2;
				cor[tag2X][tag2Y] = 2;

				cor[tag2X + 1][tagY - 1] = 2;//
				cor[tag2X + 1][tagY] = 2;//
				cor[tag2X + 1][tag2Y] = 2;//



				count1p2--;
				maxShip1--;
			}
			else if (count1p2 == 0)
			{
				cout << "\nYou don't have a ship with 2 power";
				Sleep(1500);
			}
			else {
				cout << "\nYour choice is very close to the protected land";
				Sleep(1500);
			}
		}
		else if (turn2 && tag2Y != 13)
		{
			if (count2p2 && cor[tagX][tagY] == 0 && cor[tagX][tag2Y] == 0)
			{
				cor[tagX][tagY] = 1;
				cor[tag2X][tagY] = 1;

				cor[tagX - 1][tagY - 1] = 2;//
				cor[tagX - 1][tagY] = 2;//
				cor[tagX - 1][tag2Y] = 2;//

				cor[tagX][tagY - 1] = 2;
				cor[tagX][tag2Y] = 2;
				cor[tag2X][tagY - 1] = 2;
				cor[tag2X][tag2Y] = 2;

				cor[tag2X + 1][tagY - 1] = 2;//
				cor[tag2X + 1][tagY] = 2;//
				cor[tag2X + 1][tag2Y] = 2;//

				count2p2--;
				maxShip2--;
			}
			else if (count2p2 == 0)
			{
				cout << "\nYou don't have a ship with 2 power";
				Sleep(1500);
			}
			else {
				cout << "\nYour choice is very close to the protected land";
				Sleep(1500);
			}
		}
		else
		{
			cout << "\nYour choice is very close to the protected land";
			Sleep(1500);
		}
	}
	else
	{
		if (turn1 && tag2Y != 13)
		{
			if (count1p2 && cor[tagX][tagY] == 0 && cor[tagX][tag2Y] == 0)
			{
				cor[tagX][tagY] = 1;
				cor[tagX][tag2Y] = 1;

				cor[tagX - 1][tagY - 1] = 2;
				cor[tagX - 1][tagY] = 2;
				cor[tagX - 1][tag2Y] = 2;
				cor[tagX - 1][tag2Y + 1] = 2;
				cor[tagX + 1][tagY - 1] = 2;
				cor[tagX + 1][tagY] = 2;
				cor[tagX + 1][tag2Y] = 2;
				cor[tagX + 1][tag2Y + 1] = 2;
				cor[tagX][tagY - 1] = 2;
				cor[tagX][tag2Y + 1] = 2;

				count1p2--;
				maxShip1--;
			}
			else if (count1p2 == 0)
			{
				cout << "\nYou don't have a ship with 2 power";
				Sleep(1500);
			}
			else {
				cout << "\nYour choice is very close to the protected land";
				Sleep(1500);
			}
		}
		else if (turn2 && tag2Y != 13)
		{
			if (count2p2 && cor[tagX][tagY] == 0 && cor[tagX][tag2Y] == 0)
			{
				cor[tagX][tagY] = 1;
				cor[tagX][tag2Y] = 1;

				cor[tagX - 1][tagY - 1] = 2;
				cor[tagX - 1][tagY] = 2;
				cor[tagX - 1][tag2Y] = 2;
				cor[tagX - 1][tag2Y + 1] = 2;
				cor[tagX + 1][tagY - 1] = 2;
				cor[tagX + 1][tagY] = 2;
				cor[tagX + 1][tag2Y] = 2;
				cor[tagX + 1][tag2Y + 1] = 2;
				cor[tagX][tagY - 1] = 2;
				cor[tagX][tag2Y + 1] = 2;

				count2p2--;
				maxShip2--;
			}
			else if (count2p2 == 0)
			{
				cout << "\nYou don't have a ship with 2 power";
				Sleep(1500);
			}
			else {
				cout << "\nYour choice is very close to the protected land";
				Sleep(1500);
			}
		}
		else
		{
			cout << "\nYour choice is very close to the protected land";
			Sleep(1500);
		}
	}
}

// Adding 3 Power Ship on the Board

void addShip3(int** cor, int tagX, int tagY)
{
	int tag2Y = tagY + 1;
	int tag2X = tagX + 1;
	int tag3Y = tagY + 2;
	int tag3X = tagX + 2;

	if (!rotated)
	{
		if (turn1 && tag3Y != 13)
		{
			if (count1p3 && cor[tagX][tagY] == 0 && cor[tag2X][tagY] == 0 && cor[tag3X][tagY] == 0)
			{
				cor[tagX][tagY] = 1;
				cor[tag2X][tagY] = 1;
				cor[tag3X][tagY] = 1;

				cor[tagX - 1][tagY - 1] = 2;//
				cor[tagX - 1][tagY] = 2;//
				cor[tagX - 1][tag2Y] = 2;//

				cor[tagX][tagY - 1] = 2;
				cor[tagX][tag2Y] = 2;
				cor[tag2X][tagY - 1] = 2;
				cor[tag2X][tag2Y] = 2;
				cor[tag3X][tagY - 1] = 2;
				cor[tag3X][tag2Y] = 2;

				cor[tag3X + 1][tagY - 1] = 2;//
				cor[tag3X + 1][tagY] = 2;//
				cor[tag3X + 1][tag2Y] = 2;//

				maxShip1--;
				count1p3--;

			}
			else if (count1p3 == 0)
			{
				cout << "\nYou don't have a ship with 3 power";
				Sleep(1500);
			}
			else {
				cout << "\nYour choice is very close to the protected land";
				Sleep(1500);
			}
		}
		else if (turn2 && tag3Y != 13)
		{
			if (count2p3 && cor[tagX][tagY] == 0 && cor[tagX][tag2Y] == 0 && cor[tagX][tag3Y] == 0)
			{
				cor[tagX][tagY] = 1;
				cor[tagX][tag2Y] = 1;
				cor[tagX][tag3Y] = 1;

				cor[tagX - 1][tagY - 1] = 2;
				cor[tagX - 1][tagY] = 2;
				cor[tagX - 1][tag2Y] = 2;
				cor[tagX - 1][tag3Y] = 2;
				cor[tagX - 1][tag3Y + 1] = 2;
				cor[tagX + 1][tagY - 1] = 2;
				cor[tagX + 1][tagY] = 2;
				cor[tagX + 1][tag2Y] = 2;
				cor[tagX + 1][tag3Y] = 2;
				cor[tagX + 1][tag3Y + 1] = 2;
				cor[tagX][tagY - 1] = 2;
				cor[tagX][tag3Y + 1] = 2;


				maxShip2--;
				count2p3--;

			}
			else if (count2p3 == 0)
			{
				cout << "\nYou don't have a ship with 2 power";
				Sleep(1500);
			}
			else {
				cout << "\nYour choice is very close to the protected land";
				Sleep(1500);
			}
		}
		else
		{
			cout << "\nYour choice is very close to the protected land";
			Sleep(1500);
		}
	}
	else
	{
		if (turn1 && tag3Y != 13)
		{
			if (count1p3 && cor[tagX][tagY] == 0 && cor[tagX][tag2Y] == 0 && cor[tagX][tag3Y] == 0)
			{
				cor[tagX][tagY] = 1;
				cor[tagX][tag2Y] = 1;
				cor[tagX][tag3Y] = 1;

				cor[tagX - 1][tagY - 1] = 2;
				cor[tagX - 1][tagY] = 2;
				cor[tagX - 1][tag2Y] = 2;
				cor[tagX - 1][tag3Y] = 2;
				cor[tagX - 1][tag3Y + 1] = 2;
				cor[tagX + 1][tagY - 1] = 2;
				cor[tagX + 1][tagY] = 2;
				cor[tagX + 1][tag2Y] = 2;
				cor[tagX + 1][tag3Y] = 2;
				cor[tagX + 1][tag3Y + 1] = 2;
				cor[tagX][tagY - 1] = 2;
				cor[tagX][tag3Y + 1] = 2;


				maxShip1--;
				count1p3--;

			}
			else if (count1p3 == 0)
			{
				cout << "\nYou don't have a ship with 3 power";
				Sleep(1500);
			}
			else {
				cout << "\nYour choice is very close to the protected land";
				Sleep(1500);
			}
		}
		else if (turn2 && tag3Y != 13)
		{
			if (count2p3 && cor[tagX][tagY] == 0 && cor[tagX][tag2Y] == 0 && cor[tagX][tag3Y] == 0)
			{
				cor[tagX][tagY] = 1;
				cor[tagX][tag2Y] = 1;
				cor[tagX][tag3Y] = 1;

				cor[tagX - 1][tagY - 1] = 2;
				cor[tagX - 1][tagY] = 2;
				cor[tagX - 1][tag2Y] = 2;
				cor[tagX - 1][tag3Y] = 2;
				cor[tagX - 1][tag3Y + 1] = 2;
				cor[tagX + 1][tagY - 1] = 2;
				cor[tagX + 1][tagY] = 2;
				cor[tagX + 1][tag2Y] = 2;
				cor[tagX + 1][tag3Y] = 2;
				cor[tagX + 1][tag3Y + 1] = 2;
				cor[tagX][tagY - 1] = 2;
				cor[tagX][tag3Y + 1] = 2;


				maxShip2--;
				count2p3--;

			}
			else if (count2p3 == 0)
			{
				cout << "\nYou don't have a ship with 2 power";
				Sleep(1500);
			}
			else {
				cout << "\nYour choice is very close to the protected land";
				Sleep(1500);
			}
		}
		else
		{
			cout << "\nYour choice is very close to the protected land";
			Sleep(1500);
		}
	}
}

// Started Menu Controller

void mainController(int& c)
{
	int k;
	switch (k = _getch())
	{
	case KEY_UP:
		c = 0;
		break;
	case KEY_DOWN:
		c = 1;
		break;
	case 'e':
	case 'E':
		system("cls||clear");
		if (c == 0)
		{
			cout << "Starting game.";
			int f = 5;
			while (f)
			{
				system("cls||clear");
				cout << "Starting game..";
				Sleep(250);
				system("cls||clear");
				cout << "Starting game...";
				Sleep(250);
				system("cls||clear");
				cout << "Starting game..";
				Sleep(250);
				system("cls||clear");
				cout << "Starting game.";
				Sleep(250);
				f--;
			}
			isMain = false;
			placeMod = true;
		}
		else exit(0);
		break;
	}
}

// Cross Movement for PlaceMod

void crossControllerForPlace(int** cor, int& tagX, int& tagY, int size)
{
	int c = 0;
	switch (c = _getch())
	{
	case KEY_UP:
		if (tagX != 1)
			tagX--;
		break;
	case KEY_DOWN:
		if (tagX != size - 2)
		{
			if (!(isActive2 && !rotated && tagX >= 11))
			{
				if (!(isActive3 && !rotated && tagX >= 10))
					tagX++;
			}

		}
		break;
	case KEY_LEFT:
		if (tagY != 1)
			tagY--;
		break;
	case KEY_RIGHT:
		if (tagY != size - 2)
		{
			if (!(isActive2 && rotated && tagY == 11))
			{
				if (!(isActive3 && rotated && tagY == 10))
					tagY++;
			}
		}
		break;
	case 'e':
	case 'E':
		if (isActive1)
			//cor[tagX][tagY]=1;
			addShip1(cor, tagX, tagY);
		else if (isActive2)
			addShip2(cor, tagX, tagY);
		else if (isActive3)
			addShip3(cor, tagX, tagY);
		break;
	case 'r':
	case 'R':
		if (tagX >= 11 && isActive3)
			break;
		else if (tagX >= 12 && isActive2)
			break;
		if (tagY >= 11 && isActive3)
			break;
		else if (tagY >= 12 && isActive2)
			break;
		if (rotated)
			rotated = false;
		else rotated = true;
		break;
	case 'f':
	case 'F':
		int k = 0;
		cout << "Enter Power of Your Ship: ";
		cin >> k;
		switch (k)
		{
		case 1:
			isActive1 = 1;
			isActive2 = 0;
			isActive3 = 0;
			break;
		case 2:
			if (!rotated && tagX == 12)
				rotated = true;
			else if (rotated && tagY == 12)
				rotated = false;
			isActive1 = 0;
			isActive2 = 1;
			isActive3 = 0;
			break;
		case 3:
			if (tagY >= 11 && tagX >= 11)
				break;
			if (!rotated && tagX >= 11)
				rotated = true;
			else if (rotated && tagY >= 11)
				rotated = false;
			isActive1 = 0;
			isActive2 = 0;
			isActive3 = 1;
			break;
		}
		break;
	}
}

// Attack Any Ship

void attackShip(int** cor, int tagX, int tagY)
{
	if (cor[tagX][tagY] == 1)
	{
		if (cor[tagX][tagY + 1] == 1)
			cor[tagX][tagY] = 3;
		else if (cor[tagX][tagY - 1] == 1)
			cor[tagX][tagY] = 3;
		else if (cor[tagX + 1][tagY] == 1)
			cor[tagX][tagY] = 3;
		else if (cor[tagX - 1][tagY] == 1)
			cor[tagX][tagY] = 3;
		else
		{
			if (cor[tagX][tagY + 1] == 3)
			{
				cor[tagX][tagY + 1] = 4;
				if (tagY < 12 && cor[tagX][tagY + 2] == 3)
					cor[tagX][tagY + 2] = 4;
			}
			if (cor[tagX][tagY - 1] == 3)
			{
				cor[tagX][tagY - 1] = 4;
				if (tagY > 1 && cor[tagX][tagY - 2] == 3)
					cor[tagX][tagY - 2] = 4;
			}
			if (cor[tagX + 1][tagY] == 3)
			{
				cor[tagX + 1][tagY] = 4;
				if (tagX < 12 && cor[tagX + 2][tagY] == 3)
					cor[tagX + 2][tagY] = 4;
			}
			if (cor[tagX - 1][tagY] == 3)
			{
				cor[tagX - 1][tagY] = 4;
				if (tagX > 1 && cor[tagX - 2][tagY] == 3)
					cor[tagX - 2][tagY] = 4;
			}
			cor[tagX][tagY] = 4;
			if (turn1)
			{
				liveShip2--;
			}
			else if (turn2)
			{
				liveShip1--;
			}
		}
	}
	else if (cor[tagX][tagY] != 0 && cor[tagX][tagY] != 2)
	{
		cout << "Please attack other place";
		Sleep(500);
	}
	else
	{
		cor[tagX][tagY] = 5;
		if (turn1)
		{
			turn1 = false;
			turn2 = true;
		}
		else if (turn2)
		{
			turn1 = true;
			turn2 = false;
		}
	}
}

// Cross Movement For BattleMod

void crossControllerForBattle(int** cor, int& tagX, int& tagY, int size)
{
	int c = 0;
	switch ((c = _getch()))
	{
	case KEY_UP:
		if (tagX != 1)
			tagX--;
		break;
	case KEY_DOWN:
		if (tagX != size - 2)
			tagX++;
		break;
	case KEY_LEFT:
		if (tagY != 1)
			tagY--;
		break;
	case KEY_RIGHT:
		if (tagY != size - 2)
			tagY++;
		break;
	case 'e':
	case 'E':
		attackShip(cor, tagX, tagY);
		break;
	}
}

//Table being ready for PlaceMod

void createTableForPlace(char** arr, int** cor, int size, int tagX, int tagY)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (cor[i][j] == 1) arr[i][j] = 232;
			else if (i == 0 || i == size - 1) arr[i][j] = 178;
			else if (j == 0 || j == size - 1)arr[i][j] = 178;
			else arr[i][j] = 176;
		}
	}
}

// Table being ready for BattleMod

void createTableForBattle(char** arr, int** cor, int size, int tagX, int tagY)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (i == 0 || i == size - 1) arr[i][j] = 178;
			else if (j == 0 || j == size - 1)arr[i][j] = 178;
			else if (cor[i][j] == 3) arr[i][j] = 'H';
			else if (cor[i][j] == 4) arr[i][j] = 'A';
			else if (cor[i][j] == 5) arr[i][j] = 'M';
			else arr[i][j] = 176;
		}
	}
}

//Delete Table on heap

void deleteTable(char** arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

//Show Both of them on PlaceMod

void showFullTableForPlace(char** fulltable)
{
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
}

//Show Both of them on BattleMod

void showFullTableForBattle(char** fulltable, int** cor1, int** cor2)
{
	for (size_t i = 0; i < row; i++)
	{

		for (size_t j = 0; j < row * 2; j++)
		{
			if (j >= row)
			{
				if (cor1[i][j - 14] == 3)
					SetConsoleTextAttribute(h, 14);
				else if (cor1[i][j - 14] == 4)
					SetConsoleTextAttribute(h, 2);
				else if (cor1[i][j - 14] == 5)
					SetConsoleTextAttribute(h, 4);
				else
					SetConsoleTextAttribute(h, 15);
				cout << fulltable[i][j];
			}
			else
			{
				if (cor2[i][j] == 3)
					SetConsoleTextAttribute(h, 14);
				else if (cor2[i][j] == 4)
					SetConsoleTextAttribute(h, 2);
				else if (cor2[i][j] == 5)
					SetConsoleTextAttribute(h, 4);
				else
					SetConsoleTextAttribute(h, 15);
				cout << fulltable[i][j];
			}
		}
		cout << endl;
	}
}


//Random Ship Adder
void randomMode(int** cor)
{
	while (1)
	{
		int _tagX = 0, _tagY = 0;
		_tagX = 1 + rand() % (12 - 1 + 1);
		_tagY = 1 + rand() % (12 - 1 + 1);

		if (cor[_tagX][_tagY] == 0 && count2p1)
			addShip1(cor, _tagX, _tagY);
		else if (cor[_tagX][_tagY] == 0 && count2p2)
			addShip2(cor, _tagX, _tagY);
		else if (cor[_tagX][_tagY] == 0 && count2p3)
			addShip3(cor, _tagX, _tagY);
		else if (!(count2p1 || count2p2 || count2p3))
			break;
	}
}