#pragma once

char** createArray(int row)
{
	char** table = new char* [row];
	for (int i = 0; i < row; i++)
		table[i] = new char[row];
	return table;
}

int** createCoArray(int row)
{
	int** arr = new int* [row];
	for (int i = 0; i < row; i++)
		arr[i] = new int[row];
	return arr;
}

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

void crossShower(char** arr, int size, int tagX, int tagY)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (i == tagX && j == tagY)
				arr[i][j] = 43;
		}
	}
}

void addShip1(int** cor, int tagX, int tagY)
{
	static int count1 = 4;
	if (count1 && cor[tagX][tagY] == 0)
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
		count1--;
	}
	else if (count1 == 0)
	{
		cout << "\nYou don't have a ship with a power";
		Sleep(1500);
	}
	else {
		cout << "\nYour choice is very close to the protected land";
		Sleep(1500);
	}
}

void addShip2(int** cor, int tagX, int tagY)
{
	static int count2 = 3;
	int tag2Y = tagY + 1;
	if (count2 && cor[tagX][tagY] == 0 && cor[tagX][tag2Y] == 0)
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

		count2--;
	}
	else if (count2 == 0)
	{
		cout << "\nYou don't have a ship with 2 power";
		Sleep(1500);
	}
	else {
		cout << "\nYour choice is very close to the protected land"; 
		Sleep(1500);
	}
}

void addShip3(int** cor, int tagX, int tagY)
{
	static int count3 = 2;
	int tag2Y = tagY + 1;
	int tag3Y = tagY + 2;
	if (count3 && cor[tagX][tagY] == 0 && cor[tagX][tag2Y] == 0&&cor[tagX][tag3Y]==0)
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

		count3--;
	}
	else if (count3 == 0)
	{
		cout << "\nYou don't have a ship with 2 power";
		Sleep(1500);
	}
	else {
		cout << "\nYour choice is very close to the protected land"; 
		Sleep(1500);
	}
}

void crossController(int** cor, int& tagX, int& tagY, int size)
{
	int c = 0;
	switch ((c = _putch(_getch())))
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
		if (isActive1)
			addShip1(cor, tagX, tagY);
		else if (isActive2)
			addShip2(cor, tagX, tagY);
		else if (isActive3)
			addShip3(cor, tagX, tagY);
		break;
	case 'f':
		int k = 0;
		cout << "Enter Power of Your Ship";
		cin >> k;
		switch (k)
		{
		case 1:
			isActive1 = 1;
			isActive2 = 0;
			isActive3 = 0;
			break;
		case 2:
			isActive1 = 0;
			isActive2 = 1;
			isActive3 = 0;
			break;
		case 3:
			isActive1 = 0;
			isActive2 = 0;
			isActive3 = 1;
			break;
		default:
			break;
		}
	}
}


void showTable(char** arr, int** cor, int& size, int& tagX, int& tagY)
{
	system("cls||clear");
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << tagX << ' ' << tagY<<endl<<endl;
	crossController(cor, tagX, tagY, size);
}

void createTable(char** arr, int** cor, int size, int tagX, int tagY)
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

void deleteTable(char** arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}