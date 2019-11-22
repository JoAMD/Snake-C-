// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <dos.h>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
bool snakeArr[width][height];

void Setup()
{
	gameOver = false;
	x = width / 2;
	y = height / 2;

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			snakeArr[i][j] = false;
		}
	}
	snakeArr[x][y] = true;

	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void Draw()
{
	system("cls");
	for (int i = 0; i < width + 2; i++)
	{
		cout << "#";
	}
	cout << endl;
	
	for (int i = 1; i < width + 1; i++)
	{
		cout << "#";
		for (int j = 1; j < height + 1; j++)
		{
			if (snakeArr[i - 1][j - 1])
			{
				cout << "@";
			}
			else
			{
				cout << " ";
			}
		}
		cout << "#";
		cout << endl;
	}

	for (int i = 0; i < height + 2; i++)
	{
		cout << "#";
	}
	cout << endl;
}

void Input()
{

}

void Logic()
{

}

int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		delay(10);
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
